#include "SolucionLeo.h"
#define SALDO 500
int saldo_inicial = SALDO;

int main(void) {
	pthread_t h1, h2; //Estructuras que representan un "Handle" al hilo, nos permite luego por ejemplo joinear el hilo.
	pthread_create(&h1, NULL, compras_mensuales, "Julieta");
	pthread_create(&h2, NULL, compras_mensuales, "Leo");
	pthread_join(h1, (void **) NULL); //El hilo principal (main) se bloquea hasta que el hilo h1 finalice
	pthread_join(h2, (void **) NULL);

	return EXIT_SUCCESS;
}

void compras_mensuales(void * args) {
	char* nombre = (char*) args;

	for (int i = 0; i < (SALDO / 10); i++) {
		hacer_compras(10, nombre);
		if (consulta_saldo() < 0)
			printf("La cuenta esta en rojo!! El almacenero nos va a matar!\n");
	}
}

int consulta_saldo() {
	return saldo_inicial;
}

void hacer_compras(int monto, const char* nombre) {
	if (consulta_saldo() >= monto) {
		printf("Hay saldo suficiente %s esta por comprar.\n", nombre);
		usleep(1);
		comprar(monto);
		printf("%s acaba de comprar.\n", nombre);
	} else
		printf("No queda suficiente saldo (%d) para que %s haga las compras.\n",
				consulta_saldo(), nombre);
	usleep(1);
}

void comprar(int monto) {
	saldo_inicial = saldo_inicial - monto;
}
