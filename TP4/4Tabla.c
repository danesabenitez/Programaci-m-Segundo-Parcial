#include <stdio.h>

#define TAM 6
// Calcula el maximo comun divisor de dos numeros usando el algoritmo de Euclides
int mcd(int a, int b)
{
	int resto;
	// Mientras b no sea 0, seguimos dividiendo
	while(b != 0)
	{
		resto = a % b;
		a = b;
		b = resto;
	}
	// Cuando b llega a 0, a contiene el mcd
	return a;
}

int main()
{
	int divisores[TAM] = {1, 2, 5, 10, 25, 50};
	// Matriz donde se guardan los resultados mcd(fila, columna)
	int tabla[TAM][TAM];
	
	int i, j;
	// Llenar la tabla calculando mcd para cada par
	for(i = 0; i < TAM; i++)
	{
		for(j = 0; j < TAM; j++)
		{
			tabla[i][j] = mcd(divisores[i], divisores[j]);
		}
	}
	// Mostrar encabezado de columnas
	printf("\nm.c.d |");
	for(j = 0; j < TAM; j++)
	{
		printf("%5d", divisores[j]);
	}
	printf("\n");
	// Linea separadora
	printf("------+");
	for(j = 0; j < TAM; j++)
	{
		printf("-----");
	}
	printf("\n");
	// Mostrar cada fila con su etiqueta y los valores de la tabla
	for(i = 0; i < TAM; i++)
	{
		printf("%5d |", divisores[i]);
		
		for(j = 0; j < TAM; j++)
		{
			printf("%5d", tabla[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
