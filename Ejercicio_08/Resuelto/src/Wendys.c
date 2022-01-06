#include "Wendys.h"

#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define CANT_HAMBURGUESAS 10

t_hamburguesa hamburguesa;
pthread_mutex_t mutex;
sem_t sem_llegada_nuevo_cliente;
sem_t sem_pan_inferior;
sem_t sem_condimento;
sem_t sem_carne;
sem_t sem_queso;
sem_t sem_panceta;
sem_t sem_lechuga;
sem_t sem_tomate;
sem_t sem_pan_superior;
sem_t sem_entrega;

int main(void) {
	pthread_t h0, h1, h2, h3, h4, h5, h6, h7, h8;

	sem_init(&sem_llegada_nuevo_cliente, 0, 1);
	sem_init(&sem_pan_inferior, 0, 0);
	sem_init(&sem_condimento, 0, 0);
	sem_init(&sem_carne, 0, 0);
	sem_init(&sem_queso, 0, 0);
	sem_init(&sem_panceta, 0, 0);
	sem_init(&sem_lechuga, 0, 0);
	sem_init(&sem_tomate, 0, 0);
	sem_init(&sem_pan_superior, 0, 0);
	sem_init(&sem_entrega, 0, 0);

	hamburguesa.embalada = false;
	hamburguesa.ingredientes = queue_create();

	pthread_create(&h0, NULL, (void*) llegada_nuevo_cliente, NULL);
	pthread_create(&h1, NULL, (void*) agregar_pan_inferior, NULL);
	pthread_create(&h2, NULL, (void*) agregar_condimento, NULL);
	pthread_create(&h3, NULL, (void*) agregar_carne, NULL);
	pthread_create(&h4, NULL, (void*) agregar_queso, NULL);
	pthread_create(&h5, NULL, (void*) agregar_panceta, NULL);
	pthread_create(&h6, NULL, (void*) agregar_lechuga, NULL);
	pthread_create(&h7, NULL, (void*) agregar_tomate, NULL);
	pthread_create(&h7, NULL, (void*) agregar_pan_superior, NULL);
	pthread_create(&h8, NULL, (void*) entregar, NULL);

	pthread_join(h1, (void**) NULL);
	pthread_join(h2, (void**) NULL);
	pthread_join(h3, (void**) NULL);
	pthread_join(h4, (void**) NULL);
	pthread_join(h5, (void**) NULL);
	pthread_join(h6, (void**) NULL);
	pthread_join(h7, (void**) NULL);
	pthread_join(h8, (void**) NULL);

	return EXIT_SUCCESS;
}

void llegada_nuevo_cliente() {
	for (int i = 0; i < CANT_HAMBURGUESAS; ++i) {
		sem_wait(&sem_llegada_nuevo_cliente);
		printf("Esperando nuevo cliente...\n");
		sleep(3);
		printf("Llego un nuevo cliente...\n");
		sem_post(&sem_pan_inferior);
	}
}

void agregar_pan_inferior() {
	for (int i = 0; i < CANT_HAMBURGUESAS; ++i) {
		sem_wait(&sem_pan_inferior);
		agregar(PANINFERIOR);
		sem_post(&sem_condimento);
	}
}

void agregar_condimento() {
	for (int i = 0; i < CANT_HAMBURGUESAS; ++i) {
		sem_wait(&sem_condimento);
		agregar(CONDIMENTOS);
		sem_post(&sem_carne);
	}
}

void agregar_carne() {
	for (int i = 0; i < CANT_HAMBURGUESAS; ++i) {
		sem_wait(&sem_carne);
		agregar(CARNE);
		sem_post(&sem_queso);
	}
}

void agregar_queso() {
	for (int i = 0; i < CANT_HAMBURGUESAS; ++i) {
		sem_wait(&sem_queso);
		agregar(QUESO);
		sem_post(&sem_panceta);
	}
}

void agregar_panceta() {
	for (int i = 0; i < CANT_HAMBURGUESAS; ++i) {
		sem_wait(&sem_panceta);
		agregar(PANCETA);
		sem_post(&sem_lechuga);
	}
}

void agregar_lechuga() {
	for (int i = 0; i < CANT_HAMBURGUESAS; ++i) {
		sem_wait(&sem_lechuga);
		agregar(LECHUGA);
		sem_post(&sem_tomate);
	}
}

void agregar_tomate() {
	for (int i = 0; i < CANT_HAMBURGUESAS; ++i) {
		sem_wait(&sem_tomate);
		agregar(TOMATE);
		sem_post(&sem_pan_superior);
	}
}

void agregar_pan_superior() {
	for (int i = 0; i < CANT_HAMBURGUESAS; ++i) {
		sem_wait(&sem_pan_superior);
		agregar(PANSUPERIOR);
		sem_post(&sem_entrega);
		sem_post(&sem_llegada_nuevo_cliente);
	}
}

void entregar() {
	for (int i = 0; i < CANT_HAMBURGUESAS; ++i) {
		sem_wait(&sem_entrega);
		if (!esta_bien_armada()){
			printf("Error en el armado de la hamburguesa!!\n"
					"El cliente se fue a comerse un triple bacon a mc :( \n");
		} else {
			printf("Hamburguesa armada perfectamente!!\n"
					"Le hemos tapado 5 arterias al cliente!! :)\n");
		}
	}
}

void agregar(t_Ingredientes ingrediente) {
	printf("Agregando ingrediente %s\n", ingrediente_to_string(ingrediente));
	pthread_mutex_lock(&mutex);
	int * i = malloc(sizeof(int));
	*i = ingrediente;
	queue_push(hamburguesa.ingredientes, i);
	pthread_mutex_unlock(&mutex);
}

bool esta_bien_armada() {
	/*Esta correctamente armada si tiene todos los ingredientes,
		 *  y los tiene definidos en el orden dado por el enum t_Ingredientes*/

	for (int i = 0; (((t_Ingredientes) i) <= PANSUPERIOR); i++) {
		t_Ingredientes ingrediente_correcto = (t_Ingredientes) i;
		t_Ingredientes ingrediente_hamburguesa;

		pthread_mutex_lock(&mutex);
		int* ingrediente = queue_pop(hamburguesa.ingredientes);
		pthread_mutex_unlock(&mutex);

		if (ingrediente == NULL) {
			printf("Faltaron ingredientes!\n");
			return false;
		}

		ingrediente_hamburguesa = (t_Ingredientes) *ingrediente;
		if (ingrediente_hamburguesa != ingrediente_correcto) {
			printf("Ingrediente incorrecto debia ser %s y era %s\n",
					ingrediente_to_string(ingrediente_correcto),
					ingrediente_to_string(ingrediente_hamburguesa));

			free(ingrediente);
			return false;
		}
	}

	return true;
}

char* ingrediente_to_string(t_Ingredientes ingrediente) {
	char* ingredienteChar;
	switch (ingrediente) {
	case PANINFERIOR:
		ingredienteChar = "PANINFERIOR";
		break;
	case PANSUPERIOR:
		ingredienteChar = "PANSUPERIOR";
		break;
	case CARNE:
		ingredienteChar = "CARNE";
		break;
	case QUESO:
		ingredienteChar = "QUESO";
		break;
	case PANCETA:
		ingredienteChar = "PANCETA";
		break;
	case LECHUGA:
		ingredienteChar = "LECHUGA";
		break;
	case TOMATE:
		ingredienteChar = "TOMATE";
		break;
	case CONDIMENTOS:
		ingredienteChar = "CONDIMENTOS";
		break;
	default:
		ingredienteChar = "Desconocido!";
		break;

	}

	return ingredienteChar;

}