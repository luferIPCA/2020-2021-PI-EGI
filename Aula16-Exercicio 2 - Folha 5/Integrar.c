/*
Folha de Exerc�cios 5
Exercicio 2
*/
#include "Integrar.h"
#include "Dados.h"
#include "Dados1.h"
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {

#pragma region UM
	//Reutilizar biblioteca de Garagem
	Carro c1 = { 2021,NULL};
	Carro *c2 = NovoCarro(2020);
	Carro* garagem=NULL;

	garagem = InsereCarroFinal(&c1, garagem);
	garagem = InsereCarroFinal(c2, garagem);


	int xxx = Soma(2, 3);

#pragma endregion

#pragma region DOIS

	Linhas lista;
	lista.head = NULL;		//inicio da Lista
	lista.totLinha = 0;

	Linhas* aux= (Linhas*)malloc(sizeof(Linhas));
	aux->head = NULL;
	aux->totLinha = 0;



	//Ler dados de CSV para mem�ria
	//1� - Criar Biblioteca de gest�o de Lista de M�quinas
	//2� - Usar Biblioteca para gerir uma Lista
	//Linha* head = CarregaDados("Dados.csv", &lista.head);

	//Linha* head;

	lista.head = CarregaDados("Dados.csv", &lista.head);
	MostraListaLinhas(&lista.head);
	double x = CalculaTempoMedio(&lista.head);
	char* str = DiaMelhorOut(&lista.head);
	GravaFicheiro(&lista.head, "Linhas.txt");

#pragma endregion
}