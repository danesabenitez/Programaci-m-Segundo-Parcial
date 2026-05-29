#include <stdio.h>
#include <string.h>

int main()
{
	char cadena[200];
	int largo;
	int i;
	
	printf("Ingrese una cadena: ");
	scanf(" %[^\n]", cadena);
	
	// strlen devuelve la cantidad de caracteres sin contar espacios vacios
	largo = strlen(cadena);
	
	printf("%s tiene %d letras.\n", cadena, largo);
	
	// Imprimir al reves recorriendo desde el ultimo caracter hasta el primero
	printf("%s escrita al reves es:  ", cadena);
	for(i = largo - 1; i >= 0; i--)
	{
		printf("%c", cadena[i]);
	}
	printf("\n");
	
	return 0;
}
