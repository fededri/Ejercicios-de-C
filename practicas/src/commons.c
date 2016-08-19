/*
 * commons.c
 *
 *  Created on: 18/8/2016
 *      Author: utnso
 */

#include "commons.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/log.h>
#include <commons/txt.h>
#include "tadArchivos.h"
#include <commons/string.h>

int main(){

	FILE * outputFile = fopen("output.txt","w");
	FILE* inputFile = fopen("input.txt","r");

	readInputFile(inputFile);






	return EXIT_SUCCESS;
}


t_nodo_persona* readInputFile(FILE * file){
	//Formato => Región; Nombre y Apellido; Edad; Número Telefónico; DNI; Saldo
	t_nodo_persona * list;
	t_persona persona;

	int lineSize =0;
	size_t len = 0;
	int regionSize, nameSize, ageSize, numberSize, dniSize, salarySize;


	//obtengo  longitud tota de la linea
	char c = fgetc(file);
	while(c != '\n' && c != EOF){
			lineSize++;
			c = fgetc(file);
	}
	fseek(file,0,SEEK_SET);

	char * line; //LIBERAR
	getline(&line,&len,file);

	char ** arrayStrings = string_split(line,";");

	persona.region = malloc(strlen(arrayStrings[0]));
	strcpy(persona.region, arrayStrings[0]);

	persona.nameAndLastname = malloc(strlen(arrayStrings[1]));
	strcpy(persona.nameAndLastname,arrayStrings[1]);

	persona.age = malloc (strlen(arrayStrings[2]));
	strcpy(persona.age,arrayStrings[2]);


	persona.telephone = malloc(strlen(arrayStrings[3]));
	strcpy(persona.telephone, arrayStrings[3]);

	persona.DNI = malloc(strlen(arrayStrings[4]));
	strcpy(persona.DNI,arrayStrings[4]);

	persona.salary = malloc(strlen(arrayStrings[5]));
	strcpy(persona.salary,arrayStrings[5]);
	free(arrayStrings);


	t_nodo_persona nodo;
	nodo.persona = &persona;

	list = & nodo;



	return list;


}




