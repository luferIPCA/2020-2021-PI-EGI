/*****************************************************************//**
 * \file   Basico.c
 * \brief  Tratamento de ficheiros de texto formatados
 *		   fscanf e fprintf
 * 
 * 	(%*s) ignora input at� espa�o ou \n
 *	(%*d) ignora digitos at� espa�o ou \n
 * https://www.tutorialspoint.com/c_standard_library/c_function_scanf.htm
 * 
 * \author lufer
 * \date   April 2021
 *********************************************************************/

#include <stdio.h>
#include <stdbool.h>

#define MAXCHAR 100

int main() {
	FILE* fp;
	char s1[20], s2[20];
	int v;

#pragma region scanf

#pragma region UM

	//Criar Ficheiro
	fp = fopen("Teste", "w");
	fprintf(fp, "Ola %d Oli", 12);
	fclose(fp);

	//Ler ficheiro
	fp = fopen("Teste", "r");
	
	//fscanf(fp, "%s", s1);				//l� 1� string = "Ola"
	//fscanf(fp, "%s%*s", s1);			//l� apenas a 1� string = Ola
	//fscanf(fp, "%*s %d", &v);			//apenas o num�rico	
	//fscanf(fp, "%*s %d %s", &v, s1);	//num�rico e string
	int ok=fscanf(fp, "%s %d %s", s2, &v, s1); //l� os tr�s valores
	
	if (ok>0)
		printf("%s - %d - %s", s1, v, s2);

	//fechar ficheiro
	fclose(fp);
#pragma endregion

#pragma region Dois
	//%*s ignora input at� espa�o ou \n
	//%*d ignora digitos at� espa�o ou \n
	//(%*[^,]) - ignora tudo, excepto o "," 

	char s3[20];
	char s4[20];
	//inicializa��o das vari�veis
	strcpy(s3, "");
	strcpy(s4, "");
	v = -1;

	//Cria Ficheiro e grava conte�do
	FILE *fp1 = fopen("Teste2.csv", "w");
	fprintf(fp1, "Ola,%d,Oli", 12);
	fclose(fp1);

	//Abre ficheiro e l� conte�do
	fp1 = fopen("Teste2.csv", "r");
	//ok = fscanf(fp1, "% [^,]%*c %d%*c %s", s3, &v, s4);
	//ok = fscanf(fp1, "%[^,\n]%*[,] %d, %s",s3,&v,s4);
	//ok = fscanf(fp1, "%[^,\n],%d,%s", s3, &v, s4);
	ok = fscanf(fp1, "%*[^,\n], %d, %s", &v, s4);
	
	if(ok>0)
			printf("%s - %d - %s", s3, v, s4);

	fclose(fp1);
#pragma endregion

#pragma endregion

#pragma region fgets
	//Ler strings formatadas e fazer parsing
	//Algoritmo
		//Ler linha (fgets)
		//Analisar tokens de cada linha (strtok)

	FILE* fp2;
	char row[MAXCHAR];

	fp2 = fopen("Registos.csv", "r");
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
	char string[50] = "Viva! O Porto l� se foi...";
	// Extrair o 1� token
	char* token = strtok(string, " ");	//separador � o espa�o " "
	//Encontrar restantes tokens
	while (token != NULL) {
		printf(" %s\n", token); //mostra token encontrado
		token = strtok(NULL, " ");
	}

	//EXEMPLO 2
	//char* token;
	fp2 = fopen("Registos.csv", "r");
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
#pragma endregion

}
