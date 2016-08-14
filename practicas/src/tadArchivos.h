/*
 * tadArchivos.h
 *
 *  Created on: 14/8/2016
 *      Author: utnso
 */

#ifndef TADARCHIVOS_H_
#define TADARCHIVOS_H_

typedef enum FILE_MODE{
	READ,
	WRITE
}FILE_MODE;

typedef struct t_file{
	FILE * file;
	char* fileName;
	FILE_MODE mode;

}t_file;


typedef struct Nodo{
	char* data;
	struct Nodo* sig;

}Nodo;

t_file getFile(char* fileName);
char * readFile(t_file *);
void writeFile(t_file *, char*);
void appendFile(t_file*, char*);
void closeFile(t_file*);
void mapFile(t_file*, void (*function)(char* fileLine));
void processList(Nodo* list, char* (*mapList) (Nodo));
int getFileSize(t_file * file);



#endif /* TADARCHIVOS_H_ */
