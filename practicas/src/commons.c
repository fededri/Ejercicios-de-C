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

	bool (*filterFunction) (t_persona* person) = isGreaterThan18;
	void (*cleanFunction) (t_persona* person) = freePerson;


	t_list* listFiltered = list_filter(people,filterFunction);
	//libero la lista inicial ya que no se usa mas



	fclose(inputFile);

	FILE * outputFile = fopen("output.txt","w");
	//escribo los resultados en el archivo
	writeInputFile(listFiltered,outputFile);

	//libero la lista de filtrados
	list_destroy_and_destroy_elements(listFiltered, cleanFunction);
	list_destroy_and_destroy_elements(people, cleanFunction);
	fclose(outputFile);


	printf("Programa terminado");


	return EXIT_SUCCESS;
}

bool isGreaterThan18(t_persona* person){
	int age = atoi(person->age);

	return age>18;

}


void freePerson(t_persona * person){

	free(person->DNI);
	free(person->age);
	free(person->nameAndLastname);
	free(person->region);
	free(person->salary);
	free(person->telephone);

}


void writeInputFile(t_list* people, FILE *file){


	int count = people->elements_count;
	int i = 0;

	for(;i<count;i++){
	t_persona* persona =	list_get(people,i);
	fwrite(persona->region,strlen(persona->region),1,file);
	fwrite(";",1,1,file);
	fwrite(persona->nameAndLastname,strlen(persona->nameAndLastname),1,file);
	fwrite(";",1,1,file);
	fwrite(persona->telephone,strlen(persona->telephone),1,file);
	}



}




/*
 * t_list: lista que contiene todas las personas que se encuentren en el archivo 'file'
 * */
t_list* readInputFile(FILE * file){
	//Formato => Región; Nombre y Apellido; Edad; Número Telefónico; DNI; Saldo
	t_list * mList = list_create();

	size_t len = 0;
	t_nodo_persona* lista = NULL;

	//obtengo  longitud tota de la linea

	fseek(file,0,SEEK_SET);
	char * line; //LIBERAR


	while((getline(&line,&len,file)) != -1){

		int sizeOft_persona  = sizeof(t_persona);
		t_persona* persona = malloc(sizeOft_persona);
		char ** arrayStrings = string_split(line,";");

		persona->region = malloc(strlen(arrayStrings[0]));
		strcpy(persona->region, arrayStrings[0]);

		char * name = malloc(sizeof(arrayStrings[1]));
		strcpy(name,arrayStrings[1]);
		string_trim(&name);
		persona->nameAndLastname = malloc(sizeof(name));
		strcpy(persona->nameAndLastname,name);
		free(name);


		persona->age = malloc (strlen(arrayStrings[2]));
		strcpy(persona->age,arrayStrings[2]);


		persona->telephone = malloc(strlen(arrayStrings[3]));
		strcpy(persona->telephone, arrayStrings[3]);

		persona->DNI = malloc(strlen(arrayStrings[4]));
		strcpy(persona->DNI,arrayStrings[4]);

		persona->salary = malloc(strlen(arrayStrings[5]));
		strcpy(persona->salary,arrayStrings[5]);

		list_add(mList,(persona));
		free(arrayStrings[0]);

	}

	free(line);

	return mList;


}




