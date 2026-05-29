#include <stdio.h>
// Procedimiento que ordena un arreglo de mayor a menor usando seleccion directa.
// Recibe el arreglo y su tamanio. Modifica el arreglo original (trabaja por referencia).
void ordenarMayorMenor(int arreglo[], int tam)
{
	int i, j, aux;
	
	// Por cada posicion i, busca el mayor elemento en el resto del arreglo (j)
	for(i = 0; i < tam - 1; i++)
	{
		for(j = i + 1; j < tam; j++)
		{
			// Si el elemento de adelante es mayor, los intercambia
			if(arreglo[i] < arreglo[j])
			{
				aux = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = aux;
			}
		}
	}
}
// Funcion de busqueda binaria adaptada para arreglo ordenado de MAYOR a MENOR.
// Devuelve 1 si encuentra el numero, 0 si no lo encuentra.
int busquedaBinaria(int arreglo[], int tam, int num)
{
	int inicio = 0;
	int final = tam - 1;
	int medio;
	
	while(inicio <= final)
	{
		// Calcula el indice del elemento central
		medio = (inicio + final) / 2;
		
		if(arreglo[medio] == num)
		{
			// Encontro el numero
			return 1;
		}
		else if(num > arreglo[medio])
		{
			// Como el arreglo es mayor a menor, si el buscado es mayor
			// entonces esta en la mitad IZQUIERDA (indices menores)
			final = medio - 1;
		}
		else
		{
			// Si el buscado es menor, esta en la mitad DERECHA (indices mayores)
			inicio = medio + 1;
		}
	}
	// No encontro el numero
	return 0;
}
// Procedimiento para que se muestre todos los elementos de un arreglo en una sola linea.
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
	// 1. Arreglo A cargado en etapa de declaracion
	int listaA[10] = {2, 4, 3, 1, 5, 6, 8, 7, 9, 10};
	// 2. Arreglo B se carga por teclado. C guarda la suma. D tiene hasta 20 elementos (A+B juntos).
	int listaB[10];
	int listaC[10];
	int listaD[20];
	
	int i, j;
	int num;
	int tamD = 0;   // Contador de cuantos elementos validos tiene D
	int repetido;
	// 2. Cargar arreglo B por teclado
	printf("Ingrese 10 numeros:\n");
	for(i = 0; i < 10; i++)
	{
		printf("Numero %d: ", i + 1);
		scanf("%d", &listaB[i]);
	}
	
	// Mostrar A y B antes de ordenar, para que se vean los valores originales
	printf("\nArreglo A (original):\n");
	mostrarArreglo(listaA, 10);
	
	printf("\nArreglo B (original):\n");
	mostrarArreglo(listaB, 10);
	// 3. Generar arreglo C con la suma posicion a posicion de A y B.
	// Se hace ANTES de ordenar A y B para que C refleje los valores originales.
	for(i = 0; i < 10; i++)
	{
		listaC[i] = listaA[i] + listaB[i];
	}
	// 4. Ordenar A y B de mayor a menor
	ordenarMayorMenor(listaA, 10);
	ordenarMayorMenor(listaB, 10);
	// 5. Armar arreglo D con los elementos de A y B juntos, sin repetidos.
	//    Primero se agregan los de A:
	for(i = 0; i < 10; i++)
	{
		repetido = 0;
		
		//	Revisar si el elemento ya esta en D
		for(j = 0; j < tamD; j++)
		{
			if(listaD[j] == listaA[i])
			{
				repetido = 1;
			}
		}
		//	Solo se agrega si no es repetido
		if(repetido == 0)
		{
			listaD[tamD] = listaA[i];
			tamD++;
		}
	}
	//	Se agregan los de B, con el mismo control de repetidos:
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
	// Ordenar D de mayor a menor una vez que tiene todos sus elementos.
	// Se usa tamD (no 10) porque D puede tener menos de 20 elementos.
	ordenarMayorMenor(listaD, tamD);
	// 6. Busqueda binaria en D
	printf("\nIngrese un numero a buscar en D: ");
	scanf("%d", &num);
	
	// busquedaBinaria devuelve 1 si lo encontro, 0 si no
	if(busquedaBinaria(listaD, tamD, num) == 1)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
	// 7. Mostrar todos los arreglos
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
