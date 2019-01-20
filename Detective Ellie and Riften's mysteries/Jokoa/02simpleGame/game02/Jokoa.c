#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#define SCORE_TEXTUA "Zure puntuaketa:"
#define JOKOA_SOUND ".\\sound\\BULEGOA.wav"
#define ZUZENA ".\\img\\zuzena.bmp"
#define FILAK 48
#define ZUTABEAK 64
#define JOKOA_SOUND_BULEGOA ".\\sound\\musikaBulegoa.wav"
#define JOKOA_SOUND_ELLIE ".\\sound\\musikaEllie.wav"
#define JOKOA_SOUND_KULTOA ".\\sound\\musikaKultoa.wav"
#define JOKOA_SOUND_KRIMENA ".\\sound\\musikaKrimenarenEtxean.wav"
#define JOKOA_SOUND_MAPA ".\\sound\\musikaMapaNagusia.wav"
#define JOKOA_SOUND_ZUBIA ".\\sound\\musikaZubikoPuzzlea.wav"
#define BUKAERA_SOUND_1 ".\\sound\\128NIGHT_01.wav"

int mapa[FILAK][ZUTABEAK];
JOKO_ELEMENTUA jokalaria;
int mugimenduaezkerra, up, mugimenduabehean, mugimenduaeskuina;

