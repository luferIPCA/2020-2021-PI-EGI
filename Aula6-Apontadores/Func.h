/*
* lufer
* Apontadores em C
* Structs e Apontadores
*/
#pragma once

#ifndef A
#define A 1

typedef struct Carro
{
	char matricula[8];
	int ano;
	
}Carro;

int AlteraValor(int x);
int soma(int x, int y);
void AlteraValorII(int* x);

#endif
