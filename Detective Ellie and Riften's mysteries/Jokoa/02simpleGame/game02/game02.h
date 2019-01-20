#ifndef GAME10_H
#define GAME10_H

#include "ourTypes.h"

EGOERA jokatu(void);

//ellie
int JOKOA_jokalariaAurreraIrudiaSortu();
int JOKOA_jokalariaEskuineraIrudiaSortu();
int JOKOA_jokalariaEzkerreraIrudiaSortu();
int JOKOA_jokalariaAtzeraIrudiaSortu();
int JOKOA_jokalariaKEskuineraIrudiaSortu();
int JOKOA_jokalariaKEzkerreraIrudiaSortu();
int JOKOA_jokalariaKAurreraIrudiaSortu();
int JOKOA_jokalariaKAtzeraIrudiaSortu();
int mugimendua(int puzzle6, int kulto);

//menua
int mainMenu();
int JOKOA_menuIrudiaSortu();
int JOKOA_kontrolakIrudiaSortu();
int JOKOA_menuIrtenIrudiaSortu();
int JOKOA_kontrolakAzalpenaIrudiaSortu();
int JOKOA_puntuaketaIrudiaSortu();
int JOKOA_galduIrudiaSortu();
int JOKOA_galdu1IrudiaSortu();
int menuJarraitu();
int menuIrten2();
int menuBueltatu();
int menuIrten();
int pausaMenua();
int amaieraMenua();

//Elkarrizketak
int JOKOA_hilketatxt3IrudiaSortu();
int JOKOA_kultoatxt4IrudiaSortu();
int JOKOA_kultoatxt5IrudiaSortu();
int JOKOA_kultoatxt6IrudiaSortu();
int JOKOA_ArropatxtIrudiaSortu();
int JOKOA_kultoatxtIrudiaSortu();
int JOKOA_HilketatxtIrudiaSortu();
int JOKOA_Hilketatxt1IrudiaSortu();
int JOKOA_AitaIrudiaSortu();
int JOKOA_Aita1IrudiaSortu();
int JOKOA_hilketatxtIrudiaSortu();
int JOKOA_hilketatxt1IrudiaSortu();
int JOKOA_hilketatxt2IrudiaSortu();
int JOKOA_bulegoatxt3IrudiaSortu();
int JOKOA_bulegoatxt4IrudiaSortu();
int JOKOA_bulegoatxt5IrudiaSortu();
int JOKOA_bulegoatxt6IrudiaSortu();
int JOKOA_ErrekaIrudiaSortu();
int JOKOA_kultoatxt3IrudiaSortu();
int JOKOA_Aita2IrudiaSortu();
int JOKOApanpinaIrudiaSortu();
int lehenElkarrizketa();
void hilketaTextua();
void bulegoTextSortu();
void kultotxt1();
void kultotxt2();
void kultotxt3();
void kultotxt4();
int elkarrizketaMaltzurrarekin(int id);
void elkarrizketaEzDagoEginda();
void arropaJarri();

//Puzzle1
int PUZZLE1_irudiaBistaratu();
int lehenengoPuzzlea();

//Puzzle2
int errekaPuzzlea();
int PUZZLE3_irudiaBistaratu();
int seleccion();
int selec1();
int selec2();
int pieza1L();
int pieza1D();
int pieza1R();
int pieza1U();
int pieza2L();
int pieza2D();
int pieza2R();
int pieza2U();
int pieza_3();
int pieza5D();
int pieza5R();
int pieza5U();
int pieza4L();
int pieza4D();
int pieza4R();
int pieza4U();
int pieza5L();
int pieza6D();
int pieza6U();
int pieza7D();
int pieza7U();
int pieza8L();
int pieza8D();
int pieza8R();
int pieza8U();
int pieza9L();
int pieza9D();
int pieza9R();
int pieza9U();

//Puzzle3
int PUZZLE_irudiaBistaratu();
int seleccion1();
int seleccion2();
int puzzle3(arropa);

//Puzzle4
void mapaFinala();
int PUZZLE6_irudiaBistaratu();

//Mapak
int JOKOA_hilketaIrudiaSortu();
int JOKOA_bulegoaIrudiaSortu();
int JOKOA_kultoaIrudiaSortu();
int JOKOA_MapaIrudiaSortu();
int JOKOA_Mapa1IrudiaSortu();
void hilketatikMaparaAtera();
void bulegokoIrudiaSortu();
void hilketaIrudiaSortu();
void kultotikMaparaAtera();
void elkarrizketaEgindaDago();

//Matrizeak
void kopiatuMapaNagusia();
void kopiatuMapaNagusia1();
void kopiatuMapaBulegoa();
void kopiatuMapaKultoa();
void kopiatuMapaHilketa();
void kopiatuMapaNagusia2();

//Kultoko dokumentuak
int JOKOA_notaIrudiaSortu();
void notaImg();

//irabazi baduzu
int irabaztean();

#endif

