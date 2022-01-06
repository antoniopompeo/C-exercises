#ifndef SOLUCIONLEO_H_
#define SOLUCIONLEO_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

void compras_mensuales(void* args);
int consulta_saldo();
void hacer_compras(int monto, const char* nombre);
void comprar(int monto);

#endif /* SOLUCIONLEO_H_ */
