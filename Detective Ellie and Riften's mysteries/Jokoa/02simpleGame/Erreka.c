#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#define JOKOA_SOUND_ZUBIA ".\\sound\\musikaZubikoPuzzlea.wav"

int errekaPuzzlea() {
	int puzzleErrekaIrudia = 0, ebentu = 0, pos1 = 1, pos2 = 1, pos4 = 1, pos5 = 1, pos6 = 1, pos7 = 1, pos8 = 1, pos9 = 1, konprobaketaErreka = 0, scoreerreka = 0, bukatu = 0;
	JOKO_ELEMENTUA  pieza1, pieza2, pieza3, pieza4, pieza5, pieza6, pieza7, pieza8, pieza9, select, mapaglobal;
		do {
			if (puzzleErrekaIrudia == 0) {
				audioInit();
				loadTheMusic(JOKOA_SOUND_ZUBIA);
				playMusic();
				mapaglobal.id = JOKOA_ErrekaIrudiaSortu();
				Sleep(6000);
				mapaglobal.id = PUZZLE3_irudiaBistaratu();
				pieza1.id = pieza1R();
				pieza2.id = pieza2R();
				pieza3.id = pieza_3();
				pieza4.id = pieza4L();
				pieza5.id = pieza5R();
				pieza6.id = pieza6D();
				pieza7.id = pieza7D();
				pieza8.id = pieza8R();
				pieza9.id = pieza9U();
				select.pos.x = 0;
				select.pos.y = 0;
				select.id = seleccion();
				puzzleErrekaIrudia = 1;
			}
			irudiaMugitu(select.id, select.pos.x, select.pos.y);
			if (ebentu == TECLA_d || ebentu == TECLA_RIGHT) {
				select.pos.x = select.pos.x + 120;
				irudiaKendu(select.id);
				select.id = seleccion();
			}
			if (ebentu == TECLA_a || ebentu == TECLA_LEFT) {
				select.pos.x = select.pos.x - 120;
				irudiaKendu(select.id);
				select.id = seleccion();
			}
			if (ebentu == TECLA_s || ebentu == TECLA_DOWN) {
				select.pos.y = select.pos.y + 120;
				irudiaKendu(select.id);
				select.id = seleccion();
			}
			if (ebentu == TECLA_w || ebentu == TECLA_UP) {
				select.pos.y = select.pos.y - 120;
				irudiaKendu(select.id);
				select.id = seleccion();
			}
			//markotik ez ateratzeko
			else {
				if (select.pos.x > 240) {
					select.pos.x = select.pos.x - 120;
				}
				if (select.pos.x < 0) {
					select.pos.x = select.pos.x + 120;
				}
				if (select.pos.y > 240) {
					select.pos.y = select.pos.y - 120;
				}
				if (select.pos.y < 0) {
					select.pos.y = select.pos.y + 120;
				}
			}
			//piezen errotazioa
			if (select.pos.x == 0 && select.pos.y == 0) {
				irudiaKendu(pieza1.id);
				if (pos1 == 1) {
					pieza1.id = pieza1R();
				}
				if (pos1 == 2) {
					pieza1.id = pieza1D();
				}
				if (pos1 == 3) {
					pieza1.id = pieza1L();
				}
				if (pos1 == 4) {
					pieza1.id = pieza1U();
				}
				if (ebentu == TECLA_RETURN) {
					pos1++;
					if (konprobaketaErreka == 1 || scoreerreka >= 35) {
						scoreerreka = scoreerreka - 5;
						scoreerreka = 1;
					}
					else {
						scoreerreka = scoreerreka + 5;
					}
				}
				if (pos1 > 4) { pos1 = 1; }
			}
			if (select.pos.x == 120 && select.pos.y == 0) {
				irudiaKendu(pieza2.id);
				if (pos2 == 1) {
					pieza2.id = pieza2R();
				}
				if (pos2 == 2) {
					pieza2.id = pieza2D();
				}
				if (pos2 == 3) {
					pieza2.id = pieza2L();
				}
				if (pos2 == 4) {
					pieza2.id = pieza2U();
				}
				if (ebentu == TECLA_RETURN) {
					pos2++;
					if (konprobaketaErreka == 1 || scoreerreka >= 35) {
						scoreerreka = scoreerreka - 5;
						scoreerreka = 1;
					}
					else {
						scoreerreka = scoreerreka + 5;
					}
				}
				if (pos2 > 4) { pos2 = 1; }
			}
			if (select.pos.x == 240 && select.pos.y == 0) {
				irudiaKendu(pieza3.id);
				pieza3.id = pieza_3();
				if (ebentu == TECLA_RETURN) {
					if (konprobaketaErreka == 1 || scoreerreka >= 35) {
						scoreerreka = scoreerreka - 5;
						scoreerreka = 1;
					}
					else {
						scoreerreka = scoreerreka + 5;
					}
				}
			}
			if (select.pos.x == 0 && select.pos.y == 120) {
				irudiaKendu(pieza4.id);
				if (pos4 == 1) {
					pieza4.id = pieza4L();
				}
				if (pos4 == 2) {
					pieza4.id = pieza4U();
				}
				if (pos4 == 3) {
					pieza4.id = pieza4D();
				}
				if (pos4 == 4) {
					pieza4.id = pieza4R();
				}
				if (ebentu == TECLA_RETURN) {
					pos4++;
					if (konprobaketaErreka == 1 || scoreerreka >= 35) {
						scoreerreka = scoreerreka - 5;
						scoreerreka = 1;
					}
					else {
						scoreerreka = scoreerreka + 5;
					}
				}
				if (pos4 > 4) { pos4 = 1; }
			}
			if (select.pos.x == 120 && select.pos.y == 120) {
				irudiaKendu(pieza5.id);
				if (pos5 == 1) {
					pieza5.id = pieza5R();
				}
				if (pos5 == 2) {
					pieza5.id = pieza5U();
				}
				if (pos5 == 3) {
					pieza5.id = pieza5L();
				}
				if (pos5 == 4) {
					pieza5.id = pieza5D();
				}
				if (ebentu == TECLA_RETURN) {
					pos5++;
					if (konprobaketaErreka == 1 || scoreerreka >= 35) {
						scoreerreka = scoreerreka - 5;
						scoreerreka = 1;
					}
					else {
						scoreerreka = scoreerreka + 5;
					}
				}
				if (pos5 > 4) { pos5 = 1; }
			}
			if (select.pos.x == 240 && select.pos.y == 120) {
				irudiaKendu(pieza6.id);
				if (pos6 == 1) {
					pieza6.id = pieza6D();
				}
				if (pos6 == 2) {
					pieza6.id = pieza6U();
				}
				if (ebentu == TECLA_RETURN) {
					pos6++;
					if (konprobaketaErreka == 1 || scoreerreka >= 100) {
						scoreerreka = scoreerreka - 5;
						scoreerreka = 1;
					}
					else {
						scoreerreka = scoreerreka + 5;
					}
				}
				if (pos6 > 2) { pos6 = 1; }
			}
			if (select.pos.x == 0 && select.pos.y == 240) {
				irudiaKendu(pieza7.id);
				if (pos7 == 1) {
					pieza7.id = pieza7D();
				}
				if (pos7 == 2) {
					pieza7.id = pieza7U();
				}
				if (ebentu == TECLA_RETURN) {
					if (konprobaketaErreka == 1 || scoreerreka >= 100) {
						scoreerreka = scoreerreka - 5;
						scoreerreka = 1;
					}
					else {
						scoreerreka = scoreerreka + 5;
					}
					pos7++;
				}
				if (pos7 > 2) { pos7 = 1; }
			}
			if (select.pos.x == 120 && select.pos.y == 240) {
				irudiaKendu(pieza8.id);
				if (pos8 == 1) {
					pieza8.id = pieza8R();
				}
				if (pos8 == 2) {
					pieza8.id = pieza8D();
				}
				if (pos8 == 3) {
					pieza8.id = pieza8L();
				}
				if (pos8 == 4) {
					pieza8.id = pieza8U();
				}
				if (ebentu == TECLA_RETURN) {
					pos8++;
					if (konprobaketaErreka == 1 || scoreerreka >= 100) {
						scoreerreka = scoreerreka - 5;
						scoreerreka = 1;
					}
					else {
						scoreerreka = scoreerreka + 5;
					}
				}
				if (pos8 > 4) { pos8 = 1; }
			}
			if (select.pos.x == 240 && select.pos.y == 240) {
				irudiaKendu(pieza9.id);
				if (pos9 == 1) {
					pieza9.id = pieza9U();
				}
				if (pos9 == 2) {
					pieza9.id = pieza9R();
				}
				if (pos9 == 3) {
					pieza9.id = pieza9D();
				}
				if (pos9 == 4) {
					pieza9.id = pieza9L();
				}
				if (ebentu == TECLA_RETURN) {
					pos9++;
					if (konprobaketaErreka == 1 || scoreerreka >= 100) {
						scoreerreka = scoreerreka - 5;
						scoreerreka = 1;
					}
					else {
						scoreerreka = scoreerreka + 5;
					}
				}
				if (pos9 > 4) { pos9 = 1; }
			}
			if (pos1 == 3 && pos2 == 2 && pos5 == 2 && (pos4 == 2 || pos4 == 4) && pos6 == 2 && pos9 == 2) {
				bukatu = 1;
			}
			ebentu = ebentuaJasoGertatuBada();

		} while (bukatu == 0);
		return scoreerreka;
}