#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define FILAK 48
#define ZUTABEAK 64
int mapa[FILAK][ZUTABEAK];
JOKO_ELEMENTUA jokalaria;
int mugimenduaezkerra, up, mugimenduabehean, mugimenduaeskuina;
int mugimendua(int puzzle6, int kulto) {

	int ebentu = 0, scorepuzzle = 0, konprobaketaPuzzle6 = 0, filak, zutabeak,irten=0;
	JOKO_ELEMENTUA mapaglobal;
	//Azken puzzlearen matrizea
	int mapPuzzle6[FILAK][ZUTABEAK] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,5,2,2,2,2,2,2,2,2,2,2,11,11,11,11,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,11,11,11,11,11,2,2,2,2,2,7,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1,0,0,0,0,0,4,2,0,0,0,0},
	{0,0,0,0,1,0,4,1,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,12,0,0,0},
	{0,0,0,0,1,0,4,1,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,0,0,0},
	{0,0,0,0,1,0,4,1,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,6,3,3,3,3,1,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,8,0,0,0,0,0},
	{0,0,0,0,5,2,2,2,2,1,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,4,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,7,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,4,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,0,0,0,4,1,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,4,0,0,0,0,1,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,4,1,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,4,1,0,0,0,0,4,0,0,0,1,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,4,1,0,0,0,0,2,2,2,2,2,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,1,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0},
	{0,0,0,0,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	ebentu = ebentuaJasoGertatuBada();
	//Kolisioak egiteko konprobaketak.Hau ahalbidetzen du tekla guztiak eman ahal izatea "blokeatuta" dagoena baizik
	if (mugimenduaezkerra == 0 && (ebentu == TECLA_RIGHT || ebentu == TECLA_d || ebentu == TECLA_UP || ebentu == TECLA_w || ebentu == TECLA_DOWN || ebentu == TECLA_s)) {
		mugimenduaezkerra = 1;
	}
	if (up == 0 && (ebentu == TECLA_RIGHT || ebentu == TECLA_d || ebentu == TECLA_LEFT || ebentu == TECLA_a || ebentu == TECLA_DOWN || ebentu == TECLA_s)) {
		up = 1;
	}
	if (mugimenduabehean == 0 && (ebentu == TECLA_RIGHT || ebentu == TECLA_d || ebentu == TECLA_UP || ebentu == TECLA_w || ebentu == TECLA_UP || ebentu == TECLA_w)) {
		mugimenduabehean = 1;
	}
	if (mugimenduaeskuina == 0 && (ebentu == TECLA_LEFT || ebentu == TECLA_a || ebentu == TECLA_UP || ebentu == TECLA_w || ebentu == TECLA_DOWN || ebentu == TECLA_s)) {
		mugimenduaeskuina = 1;
	}
	if (ebentu == TECLA_RIGHT || ebentu == TECLA_d) {
		if (mugimenduaeskuina == 1) {
			if (puzzle6 == 1) {//Azken puzzlea denean mugimendua aldatzeko
				if (scorepuzzle >= 70 || konprobaketaPuzzle6 == 1) {
					scorepuzzle = scorepuzzle - 5;
					konprobaketaPuzzle6 = 1;
				}
				if (konprobaketaPuzzle6 == 0) {
					scorepuzzle = scorepuzzle + 5;
				}
				while (mugimenduaeskuina == 1) {
					jokalaria.pos.x = jokalaria.pos.x + 5;
					irudiaKendu(jokalaria.id);
					jokalaria.id = JOKOA_jokalariaEskuineraIrudiaSortu();
					filak = jokalaria.pos.y / 10;
					zutabeak = jokalaria.pos.x / 10;

					if (mapPuzzle6[filak][zutabeak] == 4) {
						mugimenduaeskuina = 0;
					}
					if (mapPuzzle6[filak][zutabeak] == 7) {
						mugimenduaeskuina = 0;
						up = 0;
					}
					if (mapPuzzle6[filak][zutabeak] == 8) {
						mugimenduaeskuina = 0;
						mugimenduabehean = 0;
					}
					if (mapPuzzle6[filak][zutabeak] == 12) {
						mapaglobal.id = irabaztean();
						Sleep(2000);
						elkarrizketaMaltzurrarekin(mapaglobal.id);
						jokalaria.pos.x = 0;
						puzzle6 = 0;
						irten = 1;
					}
				}
			}
			else {
				jokalaria.pos.x = jokalaria.pos.x + 5;
				irudiaKendu(jokalaria.id);
				if (kulto == 1) {//jokalaria kultoko arropa hartu badu hori jartzen da bestela normal marrazten da
					jokalaria.id = JOKOA_jokalariaKEskuineraIrudiaSortu();
				}
				else {
					jokalaria.id = JOKOA_jokalariaEskuineraIrudiaSortu();
				}
			}
		}
	}
	if (ebentu == TECLA_UP || ebentu == TECLA_w) {
		if (puzzle6 == 1) {
			if (scorepuzzle >= 70 || konprobaketaPuzzle6 == 1) {
				scorepuzzle = scorepuzzle - 5;
				konprobaketaPuzzle6 = 1;
			}
			if (konprobaketaPuzzle6 == 0) {
				scorepuzzle = scorepuzzle + 5;
			}
			while (up == 1) {
				jokalaria.pos.y = jokalaria.pos.y - 5;
				irudiaKendu(jokalaria.id);
				jokalaria.id = JOKOA_jokalariaAtzeraIrudiaSortu();
				filak = jokalaria.pos.y / 10;
				zutabeak = jokalaria.pos.x / 10;
				if (mapPuzzle6[filak][zutabeak] == 2) {
					up = 0;
				}
				if (mapPuzzle6[filak][zutabeak] == 5) {
					up = 0;
					mugimenduaezkerra = 0;
				}
				if (mapPuzzle6[filak][zutabeak] == 7) {
					mugimenduaeskuina = 0;
					up = 0;
				}
				if (mapPuzzle6[filak][zutabeak] == 11) {
					up = 0;
					mugimenduabehean = 0;
				}
			}
		}
		else {
			if (up == 1) {
				jokalaria.pos.y = jokalaria.pos.y - 5;
				irudiaKendu(jokalaria.id);
				if (kulto == 1) {
					jokalaria.id = JOKOA_jokalariaKAurreraIrudiaSortu();
				}
				else {
					jokalaria.id = JOKOA_jokalariaAtzeraIrudiaSortu();
				}
			}
		}
	}
	if (ebentu == TECLA_LEFT || ebentu == TECLA_a) {
		if (puzzle6 == 1) {
			if (scorepuzzle >= 70 || konprobaketaPuzzle6 == 1) {
				scorepuzzle = scorepuzzle - 5;
				konprobaketaPuzzle6 = 1;
			}
			if (konprobaketaPuzzle6 == 0) {
				scorepuzzle = scorepuzzle + 5;
			}
			while (mugimenduaezkerra == 1) {
				jokalaria.pos.x = jokalaria.pos.x - 5;
				irudiaKendu(jokalaria.id);
				jokalaria.id = JOKOA_jokalariaEzkerreraIrudiaSortu();
				filak = jokalaria.pos.y / 10;
				zutabeak = jokalaria.pos.x / 10;

				if (mapPuzzle6[filak][zutabeak] == 1) {
					mugimenduaezkerra = 0;
				}
				if (mapPuzzle6[filak][zutabeak] == 5) {
					up = 0;
					mugimenduaezkerra = 0;
				}
				if (mapPuzzle6[filak][zutabeak] == 6) {
					mugimenduabehean = 0;
					mugimenduaezkerra = 0;
				}
			}
		}
		else {
			if (mugimenduaezkerra == 1) {
				jokalaria.pos.x = jokalaria.pos.x - 5;
				irudiaKendu(jokalaria.id);
				if (kulto == 1) {
					jokalaria.id = JOKOA_jokalariaKEzkerreraIrudiaSortu();
				}
				else {
					jokalaria.id = JOKOA_jokalariaEzkerreraIrudiaSortu();
				}
			}
		}
	}
	if (ebentu == TECLA_DOWN || ebentu == TECLA_s) {
		if (puzzle6 == 1) {
			if (scorepuzzle >= 70 || konprobaketaPuzzle6 == 1) {
				scorepuzzle = scorepuzzle - 5;
				konprobaketaPuzzle6 = 1;
			}
			if (konprobaketaPuzzle6 == 0) {
				scorepuzzle = scorepuzzle + 5;
			}
			while (mugimenduabehean == 1) {
				jokalaria.pos.y = jokalaria.pos.y + 5;
				irudiaKendu(jokalaria.id);
				jokalaria.id = JOKOA_jokalariaAurreraIrudiaSortu();
				filak = jokalaria.pos.y / 10;
				zutabeak = jokalaria.pos.x / 10;
				if (mapPuzzle6[filak][zutabeak] == 3) {
					mugimenduabehean = 0;
				}
				if (mapPuzzle6[filak][zutabeak] == 6) {
					mugimenduabehean = 0;
					mugimenduaezkerra = 0;
				}
				if (mapPuzzle6[filak][zutabeak] == 8) {
					mugimenduaeskuina = 0;
					mugimenduabehean = 0;
				}
				if (mapPuzzle6[filak][zutabeak] == 11) {
					up = 0;
					mugimenduabehean = 0;
				}
			}
		}
		else {
			if (mugimenduabehean == 1) {
				jokalaria.pos.y = jokalaria.pos.y + 5;
				irudiaKendu(jokalaria.id);
				if (kulto == 1) {
					jokalaria.id = JOKOA_jokalariaKAtzeraIrudiaSortu();
				}
				else {
					jokalaria.id = JOKOA_jokalariaAurreraIrudiaSortu();
				}
			}
		}
	}
	return irten;
}