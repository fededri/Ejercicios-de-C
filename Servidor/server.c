/*
 * server.c
 *
 *  Created on: 02/04/2015
 *      Author: federico
 */
/*
 * server.c
 *
 *  Created on: 01/04/2015
 *      Author: federico
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BACKLOG 5
#define PORT "1111"
#define MAXDATASIZE 1024


int main(){
struct addrinfo hints, *serverInfo;
int resultadoOp;
int listenningSocket;

memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;		// No importa si uso IPv4 o IPv6
	hints.ai_flags = AI_PASSIVE;		// Asigna el address del localhost: 127.0.0.1
	hints.ai_socktype = SOCK_STREAM;	


getaddrinfo(NULL,PORT,&hints,&serverInfo);
listenningSocket = socket(serverInfo->ai_family,serverInfo->ai_socktype,serverInfo->ai_protocol);

bind(listenningSocket,serverInfo->ai_addr,serverInfo->ai_addrlen);
freeaddrinfo(serverInfo);

printf("escuchando...");
listen(listenningSocket,BACKLOG);

struct sockaddr_in addr;
socklen_t addrlen = sizeof(addr);

int socketCliente = accept(listenningSocket, (struct sockaddr * ) &addr, &addrlen);
char package[MAXDATASIZE];
int status =1;

if(socketCliente!=-1){
	printf("Cliente conectado como socket %d",socketCliente);
}

while(status!=0){
status = recv(socketCliente, (void*) package, MAXDATASIZE,0);
if(status!=0) printf("%s",package);
}

close(socketCliente);
close(listenningSocket);


	return 0;
}



