#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define JARRAITU ".\\img\\menuPausaJarraitu.bmp"
#define IRTEN2 ".\\img\\menuPausaIrten.bmp"

//Pausa menuan "Irten" aukeratzeko argazkia pantailaratu
int menuIrten2() {
	int irtenId = -1;
	irtenId = irudiaKargatu(IRTEN2);
	irudiaMugitu(irtenId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return irtenId;
}

//Pausa menuan "Jarraitu" aukeratzeko argazkia pantailaratu
int menuJarraitu() {
	int jarraituId = -1;
	jarraituId = irudiaKargatu(JARRAITU);
	irudiaMugitu(jarraituId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return jarraituId;
}

//Pausa menuaren funtzionamendua
int pausaMenua() {
	JOKO_ELEMENTUA mapaglobal;
	int mugimenduElliePausa = 1, ebentu = 0, pausa = 0, irten = 0;
	do {
		if (mugimenduElliePausa == 1) {
			mapaglobal.id = menuJarraitu();
			mugimenduElliePausa = 0;
		}
		if (mugimenduElliePausa == 0) {
			if (ebentu == TECLA_UP) {
				irudiaKendu(mapaglobal.id);
				mapaglobal.id = menuJarraitu();
				pausa = 0;
			}
			if (ebentu == TECLA_DOWN) {
				irudiaKendu(mapaglobal.id);
				mapaglobal.id = menuIrten2();
				pausa = 1;
			}
		}
		if (pausa == 0 && ebentu == TECLA_RETURN) {
			irudiaKendu(mapaglobal.id);
			mugimenduElliePausa = 1;
			irten = 1;
		}
		if (pausa == 1 && ebentu == TECLA_RETURN) {
			sgItxi();
			irten = 3;
		}
		ebentu = ebentuaJasoGertatuBada();
	} while (irten == 0);
	return irten;
}