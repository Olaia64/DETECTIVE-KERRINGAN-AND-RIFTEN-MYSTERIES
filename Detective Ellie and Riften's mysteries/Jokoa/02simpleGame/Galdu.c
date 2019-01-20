#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define JOKOA_GALDU_IMAGE ".\\img\\GALDU.bmp"
#define JOKOA_GALDU2_IMAGE ".\\img\\GALDU2.bmp"

//"Saiatu berriro" aukeratzeko argazkia pantailaratu
int JOKOA_galduIrudiaSortu()
{
	int galdu1Id = -1;
	galdu1Id = irudiaKargatu(JOKOA_GALDU_IMAGE);
	irudiaMugitu(galdu1Id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return galdu1Id;
}

//"Bueltatu menura" aukeratzeko argazkia pantailaratu
int JOKOA_galdu1IrudiaSortu()
{
	int galdu2Id = -1;
	galdu2Id = irudiaKargatu(JOKOA_GALDU2_IMAGE);
	irudiaMugitu(galdu2Id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return galdu2Id;
}