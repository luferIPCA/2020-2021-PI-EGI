/*
Folha de Exercicios 5
Exercico 2
2)	Uma empresa possui uma máquina XPTO que exporta o seguinte conjunto de dados

Data	in	out	duração
28/04/2021	13	17	12
27/04/2021	10	13	10
26/04/2021	5	2	24
25/04/2021	18	12	10
24/04/2021	7	19	30
23/04/2021	0	3	12
22/04/2021	3	17	15
21/04/2021	18	25	16

*/
#pragma once
#include <stdio.h>
#include <stdbool.h>
#pragma warning (disable: 4996)

//a) Definir uma estrutura de dados capaz de armazenar todos os dados do ficheiro

typedef struct Linha {
	char data[10];
	int in;
	int out;
	int duracao;
	struct Linha* next;		//para manter a lista de linha
}Linha;

//H1
//Linha* head;

//H2
typedef struct Linhas {
	Linha* head;
	int totLinha;
}Linhas;


Linha* CarregaDados(char fileName[], Linha *ptr);
Linha* NovaLinha(char data[], int a, int b, int c);
Linha* InsereLinhaLista(Linha* novo, Linha* inicio);
void MostraListaLinhas(Linha* inicio);
bool GravaFicheiro(Linha* inicio, char fileName[]);
double CalculaTempoMedio(Linha* inicio);
char* DiaMelhorOut(Linha* inicio);
