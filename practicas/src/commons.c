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
#include <commons/collections/list.h>

int main(){


	FILE* inputFile = fopen("input.txt","r");

	t_list* people  =readInputFile(inputFile);
	t_persona* yo = (t_persona*) list_get(people,0);


	fclose(inputFile);

	FILE * outputFile = fopen("output.txt","w");

	writeInputFile(people,outputFile);

	void(*cleanFunction) (t_persona* person) = freePerson;
	list_destroy_and_destroy_elements(people, cleanFunction);


	fclose(outputFile);


	return EXIT_SUCCESS;
}


void freePerson(t_persona person){

	printf("nombre: %s", person.nameAndLastname );
	free(person.DNI);
	free(person.age);
	free(person.nameAndLastname);
	free(person.region);
	free(person.salary);
	free(person.telephone);

}


void writeInputFile(t_list* people, FILE *file){



}


/*
 * t_list: lista que contiene todas las personas que se encuentren en el archivo 'file'
 * */
t_list* readInputFile(FILE * file){
	//Formato => Región; Nombre y Apellido; Edad; Número Telefónico; DNI; Saldo
	t_list * mList = list_create();

	size_t len = 0;

	//obtengo  longitud tota de la linea

	fseek(file,0,SEEK_SET);
	char * line; //LIBERAR


	while((getline(&line,&len,file)) != -1){

		t_persona* persona = malloc(500);
		char ** arrayStrings = string_split(line,";");

		persona->region = malloc(strlen(arrayStrings[0]));
		strcpy(persona->region, arrayStrings[0]);

		persona->nameAndLastname = malloc(strlen(arrayStrings[1]));
		strcpy(persona->nameAndLastname,arrayStrings[1]);

		persona->age = malloc (strlen(arrayStrings[2]));
		strcpy(persona->age,arrayStrings[2]);


		persona->telephone = malloc(strlen(arrayStrings[3]));
		strcpy(persona->telephone, arrayStrings[3]);

		persona->DNI = malloc(strlen(arrayStrings[4]));
		strcpy(persona->DNI,arrayStrings[4]);

		persona->salary = malloc(strlen(arrayStrings[5]));
		strcpy(persona->salary,arrayStrings[5]);


		printf("name in funciton %s", persona->nameAndLastname);
		list_add(mList, &persona);
		free(arrayStrings);

	}

	free(line);


	t_persona* p = (t_persona*)list_get(mList,0);


	printf("name %s", p->nameAndLastname);

	return mList;


}




