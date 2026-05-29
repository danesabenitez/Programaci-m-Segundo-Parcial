#include <stdio.h>
#include <string.h>
#define MAX 50
// Definicion de la estructura cliente
struct Cliente{
	int nroCliente;
	char tipo;
	char nombre[50];
	char celular[20];
};
// Ordena el arreglo de clientes por nroCliente de menor a mayor (metodo burbuja)
void ordenarPorNro(struct Cliente clientes[], int tam){
	int i, j;
	struct Cliente aux;
	
	for(i = 0; i < tam - 1; i++){
		for(j = 0; j < tam - i - 1; j++){
			if(clientes[j].nroCliente > clientes[j+1].nroCliente){
				aux = clientes[j];
				clientes[j] = clientes[j+1];
				clientes[j+1] = aux;
			}
		}
	}
}
// Muestra el listado con el formato de tabla
void mostrarListado(struct Cliente clientes[], int tam){
	int i;
	int totalE = 0, totalP = 0;
	
	printf("\n%-15s %-15s %-20s %-15s\n",
		   "Nro.Cliente", "Tipo-Cliente", "Nombre", "Nro. Contacto");
	printf("---------------------------------------------------------------\n");
	
	for(i = 0; i < tam; i++){
		printf("%-15d %-15c %-20s %-15s\n",
			   clientes[i].nroCliente,
			   clientes[i].tipo,
			   clientes[i].nombre,
			   clientes[i].celular);
		
		if(clientes[i].tipo == 'E') totalE++;
		else                        totalP++;
	}
	
	printf("---------------------------------------------------------------\n");
	printf("Total de Clientes: %d\n", tam);
	printf("Total de Clientes Tipo E: %d\n", totalE);
	printf("Total de Clientes Tipo P: %d\n", totalP);
}
// Busqueda binaria por nro de cliente en arreglo ordenado ascendente
int busquedaBinaria(struct Cliente clientes[], int tam, int nroBuscado)
{
	int inicio = 0;
	int final = tam - 1;
	int medio;
	
	while(inicio <= final)
	{
		medio = (inicio + final) / 2;
		
		if(clientes[medio].nroCliente == nroBuscado)
		{
			return medio;
		}
		else if(nroBuscado < clientes[medio].nroCliente)
		{
			final = medio - 1;
		}
		else
		{
			inicio = medio + 1;
		}
	}
	
	return -1;
}

int main()
{
	struct Cliente clientes[MAX];
	struct Cliente tipoE[MAX];
	struct Cliente tipoP[MAX];
	
	int tam = 0;
	int tamE = 0, tamP = 0;
	int i;
	int nroBuscado, resultado;
	// Pedir cantidad de clientes
	do
	{
		printf("Cuantos clientes desea cargar? (1 a %d): ", MAX);
		scanf("%d", &tam);
	} while(tam < 1 || tam > MAX);
	// Cargar el arreglo
	for(i = 0; i < tam; i++)
	{
		printf("\n--- Cliente %d ---\n", i + 1);
		
		printf("Nro de Cliente: ");
		scanf("%d", &clientes[i].nroCliente);
		
		// Validar que el tipo sea E o P
		do
		{
			printf("Tipo de Cliente (E/P): ");
			scanf(" %c", &clientes[i].tipo);
			clientes[i].tipo = clientes[i].tipo;
		} while(clientes[i].tipo != 'E' && clientes[i].tipo != 'P');
		
		printf("Nombre: ");
		scanf(" %[^\n]", clientes[i].nombre);
		
		printf("Nro de Celular: ");
		scanf(" %[^\n]", clientes[i].celular);
	}
	// Ordenar por nro de cliente ascendente
	ordenarPorNro(clientes, tam);
	// Mostrar listado ordenado
	printf("\nListado de Clientes\n");
	mostrarListado(clientes, tam);
	// Busqueda binaria por nro de cliente
	printf("\nIngrese el nro de cliente a buscar: ");
	scanf("%d", &nroBuscado);
	
	resultado = busquedaBinaria(clientes, tam, nroBuscado);
	
	if(resultado != -1)
	{
		printf("Cliente encontrado:\n");
		printf("Nro: %d | Tipo: %c | Nombre: %s | Celular: %s\n",
			   clientes[resultado].nroCliente,
			   clientes[resultado].tipo,
			   clientes[resultado].nombre,
			   clientes[resultado].celular);
	}
	else
	{
		printf("No se encontro un cliente con el nro %d\n", nroBuscado);
	}
	// Separar en arreglo E y arreglo P
	for(i = 0; i < tam; i++)
	{
		if(clientes[i].tipo == 'E')
		{
			tipoE[tamE] = clientes[i];
			tamE++;
		}
		else
		{
			tipoP[tamP] = clientes[i];
			tamP++;
		}
	}
	// Mostrar arreglo tipo E
	printf("\n--- Clientes Tipo E (Empresa) ---\n");
	if(tamE == 0)
		printf("No hay clientes tipo E\n");
	else
		mostrarListado(tipoE, tamE);
	// Mostrar arreglo tipo P
	printf("\n--- Clientes Tipo P (Particular) ---\n");
	if(tamP == 0)
		printf("No hay clientes tipo P\n");
	else
		mostrarListado(tipoP, tamP);
	
	return 0;
}
