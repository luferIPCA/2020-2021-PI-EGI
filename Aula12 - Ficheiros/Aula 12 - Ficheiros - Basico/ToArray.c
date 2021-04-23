/*****************************************************************//**
 * \file   ToArray.c
 * \brief  Tratamento de ficheiros de texto formatados
 *		   fscanf e fprintf
 *
 * 	(%*s) ignora input até espaço ou \n
 *	(%*d) ignora digitos até espaço ou \n
 * https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm
 *
 * \author lufer
 * \date   April 2021
 *********************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define MAXCHAR 100

typedef struct Celula {
	int idade;
	char nome[MAXCHAR];
	char telefone[9];
}Celula;

int main(int argc, char* argv[]) {
	FILE* fp;
	char s1[MAXCHAR], s2[MAXCHAR];
	int v;
	char nomeFicheiro[20] = "";

	Celula valores[100];
	int totValores = 0;

#pragma region ToArray
	//inicialização das variáveis
	strcpy(s1, "");
	strcpy(s2, "");
	v = -1;

	//Cria ficheiro "csv"e grava conteúdo
	FILE* fp1 = fopen("Dados.csv", "w");
	fprintf(fp1, "%s,%d,%s\n", "Antonio",20,"22222222");
	fprintf(fp1, "%s,%d,%s\n", "Rosalina",34,"11111111");
	fprintf(fp1, "%s,%d,%s", "Augusta",47,"33333333");
	fclose(fp1);

	//Abre ficheiro e lê conteúdo
	fp1 = fopen("Dados.csv", "r");
	if (!fp1) return;
	while (fscanf(fp1, "%[^,\n],%d,%s\n", s1, &v, s2) != EOF) {
		strcpy(valores[totValores].nome,s1); 
		strcpy(valores[totValores].telefone,s2);
		valores[totValores++].idade = v;
	}
	fclose(fp1);
#pragma endregion


	return 0;

	//EXERCICIO
	//Ficheiro com Nome;Idade;Telefone
	//a) Carregar dados para array
	//b) Carregar dados para Lista

}
