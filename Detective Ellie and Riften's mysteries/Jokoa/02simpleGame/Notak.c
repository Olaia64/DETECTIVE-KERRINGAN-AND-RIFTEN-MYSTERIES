#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define JOKOA_NOTA_IMAGE ".\\img\\NOTA.bmp"

//Kultoko dokumentuak aurkitzerakoan adierazten duen textua pantailaratu
int JOKOA_notaIrudiaSortu() {
	int notaId = -1;
	notaId = irudiaKargatu(JOKOA_NOTA_IMAGE);
	irudiaMugitu(notaId, 0, 330);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return notaId;
}

//Textua irakurtzeko denbora zehaztu
void notaImg() {
	JOKO_ELEMENTUA nota;
	nota.id = JOKOA_notaIrudiaSortu();
	Sleep(4000);
	irudiaKendu(nota.id);
}
