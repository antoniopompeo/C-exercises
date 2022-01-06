#ifndef MASCOTA_H_
#define MASCOTA_H_

#include <stdbool.h>
#include "Stream.h"

typedef struct {
	char* apodo;
	char edad;
	bool da_vueltas;
}__attribute__((packed)) t_mascota;

t_mascota* mascota_crear(char* apodo, bool daVueltas, int edad);
void mascota_destroy(t_mascota* mascota);

t_stream* mascota_serialize(t_mascota* mascota);
t_mascota* mascota_deserialize(char* stream, int* size);

#endif /* MASCOTA_H_ */
