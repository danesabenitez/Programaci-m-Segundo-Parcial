#include <stdio.h>

void ordenarBurbuja(int arreglo[], int tam)
{
	int i, j, aux;
	
	for(i = 0; i < tam - 1; i++)
	{
		for(j = 0; j < tam - i - 1; j++)
		{
			if(arreglo[j] > arreglo[j + 1])
			{
				aux = arreglo[j];
				arreglo[j] = arreglo[j + 1];
				arreglo[j + 1] = aux;
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
		else if(num < arreglo[medio])
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
void mostrarArreglo(int arreglo[], int tam, char etiqueta[])
{
	int i;
	printf("\n%s\n", etiqueta);
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
	// E puede tener hasta 20 elementos (A y B juntos)
	int listaE[20];	
	int i, j;
	int tamE = 0;
	int repetido;
	int num;

	printf("Ingrese 10 numeros para el arreglo B:\n");
	for(i = 0; i < 10; i++)
	{
		printf("Numero %d: ", i + 1);
		scanf("%d", &listaB[i]);
	}
	
	// Armar E con los elementos de A sin repetidos
	for(i = 0; i < 10; i++)
	{
		repetido = 0;
		
		for(j = 0; j < tamE; j++)
		{
			if(listaE[j] == listaA[i])
			{
				repetido = 1;
			}
		}
		
		if(repetido == 0)
		{
			listaE[tamE] = listaA[i];
			tamE++;
		}
	}
	// Agregar los de B a E, tambien sin repetidos
	for(i = 0; i < 10; i++)
	{
		repetido = 0;
		
		for(j = 0; j < tamE; j++)
		{
			if(listaE[j] == listaB[i])
			{
				repetido = 1;
			}
		}
		
		if(repetido == 0)
		{
			listaE[tamE] = listaB[i];
			tamE++;
		}
	}
	
	// Ordenar E de menor a mayor con burbuja
	ordenarBurbuja(listaE, tamE);
	
	// Mostrar los tres arreglos
	mostrarArreglo(listaA, 10, "Arreglo A:");
	mostrarArreglo(listaB, 10, "Arreglo B:");
	mostrarArreglo(listaE, tamE, "Arreglo E (A y B juntos, sin repetidos, menor a mayor):");
	
	// Ingresar numero y verificar si esta entre el menor y mayor de E.
	// Como E esta ordenado, el menor es E[0] y el mayor es E[tamE-1].
	printf("\nIngrese un numero a buscar en E: ");
	scanf("%d", &num);
	
	if(num >= listaE[0] && num <= listaE[tamE - 1])
	{
		if(busquedaBinaria(listaE, tamE, num) == 1)
		{
			printf("El numero %d se encuentra en el arreglo E\n", num);
		}
		else
		{
			printf("El numero %d no se encuentra en el arreglo E\n", num);
		}
	}
	else
	{
		printf("El numero %d no esta entre el menor (%d) y el mayor (%d) de E\n",
			   num, listaE[0], listaE[tamE - 1]);
	}
	
	return 0;
}
