/*
*   Versão 1:
	Chave criptográfica simples

	Versão 2:
		Testar Hashing de Ficheiros (MD5)
*/

#include "Funcoes.h"
#include <stdio.h>


#define FILENAMESIZE 20

int main() {
	char fname[FILENAMESIZE];

	printf("Enter Filename: ");
	gets(fname);
	int aux = Encript(fname);
	if (aux==1)
		printf("\Ficheiro %s Encriptado com Sucesso !\n", fname);
	getch();

	aux = Decrypt(fname);
	if (aux == 1)
		printf("\Ficheiro %s Desencriptado com Sucesso!\n", fname);
	getch();



	aux = Encript2(fname);
	if (aux == 1)
		printf("\Ficheiro II %s Encriptado com Sucesso !\n", fname);
	getch();

	aux = Encript2(fname);
	if (aux == 1)
		printf("\Ficheiro II %s Desencriptado com Sucesso !\n", fname);
	getch();


}