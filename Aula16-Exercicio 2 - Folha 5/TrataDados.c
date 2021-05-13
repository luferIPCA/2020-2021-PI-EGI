/*
Folha de Exercícios 5
Exercicio 2
*/
#include <stdio.h>
#include <stdbool.h>
#include "Dados.h"
#include "Integrar.h"

Linha* CarregaDados(char fileName[], Linha* inicio) {
	FILE* fp;
	Linha aux;		//guarda temporariamente os dados de cada linha do ficheiro

	fp = fopen(fileName, "r");
	if (fp == NULL) return false;
	while (fscanf(fp,"%s\t%d\t%d\t%d", aux.data, &aux.in, &aux.out, &aux.duracao) != EOF) {
		//Cria espaço em memória e coloca lá os dados que vêm do ficheiro
		Linha *nova = NovaLinha(aux.data, aux.in, aux.out, aux.duracao);
		//Insere dados na lista
		inicio = InsereLinhaLista(nova, inicio);
	}
	fclose(fp);
	return inicio;
}


#pragma region GereLista

/// <summary>
/// 
/// </summary>
/// <param name="ano"></param>
/// <returns></returns>
Linha* NovaLinha(char data[], int a, int b, int c) {
	Linha* aux;
	aux = (Linha*)calloc(sizeof(Linha));
	strcpy(aux->data, data);
	aux->duracao = c;
	aux->in = a;
	aux->out = b;
	aux->next = NULL;
	return aux;
}

/// <summary>
/// Insere nova linha no final da lista
/// </summary>
/// <param name="novo"></param>
/// <param name="inicio"></param>
/// <returns></returns>
Linha* InsereLinhaLista(Linha* novo, Linha* inicio) {
	if (inicio == NULL)	//é a 1ª linha
		inicio = novo;
	else
	{
		//coloco-me no fim da lista
		Linha* aux = inicio;
		while (aux && aux->next != NULL) 
			aux = aux->next;
		//anexo o novo carro
		aux->next = novo;
	}
	return inicio;
}

/// <summary>
/// 
/// </summary>
/// <param name="inicio"></param>
void MostraListaLinhas(Linha* inicio) {
	Linha* ptr = inicio;
	while (ptr != NULL) {
		printf("Data: %s - In: %d - Out: %d\ - Duracao: %d\n", ptr->data, ptr->in, ptr->out, ptr->duracao);
		ptr = ptr->next;
	}
}


/// <summary>
/// c)	Calcular o tempo médio que as máquinas gastaram
/// </summary>
/// <param name="inicio"></param>
/// <returns></returns>
double CalculaTempoMedio(Linha* inicio) {
	double tot = 0;
	double soma = 0;

	Linha* aux = inicio;
	while (aux!=NULL) {
		soma += aux->duracao;
		tot++;
		aux = aux->next;
	}
	return (soma / tot);
}

/// <summary>
/// d)	Identificar o dia em que a máquina conseguiu melhor resultado (out)
/// </summary>
/// <param name="inicio"></param>
/// <returns></returns>
char* DiaMelhorOut(Linha* inicio) {
	char diaMaior[10];
	int auxOut =0;
	Linha* ptr = inicio;

	strcpy(diaMaior, "");
	if (inicio == NULL) return diaMaior;
	//Analisa o head da lista
	strcpy(diaMaior, inicio->data);		//valor inicial de data!!!
	auxOut = inicio->out;
	//analisa a restante lista
	ptr = ptr->next;
	while (ptr != NULL) {
		if (auxOut < ptr->out)
		{
			auxOut = ptr->out;
			strcpy(diaMaior, ptr->data);
		}
		ptr = ptr->next;
	}
	return diaMaior;
}

bool GravaFicheiro(Linha* inicio, char fileName[]) {
	FILE* fp;
	Linha* aux = inicio;
	fp = fopen(fileName, "w");
	if (!fp) return false;
	while (aux != NULL) {
		fprintf(fp, "%d - %d - %d - %d\n", aux->data, aux->in, aux->out, aux->duracao);
		aux = aux->next;
	}
	fclose(fp);
	return true;
}

#pragma endregion