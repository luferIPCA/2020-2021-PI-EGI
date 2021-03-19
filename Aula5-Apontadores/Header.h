//h1
//#pragma once
//h2
#ifndef F
#define F

void showArray(int v[], int n);
void showArrayII(int* v, int n);
int f();
int* getArray(int size);
//Analisar erro!!!
int get(int* ptr);

void changeValue(int x);

int changeValueII(int x);

void changeValueIII(int* p);

int changeValueIV(const int* p);

void mostraArray(int v[], int size);

void mostraArrayII(int* v, int size);

int whatItDoes();

typedef struct Carro
{
	char matricula[8];
	int ano;

}Carro;
#endif
