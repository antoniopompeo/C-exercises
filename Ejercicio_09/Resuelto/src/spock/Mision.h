#ifndef MISION_H_
#define MISION_H_

#include "Mision.h"
#include "Stream.h"

#include "stdint.h"

typedef struct {
	char* info_codificada;
	uint32_t longitud;
}__attribute__((packed)) t_mision;

t_mision* mision_crear(char* mensaje);
void mision_destroy(t_mision* mision);

t_stream* mision_serialize(t_mision* mision);
t_mision* mision_deserialize(char* stream, int* size);

#endif /* MISION_H_ */
