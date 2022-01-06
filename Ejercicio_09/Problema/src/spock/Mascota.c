#include "Mascota.h"

#include <stdlib.h>
#include <string.h>

t_mascota* mascota_crear(char* apodo, bool daVueltas, int edad) {
	t_mascota* mascota = malloc(sizeof(t_mascota));
	mascota->apodo = strdup(apodo);
	mascota->da_vueltas = daVueltas;
	mascota->edad = edad;

	return mascota;
}

void mascota_destroy(t_mascota* mascota) {
	free(mascota->apodo);
	free(mascota);
}
