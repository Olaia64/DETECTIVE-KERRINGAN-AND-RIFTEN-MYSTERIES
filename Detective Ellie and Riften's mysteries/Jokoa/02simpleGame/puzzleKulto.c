#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define JOKOA_SOUND_KULTOA ".\\sound\\musikaKultoa.wav"
JOKO_ELEMENTUA jokalaria;

//Kultoko puzzlearen funtzionamendua
int puzzle3(arropa) {
	JOKO_ELEMENTUA mapaglobal,karratu1,karratu2;
	int irten = 0, puzzleKultoIrudia = 0, puzzleKultoGalduIrudia = 0, puzzleKulto = 0, ebentu = 0, aukeraketaHilketa = 0, saiatuBerriz = 0;
	do {
		if (arropa == 1) {
			if (puzzleKulto == 0) {
				if (puzzleKultoIrudia == 0) {
					mapaglobal.id = PUZZLE_irudiaBistaratu();
					karratu1.id = seleccion1();
					puzzleKultoIrudia = 1;
				}
				ebentu = ebentuaJasoGertatuBada();
				if (ebentu == TECLA_RIGHT || ebentu == TECLA_d) {
					irudiaKendu(karratu1.id);
					karratu2.id = seleccion2();
					aukeraketaHilketa = 1;
				}
				if ((ebentu == TECLA_LEFT || ebentu == TECLA_a) && aukeraketaHilketa == 1) {
					irudiaKendu(karratu2.id);
					karratu1.id = seleccion1();
					aukeraketaHilketa = 0;
				}
				if (ebentu == TECLA_RETURN && aukeraketaHilketa == 0) {
					mapaglobal.id = irabaztean();
					Sleep(1000);
					mapaglobal.id = JOKOA_kultoatxtIrudiaSortu();
					Sleep(7000);
					irudiaKendu(mapaglobal.id);
					mapaglobal.id = JOKOA_kultoaIrudiaSortu();
					kopiatuMapaKultoa();
					jokalaria.pos.x = 300;
					jokalaria.pos.y = 430;
					jokalaria.id = JOKOA_jokalariaKAtzeraIrudiaSortu();
					puzzleKultoGalduIrudia = 0;
					aukeraketaHilketa = 0;
					puzzleKulto = 0;
					irten = 1;
				}
			}
			if ((ebentu == TECLA_RETURN && aukeraketaHilketa == 1) || puzzleKultoGalduIrudia == 1) {
				if (puzzleKultoGalduIrudia == 0) {
					mapaglobal.id = JOKOA_galduIrudiaSortu();
					puzzleKultoGalduIrudia = 1;
				}
				if (ebentu == TECLA_DOWN || ebentu == TECLA_s) {
					irudiaKendu(mapaglobal.id);
					mapaglobal.id = JOKOA_galdu1IrudiaSortu();
					saiatuBerriz = 1;
				}
				if (ebentu == TECLA_UP || ebentu == TECLA_w) {
					irudiaKendu(mapaglobal.id);
					mapaglobal.id = JOKOA_galduIrudiaSortu();
					saiatuBerriz = 0;
				}
				if (ebentu == TECLA_e && saiatuBerriz == 0) {
					mapaglobal.id = JOKOA_Mapa1IrudiaSortu();
					kopiatuMapaNagusia1();
					jokalaria.pos.x = 300;
					jokalaria.pos.y = 430;
					jokalaria.id = JOKOA_jokalariaKAtzeraIrudiaSortu();
					aukeraketaHilketa = 0;
					puzzleKultoIrudia = 0;
					puzzleKultoGalduIrudia = 0;
					puzzleKulto = 0;
					irten = 2;
				}
				if (ebentu == TECLA_e && saiatuBerriz == 1) {
					puzzleKultoGalduIrudia = 0;
					puzzleKultoIrudia = 0;
					puzzleKulto = 0;
					irten = 3;
				}
			}
		}
		else {
			mapaglobal.id = JOKOA_HilketatxtIrudiaSortu();
			Sleep(4500);
			mapaglobal.id = JOKOA_Hilketatxt1IrudiaSortu();
			Sleep(4500);
			jokalaria.pos.y = jokalaria.pos.y + 40;
			mapaglobal.id = JOKOA_Mapa1IrudiaSortu();
			irten = 4;
		}
	} while (irten == 0);
	return irten;
}
