/*
 * Ej 5 de C sobre concurrencia y sincronizacion
 * Dado el codigo, se resolvo creando un mutex para garantizar que el saldo de la cuenta no llegue a negativo nunca
 *
 *
 */

#include "solucionLeo.h"
#define SALDO 500
int saldo_inicial = SALDO;


/* mutex para sincronizar el acceso a buffer */
pthread_mutex_t mutex;


int main(void) {


	/* Se inicializa el mutex */
	pthread_mutex_init (&mutex, NULL);


	pthread_t h1, h2; //Estructuras que representan un "Handle" al hilo, nos permite luego por ejemplo joinear el hilo.
	pthread_create(&h1, NULL, compras_mensuales, "Julieta");
	pthread_create(&h2, NULL, compras_mensuales, "Leo");
	pthread_join(h1, (void **) NULL); //El hilo principal (main) se bloquea hasta que el hilo h1 finalice
	pthread_join(h2, (void **) NULL);

	return EXIT_SUCCESS;
}

void compras_mensuales(void * args) {
	char* nombre = (char*) args;

	int i = 0;
	for (; i < (SALDO / 10); i++) {
		hacer_compras(10, nombre);
		if (consulta_saldo() < 0)
			printf("La cuenta esta en rojo!! El almacenero nos va a matar!\n");
	}
}

int consulta_saldo() {
	return saldo_inicial;
}

void hacer_compras(int monto, const char* nombre) {


	pthread_mutex_lock(&mutex);
	int saldoDisponible = consulta_saldo();


	if (saldoDisponible>= monto) {
		printf("Hay saldo suficiente %s esta por comprar.\n", nombre);
		usleep(1);
		comprar(monto);
		printf("%s acaba de comprar.\n", nombre);
	} else
		printf("No queda suficiente saldo (%d) para que %s haga las compras.\n",
				consulta_saldo(), nombre);

	pthread_mutex_unlock(&mutex);

	usleep(1);
}

void comprar(int monto) {
	saldo_inicial = saldo_inicial - monto;

}
