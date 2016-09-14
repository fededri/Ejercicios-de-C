/*
 * ej4.c
 *
 *  Created on: 14/9/2016
 *      Author: utnso
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>


void* funcionA();
void* funcionB();


sem_t semA;
sem_t semB;

void ejercicio4(){

	pthread_t  hiloA,hiloB;
	int rcA, rcB; //resultado de creacion de hilos

	sem_init(&semA,0,1);
	sem_init(&semB,0,0);

	rcA= pthread_create(&hiloA,NULL,funcionA,NULL);
	rcB= pthread_create(&hiloB,NULL,funcionB,NULL);




	pthread_join(hiloA,NULL);
	pthread_join(hiloB,NULL);

	sem_destroy(&semA);
	sem_destroy(&semB);

}



void* funcionA(){
	int i=0;
	for(;i<100;i++){
		sem_wait(&semA);
			printf("A");
			sem_post(&semB);
	}

	return NULL;
}

void* funcionB(){
	int i=0;
		for(;i<100;i++){
			sem_wait(&semB);
				printf("B");
				sem_post(&semA);
		}

	return NULL;
}


