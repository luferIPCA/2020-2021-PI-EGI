
/**
 * author: lufer
 * P - EGI
 * manipulação de apontadores em estruturas estáticas e dinâmicas.
 */

#include <stdio.h>
#include "Dados.h"



int main(){

#pragma region Um

	Pessoa p;
	p.idade = 12;
	strcpy(p.nome, "Benfica");
	p.proximo = NULL;

	Pessoa q;
	q.idade = 18;
	strcpy(q.nome, "Braga");
	p.proximo = NULL;
	q.proximo = NULL;

	p.proximo = &q;
	printf("Nome: %s\n", p.proximo->nome);

#pragma endregion

#pragma region Dois

	Pessoa* ptr, *ptr2;

	ptr = &p;

	//(TipoDados*)calloc(TAMANHO)
	int* pAux = (int*)calloc(sizeof(int) * 10);

	ptr->proximo = (Pessoa*)calloc(sizeof(Pessoa));

	ptr->proximo->idade = 13;
	strcpy(ptr->proximo->nome, "Porto");

	ptr2 = SetValues("ola", 12);

	printf("Nome: %s\n", ptr->nome);
	printf("Nome: %s\n", ptr->proximo->nome);

#pragma endregion

#pragma region Tres

	Pessoa turma[N];
	turma[0] = p;
	turma[1] = q;
	turma[2] = *ptr;

	Pessoa *turma2[N];

	for (int i = 0; i < N; i++) {
		turma2[i] = NULL;
	}
	turma2[0] = &q;

	for (int i = 0; i < N; i++) {
		if (turma2[i] != NULL) {
			printf("Nome= %s\n",turma2[i]->nome);
		}
	}

	//Analisar o comportamento das seguintes instruções
	//free(ptr);
	//free(ptr2);
	//free(turma2);
#pragma endregion

#pragma region Quatro
	////Array de apontadores para structs
	//Pessoa* turma;
	//turma = (Pessoa*)calloc(M * sizeof(Pessoa));	//criar espaço para M Pessoas

	////Array de stucts
	//Pessoa turmaEGI[M];							//array de M Pessoas
	//turmaEGI[0].idade = 12;
	//strcopy(turmaEGI[0].nome, "Maria");


	Pessoa *aux = DefineValores("ola", 12);

	printf("%d", aux->idade);

	Pessoa* outra = DefineValores("outra", 13);

	aux->proximo = outra;


	//free(aux);										//liberta a memoria alocada!


	Pessoa nova;
	nova.idade = 23;
	strcpy(nova.nome, "Benfica");
	nova.proximo = &p;

	printf("Nome Nova = %s\n", nova.nome);
	printf("Nome P1 = %s\n", (nova.proximo)->nome);
#pragma endregion

	getch();

}
