#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define JOKOA_HASI_IMAGE ".\\img\\MenuHasi.bmp"
#define JOKOA_KONTROLAK_IMAGE ".\\img\\kontrolakMenu.bmp"
#define JOKOA_IRTEN_IMAGE ".\\img\\MenuIrten.bmp"
#define JOKOA_IRTEN_IMAGE ".\\img\\MenuIrten.bmp"
#define JOKOA_PUNTUAKETA_IMAGE ".\\img\\Puntuaketa.bmp"
#define JOKOA_KONTROLAK2_IMAGE ".\\img\\Kontrolakdefinitibobmp.bmp"
#define JOKOA_SOUND_BULEGOA ".\\sound\\musikaBulegoa.wav"
#define FILAS 48
#define COLUMNAS 64
JOKO_ELEMENTUA jokalaria;

//Joko hasierako elkarrizketa
int lehenElkarrizketa() {
	JOKO_ELEMENTUA mapaglobal;
	audioInit();
	loadTheMusic(JOKOA_SOUND_BULEGOA);
	playMusic();
	mapaglobal.id = JOKOA_puntuaketaIrudiaSortu();
	Sleep(6000);
	mapaglobal.id = JOKOA_AitaIrudiaSortu();
	Sleep(6000);
	mapaglobal.id = JOKOA_Aita1IrudiaSortu();
	Sleep(6000);
	mapaglobal.id = JOKOA_Aita2IrudiaSortu();
	Sleep(6000);
	mapaglobal.id = JOKOA_bulegoaIrudiaSortu();
	jokalaria.pos.x = 500;
	jokalaria.pos.y = 400;
	jokalaria.id = JOKOA_jokalariaAurreraIrudiaSortu();
	kopiatuMapaBulegoa();
	return 1;
}

//Hasierako menuan "Hasi" aukeratzeko argazkia pantailaratu
int JOKOA_menuIrudiaSortu() {
	int hasiId = -1;
	hasiId = irudiaKargatu(JOKOA_HASI_IMAGE);
	irudiaMugitu(hasiId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return hasiId;
}

//Hasierako menuan "Irten" aukeratzeko argazkia pantailaratu
int JOKOA_menuIrtenIrudiaSortu()
{
	int irtenId = -1;
	irtenId = irudiaKargatu(JOKOA_IRTEN_IMAGE);
	irudiaMugitu(irtenId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return irtenId;
}

//Kontrolen azalpeneko argazkia pantailaratu
int JOKOA_kontrolakAzalpenaIrudiaSortu()
{
	int kontrolakId = -1;
	kontrolakId = irudiaKargatu(JOKOA_KONTROLAK2_IMAGE);
	irudiaMugitu(kontrolakId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kontrolakId;
}

//Hasierako menuan "Kontrolak" aukeratzeko argazkia pantailaratu
int JOKOA_kontrolakIrudiaSortu() {
	int kontrolakId = -1;
	kontrolakId = irudiaKargatu(JOKOA_KONTROLAK_IMAGE);
	irudiaMugitu(kontrolakId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kontrolakId;
}

//Elkartearen dokumentuak hartzeko adierazten duen argazkia pantailaratu
int JOKOA_puntuaketaIrudiaSortu() {
	int puntuaketaId = -1;
	puntuaketaId = irudiaKargatu(JOKOA_PUNTUAKETA_IMAGE);
	irudiaMugitu(puntuaketaId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return puntuaketaId;
}

//Hasierako menuaren funtzionamendua
int mainMenu() {
	int jokoahasi = 0, hasi = 0, menu = 1, ebentu = 0, irten = 0;
	JOKO_ELEMENTUA mapaglobal;
	do {
		if (jokoahasi == 0) {
			if (hasi == 0) {
				mapaglobal.id = JOKOA_menuIrudiaSortu();
				hasi = 1;
			}
			if (menu == 1){
				irudiaKendu(mapaglobal.id);
				mapaglobal.id = JOKOA_menuIrudiaSortu();
			}
			else if (menu == 2){
				irudiaKendu(mapaglobal.id);
				mapaglobal.id = JOKOA_kontrolakIrudiaSortu();
			}
			else if (menu == 3){
				irudiaKendu(mapaglobal.id);
				mapaglobal.id = JOKOA_menuIrtenIrudiaSortu();
			}
			ebentu = ebentuaJasoGertatuBada();
			if ((ebentu == TECLA_DOWN || ebentu == TECLA_s) && (menu < 3)){
				menu++;
			}
			if ((ebentu == TECLA_w || ebentu == TECLA_UP) && (menu > 1)) { menu--; }
			if (menu == 2 && ebentu == TECLA_RETURN){
				while (ebentu != TECLA_e && menu == 2)
				{
					irudiaKendu(mapaglobal.id);
					mapaglobal.id = JOKOA_kontrolakAzalpenaIrudiaSortu();
					ebentu = ebentuaJasoGertatuBada();
				}
			}
			if (menu == 3 && ebentu == TECLA_RETURN ){
				sgItxi();
			}
			if (menu == 1 && ebentu == TECLA_RETURN) {
				irten = 1;
			}
		}
	} while (irten == 0);
	return irten;
}


