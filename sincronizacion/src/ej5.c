/*
 * ej5.c
 *
 *  Created on: 14/9/2016
 *      Author: utnso
 */


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

void* e5_funcionA();
void* e5_funcionB();
void* e5_funcionC();


sem_t semA;
sem_t semB;
sem_t semC;

void ejercicio5(){

	pthread_t  hiloA,hiloB,hiloC;
		int rcA, rcB,rcC; //resultado de creacion de hilos

		sem_init(&semA,0,1);
		sem_init(&semB,0,0);
		sem_init(&semC,0,0);

		rcA= pthread_create(&hiloA,NULL,e5_funcionA,NULL);
		rcB= pthread_create(&hiloB,NULL,e5_funcionB,NULL);
		rcC = pthread_create(&hiloC,NULL,e5_funcionC,NULL);



		pthread_join(hiloA,NULL);
		pthread_join(hiloB,NULL);

		sem_destroy(&semA);
		sem_destroy(&semB);
		sem_destroy(&semC);
}



void* e5_funcionA(){
	int i=0;
	for(;i<100;i++){
		sem_wait(&semA);
			printf("A");
			sem_post(&semB);
	}

	return NULL;
}

void* e5_funcionB(){
	int i=0;
		for(;i<100;i++){
			sem_wait(&semB);
				printf("B");
				sem_post(&semC);
		}

	return NULL;
}


void* e5_funcionC(){
	int i=0;
		for(;i<100;i++){
			sem_wait(&semC);
				printf("C");
				sem_post(&semA);
		}

	return NULL;
}
