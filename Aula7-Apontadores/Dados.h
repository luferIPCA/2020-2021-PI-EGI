

#ifndef A
#define A 1

#define N 50


typedef struct Pessoa
{
	char nome[N];
	int idade;
	struct Pessoa* proximo;
}Pessoa;

Pessoa* DefineValores(char nome[], int idade);
Pessoa* SetValues(char nome[], int idade);

#endif
