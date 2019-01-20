#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define PUZZLE_6 ".\\img\\Puzzle6.bmp"
#define FILAK 48
#define ZUTABEAK 64
JOKO_ELEMENTUA jokalaria;

//Puzzle finalaren argazkia pantailaratu
int PUZZLE6_irudiaBistaratu() {
	int puzzle = -1;
	puzzle = irudiaKargatu(PUZZLE_6);
	irudiaMugitu(puzzle, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return puzzle;
}


//Puzzle finala eta jokalaria pantailaratu
void mapaFinala() {
	JOKO_ELEMENTUA mapaglobal;
	mapaglobal.id = PUZZLE6_irudiaBistaratu();
	jokalaria.pos.x = 220;
	jokalaria.pos.y = 340;
	jokalaria.id = JOKOA_jokalariaAurreraIrudiaSortu();
}