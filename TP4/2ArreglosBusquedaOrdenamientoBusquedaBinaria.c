#include <stdio.h>

void ordenarMayorMenor(int arreglo[], int tam)
{
	int i, j, aux;
	
	for(i = 0; i < tam - 1; i++)
	{
		for(j = i + 1; j < tam; j++)
		{
			if(arreglo[i] < arreglo[j])
			{
				aux = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = aux;
			}
		}
	}
}

int busquedaBinaria(int arreglo[], int tam, int num)
{
	int inicio = 0;
	int final = tam - 1;
	int medio;
	
	while(inicio <= final)
	{
		medio = (inicio + final) / 2;
		
		if(arreglo[medio] == num)
		{
			return 1;
		}
		else if(num > arreglo[medio])
		{
			final = medio - 1;
		}
		else
		{
			inicio = medio + 1;
		}
	}
	
	return 0;
}
void mostrarArreglo(int arreglo[], int tam)
{
	int i;
	
	for(i = 0; i < tam; i++)
	{
		printf("%d ", arreglo[i]);
	}
	
	printf("\n");
}

int main()
{
	int listaA[10] = {2, 4, 3, 1, 5, 6, 8, 7, 9, 10};
	
	int listaB[10];
	int listaC[10];
	int listaD[20];
	int i, j;
	int num;
	int tamD = 0;
	int repetido;
	int contador;       // 2.1: cuenta cuantas veces aparece un numero en C
	
	printf("Ingrese 10 numeros:\n");
	for(i = 0; i < 10; i++)
	{
		printf("Numero %d: ", i + 1);
		scanf("%d", &listaB[i]);
	}
	
	printf("\nArreglo A (original):\n");
	mostrarArreglo(listaA, 10);
	
	printf("\nArreglo B (original):\n");
	mostrarArreglo(listaB, 10);
	
	for(i = 0; i < 10; i++)
	{
		listaC[i] = listaA[i] + listaB[i];
	}
	// 2.1: Buscar cuantas veces aparece un numero en C
	printf("\nIngrese un numero a buscar en C: ");
	scanf("%d", &num);
	
	contador = 0;
	for(i = 0; i < 10; i++)
	{
		// Si el elemento coincide con el buscado, suma 1 al contador
		if(listaC[i] == num)
		{
			contador++;
		}
	}
	
	printf("El numero %d aparece %d veces en el arreglo C\n", num, contador);
	
	ordenarMayorMenor(listaA, 10);
	ordenarMayorMenor(listaB, 10);
	
	for(i = 0; i < 10; i++)
	{
		repetido = 0;
		
		for(j = 0; j < tamD; j++)
		{
			if(listaD[j] == listaA[i])
			{
				repetido = 1;
			}
		}
		
		if(repetido == 0)
		{
			listaD[tamD] = listaA[i];
			tamD++;
		}
	}
	
	for(i = 0; i < 10; i++)
	{
		repetido = 0;
		
		for(j = 0; j < tamD; j++)
		{
			if(listaD[j] == listaB[i])
			{
				repetido = 1;
			}
		}
		
		if(repetido == 0)
		{
			listaD[tamD] = listaB[i];
			tamD++;
		}
	}
	
	ordenarMayorMenor(listaD, tamD);
	
	printf("\nIngrese un numero a buscar en D: ");
	scanf("%d", &num);
	
	if(busquedaBinaria(listaD, tamD, num) == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
	
	printf("\nArreglo A (ordenado mayor a menor):\n");
	mostrarArreglo(listaA, 10);
	
	printf("\nArreglo B (ordenado mayor a menor):\n");
	mostrarArreglo(listaB, 10);
	
	printf("\nArreglo C (suma original de A y B):\n");
	mostrarArreglo(listaC, 10);
	
	printf("\nArreglo D (A y B juntos, sin repetidos, mayor a menor):\n");
	mostrarArreglo(listaD, tamD);
	
	return 0;
}
