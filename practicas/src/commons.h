/*
 * commons.h
 *
 *  Created on: 18/8/2016
 *      Author: utnso
 */


#ifndef TADARCHIVOS_H_
#define TADARCHIVOS_H_
#include <stdio.h>
#include <string.h>
#include <commons/string.h>
#include <commons/collections/list.h>


typedef struct t_persona{
	char* region;
	char* nameAndLastname;
	char* age;
	char* telephone;
	char* DNI;
	char* salary;

}t_persona;


typedef struct t_nodo_persona{
	t_persona* persona;
	t_persona* sig;

}t_nodo_persona;


t_list* readInputFile(FILE * file);
void freePerson(t_persona* person);
void writeInputFile(t_list* people, FILE *file);
bool isGreaterThan18(t_persona* person);
bool comparatorRegionAndAge(t_persona* person1, t_persona * person2);



#endif
