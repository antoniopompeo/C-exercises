#ifndef VILLANO_H_
#define VILLANO_H_

#include <stdint.h>

typedef struct {
	char nombre[25];
	uint16_t edad;
}__attribute__((packed)) t_villano;

t_villano* villano_create(char* nombre, int edad);
void villano_destroy(t_villano* villano);

#endif /* VILLANO_H_ */
