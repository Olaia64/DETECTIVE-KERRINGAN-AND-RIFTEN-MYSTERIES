#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define JOKOA_HILKETA_IMAGE ".\\img\\HILKETA.bmp"
#define JOKOA_HILKETAELKARRIZKETA_IMAGE ".\\img\\Hilketatxt.bmp"
#define JOKOA_HILKETAELKARRIZKETA1_IMAGE ".\\img\\Hilketatxt1.bmp"
#define JOKOA_HILKETAELKARRIZKETA2_IMAGE ".\\img\\Hilketatxt2.bmp"
#define JOKOA_HILKETAELKARRIZKETA3_IMAGE ".\\img\\Hilketatxt3.bmp"
#define JOKOA_SOUND_KRIMENA ".\\sound\\musikaKrimenarenEtxean.wav"
#define FILAK 48
#define ZUTABEAK 64
int mapa[FILAK][ZUTABEAK];
#define JOKOA_PANPINA_IMAGE ".\\img\\PANPINA.bmp"
JOKO_ELEMENTUA jokalaria;

//Hilektaren maparen argazkia pantailaratu
int JOKOA_hilketaIrudiaSortu()
{
	int hilketaId = -1;
	hilketaId = irudiaKargatu(JOKOA_HILKETA_IMAGE);
	irudiaMugitu(hilketaId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return hilketaId;
}

//Alargunaren elkarrizketaren lehen textua pantailaratu
int JOKOA_hilketatxtIrudiaSortu()
{
	int hilketaelkarrizketaId = -1;
	hilketaelkarrizketaId = irudiaKargatu(JOKOA_HILKETAELKARRIZKETA_IMAGE);
	irudiaMugitu(hilketaelkarrizketaId, 0, 180);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return hilketaelkarrizketaId;
}

//Alargunaren elkarrizketaren bigarren textua pantailaratu
int JOKOA_hilketatxt1IrudiaSortu()
{
	int hilketaelkarrizketa1Id = -1;
	hilketaelkarrizketa1Id = irudiaKargatu(JOKOA_HILKETAELKARRIZKETA1_IMAGE);
	irudiaMugitu(hilketaelkarrizketa1Id, 0, 180);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return hilketaelkarrizketa1Id;
}

//Alargunaren elkarrizketaren hirugarren textua pantailaratu
int JOKOA_hilketatxt2IrudiaSortu()
{
	int hilketaelkarrizketa2Id = -1;
	hilketaelkarrizketa2Id = irudiaKargatu(JOKOA_HILKETAELKARRIZKETA2_IMAGE);
	irudiaMugitu(hilketaelkarrizketa2Id, 0, 180);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return hilketaelkarrizketa2Id;
}

//Alargunaren elkarrizketaren laugarren textua pantailaratu
int JOKOA_hilketatxt3IrudiaSortu()
{
	int hilketaelkarrizketa3Id = -1;
	hilketaelkarrizketa3Id = irudiaKargatu(JOKOA_HILKETAELKARRIZKETA3_IMAGE);
	irudiaMugitu(hilketaelkarrizketa3Id, 0, 180);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return hilketaelkarrizketa3Id;
}

//Puzzlea ondo egiterakoan agertzen den textua pantailaratu
int JOKOApanpinaIrudiaSortu()
{
	int panpinaId = -1;
	panpinaId = irudiaKargatu(JOKOA_PANPINA_IMAGE);
	irudiaMugitu(panpinaId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return panpinaId;
}

//Hilketaren maparen matrizea
int mapHilketa[FILAK][ZUTABEAK] = {
	{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,5,2,2,7,2,2,2,2,5,2,2,2,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,2,2,2,2,2,7,2,2,2,2,5,2,2,2,2,2,2,2,7,2,2,2},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
	{2,2,2,2,2,5,2,2,7,2,2,2,2,5,2,2,2,7,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,5,2,2,2,2,2,7,2,2,2,2,5,2,2,2,2,2,2,2,7,2,2,2},
	{5,2,2,5,7,2,2,2,2,5,2,2,2,2,2,2,2,7,2,2,2,2,2,2,2,2,5,2,2,2,2,2,2,2,7,2,2,5,5,7,2,2,2,5,2,2,7,2,2,2,2,2,5,7,2,2,5,2,7,7,2,2,2,2},
	{1,0,0,1,2,2,2,2,2,2,0,0,0,0,0,43,43,43,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,4,0,0,1,1,0,2,2,2,0,0,0,4,4,0,1,2,2,1,4,2,0,1,0,4,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,43,43,43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,5,1,0,0,0,0,0,0,0,4,4,0,1,1,0,0,2,2,2,2,0,4,7,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,43,43,43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,4,4,0,1,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,43,43,43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,4,4,0,1,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,4,2,2,2,1,0,0,3,3,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,8,3,3,3,3,3,1,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,1,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,4,3,3,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,5,1,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,4,4,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,2,2,1,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,6,3,3,3,3,3,3,3,3,3,3,8,3,8,3,3,3,3,3,3,6,3,0,3,3,3,3,3,3,3,3,8,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,4,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,3,3,3,3,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,4,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,4,0,0,0,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,4,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,4,3,3,3,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,4,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,4,3,3,0,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,4,0,0,0,0,0,0,0,4,0,0,1,0,0,0,0,0,0,0,0,4,0,0,0,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,5,7,2,2,2,2,5,2,2,2,2,7,7,2,2,5,2,2,2,2,2,2,0,7,2,2,5,2,2,2,2,7,0,0,6,0,0,0,0,0,0,0,0,4,0,0,0,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,7,2,0,1,0,0,0,0,0,4,4,0,0,1,0,0,0,0,0,0,0,0,4,1,1,0,0,0,0,4,0,0,1,1,0,0,0,0,0,0,0,4,2,2,2,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,2,2,0,0,0,0,0,0,4,4,0,0,1,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,4,0,0,1,1,0,0,0,0,0,0,0,4,0,0,0,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,7,4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1,1,0,0,0,0,0,0,0,4,2,2,2,1,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,4,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,2,2,5,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,6,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,3,1,1,1,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,13,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,3,3,3,6,3,3,3,3,3,3,3,8,8,8,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,3,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,0,4,0,4},
	{1,0,0,1,2,7,2,2,2,2,2,5,7,2,2,2,5,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,7,5,5,8,6,5,5,7,2,2,2,2,5,2,2,2,2,2,2,2,2,2,2,2,7,0,4,0,4},
	{1,0,0,1,0,4,2,2,2,2,2,1,4,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,1,1,2,7,8,0,4,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,2,44,44,44,2,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,16,16,16,16,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,44,44,44,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{6,3,3,6,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,8,3,3,3,3},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,0,0,0,0,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,4,0,4},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,15,15,15,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
	{3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3},
};

//Hilketaren matrizea "Mapa" matrizera kopiatu
void kopiatuMapaHilketa()
{
	for (int i = 0; i < FILAK; i++) {
		for (int j = 0; j < ZUTABEAK; j++)
			mapa[i][j] = mapHilketa[i][j];
	}
}

//Hilketa etxetik atera mapa nagusira ateratzea
void hilketatikMaparaAtera() {
	JOKO_ELEMENTUA mapaglobal;
	mapaglobal.id = JOKOA_MapaIrudiaSortu();
	kopiatuMapaNagusia2();
	jokalaria.pos.x = 555;
	jokalaria.pos.y = 420;
	jokalaria.id = JOKOA_jokalariaAurreraIrudiaSortu();
}

//Alargunaren elkarrizketa osoa pantailaratu
void hilketaTextua() {
	JOKO_ELEMENTUA mapaglobal;
	mapaglobal.id = JOKOA_hilketatxtIrudiaSortu();
	Sleep(6000);
	irudiaKendu(mapaglobal.id);
	mapaglobal.id = JOKOA_hilketatxt1IrudiaSortu();
	irudiaKendu(mapaglobal.id);
	Sleep(6000);
	mapaglobal.id = JOKOA_hilketatxt3IrudiaSortu();
	Sleep(6000);
	irudiaKendu(mapaglobal.id);
	mapaglobal.id = JOKOA_hilketatxt2IrudiaSortu();
	Sleep(6000);
	irudiaKendu(mapaglobal.id);
	audioInit();
	loadTheMusic(JOKOA_SOUND_KRIMENA);
	playMusic();
	mapaglobal.id = JOKOA_hilketaIrudiaSortu();
	jokalaria.pos.y = jokalaria.pos.y + 10;
	jokalaria.pos.x = jokalaria.pos.x - 10;
}
void hilketaIrudiaSortu() {
	JOKO_ELEMENTUA mapaglobal;
	audioInit();
	loadTheMusic(JOKOA_SOUND_KRIMENA);
	playMusic();
	mapaglobal.id = JOKOA_hilketaIrudiaSortu();
	kopiatuMapaHilketa();
	jokalaria.pos.x = 310;
	jokalaria.pos.y = 430;
	jokalaria.id = JOKOA_jokalariaAtzeraIrudiaSortu();
}