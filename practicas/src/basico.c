/*
 ============================================================================
 Name        : practicas.c
 Author      : Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 1 de la practica
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basico.h"


int main1(void) {



	char* saludo;
	printf("%s",string_concat("concatenado "," comun\n"));

	string_concat_dynamic("un elefante"," se balanceaba y se pasaba por referencia\n", &saludo);
	printf("%s", saludo);

	char* user;
	char* domine;
	mail_split("fede@hotmail.com",&user,&domine);
	printf("El user es %s y el dominio %s",user,domine);

	return EXIT_SUCCESS;
}


char* string_concat(char* first, char* second){

	int spaceToAllocate = sizeof(first) + sizeof(second) - 1; // resto 1 porque si no estaria contando dos veces el caracter \0
	char* aux = malloc(spaceToAllocate);
	int i = 0;
	int secondStringLenght = getLenghtOfString((second));

	//copio los del primer string
	while(first[i] != '\0'){
		aux[i] = first[i];
		i++;
	}

	//copio los del segundo string
	int j  = 0;
	while(j<secondStringLenght){
		aux[i] = second[j];
		j++;
		i++;
	}
	aux[++i] = '\0';
	return aux;


}


void string_concat_dynamic(char* first, char* second, char** result){
	//podria hacerse utilizando la funcion sin valor por referencia tranquilamente

	int spaceToAllocate = sizeof(first) + sizeof(second) - 1; // resto 1 porque si no estaria contando dos veces el caracter \0
		*result = malloc(spaceToAllocate);
		int i = 0;
		int secondStringLenght = getLenghtOfString((second));

		//copio los del primer string
		while(first[i] != '\0'){
			(*result)[i] = first[i];
			i++;
		}

		//copio los del segundo string
		int j  = 0;
		while(j<secondStringLenght){
			(*result)[i] = second[j];
			j++;
			i++;
		}
		(*result)[++i] = '\0';



}

int getLenghtOfString(char* string){
int i = 0;
while(string[i] != '\0'){
	i++;
}
return i;
}


char* addCharToString(char* string, char c){
int i = 0;
char* aux = malloc(sizeof(*string)+1);
strcpy(aux,string);

	for(; aux[i] != '\0'; i++){

	}
	aux[i] = c;
	aux[++i] = '\0';
	return aux;

}


void mail_split(char* mail, char** user, char** domine){

	int mailLenght = getLenghtOfString(mail);
	int i = 0;
	int userLenght = 0, domineLenght=0;

	while(mail[i] != '@'){
		userLenght++;
		i++;
	}

	i++;
	while(mail[i] != '\0'){
		domineLenght++;
		i++;
	}
	i=0;

	(*user) = malloc(userLenght+1);
	(*domine) = malloc(domineLenght+1);


	for(;i< mailLenght && mail[i] != '@';i++){
		(*user)[i] = mail[i];

	}

	(*user)[i] = '\0';
	i++;

	int j = 0;
	for(;i<mailLenght && mail[i] != '\0';i++){
		(*domine)[j] = mail[i];
		j++;
	}
	(*domine)[j] = '\0';


}


