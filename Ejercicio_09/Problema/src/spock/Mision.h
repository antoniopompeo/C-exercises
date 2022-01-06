#ifndef MISION_H_
#define MISION_H_

typedef struct {
	char* info_codificada;
	int longitud_info;
}__attribute__((packed)) t_mision;

t_mision* mision_crear(char* mensaje);
void mision_destroy(t_mision* mision);

#endif /* MISION_H_ */
