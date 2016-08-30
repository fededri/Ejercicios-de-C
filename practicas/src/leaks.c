/*
 * leaks.c
 *
 *  Created on: 22/8/2016
 *      Author: utnso
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main4(){

	char* array = malloc(5*sizeof(char));
	array[4] = 'B';

	printf("programa terminado %c", array[4]);
	free(array);

}
