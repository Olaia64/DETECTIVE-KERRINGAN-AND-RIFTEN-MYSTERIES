#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
JOKO_ELEMENTUA jokalaria;

//Hilketako puzzlearen funtzionamendua
int lehenengoPuzzlea() {
	JOKO_ELEMENTUA  mapaglobal, marco1, marco2;
	int aukeraketaHilketa = 0, puzzleHilketa = 0, ebentu = 0, puzzleMaltzurra = 0, lortuPuzzlea = 0, puzzle2 = 0, saiatuBerriz = 0, irten = 0;
	do {
		if (puzzleMaltzurra == 0) {
			if (puzzleHilketa == 0) {
				mapaglobal.id = PUZZLE1_irudiaBistaratu();
				marco1.id = selec1();
				puzzleHilketa = 1;
			}
			ebentu = ebentuaJasoGertatuBada();
			if ((ebentu == TECLA_RIGHT || ebentu == TECLA_d) && aukeraketaHilketa == 0) {
				irudiaKendu(marco1.id);
				marco2.id = selec2();
				aukeraketaHilketa = 1;
			}
			if ((ebentu == TECLA_LEFT || ebentu == TECLA_a) && aukeraketaHilketa == 1) {
				irudiaKendu(marco2.id);
				marco1.id = selec1();
				aukeraketaHilketa = 0;
			}
		}
		if (ebentu == TECLA_RETURN && aukeraketaHilketa == 0) {
			puzzleMaltzurra = 1;
			mapaglobal.id = irabaztean();
			Sleep(1000);
			mapaglobal.id = JOKOApanpinaIrudiaSortu();
			Sleep(8000);
			kopiatuMapaNagusia();
			mapaglobal.id = JOKOA_MapaIrudiaSortu();
			jokalaria.pos.x = 555;
			jokalaria.pos.y = 410;
			jokalaria.id = JOKOA_jokalariaAurreraIrudiaSortu();
			irten = 1;
		}
		if ((ebentu == TECLA_RETURN && aukeraketaHilketa == 1) || lortuPuzzlea == 1) {
			puzzleMaltzurra = 1;
			lortuPuzzlea = 1;
			if (puzzle2 == 0) {
				mapaglobal.id = JOKOA_galduIrudiaSortu();
				saiatuBerriz = 0;
				puzzle2 = 1;
			}
			ebentu = ebentuaJasoGertatuBada();
			if (ebentu == TECLA_DOWN||ebentu==TECLA_s) {
				irudiaKendu(mapaglobal.id);
				mapaglobal.id = JOKOA_galdu1IrudiaSortu();
				saiatuBerriz = 1;
			}
			if (ebentu == TECLA_UP||ebentu==TECLA_w) {
				irudiaKendu(mapaglobal.id);
				mapaglobal.id = JOKOA_galduIrudiaSortu();
				saiatuBerriz = 0;
			}
			if (ebentu == TECLA_e && saiatuBerriz == 0) {
				mapaglobal.id = JOKOA_hilketaIrudiaSortu();
				jokalaria.pos.x = 300;
				jokalaria.pos.y = 400;
				jokalaria.id = JOKOA_jokalariaAtzeraIrudiaSortu();
				irten = 2;
			}
			if (ebentu == TECLA_e && saiatuBerriz == 1) {
				irten = 3;
			}
		}
	} while (irten == 0);
	return irten;
}
