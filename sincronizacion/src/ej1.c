/*
 * ej1.c
 *
 *  Created on: 14/9/2016
 *      Author: utnso
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>



void* hilo2Funcion(void* hiloName);
void* hilo1Funcion(void* hiloName);

int compartida = 0;
sem_t semaforo;


void ejercicio1(){
	pthread_t hilo1,hilo2;
	int creacionHilo1, creacionHilo2;
	const char * msg1 = "hilo1";
	const char * msg2 = "hilo2";


	sem_init(&semaforo,0,1); //con 1 es un mutex



	printf("SINCRONIZADO\n");
	creacionHilo1 = pthread_create( &hilo1, NULL, hilo1Funcion, (void*) msg1);
	creacionHilo2 = pthread_create( &hilo2, NULL, hilo2Funcion,(void*) msg2);

	if(creacionHilo1)
	     {
	         fprintf(stderr,"Error - pthread_create() return code: %d\n",creacionHilo1);
	     }

	if(creacionHilo2)
		     {
		         fprintf(stderr,"Error - pthread_create() return code: %d\n",creacionHilo2);

		     }


	pthread_join( hilo1, NULL);
    pthread_join( hilo2, NULL);




}


void* hilo2Funcion(void* hiloName){

	sem_wait(&semaforo);
	printf("entro al hilo 2\n");

	int i =0;
		for(;i<10;i++){

			compartida +=2;

			printf("compartida en el hilo 2 vale %d\n",compartida);
			sleep(1);
		}
		printf("termina hilo 2------- \n");
		compartida = 0;
		sem_post(&semaforo);
		return NULL;
}



void* hilo1Funcion(void* hiloName){
	sem_wait(&semaforo);
	printf("entro al hilo 1\n");


		int i =0;
				for(;i<10;i++){
					compartida +=3;
					printf("compartida en el hilo 1 vale %d\n",compartida);
					sleep(1);
				}


	printf("termina hilo 1------\n");
	compartida = 0;
	sem_post(&semaforo);
	return NULL;

}
