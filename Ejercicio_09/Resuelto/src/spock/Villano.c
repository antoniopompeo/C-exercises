#include "Villano.h"

#include <stdlib.h>
#include <string.h>

t_villano* villano_crear(char* nombre, int edad) {
	t_villano* villano = malloc(sizeof(t_villano));
	strncpy(villano->nombre, nombre, 24);
	villano->edad = edad;
	return villano;
}

void villano_destroy(t_villano* villano) {
	free(villano);
}

t_stream* villano_serialize(t_villano* villano) {
	t_stream *stream = stream_create(sizeof(t_villano));
	memcpy(stream->data, villano, sizeof(t_villano));
	return stream;
}

t_villano* villano_deserialize(char* stream, int* size) {
	t_villano *villano = malloc(sizeof(t_villano));
	memcpy(villano, stream, sizeof(t_villano));

	*size = sizeof(t_villano);

	return villano;
}
