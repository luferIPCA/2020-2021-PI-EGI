/*****************************************************************//**
 * \file   Basico.c
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

int main8(int argc, char *argv[]) {
	FILE* fp;
	char s1[20], s2[20];
	int v;
	char nomeFicheiro[20]="";

#pragma region ARGS

	printf("ARGS: %d\n", argc);
	int args = argc;
	while (args > 0) {
		printf("ARGS: %d - %s\n", (argc - args), argv[argc-args]);
		args--;
	}


	if (argc > 1) {
		strcpy(nomeFicheiro, argv[1]);	//segunda string no comando é o nome do ficheiro
	}
	else
		strcpy(nomeFicheiro, "Teste");

#pragma endregion

#pragma region scanf

#pragma region UM

	//Criar Ficheiro
	fp = fopen(nomeFicheiro, "w");
	//fp = fopen("Teste", "w");
	fprintf(fp, "Ola %d Oli", 12);
	fclose(fp);

	//Ler ficheiro
	fp = fopen(nomeFicheiro, "r");
	//fp = fopen("Teste", "r");
	
	//fscanf(fp, "%s", s1);				//lê 1ª string = "Ola"
	//fscanf(fp, "%s%*s", s1);			//lê apenas a 1ª string = Ola
	//fscanf(fp, "%*s %d", &v);			//apenas lê o numérico	
	//fscanf(fp, "%*s %d %s", &v, s1);	//ignora a 1ª string, lê numérico e última string
	int ok=fscanf(fp, "%s %d %s", s2, &v, s1); //lê os três valores
	if (ok>0)
		printf("%s - %d - %s", s1, v, s2);

	//fechar ficheiro
	fclose(fp);
#pragma endregion

#pragma region Dois
	//%*s ignora input até espaço ou \n
	//%*d ignora digitos até espaço ou \n
	//(%*[^,]) - ignora tudo, excepto o "," 

	char s3[20];
	char s4[20];
	//inicialização das variáveis
	strcpy(s3, "");
	strcpy(s4, "");
	v = -1;

	//Cria ficheiro "csv"e grava conteúdo
	FILE *fp1 = fopen("Teste2.csv", "w");
	fprintf(fp1, "Ola,%d,Oli", 1228);
	fclose(fp1);

	//Abre ficheiro e lê conteúdo
	fp1 = fopen("Teste2.csv", "r");
	if (!fp1) return;
	ok = fscanf(fp1, "%[^,\n],%d,%s", s3, &v, s4);
	//ok = fscanf(fp1, "%*[^,\n], %d, %s", &v, s4);	//Expressões Regulares..ignora a 1ª string
	
	if(ok>0)
			printf("%s - %d - %s", s3, v, s4);

	fclose(fp1);
#pragma endregion

#pragma endregion

#pragma region fgets
	//Ler strings formatadas e fazer parsing
	//Algoritmo
		//Enquanto não atingir o fim do ficheiro
		//Ler linha (fgets)
		//Analisar tokens de cada linha (strtok)

	FILE* fp2;
	char row[MAXCHAR];

	fp2 = fopen("Recursos.csv", "r");
	if (fp2 != NULL) {
		while (feof(fp2) != true)
		{
			fgets(row, MAXCHAR, fp2);
			printf("Row: %s", row);
		}
	}
	fclose(fp2);


	//Analizar tokens de cada linha - Tokenizar

	//EXEMPLO 1
	char string[50] = "Viva! O Porto lá se foi...";
	// Extrair o 1º token
	char* token = strtok(string, " ");	//separador é o espaço " "
	//Encontrar restantes tokens
	while (token != NULL) {
		printf(" %s\n", token); //mostra token encontrado
		token = strtok(NULL, " ");
	}

	//EXEMPLO 2
	//char* token;
	fp2 = fopen("Recursos.csv", "r");
	if (fp2 != NULL) {
		while (feof(fp2) != true)
		{
			fgets(row, MAXCHAR, fp2);
			printf("Row: %s", row);
			token = strtok(row, ",");

			//Array auxiliar para guardar todos os tokens
			char* tokens[10];
			int i = 0;

			while (token != NULL)
			{
				tokens[i++] = token;
				printf("Token: %s\n", token);
				token = strtok(NULL, ",");
			}
			//Mostra tokens
			for (int j = 0; j < i; j++) {
				printf("Token: %s\n", tokens[j]);
			}
		}
	}
	fclose(fp2);
	return 0;

	//EXERCICIO
	//Ficheiro com Nome;Idade;Telefone
	//a) Carregar dados para array
	//b) Carregar dados para Lista
#pragma endregion

}
