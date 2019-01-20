#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define PUZZLE_1 ".\\img\\Puzzle1.bmp"
#define MARCO ".\\img\\marco.bmp"

//Hilketaren puzzlearen argazkia pantailaratu
int PUZZLE1_irudiaBistaratu() {
	int puzzle = -1;
	puzzle = irudiaKargatu(PUZZLE_1);
	irudiaMugitu(puzzle, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return puzzle;
}

//Hautze markoa ezkerraldean pantalaratu
int selec1() {
	int marcoId = -1;
	marcoId = irudiaKargatu(MARCO);
	irudiaMugitu(marcoId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return marcoId;
}

//Hautze markoa eskumaldean pantalaratu
int selec2() {
	int marcoId = -1;
	marcoId = irudiaKargatu(MARCO);
	irudiaMugitu(marcoId, 310, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return marcoId;
}
