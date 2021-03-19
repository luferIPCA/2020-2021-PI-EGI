#pragma once

typedef struct Conta {
	int numero;
	double saldo;
	struct Conta* seguinte;
}ContaBancaria;

//#define FALSE 0
//#define TRUE 1

typedef enum boolean { FALSE, TRUE } bool;
//typedef enum boolean bool;

typedef enum Dias { SEG, TER, QUAR, QUI, SEX, SAB, DOM } Dias;

#pragma region Funções
ContaBancaria* CriaConta(double saldo);
bool InsereContaNoFim(ContaBancaria* nova, ContaBancaria* banco);
void mostraConta(ContaBancaria c);
bool todasContas(ContaBancaria* b);
#pragma endregion
