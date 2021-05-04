#include <stdio.h>
#include "Funcoes.h"

int x = 10;

/// <summary>
/// Função Recursiva
/// </summary>
/// <param name="y"></param>
/// <returns></returns>
int Aux(int y) {
	static int f = 0;
	if (y > 0) {
		f += y;
		//y++;
		x++;
		y--;
		return Aux(y);
	}	
	else
		return(f);
}


typedef struct Cliente {
	int num;
	char nome[20];
	Cliente* prox;
}Cliente ;


typedef struct ListaCliente {
	struct Cliente p[20];
	struct Cliente *cli;
}ListaCliente;


Cliente* InsereCliente(Cliente *c, Cliente* head) {
	if (head == NULL)
	{
		head = c;
	}
	else
	{
		Cliente* aux = head;
		while (aux->prox != NULL) aux = aux->prox;
		aux->prox = c;
	}
	return head;
}

int GravaFicheiro(char nome[], Cliente* h) {
	if (h == NULL) return -1;
	Cliente* aux = h;

	FILE* fp = fopen(nome, "w");
	if (fp == NULL) return -2;
	int n = 0;
	while (aux != NULL) {
		fprintf("%d;%s;%d", aux->num, aux->nome,n);
		aux = aux->prox;
		n++;
	}
	fclose(fp);
	free(fp);
}

int main() {

	//extern int x;

	int aux = Soma(12, 13);

	printf("%d\n", x);

	int x1 = Aux(3);

	printf("X=%d - Y=%d", x, Aux(12));


	//Cliente c1;
	//c1.num = 1;
	//c1.prox = NULL;

	//
	//ListaCliente lc;
	////lc.p[0] = c1;
	////lc.cli = &c1;
	//lc.cli = InsereCliente(&c1, lc.cli);

	//Cliente c2;
	//c2.num = 2;
	////lc.p[1] = c2;
	////lc.cli->prox = &c2;
	//lc.cli = InsereCliente(&c2, lc.cli);


}


