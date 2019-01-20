#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define JOKOA_AITA1_IMAGE ".\\img\\AITA1.bmp"
#define JOKOA_AITA2_IMAGE ".\\img\\AITA2.bmp"
#define JOKOA_AITA3_IMAGE ".\\img\\Negarra.bmp"

//Aitarekin elkarrizketaren lehen textua pantailaratu
int JOKOA_AitaIrudiaSortu()
{
	int aitaId = -1;
	aitaId = irudiaKargatu(JOKOA_AITA1_IMAGE);
	irudiaMugitu(aitaId, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return aitaId;
}

//Aitarekin elkarrizketaren bigarren textua pantailaratu
int JOKOA_Aita1IrudiaSortu()
{
	int aita1Id = -1;
	aita1Id = irudiaKargatu(JOKOA_AITA2_IMAGE);
	irudiaMugitu(aita1Id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return aita1Id;
}

//Aitarekin elkarrizketaren hirugarren textua pantailaratu
int JOKOA_Aita2IrudiaSortu()
{
	int aita2Id = -1;
	aita2Id = irudiaKargatu(JOKOA_AITA3_IMAGE);
	irudiaMugitu(aita2Id, 0, 0);
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return aita2Id;
}