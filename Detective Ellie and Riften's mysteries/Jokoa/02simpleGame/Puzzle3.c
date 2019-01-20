#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define PUZZLE_3 ".\\img\\Puzzle4.bmp"
#define KUADRO ".\\img\\cuadrito.bmp"

//Kultoko puzzlearen argazkia pantailaratu
int PUZZLE_irudiaBistaratu() {
	int id = -1;
	id = irudiaKargatu(PUZZLE_3);
	irudiaMugitu(id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return id;
}

//Hautze markoa ezkerraldean pantalaratu
int seleccion1() {
	int cuadroid = -1;
	cuadroid = irudiaKargatu(KUADRO);
	irudiaMugitu(cuadroid, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return cuadroid;
}

//Hautze markoa eskumaldean pantalaratu
int seleccion2() {
	int cuadroid = -1;
	cuadroid = irudiaKargatu(KUADRO);
	irudiaMugitu(cuadroid, 400, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return cuadroid;
}
