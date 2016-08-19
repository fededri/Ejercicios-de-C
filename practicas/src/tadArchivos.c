/*
 * tadArchivos.c
 *
 *  Created on: 14/8/2016
 *      Author: utnso
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadArchivos.h"
#include "basico.h"

int main2(void) {


	t_file file = getFile("test.txt");


	char c[] = "manuelita la tortuga saltaba sobre una pata\n";
	//writeFile(&file,c);
	printf("Leyendo el archivo...\n %s",readFile(&file));

	void  (*mFunction) (char*) = printLn;
	mapFile(&file, mFunction);

	closeFile(&file);
	return EXIT_SUCCESS;
}


void printLn(char* string){
	printf("Entrando en la funcion printLn\n");
	printf("%s \n",string);
}

t_file getFile(char* fileName){

	t_file mFile;
	mFile.fileName = malloc(sizeof(fileName));
	strcpy(mFile.fileName,fileName);
	mFile.file = fopen(fileName, "a+");


	return mFile;

}


int getFileSize(t_file * file){
	fseek(file->file, 0L, SEEK_END);
	int size = ftell(file->file);
	fseek(file->file,0,SEEK_SET);

	return size;
}

char * readFile(t_file * file){

	fseek(file->file,0,SEEK_SET);
	char * string = malloc(sizeof(char) * 100);
	int i =0;
	char c;
	c = fgetc(file->file);
	while(c != EOF){
		string[i]= c;
		c = fgetc(file->file);
		i++;
	}


	return string;
}
void writeFile(t_file * file, char* string){

	  if (truncate(file->fileName, 0) == -1){
	      perror("Could not truncate");
	  }

	fwrite(string,sizeof(char),getLenghtOfString(string),file->file);

}
void appendFile(t_file* file, char* string){
	fwrite(string,sizeof(char),getLenghtOfString(string),file->file);
}
void closeFile(t_file* file){

	free(file->fileName);
	fclose(file->file);
}
void mapFile(t_file* file, void (*function)(char* fileLine)){
	char line[256];
	fseek(file->file,0,SEEK_SET);
	while(fgets(line,sizeof(line),file->file)){
		(*function) (line);
	}

}
void processList(Nodo* list, char* (*mapList) (Nodo)){

}
