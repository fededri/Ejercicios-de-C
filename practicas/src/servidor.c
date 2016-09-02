/*
 * servidor.c
 *
 *  Created on: 01/09/2016
 *      Author: federico
 */


#include "servidor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>


#define PORT "3490"
#define BACKLOG 10 // cantidad de conexiones que se admiten en la cola


int main(){

	int sockfd, new_fd;
	struct addrinfo hints, * res, *p;
	struct sockaddr_storage their_addr;

	printf("Iniciando servidor \n");
	fflush(stdout);
	memset(&hints,0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;




	int addrInfoResult = getaddrinfo(NULL, PORT, &hints, &res);
	if ( addrInfoResult != 0){
		return 1;
	}

	printf("Estructura addrInfo obtenida \n");



	for(p = res; p!= NULL; p = p->ai_next){
		//TIP IMPORTANTE: el == tiene precedencia ante el =, por lo que si no se ponen bien los parentesis
		// el socket va a tener el valor 0 si se crea como resultado de una expresion booleana
		//y va terminar en error en las proximas llamadas
		if(( (sockfd =  socket(p->ai_family,p->ai_socktype ,p->ai_protocol))== -1)){
			perror("server: socket");
			continue;
		}

		int yes = 0;
		if(setsockopt(sockfd, SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1){
			perror("serversockopt");
			exit(1);
		}

		if(bind(sockfd, p->ai_addr,p->ai_addrlen) == -1){
			close(sockfd);
			perror("server:bind");
			continue;
		}

		break;

	}

	freeaddrinfo(res);

	if(p == NULL){
		printf(" error en los resultados de las direcciones (getaddrinfo())");
		exit(1);
	}

	if(listen(sockfd,BACKLOG) == -1){
		perror("listen");
		exit(1);
	}




	printf("Escuchando clientes... \n");

	socklen_t sin_size = sizeof their_addr;
	new_fd = accept(sockfd, (struct sockaddr *) &their_addr, &sin_size);

	if(new_fd == -1){
		perror("accept");
		exit(1);
	}

	char s[200];
	inet_ntop(their_addr.ss_family,(struct sockaddr*) &their_addr, s,sizeof s);

	printf("conectado un cliente \n");
	fflush(stdout);


		if(!fork()){ // proceso hijo
			close(sockfd); //el hijo no necesita el socket de conexion que escucha
			if(send(new_fd, "Holaa! \n", 13,0) == -1){
				perror("send");
				exit(0);
			}
		}else { //PADRE
			close(new_fd); // padre no necesita el socket del cliente
			printf("saliendo del programa..\n");

		}



	return EXIT_SUCCESS;
}



