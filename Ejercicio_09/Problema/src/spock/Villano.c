#include "Villano.h"

#include <stdlib.h>
#include <string.h>

t_villano* villano_create(char* nombre, int edad) {
	t_villano* villano = malloc(sizeof(t_villano));
	strncpy(villano->nombre, nombre, 24);
	villano->edad = edad;
	return villano;
}

void villano_destroy(t_villano* villano) {
	free(villano);
}
