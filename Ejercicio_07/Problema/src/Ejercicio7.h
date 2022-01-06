#ifndef EJERCICIO7_H_
#define EJERCICIO7_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include "Collections/queue.h"

void  trabajar(void* args);
void  procesar_cola_impresion(void* args);
void  mandar_a_imprimir(t_queue* jobQueue);
char* crear_data();

typedef struct {
	int pc; //PC que hizo el pedido de impresion
	char* data; //Datos a imprimir
} t_print_job;

#endif /* EJERCICIO7_H_ */
