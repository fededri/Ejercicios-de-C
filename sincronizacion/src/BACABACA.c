/*
 * BACABACA.c
 *
 *  Created on: 8/5/2017
 *      Author: utnso
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semA;
sem_t semB;
sem_t semC;
sem_t semD;

void* BACA_funcA();
void* BACA_funcB();
void* BACA_funcC();

void BACABACA(){
	pthread_t  hiloA,hiloB,hiloC;
	int rcA, rcB,rcC,rcD; //resultado de creacion de hilos

	sem_init(&semA,0,0);
	sem_init(&semB,0,1);
	sem_init(&semC,0,0);
	sem_init(&semD,0,1);

	rcA= pthread_create(&hiloA,NULL,BACA_funcA,NULL);
	rcB= pthread_create(&hiloB,NULL,BACA_funcB,NULL);
	rcC = pthread_create(&hiloC,NULL,BACA_funcC,NULL);


	pthread_join(hiloA,NULL);
	pthread_join(hiloB,NULL);
	pthread_join(hiloC,NULL);

	sem_destroy(&semA);
	sem_destroy(&semB);
	sem_destroy(&semC);
}

void* BACA_funcA(){
	int i=0;
		for(;i<100;i++){
			sem_wait(&semA);
				printf("A");
				fflush(stdout);
				sem_post(&semD);
				//sem_post(&semC);
		}
	return NULL;
}

void* BACA_funcB(){
	int i=0;
		for(;i<100;i++){
			sem_wait(&semB);
			sem_wait(&semD);
				printf("B");
				fflush(stdout);
				sem_post(&semA);
				sem_post(&semC);
		}
	return NULL;
}


void* BACA_funcC(){
	int i=0;
		for(;i<100;i++){
			sem_wait(&semC);
			sem_wait(&semD);
				printf("C");
				fflush(stdout);
				sem_post(&semA);
				sem_post(&semB);

		}
	return NULL;
}



