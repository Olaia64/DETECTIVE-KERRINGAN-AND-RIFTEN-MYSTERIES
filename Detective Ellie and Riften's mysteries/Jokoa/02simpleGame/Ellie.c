#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define JOKOA_PLAYERDOWN_IMAGE ".\\img\\ELLIED.bmp"
#define JOKOA_PLAYERDOWN1_IMAGE ".\\img\\ELLIED1.bmp"
#define JOKOA_PLAYERUP_IMAGE ".\\img\\ELLIEUP.bmp"
#define JOKOA_PLAYERUP1_IMAGE ".\\img\\ELLIEUP1.bmp"
#define JOKOA_PLAYERRIGHT1_IMAGE ".\\img\\ELLIER2.bmp"
#define JOKOA_PLAYERRIGHT2_IMAGE ".\\img\\ELLIER6.bmp"
#define JOKOA_PLAYERLEFT_IMAGE ".\\img\\ELLIEL.bmp"
#define JOKOA_PLAYERLEFT1_IMAGE ".\\img\\ELLIEL1.bmp"

#define JOKOA_ELLIEKDOWN_IMAGE ".\\img\\ELLIEKD.bmp"
#define JOKOA_ELLIEKDOWN1_IMAGE ".\\img\\ELLIEKD1.bmp"
#define JOKOA_ELLIEKUP_IMAGE ".\\img\\ELLIEKU.bmp"
#define JOKOA_ELLIEKUP1_IMAGE ".\\img\\ELLIEKU1.bmp"
#define JOKOA_ELLIEKRIGHT_IMAGE ".\\img\\ELLIEKR.bmp"
#define JOKOA_ELLIEKRIGHT1_IMAGE ".\\img\\ELLIEKR1.bmp"
#define JOKOA_ELLIEKLEFT_IMAGE ".\\img\\ELLIEKL.bmp"
#define JOKOA_ELLIEKLEFT1_IMAGE ".\\img\\ELLIEKL1.bmp"

//Ellieren argazkiak tartekatzeko aldagaiak
int i = 0, k = 0, j = 0, l = 0, m = 0, n = 0, o = 0, p = 0;

//Mapa nagusian beheruntza egiterakoan jarri behar diren Ellieren argazkiak
int JOKOA_jokalariaAurreraIrudiaSortu()
{
	int ellieId = -1;
	if (j % 2 == 0) {
		ellieId = irudiaKargatu(JOKOA_PLAYERDOWN_IMAGE);
	}
	else {
		ellieId = irudiaKargatu(JOKOA_PLAYERDOWN1_IMAGE);
	}
	j++;
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return ellieId;
}

//Mapa nagusian goruntza egiterakoan jarri behar diren Ellieren argazkiak
int JOKOA_jokalariaAtzeraIrudiaSortu()
{
	int ellieId = -1;
	if (l % 2 == 0) {
		ellieId = irudiaKargatu(JOKOA_PLAYERUP_IMAGE);
	}
	else {
		ellieId = irudiaKargatu(JOKOA_PLAYERUP1_IMAGE);
	}
	l++;
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return ellieId;
}

//Mapa nagusian eskumara egiterakoan jarri behar diren Ellieren argazkiak
int JOKOA_jokalariaEskuineraIrudiaSortu()
{
	int ellieId = -1;
	if (i % 2 == 0) {
		ellieId = irudiaKargatu(JOKOA_PLAYERRIGHT1_IMAGE);
	}
	else {
		ellieId = irudiaKargatu(JOKOA_PLAYERRIGHT2_IMAGE);
	}
	i++;
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return ellieId;
}

//Mapa nagusian ezkerrera egiterakoan jarri behar diren Ellieren argazkiak
int JOKOA_jokalariaEzkerreraIrudiaSortu()
{
	int ellieId = -1;
	if (k % 2 == 0) {
		ellieId = irudiaKargatu(JOKOA_PLAYERLEFT_IMAGE);
	}
	else {
		ellieId = irudiaKargatu(JOKOA_PLAYERLEFT1_IMAGE);
	}
	k++;
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return ellieId;
}

//Kultoko mapan ezkerrera egiterakoan jarri behar diren Ellieren argazkiak
int JOKOA_jokalariaKEzkerreraIrudiaSortu()
{
	int ellieId = -1;
	if (p % 2 == 0) {
		ellieId = irudiaKargatu(JOKOA_ELLIEKLEFT_IMAGE);
	}
	else {
		ellieId = irudiaKargatu(JOKOA_ELLIEKLEFT1_IMAGE);
	}
	p++;
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return ellieId;
}

//Kultoko mapan eskumara egiterakoan jarri behar diren Ellieren argazkiak
int JOKOA_jokalariaKEskuineraIrudiaSortu()
{
	int ellieId = -1;
	if (m % 2 == 0) {
		ellieId = irudiaKargatu(JOKOA_ELLIEKRIGHT_IMAGE);
	}
	else {
		ellieId = irudiaKargatu(JOKOA_ELLIEKRIGHT1_IMAGE);
	}
	m++;
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return ellieId;
}

//Kultoko mapan goruntza egiterakoan jarri behar diren Ellieren argazkiak
int JOKOA_jokalariaKAurreraIrudiaSortu()
{
	int ellieId = -1;
	if (n % 2 == 0) {
		ellieId = irudiaKargatu(JOKOA_ELLIEKUP_IMAGE);
	}
	else {
		ellieId = irudiaKargatu(JOKOA_ELLIEKUP1_IMAGE);
	}
	n++;
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return ellieId;
}

//Kultoko mapan beheruntza egiterakoan jarri behar diren Ellieren argazkiak
int JOKOA_jokalariaKAtzeraIrudiaSortu()
{
	int ellieId = -1;
	if (o % 2 == 0) {
		ellieId = irudiaKargatu(JOKOA_ELLIEKDOWN_IMAGE);
	}
	else {
		ellieId = irudiaKargatu(JOKOA_ELLIEKDOWN1_IMAGE);
	}
	o++;
	pantailaGarbitu();
	irudiakMarraztu();
	pantailaBerriztu();
	return ellieId;
}