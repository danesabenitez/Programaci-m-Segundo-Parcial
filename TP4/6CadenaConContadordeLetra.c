#include <stdio.h>
#include <string.h>

int main()
{
	char frase[200];
	char letra;
	int i = 0;
	int contador = 0;
	
	// Leer la frase completa (con espacios)
	printf("Ingrese una frase: ");
	scanf(" %[^\n]", frase);
	
	// Leer la letra a buscar
	printf("Ingrese una letra: ");
	scanf(" %c", &letra);
	
	// Recorrer la frase
	while(frase[i] != '\0')
	{
		if(frase[i] == letra)
		{
			contador++;
		}
		i++;
	}
	
	printf("La letra '%c' aparece %d veces en la frase\n", letra, contador);
	
	return 0;
}
