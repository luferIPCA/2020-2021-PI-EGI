/*****************************************************************//**
 * \file   Fabrica.c
 * \brief	Gestão de Linha de Montagem
 *			Definição de Funções
 * 
 * \author lufer
 * \date   April 2021
 *********************************************************************/
#include "Maquina.h"
#include <stdio.h>
#include <stdbool.h>

/// <summary>
/// Aloca espaço em memória para uma nova máquina
/// </summary>
/// <param name="num"></param>
/// <returns></returns>
Maquina* CriaMaquinaNova(int num) {
	Maquina* aux;
	aux = (Maquina*)calloc(sizeof(Maquina));
	aux->num = num;
	return aux;
}

/// <summary>
/// Cria registo para inserir na linha de montagem
/// </summary>
ListaMaquinas* CriaMaquinaLinha(Maquina* nova) {
	ListaMaquinas* aux = (ListaMaquinas*)calloc(sizeof(ListaMaquinas));
	aux->maquina = *nova;
	aux->prox = NULL;
	return aux;
}

/// <summary>
/// Insere uma máquina nova no início da linha de montagem
/// O início da lista resulta alterado
/// Parte-se do principio que a máquina ainda não existe
/// Implementa uma Stack
/// </summary>
/// <param name="h">Inicio da Lista</param>
/// <param name="n">Maquina nova</param>
/// <returns>Inicio da Lista</returns>
ListaMaquinas* InsereNovaInicio(ListaMaquinas* head, Maquina* nova) {
	
	//Se a lista é vazia, cria-se a lista com esta nova maquina
	if (head == NULL) {
		ListaMaquinas* aux = CriaMaquinaLinha(nova);
		head = aux;
	}
	//h!=NULL --- significa que a linha tem mais máquinas...vai inserir no inicio da lista
	else
	{
		//Se já existe a máquina nada é alterado
		if (ExisteMaquina(nova->num, head) == false)	
		{
			ListaMaquinas *aux = CriaMaquinaLinha(nova);
			aux->prox = nova;
			head->prox=nova;
		}
	}
	return head;
}

/// <summary>
/// Mostrar todas as maquinas
/// </summary>
/// <param name="h"></param>
void MostraLinhaMontagem(ListaMaquinas* h) {
	ListaMaquinas* aux = h;
	while (aux != NULL)
	{
		printf("Maquina: %d\n", aux->maquina.num);
		aux = aux->prox;
	}
}

/// <summary>
/// Insere uma máquina nova no fim da linha de montagem
/// O início da lista pode resultar alterado
/// Parte-se do principio que a máquina ainda não existe
/// Implementa uma Queue ou Fila 
/// </summary>
/// <param name="head">Inicio da Lista</param>
/// <param name="nova">Nova Maquina a inserir</param>
/// <returns>Novo Inicio da Lista</returns>
ListaMaquinas* InsereNovaFim(ListaMaquinas* head, Maquina* nova) {
	//Se a lista é vazia, cria-se a lista com esta nova maquina
	if (head == NULL) {
		ListaMaquinas* aux = CriaMaquinaLinha(nova);
		head = aux;
	}
	else
	{
		//Se já existe a máquina, nada é alterado
		if (ExisteMaquina(nova->num, head) == false)
		 {
			ListaMaquinas* aux = head;
			//coloca-se no fim  da lista de máquinas
			while (aux->prox != NULL)
				aux = aux->prox;
			//insere no fim
			ListaMaquinas* auxNova = CriaMaquinaLinha(nova);
			aux->prox = auxNova;
		}
	}
	return head;
}


/// <summary>
/// Insere uma nova máquina ordenado pelo número de máquina
/// O início da lista pode resultar alterado
/// Parte-se do principio que a máquina ainda não existe
/// </summary>
/// <param name="head"></param>
/// <param name="nova"></param>
/// <returns></returns>
ListaMaquinas* InserePorOrdem(ListaMaquinas* head, Maquina* nova){
	if (head == NULL) {
		ListaMaquinas* auxNova = CriaMaquinaLinha(nova);
		head = auxNova;
	}
	else
	{
		//Se já existe a máquina, nada é alterado
		if (ExisteMaquina(nova->num, head) == false)
		{
			//cria novo registo de máquina
			ListaMaquinas* auxNova = CriaMaquinaLinha(nova);
			//Auxiliuares para encontar a posição onde inserir
			ListaMaquinas* aux1 = head;
			ListaMaquinas* aux2 = head;
			while (aux1 != NULL && aux1->maquina.num < nova->num) {
				aux2 = aux1;
				aux1 = aux1->prox;
			}
			//Se porventura tiver que ficar no início, o head é alterado
			if (aux1 == head) {
				auxNova->prox = head;
				head = auxNova;
			}
			else
			{
				if (aux1 == NULL) {			//Insere no fim
					aux2->prox = auxNova;
				}
				//se não inserir entre aux 2 e aux1
				else {
					auxNova->prox = aux1;
					aux2->prox = auxNova;
				}
			}
		}
	}
	return head;
}

/// <summary>
/// Verifica se determinado número de máquina já existe
/// </summary>
/// <param name="numMaquina"></param>
/// <param name="head"></param>
/// <returns></returns>
bool ExisteMaquina(int numMaquina, ListaMaquinas* head) {
	if (head == NULL) return false;
	ListaMaquinas* aux = head;
	while (aux != NULL && aux->maquina.num!= numMaquina) {
		aux = aux->prox;
	}
	//se (aux !==NULL)==true então é porque foi encontrada uma máquina com o número que se procura
	return (aux != NULL);		
}
