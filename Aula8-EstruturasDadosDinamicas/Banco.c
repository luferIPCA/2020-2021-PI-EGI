/*****************************************************************//**
 * \file   Banco.c
 * \brief  Estrutura de Dados dinâmicas
 * P- EGI
 * \author lufer
 * \date   March 2021
 *********************************************************************/

#include <stdio.h>
#include "Def.h"

int main() {


	ContaBancaria c1;
	c1.saldo = 200;
	c1.numero = 1;
	c1.seguinte = NULL;

	ContaBancaria c2;
	c2.numero = 2;
	c2.saldo = 1500;
	c2.seguinte = NULL;

	c1.seguinte = &c2;
	
	ContaBancaria* aux;
	aux = &c1;

	printf("Aux.Saldo= %0.2f\n", aux->saldo);
	//h1
	printf("Aux.Saldo = %0.2f\n", aux->seguinte->saldo);
	//h2
	aux = aux->seguinte;
	printf("Aux.Saldo= %.2f\n", aux->saldo);

	//Listas Ligadas Simples em C

	ContaBancaria* banco;

	banco = CriaConta(200);
	banco->seguinte = CriaConta(2000);
	InsereContaNoFim(&c1, banco);
	todasContas(banco);

	getche();
}



