/*****************************************************************//**
 * \file   Func.c
 * \brief  Implementação de funções que gerem uma conta bancária
 * 
 * \author lufer
 * \date   March 2021
 *********************************************************************/

#include <stdio.h>
#include "Def.h"


/// <summary>
/// COMPLETAR!!!!
/// </summary>
/// <param name="valor"></param>
/// <param name="c"></param>
/// <returns></returns>
bool LevantaValor(double valor, ContaBancaria* c) {
	if (valor <= 0)
		return FALSE;
	return TRUE;
}

/// <summary>
/// Cria uma nova conta bancária
/// </summary>
/// <param name="saldo">Saldo inicial</param>
/// <returns>Nova conta bancária</returns>
ContaBancaria *CriaConta(double saldo) {
	static int numeroConta = 0;
	ContaBancaria* aux = (ContaBancaria*)calloc(sizeof(ContaBancaria));
	if (aux != NULL) {
		aux->numero = numeroConta++;
		aux->saldo = saldo;
		aux->seguinte = NULL;
	}
	return aux;
}

/// <summary>
/// Insere nova conta bancária no final das existentes
/// </summary>
/// <param name="nova"></param>
/// <param name="banco"></param>
/// <returns></returns>
bool InsereContaNoFim(ContaBancaria* nova, ContaBancaria* banco) {
	if (banco == NULL)
	{
		banco = nova;
		return TRUE;
	}
	else //Insere no fim
	{
		ContaBancaria* aux = banco;
		while (aux->seguinte != NULL) {
			aux = aux->seguinte;
		}
		aux->seguinte = nova;
		return TRUE;
	}
	//Se conta já existe, return FALSE;
}

/// <summary>
/// Apresenta todas as contas bancárias existentes
/// </summary>
/// <param name="b"></param>
/// <returns></returns>
bool todasContas(ContaBancaria* b) {
	ContaBancaria* aux = b;
	while (aux) {
		mostraConta(*aux);
		aux = aux->seguinte;
	}
}

/// <summary>
/// Apresenta um determinada comta bancária
/// </summary>
/// <param name="c"></param>
void mostraConta(ContaBancaria c) {
	printf("Numero:%d\n", c.numero);
	printf("Saldo: %0.2f\n", c.saldo);
}
