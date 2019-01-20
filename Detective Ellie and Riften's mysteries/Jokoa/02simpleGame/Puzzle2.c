#include "game02.h"
#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>

#define PUZZLE_3 ".\\img\\Puzzle3.bmp"

//Errekako puzzlearen argazkia pantailaratu
int PUZZLE3_irudiaBistaratu() {
	int puzzle = -1;
	puzzle = irudiaKargatu(PUZZLE_3);
	irudiaMugitu(puzzle, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return puzzle;
}

#define PIEZA1L ".\\img\\pieza1L.bmp"
#define PIEZA1D ".\\img\\pieza1D.bmp"
#define PIEZA1R ".\\img\\pieza1R.bmp"
#define PIEZA1U ".\\img\\pieza1U.bmp"

//Lehenengo pieza pantailaratu

int pieza1L() {
	int pieza1L = -1;
	pieza1L = irudiaKargatu(PIEZA1L);
	irudiaMugitu(pieza1L, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza1L;
}
int pieza1D() {
	int pieza1D = -1;
	pieza1D = irudiaKargatu(PIEZA1D);
	irudiaMugitu(pieza1D, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza1D;
}
int pieza1R() {
	int pieza1R = -1;
	pieza1R = irudiaKargatu(PIEZA1R);
	irudiaMugitu(pieza1R, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza1R;
}
int pieza1U() {
	int pieza1U = -1;
	pieza1U = irudiaKargatu(PIEZA1U);
	irudiaMugitu(pieza1U, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza1U;
}

#define PIEZA2L ".\\img\\pieza2L.bmp"
#define PIEZA2D ".\\img\\pieza2D.bmp"
#define PIEZA2R ".\\img\\pieza2R.bmp"
#define PIEZA2U ".\\img\\pieza2U.bmp"

//Bigarren pieza pantailaratu

int pieza2L() {
	int pieza2L = -1;
	pieza2L = irudiaKargatu(PIEZA2L);
	irudiaMugitu(pieza2L, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza2L;
}
int pieza2D() {
	int pieza2D = -1;
	pieza2D = irudiaKargatu(PIEZA2D);
	irudiaMugitu(pieza2D, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza2D;
}
int pieza2R() {
	int pieza2R = -1;
	pieza2R = irudiaKargatu(PIEZA2R);
	irudiaMugitu(pieza2R, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza2R;
}

int pieza2U() {
	int pieza2U = -1;
	pieza2U = irudiaKargatu(PIEZA2U);
	irudiaMugitu(pieza2U, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza2U;
}

#define PIEZA5L ".\\img\\pieza5L.bmp"
#define PIEZA5D ".\\img\\pieza5D.bmp"
#define PIEZA5R ".\\img\\pieza5R.bmp"
#define PIEZA5U ".\\img\\pieza5U.bmp"

//Bostgarren pieza pantailaratu

int pieza5L() {
	int pieza5L = -1;
	pieza5L = irudiaKargatu(PIEZA5L);
	irudiaMugitu(pieza5L, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza5L;
}
int pieza5D() {
	int pieza5D = -1;
	pieza5D = irudiaKargatu(PIEZA5D);
	irudiaMugitu(pieza5D, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza5D;
}
int pieza5R() {
	int pieza3R = -1;
	pieza3R = irudiaKargatu(PIEZA5R);
	irudiaMugitu(pieza3R, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza3R;
}
int pieza5U() {
	int pieza5U = -1;
	pieza5U = irudiaKargatu(PIEZA5U);
	irudiaMugitu(pieza5U, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza5U;
}

#define PIEZA4L ".\\img\\pieza4L.bmp"
#define PIEZA4D ".\\img\\pieza4D.bmp"
#define PIEZA4R ".\\img\\pieza4R.bmp"
#define PIEZA4U ".\\img\\pieza4U.bmp"

//Laugarren pieza pantailaratu

int pieza4L() {
	int pieza4L = -1;
	pieza4L = irudiaKargatu(PIEZA4L);
	irudiaMugitu(pieza4L, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza4L;
}
int pieza4D() {
	int pieza4D = -1;
	pieza4D = irudiaKargatu(PIEZA4D);
	irudiaMugitu(pieza4D, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza4D;
}
int pieza4R() {
	int pieza4R = -1;
	pieza4R = irudiaKargatu(PIEZA4R);
	irudiaMugitu(pieza4R, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza4R;
}
int pieza4U() {
	int pieza4U = -1;
	pieza4U = irudiaKargatu(PIEZA4U);
	irudiaMugitu(pieza4U, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza4U;
}

#define PIEZA3 ".\\img\\pieza3.bmp"

//Hirugarren pieza pantailaratu

int pieza_3() {
	int pieza3 = -1;
	pieza3 = irudiaKargatu(PIEZA3);
	irudiaMugitu(pieza3, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza3;
}

#define PIEZA6D ".\\img\\pieza6D.bmp"
#define PIEZA6U ".\\img\\pieza6U.bmp"

//Seigarren pieza pantailaratu

int pieza6D() {
	int pieza6D = -1;
	pieza6D = irudiaKargatu(PIEZA6D);
	irudiaMugitu(pieza6D, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza6D;
}
int pieza6U() {
	int pieza6U = -1;
	pieza6U = irudiaKargatu(PIEZA6U);
	irudiaMugitu(pieza6U, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza6U;
}

#define PIEZA7D ".\\img\\pieza7D.bmp"
#define PIEZA7U ".\\img\\pieza7U.bmp"

//Zazpigarren pieza pantailaratu

int pieza7D() {
	int pieza7D = -1;
	pieza7D = irudiaKargatu(PIEZA7D);
	irudiaMugitu(pieza7D, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza7D;
}
int pieza7U() {
	int pieza7U = -1;
	pieza7U = irudiaKargatu(PIEZA7U);
	irudiaMugitu(pieza7U, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza7U;
}

#define PIEZA8L ".\\img\\pieza8L.bmp"
#define PIEZA8D ".\\img\\pieza8D.bmp"
#define PIEZA8R ".\\img\\pieza8R.bmp"
#define PIEZA8U ".\\img\\pieza8U.bmp"

//Zortzigarren pieza pantailaratu

int pieza8L() {
	int pieza8L = -1;
	pieza8L = irudiaKargatu(PIEZA8L);
	irudiaMugitu(pieza8L, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza8L;
}
int pieza8D() {
	int pieza8D = -1;
	pieza8D = irudiaKargatu(PIEZA8D);
	irudiaMugitu(pieza8D, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza8D;
}
int pieza8R() {
	int pieza8R = -1;
	pieza8R = irudiaKargatu(PIEZA8R);
	irudiaMugitu(pieza8R, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza8R;
}
int pieza8U() {
	int pieza8U = -1;
	pieza8U = irudiaKargatu(PIEZA8U);
	irudiaMugitu(pieza8U, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza8U;
}

#define PIEZA9L ".\\img\\pieza9L.bmp"
#define PIEZA9D ".\\img\\pieza9D.bmp"
#define PIEZA9R ".\\img\\pieza9R.bmp"
#define PIEZA9U ".\\img\\pieza9U.bmp"

//Bederatzigarren pieza pantailaratu

int pieza9L() {
	int pieza9L = -1;
	pieza9L = irudiaKargatu(PIEZA9L);
	irudiaMugitu(pieza9L, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza9L;
}
int pieza9D() {
	int pieza9D = -1;
	pieza9D = irudiaKargatu(PIEZA9D);
	irudiaMugitu(pieza9D, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza9D;
}
int pieza9R() {
	int pieza9R = -1;
	pieza9R = irudiaKargatu(PIEZA9R);
	irudiaMugitu(pieza9R, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza9R;
}
int pieza9U() {
	int pieza9U = -1;
	pieza9U = irudiaKargatu(PIEZA9U);
	irudiaMugitu(pieza9U, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return pieza9U;
}

#define AUKERA  ".\\img\\select.bmp"

//Hautatze markoa pantailaratu
int seleccion() {
	int aukeraId = -1;
	aukeraId = irudiaKargatu(AUKERA);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return aukeraId;

}