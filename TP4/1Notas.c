#include <stdio.h>

int main() {
	float notas[5];
	float suma = 0;
	float media;
	float max, min;
	int i;
	// Lectura de notas
	for(i = 0; i < 5; i++) {
		do {
			printf("Ingresar nota %d (0 a 10): ", i + 1);
			scanf("%f", &notas[i]);
		} while(notas[i] < 0 || notas[i] > 10);
	}
	// se inicializa max y min con la primer nota
	max = notas[0];
	min = notas[0];
	
	// Procesar datos
	for(i = 0; i < 5; i++) {
		suma += notas[i];
		
		if(notas[i] > max) {
			max = notas[i];
		}
		
		if(notas[i] < min) {
			min = notas[i];
		}
	}
	//nota media operacion
	media = suma / 5;
	//resultados
	printf("\nnotas ingresadas:\n");
	for(i = 0; i < 5; i++) {
		printf("nota %d: %.2f\n", i + 1, notas[i]);
	}
	printf("\nnota media: %.2f\n", media);
	printf("nota mas alta: %.2f\n", max);
	printf("nota mas baja: %.2f\n", min);
	
	return 0;
}
