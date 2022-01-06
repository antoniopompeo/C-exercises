#ifndef SPOCK_H_
#define SPOCK_H_

#include "Mision.h"
#include "Villano.h"
#include "Stream.h"
#include "Mascota.h"
#include "../Collections/list.h"

typedef struct {
	char* nombre;
	char edad;
	t_list* villanos;
	t_mascota* mascota;
	t_mision* mision;
}__attribute__((packed)) t_spock;

t_spock* spock_create();
void spock_destroy(t_spock* spock);

t_stream* spock_serialize(t_spock* spock);
t_spock* spock_deserialize(char* stream, int* size);


void spock_enviar_a_mision(t_spock* spock, char* file_name);
t_spock* spock_volver_de_mision(char* file_name);

void spock_es_igual(t_spock* spock, t_spock* otro_spock);
void spock_print(t_spock* spock);

#endif /* SPOCK_H_ */
