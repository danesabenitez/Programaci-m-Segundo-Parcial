#include <stdio.h>

#define TAM 3

// Verifica si un numero ya existe en la matriz
int estaRepetido(int mat[][TAM], int filaActual, int colActual, int num)
{
	int i, j;
	
	for(i = 0; i <= filaActual; i++)
	{
		int limite = (i == filaActual) ? colActual : TAM;
		
		for(j = 0; j < limite; j++)
		{
			if(mat[i][j] == num)
			{
				return 1;
			}
		}
	}
	
	return 0;
}

// Muestra la matriz con formato de corchetes
void mostrarMatriz(int mat[][TAM])
{
	int i, j;
	
	printf("\n");
	for(i = 0; i < TAM; i++)
	{
		// Corchete izquierdo: [ solo en la primera fila, | en las del medio, ] en la ultima
		if(i == 0)           printf("[ ");
		else if(i == TAM-1)  printf("[ ");
		else                 printf("| ");
		
		for(j = 0; j < TAM; j++)
		{
			printf("%4d", mat[i][j]);
		}
		
		if(i == 0)           printf("  ]\n");
		else if(i == TAM-1)  printf("  ]\n");
		else                 printf("  |\n");
	}
	printf("\n");
}

int main()
{
	int mat[TAM][TAM];
	int i, j;
	int num;
	
	// Variables para maximo y minimo con su posicion
	int max, minVal;
	int maxFila, maxCol, minFila, minCol;
	
	// Arreglo para las diagonales (maximo 5 elementos: 3 principal + 3 secundaria - 1 centro)
	int diag[5];
	int tamDiag = 0;
	int repetido;
	
	// Cargar la matriz sin repetidos
	printf("Ingrese los elementos de la matriz 3x3 (sin repetidos):\n");
	for(i = 0; i < TAM; i++)
	{
		for(j = 0; j < TAM; j++)
		{
			do
			{
				printf("Posicion [%d][%d]: ", i, j);
				scanf("%d", &num);
				
				if(estaRepetido(mat, i, j, num))
				{
					printf("Numero repetido, ingrese otro.\n");
				}
			} while(estaRepetido(mat, i, j, num));
			
			mat[i][j] = num;
		}
	}
	
	// Mostrar la matriz
	printf("\nMatriz ingresada:");
	mostrarMatriz(mat);
	
	// Buscar maximo y minimo inicializando con el primer elemento
	max    = mat[0][0];
	minVal = mat[0][0];
	maxFila = maxCol = minFila = minCol = 0;
	
	for(i = 0; i < TAM; i++)
	{
		for(j = 0; j < TAM; j++)
		{
			if(mat[i][j] > max)
			{
				max = mat[i][j];
				maxFila = i;
				maxCol  = j;
			}
			
			if(mat[i][j] < minVal)
			{
				minVal = mat[i][j];
				minFila = i;
				minCol  = j;
			}
		}
	}
	
	printf("Maximo: %d en posicion [%d][%d]\n", max, maxFila, maxCol);
	printf("Minimo: %d en posicion [%d][%d]\n", minVal, minFila, minCol);
	
	// Armar arreglo con elementos de la diagonal principal (i == j) y diagonal secundaria (i + j == TAM - 1), sin repetir el centro
	for(i = 0; i < TAM; i++)
	{
		for(j = 0; j < TAM; j++)
		{
			if(i == j || i + j == TAM - 1)
			{
				repetido = 0;
				int k;
				for(k = 0; k < tamDiag; k++)
				{
					if(diag[k] == mat[i][j])
					{
						repetido = 1;
					}
				}
				
				if(repetido == 0)
				{
					diag[tamDiag] = mat[i][j];
					tamDiag++;
				}
			}
		}
	}
	
	// Mostrar el arreglo de diagonales
	printf("\nElementos de las diagonales:\n");
	for(i = 0; i < tamDiag; i++)
	{
		printf("%d ", diag[i]);
	}
	printf("\n");
	
	return 0;
}
