
/*
*/

#include <stdio.h>
#include "Func.h"

int main() {

	Carro c;
	Carro* ptr;
	
	c.ano = 2020;
	ptr = &c;
	(*ptr).ano = 2021;
	strcpy((*ptr).matricula, "00-00-00");
	ptr->ano = 2021;

	int v = 10;
	int y;

	int* p = NULL;
	p = &y;								//p fica com o valor do endereço de y, ie, p aponta para y
	*p = v;								//dentro de p o valor de v=10;
	printf("Valor apontado por p: %d - %d\n", *p, y);

	v = 10;

	int aux;

	aux = AlteraValor(v);

	AlteraValorII(&v);

}

int AlteraValor(int x)
{
	x++;
	return x;
}

void AlteraValorII(int* x)
{
	(*x)++;
}
