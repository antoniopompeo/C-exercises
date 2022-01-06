#ifndef VILLANO_H_
#define VILLANO_H_

#include "Stream.h"
#include <stdint.h>

typedef struct {
	char nombre[25];
	uint16_t edad;
}__attribute__((packed)) t_villano;

t_villano* villano_crear(char* nombre, int edad);
void villano_destroy(t_villano* villano);

t_stream* villano_serialize(t_villano* villano);
t_villano* villano_deserialize(char* stream, int* size);

#endif /* VILLANO_H_ */
