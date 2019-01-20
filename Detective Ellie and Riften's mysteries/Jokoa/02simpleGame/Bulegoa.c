#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define JOKOA_BULEGOA_IMAGE ".\\img\\bulegoa.bmp"
#define JOKOA_BULEGOABALANTZA_IMAGE ".\\img\\bulegoa_balantza.bmp"
#define JOKOA_BULEGOALIBURUTEGIA_IMAGE ".\\img\\bulegoa_liburutegia.bmp"
#define JOKOA_BULEGOAELKARRIZKETA_IMAGE ".\\img\\ELKARRIZKETA.bmp"
#define JOKOA_BULEGOAELKARRIZKETA1_IMAGE ".\\img\\ELKARRIZKETA1.bmp"
#define JOKOA_BULEGOAELKARRIZKETA2_IMAGE ".\\img\\ELKARRIZKETA2.bmp"
#define JOKOA_ATEA_IMAGE ".\\img\\ATEA.bmp"
#define FILAK 48
#define ZUTABEAK 64
int mapa[FILAK][ZUTABEAK];
JOKO_ELEMENTUA jokalaria;

//Bulegoaren argazkia pantailaratu
int JOKOA_bulegoaIrudiaSortu()
{
	int bulegoId = -1;
	bulegoId = irudiaKargatu(JOKOA_BULEGOA_IMAGE);
	irudiaMugitu(bulegoId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return bulegoId;
}

//Balantzaren textua pantailaratu
int JOKOA_bulegoatxt1IrudiaSortu()
{
	int bulegobalantzaId = -1;
	bulegobalantzaId = irudiaKargatu(JOKOA_BULEGOABALANTZA_IMAGE);
	irudiaMugitu(bulegobalantzaId, 0, 380);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return bulegobalantzaId;
}

//Liburutegiko textua pantailaratu
int JOKOA_bulegoatxt2IrudiaSortu()
{
	int bulegoliburutegiaId = -1;
	bulegoliburutegiaId = irudiaKargatu(JOKOA_BULEGOALIBURUTEGIA_IMAGE);
	irudiaMugitu(bulegoliburutegiaId, 0, 380);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return bulegoliburutegiaId;
}

//Ofizialarekin elkarrizketakoren lehen textua pantailaratu
int JOKOA_bulegoatxt3IrudiaSortu()
{
	int bulegoelkarrizketaId = -1;
	bulegoelkarrizketaId = irudiaKargatu(JOKOA_BULEGOAELKARRIZKETA_IMAGE);
	irudiaMugitu(bulegoelkarrizketaId, 0, 180);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return bulegoelkarrizketaId;
}

//Ofizialarekin elkarrizketakoren bigarren textua pantailaratu
int JOKOA_bulegoatxt4IrudiaSortu()
{
	int bulegoelkarrizketa1Id = -1;
	bulegoelkarrizketa1Id = irudiaKargatu(JOKOA_BULEGOAELKARRIZKETA1_IMAGE);
	irudiaMugitu(bulegoelkarrizketa1Id, 0, 180);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return bulegoelkarrizketa1Id;
}

//Ofizialarekin elkarrizketaren hirugarren textua pantailaratu
int JOKOA_bulegoatxt5IrudiaSortu()
{
	int bulegoelkarrizketa2Id = -1;
	bulegoelkarrizketa2Id = irudiaKargatu(JOKOA_BULEGOAELKARRIZKETA2_IMAGE);
	irudiaMugitu(bulegoelkarrizketa2Id, 0, 180);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return bulegoelkarrizketa2Id;
}

//Ofizialarekin hitz egin baino lehenago irten nahi baduzu agertzen den oharra
int JOKOA_bulegoatxt6IrudiaSortu()
{
	int ateaId = -1;
	ateaId = irudiaKargatu(JOKOA_ATEA_IMAGE);
	irudiaMugitu(ateaId, 0, 380);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return ateaId;
}

//Bulegoaren Matrizea
int mapBulegoa[FILAK][ZUTABEAK] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 2, 2, 2, 2, 2, 2,2, 2,2,2, 2,2, 2, 2, 2, 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,2, 2, 2, 2, 2, 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41, 41, 41,41,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,2,7,7,2,2,1,2,2,2,2,2,2,2,2,2,7,2,2,2,2,2,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41, 41, 41, 41, 41,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,5,7,2,2,2,5,2,2,2,2,2,2,2,2,4,7,2,2,4,0,0,0},
	{1, 0, 0, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 41, 41, 41, 41, 41,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,1,4,2,2,2,0,0,0,0,0,0,0,0,0,4,40,40,7,4,0,0,0},
	{1, 0, 0, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 41, 41, 41, 41, 41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1,0,26,26,0,0,0,0,0,0,0,0,0,0,0,0,0,7,4,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 41, 41,41, 41, 41,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 41, 41, 41, 41, 41,41,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,4,2,2,1,0,0,0,0,0,0,0,8,3,3,3,3,3,6,0,0,4,4,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 24, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,4,3,1,1,1,3,1,0,0,4,4,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 24, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,3,1,0,0,0,0,0,0,0,4,2,2,2,1,2,1,0,0,4,4,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 24, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,1,0,0,0,0,0,0,7,2,2,2,2,2,5,0,0,0,4,4,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,1,0,0,0,0,0,0,0,25,25,25,25,25,0,0,0,4,4,4,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0},
	{1, 0, 0, 1, 3, 3, 3, 3, 3,3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,3,3,3,3,3,8,3,4,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,1,1,0,0,0,4,4,0,0,0,4,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,1,1,0,0,0,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,1,23,23,23,23,23,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 3, 3, 3, 3, 3,3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,3,3,3,3,3,3,3,3,3,1,1,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

//Bulegoko matrizea "Mapa" matrizera kopiatu
void kopiatuMapaBulegoa()
{
	for (int i = 0; i < FILAK; i++) {
		for (int j = 0; j < ZUTABEAK; j++)
			mapa[i][j] = mapBulegoa[i][j];
	}
}

//Bulegoko eta pertsonaiaren argazkiak
void bulegokoIrudiaSortu() {
	JOKO_ELEMENTUA mapaglobal;
	mapaglobal.id = JOKOA_bulegoaIrudiaSortu();
	kopiatuMapaBulegoa();
	jokalaria.pos.x = 300;
	jokalaria.pos.y = 420;
	jokalaria.id = JOKOA_jokalariaAtzeraIrudiaSortu();
}

//Ofizialarekin elkarrizketa osoa
void bulegoTextSortu() {
	JOKO_ELEMENTUA mapaglobal;
	mapaglobal.id = JOKOA_bulegoatxt3IrudiaSortu();
	irudiaKendu(mapaglobal.id);
	Sleep(6000);
	mapaglobal.id = JOKOA_bulegoatxt4IrudiaSortu();
	irudiaKendu(mapaglobal.id);
	Sleep(3500);
	mapaglobal.id = JOKOA_bulegoatxt5IrudiaSortu();
	Sleep(6000);
	jokalaria.pos.x = jokalaria.pos.x + 32;
	irudiaKendu(mapaglobal.id);
}

//Liburutegiko textua
void bulegoLiburutegia() {
	JOKO_ELEMENTUA bulegoaliburutegia;
	bulegoaliburutegia.id = JOKOA_bulegoatxt2IrudiaSortu();
	Sleep(4000);
	irudiaKendu(bulegoaliburutegia.id);
}

//Ofizialarekin hitz egin baino lehenago bulegotik irten nahi bada
void elkarrizketaEzDagoEginda() {
	JOKO_ELEMENTUA mapaglobal;
	mapaglobal.id = JOKOA_bulegoatxt6IrudiaSortu();
	Sleep(1000);
	irudiaKendu(mapaglobal.id);
	jokalaria.pos.y = jokalaria.pos.y - 10;
}

//Ofizialarenkin hitz egin ostean bulegotik irten nahi bada
void elkarrizketaEgindaDago() {
	JOKO_ELEMENTUA mapaglobal;
	mapaglobal.id = JOKOA_MapaIrudiaSortu();
	kopiatuMapaNagusia2();
	jokalaria.pos.x = 60;
	jokalaria.pos.y = 420;
	jokalaria.id = JOKOA_jokalariaAurreraIrudiaSortu();
}