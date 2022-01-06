#include "spock/Spock.h"

#include <stdlib.h>
#include <stdio.h>

/*
 * Por una cuestion de simplicidad del ejercicio
 * el stream resultante de la serializacion es grabado a un archivo
 * Si se reemplazaran los write, por send y los read por recv
 * se puede usar para armar un protocolo de comunicacion simple
 * en el que podemos enviar estructuras complejas.
 */


int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Argumentos invalidos\n");
		return EXIT_FAILURE;
	}

	char* file_name = argv[1];

	t_spock* spock = spock_create();
	spock_enviar_a_mision(spock, file_name);
	spock_destroy(spock);

	return EXIT_SUCCESS;
}
