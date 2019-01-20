#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define IRTEN ".\\img\\amaieraIrten.bmp"
#define BUELTATU_MENURA ".\\img\\amaieraBueltatu.bmp"

//"Irten" aukeratzeko argazkia pantailaratu
int menuIrten() {
	int irtenId = -1;
	irtenId = irudiaKargatu(IRTEN);
	irudiaMugitu(irtenId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return irtenId;
}

//"Bueltatu Menura" aukeratzeko argazkia pantailaratu
int menuBueltatu() {
	int bueltatuId = -1;
	bueltatuId = irudiaKargatu(BUELTATU_MENURA);
	irudiaMugitu(bueltatuId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return bueltatuId;
}

//Amaierako menuaren aukeraketa
int amaieraMenua() {
	int menuFinal = 1, ebentu = 0, menu2 = 0, menu = 0;
	JOKO_ELEMENTUA mapaglobal;
	do {
		if (menuFinal == 1) {
			mapaglobal.id = menuBueltatu();
			menuFinal = 0;
		}
		if (menuFinal == 0) {
			if (ebentu == TECLA_UP) {
				irudiaKendu(mapaglobal.id);
				mapaglobal.id = menuBueltatu();
				menu2 = 0;
			}
			if (ebentu == TECLA_DOWN) {
				irudiaKendu(mapaglobal.id);
				mapaglobal.id = menuIrten();
				menu2 = 1;
			}
			if (ebentu == TECLA_e && menu2 == 0) {

				menu = 1;
			}
			if (menu2 == 1 && ebentu == TECLA_e) {
				sgItxi();
				menu = 3;
			}
			ebentu = ebentuaJasoGertatuBada();
		}
	} while (menu == 0);
	return menu;
}