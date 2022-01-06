#ifndef EJERCICIO7_H_
#define EJERCICIO7_H_

#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include "Collections/queue.h"

typedef struct {
	const char* pc; //PC que hizo el pedido de impresion
	char* data;
} t_print_job;

void trabajar(void * args);
void procesar_cola_impresion(void * args);
void mandar_a_imprimir(t_queue* jobQueue, const char* nombre);
char* crear_data();

void* queue_sync_pop(t_queue* self);
void queue_sync_push(t_queue* self, void* element);

#endif /* EJERCICIO7_H_ */
