
#include "Maquina.h"
#include <stdio.h>

int main(){

#pragma region Basico

	Maquina m1;
	m1.num = 1;

	Maquina m2;
	m2.num = 2;

	Maquina* pt;
	pt = &m1;

	//(*pt).num			//apontado por pt campo "num"
	//ou
	//pt->num
	pt->num = 12;
	pt->num++;

	//m1 a apontar para m2
	m1.prox = &m2;
	printf("%d\n", m1.prox->num);	//escreve valor "num" de m2
	//m2 a apontar para m1
	m2.prox = &m1;
	printf("%d\n", m1.prox->prox->num);	//escreve valor "num" de m1 == m2.prox->num

#pragma endregion


	Maquina* head=NULL;		//marca o ínicio da lista; No inicio a lista está vazia
	//a)
	Maquina* nova = CriaMaquinaNova(12);
	//b)
	//i) Insere o 1º elemento da lista
	/*if (head == NULL) {
		head = nova;
	}*/

	//nova maquina
	nova = CriaMaquinaNova(120);

	//ii) Insere sempre no inicio da lista
	/*if(head != NULL) {
		nova->prox = head;
		head = nova;
	}*/

	head = InsereNovaInicio(head, nova);

	//iii)Insere sempre no final da lista
	//- Procurar o fim da lista
	//Maquina* aux = head;
	//while (aux->prox != NULL)
	//	aux = aux->prox;
	////insere no fim
	//aux->prox = nova;


	head = NULL;
	nova = CriaMaquinaNova(13);
	head = InsereNovaFim(head, nova);
	nova = CriaMaquinaNova(14);
	head = InsereNovaFim(head, nova);
	nova = CriaMaquinaNova(7);
	head = InsereNovaFim(head, nova);
	MostraLinhaMontagem(head);


	head = NULL;
	nova = CriaMaquinaNova(13);
	head = InserePorOrdem(head,nova);
	nova = CriaMaquinaNova(14);
	head = InserePorOrdem(head, nova);
	nova = CriaMaquinaNova(7);
	head = InserePorOrdem(head, nova);
	MostraLinhaMontagem(head);
}


Maquina* CriaMaquinaNova(int num) {
	Maquina* aux;
	aux = (Maquina*)calloc(sizeof(Maquina));
	aux->num = num;
	aux->prox = NULL;
	return aux;
}

/// <summary>
/// 
/// </summary>
/// <param name="h">Inicio da Lista</param>
/// <param name="n">Maquina nova</param>
/// <returns>Inicio da Lista</returns>
Maquina* InsereNovaInicio(Maquina* head, Maquina* nova) {
	if (head == NULL) {
		head = nova;
	}
	else //h!=NULL --- significa que a lista tem mais máquinas...vai inserir no inicio da lista
	{
		nova->prox = head;
		head = nova;
	}
	return head;
}

/// <summary>
/// Mostrar todas as maquinas
/// </summary>
/// <param name="h"></param>
void MostraLinhaMontagem(Maquina* h) {
	Maquina* aux = h;
	while (aux != NULL)
	{
		printf("Maquina %d\n", aux->num);
		aux = aux->prox;
	}
}

/// <summary>
/// 
/// </summary>
/// <param name="head">Inicio da Lista</param>
/// <param name="nova">Nova Maquina a inserir</param>
/// <returns>Novo Inicio da Lista</returns>
Maquina* InsereNovaFim(Maquina* head, Maquina* nova) {
	if (head == NULL) {
		head = nova;
	}
	else {
		Maquina* aux = head;
		while (aux->prox != NULL)
			aux = aux->prox;
		//insere no fim
		aux->prox = nova;
	}
	return head;

	//Stack
	//Fila
	//
}



Maquina* InserePorOrdem(Maquina* head, Maquina* nova){
	if (head == NULL) {
		head = nova;
	}
	else
	{
		Maquina* aux1 = head;
		Maquina* aux2 = head;
		while (aux1->num < nova->num && aux1->prox!=NULL) {
			aux2 = aux1;
			aux1 = aux1->prox;
		}
		if (aux2 == head) {
			aux2->prox = head;
			head = nova;
		}
		else {
			aux2->prox = nova;
			nova->prox = aux1;
		}
	}
	return head;
}
