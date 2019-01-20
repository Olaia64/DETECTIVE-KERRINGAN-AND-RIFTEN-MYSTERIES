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
#define JOKOA_KULTOA_IMAGE ".\\img\\KULTOATXT3.bmp"
#define JOKOA_KULTOATXT_IMAGE ".\\img\\KALEB.bmp"
#define JOKOA_KULTOATXT3_IMAGE ".\\img\\KULTOATXT4.bmp"
#define JOKOA_KULTOATXT4_IMAGE ".\\img\\KULTOATXT5.bmp"
#define JOKOA_KULTOATXT5_IMAGE ".\\img\\KULTOATXT6.bmp"
#define JOKOA_KULTOATXT6_IMAGE ".\\img\\KULTOATXT7.bmp"
JOKO_ELEMENTUA jokalaria;

//Kultoko argazkia pantailaratu
int JOKOA_kultoaIrudiaSortu()
{
	int kultoId = -1;
	kultoId = irudiaKargatu(JOKOA_KULTOA_IMAGE);
	irudiaMugitu(kultoId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kultoId;
}

//Maltzurraren bakarizketaren textua pantailaratu
int JOKOA_kultoatxtIrudiaSortu()
{
	int kultoId = -1;
	kultoId = irudiaKargatu(JOKOA_KULTOATXT_IMAGE);
	irudiaMugitu(kultoId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kultoId;
}

//Kultoko bazkide baten bakarrizketaren textua pantailaratu
int JOKOA_kultoatxt3IrudiaSortu()
{
	int kultoId = -1;
	kultoId = irudiaKargatu(JOKOA_KULTOATXT3_IMAGE);
	irudiaMugitu(kultoId, 0, 330);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kultoId;
}

//Kultoko bazkide baten bakarrizketaren textua pantailaratu
int JOKOA_kultoatxt4IrudiaSortu()
{
	int kultoId = -1;
	kultoId = irudiaKargatu(JOKOA_KULTOATXT4_IMAGE);
	irudiaMugitu(kultoId, 0, 330);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kultoId;
}

//Kultoko bazkide baten bakarrizketaren textua pantailaratu
int JOKOA_kultoatxt5IrudiaSortu()
{
	int kultoId = -1;
	kultoId = irudiaKargatu(JOKOA_KULTOATXT5_IMAGE);
	irudiaMugitu(kultoId, 0, 330);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kultoId;
}

//Kultoko bazkide baten bakarrizketaren textua pantailaratu
int JOKOA_kultoatxt6IrudiaSortu()
{
	int kultoId = -1;
	kultoId = irudiaKargatu(JOKOA_KULTOATXT6_IMAGE);
	irudiaMugitu(kultoId, 0, 330);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return kultoId;
}

//Kultoko matrizea
int mapKultoa[FILAK][ZUTABEAK] = {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,5,2,2,7,2,2,2,2,5,2,2,2,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,2,2,2,2,2,7,2,2,2,2,5,2,2,2,2,2,2,2,7,2,2,2},
	{1,1,2,1,1,5,0,0,7,4,4,1,1,5,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,5,0,0,0,0,0,7,0,0,0,0,5,0,0,0,0,0,0,0,4,4,0,4},
	{1,5,2,2,2,2,0,0,2,2,2,2,2,2,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,64,64,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,64,64,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,64,64,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,62,62,62,0,0,0,0,0,63,63,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,8,3,6,0,0,0,0,0,0,0,0,8,3,6,0,0,0,0,0,0,0,0,8,3,6,0,0,0,0,0,0,0,0,8,3,6,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,7,2,5,0,0,0,0,0,0,0,0,7,2,5,0,0,0,0,0,0,0,0,7,2,5,0,0,0,0,0,0,0,0,7,2,5,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,42,42,42,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,8,3,6,0,0,0,0,0,0,0,0,8,3,6,0,0,0,0,0,0,0,0,8,3,6,0,0,0,0,0,0,0,0,8,3,6,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,4,4,1,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,4,4,1,0,0,0,0,0,0,0,0,4,0,1,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,7,2,5,0,0,0,0,0,0,0,0,7,2,5,0,0,0,0,0,0,0,0,7,2,5,0,0,0,0,0,0,0,0,7,2,5,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,6,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8,3,3,3},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,61,61,61,61,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,4},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
};

//Kultoko matrizea "Mapa" matrizera kopiatu
void kopiatuMapaKultoa()
{
	for (int i = 0; i < FILAK; i++) {
		for (int j = 0; j < ZUTABEAK; j++)
			mapa[i][j] = mapKultoa[i][j];
	}
}

//Kultotik mapa nagusira atera
void kultotikMaparaAtera() {
	JOKO_ELEMENTUA mapaglobal;
	mapaglobal.id = JOKOA_Mapa1IrudiaSortu();
	kopiatuMapaNagusia1();
	jokalaria.pos.x = 80;
	jokalaria.pos.y = 130;
	jokalaria.id = JOKOA_jokalariaAurreraIrudiaSortu();
}

//Kultoko bazkide baten bakarrizketa
void kultotxt1() {
	JOKO_ELEMENTUA mapaglobal,txt;
	txt.id = JOKOA_kultoatxt3IrudiaSortu();
	Sleep(5000);
	mapaglobal.id = JOKOA_kultoaIrudiaSortu();
	jokalaria.pos.y = jokalaria.pos.y + 10;
	jokalaria.id = JOKOA_jokalariaKAurreraIrudiaSortu();
}

//Kultoko bazkide baten bakarrizketa
void kultotxt2() {
	JOKO_ELEMENTUA mapaglobal,txt;
	txt.id = JOKOA_kultoatxt4IrudiaSortu();
	Sleep(5000);
	mapaglobal.id = JOKOA_kultoaIrudiaSortu();
	jokalaria.pos.y = jokalaria.pos.y + 10;
	jokalaria.id = JOKOA_jokalariaKAurreraIrudiaSortu();
}

//Kultoko bazkide baten bakarrizketa
void kultotxt3() {
	JOKO_ELEMENTUA mapaglobal,txt;
	txt.id = JOKOA_kultoatxt5IrudiaSortu();
	Sleep(5000);
	mapaglobal.id = JOKOA_kultoaIrudiaSortu();
	jokalaria.pos.y = jokalaria.pos.y + 10;
	jokalaria.id = JOKOA_jokalariaKAurreraIrudiaSortu();
}

//Kultoko bazkide baten bakarrizketa
void kultotxt4() {
	JOKO_ELEMENTUA mapaglobal,txt;
	txt.id = JOKOA_kultoatxt6IrudiaSortu();
	Sleep(8000);
	mapaglobal.id = JOKOA_kultoaIrudiaSortu();
	jokalaria.pos.y = jokalaria.pos.y + 10;
	jokalaria.id = JOKOA_jokalariaKAurreraIrudiaSortu();
}

//Kultoko arropa jarri
void arropaJarri() {
	JOKO_ELEMENTUA mapaglobal, arropa;
	mapaglobal.id = JOKOA_ArropatxtIrudiaSortu();
	Sleep(4000);
	arropa.id = JOKOA_Mapa1IrudiaSortu();
	jokalaria.pos.y = jokalaria.pos.y + 10;
	jokalaria.id = JOKOA_jokalariaKAurreraIrudiaSortu();
}