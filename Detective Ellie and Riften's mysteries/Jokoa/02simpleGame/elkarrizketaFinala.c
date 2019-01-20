#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define ELKARRIZKETAMALTZURRA1 ".\\img\\maltzurraElkar1.bmp"
#define ELKARRIZKETAMALTZURRA2 ".\\img\\maltzurraElkar2.bmp"
#define ELKARRIZKETAMALTZURRA3 ".\\img\\maltzurraElkar3.bmp"
#define ELKARRIZKETAMALTZURRA4 ".\\img\\maltzurraElkar4.bmp"
#define ELKARRIZKETAMALTZURRA5 ".\\img\\maltzurraElkar5.bmp"
#define ZUZENA ".\\img\\zuzena.bmp"

//"Zuzena" argazkia pantailaratu
int irabaztean() {
	int zuzenaId = -1;
	zuzenaId = irudiaKargatu(ZUZENA);
	irudiaMugitu(zuzenaId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return zuzenaId;
}

//Maltzurrarekin elkarrizketako lehen textua pantailaratu
int elkarrizketaMaltzurra1() {
	int maltzurrarekinId = -1;
	maltzurrarekinId = irudiaKargatu(ELKARRIZKETAMALTZURRA1);
	irudiaMugitu(maltzurrarekinId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return maltzurrarekinId;
}

//Maltzurrarekin elkarrizketako bigarren textua pantailaratu
int elkarrizketaMaltzurra2() {
	int maltzurrarekinId = -1;
	maltzurrarekinId = irudiaKargatu(ELKARRIZKETAMALTZURRA2);
	irudiaMugitu(maltzurrarekinId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return maltzurrarekinId;
}

//Maltzurrarekin elkarrizketako hirugarren textua pantailaratu
int elkarrizketaMaltzurra3() {
	int maltzurrarekinId = -1;
	maltzurrarekinId = irudiaKargatu(ELKARRIZKETAMALTZURRA3);
	irudiaMugitu(maltzurrarekinId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return maltzurrarekinId;
}

//Maltzurrarekin elkarrizketako laugarren textua pantailaratu
int elkarrizketaMaltzurra4() {
	int maltzurrarekinId = -1;
	maltzurrarekinId = irudiaKargatu(ELKARRIZKETAMALTZURRA4);
	irudiaMugitu(maltzurrarekinId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return maltzurrarekinId;
}

//Maltzurrarekin elkarrizketako bostgarren textua pantailaratu
int elkarrizketaMaltzurra5() {
	int maltzurrarekinId = -1;
	maltzurrarekinId = irudiaKargatu(ELKARRIZKETAMALTZURRA5);
	irudiaMugitu(maltzurrarekinId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return maltzurrarekinId;
}

//Maltzurrarekin elkarrizketa osoa pantailaratu
int elkarrizketaMaltzurrarekin(int id) {
	id = elkarrizketaMaltzurra1();
	Sleep(6000);
	id = elkarrizketaMaltzurra2();
	Sleep(6000);
	id = elkarrizketaMaltzurra3();
	Sleep(6000);
	id = elkarrizketaMaltzurra4();
	Sleep(6000);
	id = elkarrizketaMaltzurra5();
	Sleep(6000);
	return id;
}