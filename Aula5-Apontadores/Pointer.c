/*
* lufer
* P-EGI
* Apontadores em C
* Aritmetica de apontadores
*/

#include <stdio.h>
#include <locale.h>	// ASCII SET
#include "Header.h"

int main() {
	setlocale(LC_ALL, "Portuguese");

#pragma region UM

	int x = 99;
	int* p1;
	p1 = &x;
	printf("Valor em p1 : %d\n", *p1);
	printf("Endereço de Memória apontado por p1: %p\n", p1);

	int a = 25;
	int* b;
	b = &a;
	printf("\n Address of a = %u", &a);
	printf("\n Address of a = %u", b);
	printf("\n Address of b = %u", &b);
	printf("\n Value of b = %u", b);
	printf("\n Value of a = %d", a);
	printf("\n Value of a = %d", *(&a));
	printf("\n Value of a = %d", *b);

	f();
	//get(&a)
	int* c = getArray(10);
	showArray(c, 10);
	free(c);


#pragma endregion

#pragma region II

	x = 20;
	int y = 2 * x;

	int valores[] = { 1,2,3,4,5 };

	printf("X: %d\n", x);
	printf("Y: %d\n", y);
	printf("Endereço de memoria de X: %p\n", &x);
	printf("Endereço de memoria de Y: %p\n", &y);

	int* p;

	printf("Size (int *p): %d - Size (int x): %d\n", sizeof(p), sizeof(x));
	//p vai apontar para x
	p = &x;
	printf("Endereço de P: %p\n", &p);
	printf("Valor de p: %p\n", p);
	printf("Valor apontado por p: %d\n", *p);

	int* q;
	q = p;		//ambos apontam para X
	printf("Valor apontado por q: %d\n", *q);

	if (*p == 20) {
		//...
	}

	//
	(*p)++;		//x = x+1
	*p = *p + 1;

	*(p++);		//p fica a apontar para outra posição de memória
	printf("Valor apontado por p: %d\n", *p);


	changeValue(x);
	printf("Valor de X: %d\n", x);

	x = changeValueII(x);
	printf("Valor de X: %d\n", x);

	changeValueIII(&x);
	printf("Valor de X: %d\n", x);

	x = changeValueIV(&x);
	printf("Valor de X: %d\n", x);

	for (int i = 0; i < 5; i++) {
		printf("%d\n", valores[i]);
	}

	mostraArray(valores, 5);
	mostraArrayII(valores, 5);

#pragma endregion


	a = whatItDoes();
	printf("a= %d\n", a);

	getch();
	return 0;
}

