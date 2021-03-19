#include "Dados.h"
#include <stdio.h>

Pessoa* DefineValores(char nome[], int idade) {
	Pessoa* aux;
	aux = (Pessoa*)calloc(sizeof(Pessoa));			//cria uma struct e aux aponta para ela!
	if (aux != NULL) {								//se consegiui criar a memória
		aux->idade = idade;
		strcpy(aux->nome, nome);
	}
	return aux;										//devolve o endereço da memoria criada
}


Pessoa* SetValues(char nome[], int idade) {
	Pessoa* aux = (Pessoa*)malloc(sizeof(Pessoa));
	if (aux != NULL) {
		aux->idade = idade;
		strcpy(aux->nome, nome);
		aux->proximo = NULL;
	}
	return aux;
}