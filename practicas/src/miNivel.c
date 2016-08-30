/*
 * miNivel.c
 *
 *  Created on: 28/8/2016
 *      Author: utnso
 */

#include "miNivel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <tad_items.h>

int main(){

	t_list* items = list_create();
	int rows, cols;


	nivel_gui_inicializar();
	nivel_gui_get_area_nivel(&rows, &cols);

	int xCenter = cols / 2;
	int yCenter = rows / 2;

	int currentX, currentY;
	currentX = xCenter;
	currentY = yCenter;


	CrearPersonaje(items, 'S', xCenter++	, yCenter);
	CrearPersonaje(items, 'a', xCenter++, yCenter);
	CrearPersonaje(items, 'a', xCenter++, yCenter);
	CrearCaja(items, 'a', xCenter++, yCenter++,2);
	CrearCaja(items, 'a', xCenter++, yCenter,2);
	CrearCaja(items, 'a', xCenter++, yCenter,2);
	CrearCaja(items, 'a', xCenter++, yCenter,2);
	CrearCaja(items, 'a', xCenter++, yCenter,2);
	CrearCaja(items, 'a', xCenter++, yCenter,2);
	nivel_gui_dibujar(items, "Hola ameo");


	while(1){
		int key = getch();

		switch(key){

		case KEY_UP:
			currentY--;

			break;

		case KEY_DOWN:
			currentY++;
			break;


		case KEY_LEFT:
			currentX--;
			break;

		case KEY_RIGHT:
			currentX++;

		break;


		case 'q':
			nivel_gui_terminar();
			exit(0);
			break;

		}
		MoverPersonaje(items,'S', currentX,currentY);
		nivel_gui_dibujar(items,"Testing");


	}





	return EXIT_SUCCESS;

}
