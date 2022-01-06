#ifndef WENDYS_H_
#define WENDYS_H_

#include <stdbool.h>
#include "Collections/queue.h"

typedef struct {
	bool embalada;
	t_queue* ingredientes;
}t_hamburguesa;

typedef enum {
	PANINFERIOR,
	CONDIMENTOS,
	CARNE,
	QUESO,
	PANCETA,
	LECHUGA,
	TOMATE,
	PANSUPERIOR,
} t_Ingredientes;

void llegada_nuevo_cliente();
void  agregar_pan_inferior();
void  agregar_condimento();
void  agregar_carne();
void  agregar_queso();
void  agregar_panceta();
void  agregar_lechuga();
void  agregar_tomate();
void  agregar_pan_superior();
void  entregar();
void  agregar(t_Ingredientes ingrediente);
char* ingrediente_to_string(t_Ingredientes ingrediente);
bool  esta_bien_armada();

#endif /* WENDYS_H_ */
