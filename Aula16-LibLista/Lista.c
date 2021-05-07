/*****************************************************************//**
 * \file   Lista.c
 * \brief  Listas Ligadas Simples
 * 
 * \author lufer
 * \date   March 2021
 *********************************************************************/
#include "Dados.h"
#include <stdio.h>

/// <summary>
/// 
/// </summary>
/// <param name="ano"></param>
/// <returns></returns>
Carro* NovoCarro(int ano) {
	Carro* aux;
	aux = (Carro*)calloc(sizeof(Carro));
	aux->ano = ano;
	return aux;
}

/// <summary>
/// 
/// </summary>
/// <param name="novo"></param>
/// <param name="inicio"></param>
/// <returns></returns>
Carro* InsereCarroFinal(Carro* novo, Carro* inicio) {

	if (inicio == NULL)	//é o 1º carrro
		inicio = novo;
	else
	{
		//coloco-me no fim da lista
		Carro* aux = inicio;
		while (aux->seg != NULL) aux = aux->seg;
		//anexo o novo carro
		aux->seg = novo;
	}

	return inicio;

}
/// <summary>
/// 
/// </summary>
/// <param name="inicio"></param>
void MostraLista(Carro* inicio) {
	Carro* corrente = inicio;
	while (corrente != NULL) {
		printf("Ano: %d\n", corrente->ano);
		corrente = corrente->seg;
	}
}

/// <summary>
/// Supor que um carro é identifcado pelo ano
/// </summary>
/// <param name="ano"></param>
/// <returns></returns>
Carro* CarroSaiGaragem(int ano, Carro *inicio) {
	Carro* aux = inicio;
	//procurar carro
	while (aux->ano != ano) aux = aux->seg;

	if (aux == inicio) { //remover o inicio da lista
		inicio = aux->seg;
		free(aux);
		return inicio;
	}
	else {
		//TPC
	}

}

//Ordenar
//Remover
//Contar
//Procurar
