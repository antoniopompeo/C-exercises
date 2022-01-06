#include "Mision.h"

#include <stdlib.h>
#include <string.h>

t_mision* mision_crear(char* mensaje) {
	t_mision* mision = malloc(sizeof(t_mision));
	mision->info_codificada = strdup(mensaje);
	mision->longitud_info = strlen(mision->info_codificada);
	return mision;
}

void mision_destroy(t_mision* mision) {
	free(mision->info_codificada);
	free(mision);
}
