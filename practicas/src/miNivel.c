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
#include <tad_items.h>

int main(){

	t_list* items = list_create();
	int rows, cols;
	int q, p;

	nivel_gui_inicializar();
	nivel_gui_get_area_nivel(&rows, &cols);

	p = cols;
	q = rows;

	CrearPersonaje(items, '@', p, q);
	nivel_gui_dibujar(items, "Test Chamber 04");





	return EXIT_SUCCESS;

}