EGOERA jokatu(void)
{
	int filak, zutabeak,mugimenduElliePausa = 1, konprobaketaErreka = 0, scoreerreka, pausa = 0, mugimeduaEllieHilketa = 1, puzzle = 0,score = 0, konprobaketaPuzzle6 = 0, arropaJantzitaEgonDa=0;
	EGOERA  egoera = JOLASTEN;
	char buffer[50];
	int ebentu = 0, hasiera = 0, elkarrizketa = 0, puzzleKultoIrudia = 0, menu2 = 0, menuFinal = 1, puzzleKultoGalduIrudia = 0, puzzleKulto = 0, saiatuBerriz = 0, puzzleHilketa = 0, puzzle2 = 0, puzzleMaltzurra = 0, lortuPuzzlea = 0, kulto = 0, arropa = 0, kultoa = 0, hasi = 0, menu = 1, nota1 = 0, nota2 = 0, nota3 = 0, nota4 = 0, nota5 = 0, nota6 = 0, printeatuScore = 0;
	int  puzzle6 = 0, hasierakoElkarrizketa = 0, jokoahasi = 0, probafinal = 0, puzzlefinal = 0, scorepuzzle = 0, jokoarenAmaiera,amaiera=0;
	JOKO_ELEMENTUA mapaglobal;
	jokalaria.pos.x = 500;
	jokalaria.pos.y = 400;
	audioInit();
	loadTheMusic(JOKOA_SOUND_ELLIE);
	playMusic();
	kopiatuMapaBulegoa();
	do {
		Sleep(2);
		if (jokoahasi == 0) {//Hasierako menua aldi bat bakarrik errepikatzeko
			menu = mainMenu();//Menura joateko funtzioa
			jokoahasi = 1;
		}
		pantailaGarbitu();
		if (hasierakoElkarrizketa == 0) {
				hasierakoElkarrizketa =lehenElkarrizketa();
			}
		irudiaMugitu(jokalaria.id, jokalaria.pos.x, jokalaria.pos.y);
		irudiakMarraztu();
		pantailaBerriztu();
		jokoarenAmaiera =mugimendua(puzzle6,kulto);
		if (jokoarenAmaiera == 1) {//Azken puzzlea bete bada score-a jartzeko
			probafinal = 0;
			menu = 1;
			printeatuScore = 1;
		}
		if (printeatuScore == 1){//Puzzleen, elkarrizketen eta noteen batura
			score = score + scorepuzzle;
			printeatuScore = 0;
			score = score + scoreerreka;
			pantailaGarbitu();
			scorepuzzle = 0;
			scoreerreka = 0;
			textuaIdatzi(100, 200, SCORE_TEXTUA);
			sprintf(buffer, "%d", score);
			textuaIdatzi(225, 200, buffer);
			pantailaBerriztu();
			Sleep(5000);
			jokoahasi = -1;
		}
		filak = jokalaria.pos.y / 10;//jokalariaren posizioa matrizera pasatzeko kalkuloa y ardatzan
		zutabeak = jokalaria.pos.x / 10;//jokalariaren posizioa matrizera pasatzeko kalkuloa x ardatzan
		if (mapa[filak][zutabeak] == 1) {//ezkerreko kolisioa egin
			mugimenduaezkerra = 0;
		}
		if (mapa[filak][zutabeak] == 2) {//goiko kolisioa egin
			up = 0;
		}
		if (mapa[filak][zutabeak] == 3) {//beheko kolisioa egin
			mugimenduabehean = 0;
		}
		if (mapa[filak][zutabeak] == 4) {//eskuineko kolisioa egin
			mugimenduaeskuina = 0;
		}
		if (mapa[filak][zutabeak] == 5) {//ezker-goiko kolisioa egin
			mugimenduaezkerra = 0;
			up = 0;
		}
		if (mapa[filak][zutabeak] == 6) {//ezker-beheko kolisioa egin
			mugimenduaezkerra = 0;
			mugimenduabehean = 0;
		}
		if (mapa[filak][zutabeak] == 7) {//goi-eskuineko kolisioa egin
			mugimenduaeskuina = 0;
			up = 0;
		}
		if (mapa[filak][zutabeak] == 8) {//behe-eskuineko kolisioa egin
			mugimenduaeskuina = 0;
			mugimenduabehean = 0;
		}
		if (mapa[filak][zutabeak] == 16) {//hilketaren textua jarri
			hilketaTextua();
			score = score + 5;
		}
		if (mapa[filak][zutabeak] == 15) {//hilketa mapatik ateratzea
			hilketatikMaparaAtera();
		}
		if (mapa[filak][zutabeak] == 13) {//lehenengo puzzlearen kodigoa
			mugimeduaEllieHilketa = lehenengoPuzzlea();
			if (mugimeduaEllieHilketa == 1) {//irabazi baduzu
				puzzle2 = 0;
				puzzleMaltzurra = 0;
				puzzleHilketa = 0;
				score = score + 25;
				audioInit();
				loadTheMusic(JOKOA_SOUND_MAPA);
				playMusic();
			}
			else if (mugimeduaEllieHilketa == 2) {//berriro jokatu sakatzean
				score = score - 50;
			}
			else {//bueltatu menura sakatzean
				score = 0;
				jokoahasi = 0;
				menu = 1;
				hasierakoElkarrizketa = 0;
			}
		}
		if (mapa[filak][zutabeak] == 24) {//bulegoko elkarrizketa
			bulegoTextSortu();
			elkarrizketa = 1;
		}
		if (mapa[filak][zutabeak] == 23) {//elkarrizketaren konprobaketa
			if (elkarrizketa == 0) {//elkarrizketa ez badago eginda
				elkarrizketaEzDagoEginda();
			}
			if (elkarrizketa == 1) {//elkarrizketa eginda dago
				elkarrizketaEgindaDago();
			}
		}
		if (mapa[filak][zutabeak] == 31) {//bulegoaren irudia sortu
			bulegokoIrudiaSortu();
		}
		if (mapa[filak][zutabeak] == 32) {//hilketaren irudia sortu
			hilketaIrudiaSortu();
		}
		if (mapa[filak][zutabeak] == 34) {//erreka puzzlea jarri
			scoreerreka=errekaPuzzlea();
			mapaglobal.id = irabaztean();
			mapaglobal.id = JOKOA_Mapa1IrudiaSortu();
			kopiatuMapaNagusia1();
			jokalaria.id = JOKOA_jokalariaAurreraIrudiaSortu();
		}
		if (mapa[filak][zutabeak] == 40) {//nota1
			if (nota1 == 0) {
				notaImg();
				score = score + 5;
				nota1 = 1;
			}
		}
		if (mapa[filak][zutabeak] == 41) {//nota2
			if (nota2 == 0) {
				notaImg();
				score = score + 5;
				nota2 = 1;
			}
		}
		if (mapa[filak][zutabeak] == 42) {//nota3
			if (nota3 == 0) {
				notaImg();
				score = score + 5;
				nota3 = 1;
			}
		}
		if (mapa[filak][zutabeak] == 43) {//nota4
			if (nota4 == 0) {
				notaImg();
				score = score + 5;
				nota4 = 1;
			}
		}
		if (mapa[filak][zutabeak] == 44 && ebentu == TECLA_e) {//nota5
			if (nota5 == 0) {
				notaImg();
				score = score + 5;
				nota5 = 1;
			}
		}
		if (mapa[filak][zutabeak] == 45 && ebentu == TECLA_e) {//nota6
			if (nota6 == 0) {
				notaImg();
				score = score + 5;
				nota6 = 1;
			}
		}
		if (mapa[filak][zutabeak] == 60&&jokoahasi==1) {//kultoaren puzzlea
			kultoa = puzzle3(arropa);
			if (kultoa == 1) {//ondo egin bada
				score = score + 25;
			}
			else if (kultoa == 2) {//jokatu berriro
				score = score - 50;
			}
			else if(kultoa==3){//bueltatu menura
				hasierakoElkarrizketa = 0;
				jokoahasi = 0;
				menu = 1;
				kulto = 0;
				score = 0;
			}
		}
		if (mapa[filak][zutabeak] == 61) {//kulto mapatik ateratzeko
			kultotikMaparaAtera();
			kulto = 0;
			probafinal = 1;
			arropaJantzitaEgonDa = 1;
		}
		if (mapa[filak][zutabeak] == 62) {//kultoaren elkarrizketa 1
			kultotxt1();
			score = score + 5;
		}
		if (mapa[filak][zutabeak] == 63) {//kultoaren elkarrizketa 2
			kultotxt2();
			score = score + 5;
		}
		if (mapa[filak][zutabeak] == 64) {//kultoaren elkarrizketa 3
			kultotxt3();
			score = score + 5;
		}
		if (mapa[filak][zutabeak] == 65) {//kultoaren elkarrizketa 4
			kultotxt4();
		}
		if (mapa[filak][zutabeak] == 99&&arropaJantzitaEgonDa==0) {//arropa jarri
			arropaJarri();
			kulto = 1;
			arropa = 1;
		}
		if (mapa[filak][zutabeak] == 36 && probafinal == 1) {//puzzle finala jarri
			mapaFinala();
			puzzle6 = 1;
			}
		if (ebentu == TECLA_p) {//pausa menua
			pausa=pausaMenua();
		}

		if (jokoahasi == -1) {//amaireako menua
			amaiera = amaieraMenua();
			jokoahasi = 0;
			hasi = 0;
			menu = 1;
			hasierakoElkarrizketa = 0;
			menuFinal = 1;
			kultoa = 0;
			score = 0;
		}
		ebentu = ebentuaJasoGertatuBada();
		if (menu == 3||pausa==3||amaiera==3) {
			egoera = GALDU;
		}
	} while (egoera == JOLASTEN);
	irudiaKendu(jokalaria.id);
	toggleMusic();
	audioTerminate();
	pantailaGarbitu();
	pantailaBerriztu();
	return egoera;
}
