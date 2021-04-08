/*****************************************************************//**
 * \file   Varios.c
 * \brief  Manipular ETD Dinâmicas
 *			Inserir
 *			Eliminar
 *			Procurar
 *			Alterar
 *			Preservar (Guardar em ficheiro, por exemplo!)
 * H1: Abordagem com duplicação de código
 * H2: Abordagem com reutilização: definição e chamada de funções
 * \author lufer
 * \date   April 2021
 *********************************************************************/

#include <stdio.h>
#include <stdbool.h>
#pragma warning (disable: 4996)
#define N 50

/// <summary>
/// Estrutura para guardar em ficheiro. Não pode guardar apontadores!
/// </summary>
typedef struct ValorFicheiro {
	int v;
	char nome[N];
}ValorFicheiro, *PtrValorFicheiro;

/// <summary>
/// Estrutura para guardar em memória. Tem apontadores
/// </summary>
typedef struct Valor {
	struct Valor *proximo;
	int v;	
	char nome[N];
}Valor, *PtrValor;

#pragma region MOETODOS_LISTAS

/// <summary>
/// Verifica se existe valor numa lista
/// </summary>
/// <param name="valor"></param>
/// <param name="h"></param>
/// <returns></returns>
bool ExisteLista(int valor, Valor* h) {
	bool encontrou = false;
	if (h != NULL)
	{
		Valor* auxLista = h;
		while (auxLista != NULL) {
			if (auxLista->v == valor) {
				encontrou = true;
				break;
			}
			auxLista = auxLista->proximo;
		}
	}
	return encontrou;
}

/// <summary>
/// Insere valor numa lista ligada simples
/// </summary>
/// <param name="novoValor"></param>
/// <param name="head"></param>
/// <returns></returns>
Valor* InsereInicioLista(Valor *novoValor, Valor* head) {
	novoValor->proximo = head;
	head = novoValor;
	return head;
}

void MostraLista(Valor* head) {
	Valor* aux = head;
	while (aux) {
		printf("Num: %d - Nome: %s\n", aux->v, aux->nome);
		aux = aux->proximo;
	}
}

#pragma region FICHEIROS
/// <summary>
/// Grava Lista em Ficheiro
/// </summary>
/// <param name="fileName"></param>
/// <param name="h"></param>
/// <returns></returns>
bool GravaFicheiro(char fileName[], Valor *h)
{
	FILE *fp = fopen(fileName, "wb");
	if (fp != NULL) {
		Valor* auxLista = h;
		ValorFicheiro auxFile;
		while (auxLista) {
			auxFile.v = auxLista->v;
			strcpy(auxFile.nome, auxLista->nome);
			fwrite(&auxFile, sizeof(ValorFicheiro), 1, fp);
			auxLista = auxLista->proximo;
		}
		fclose(fp);
		return true;
	}
	return false;
}

/// <summary>
/// Le toda a informação do ficheiro para a lista em memória
/// </summary>
/// <param name="fileName"></param>
/// <param name="h"></param>
/// <returns></returns>
Valor* LeFicheiro(char fileName[], Valor *h) {
	Valor* aux;
	ValorFicheiro auxFile;
	FILE* fp = fopen(fileName, "rb");
	if (fp == NULL) return h;
	aux = (Valor*)calloc(1,sizeof(Valor));
	while (fread(&auxFile, sizeof(ValorFicheiro), 1, fp) != NULL) {
		aux->v = auxFile.v;
		strcpy(aux->nome, auxFile.nome);
		h = InsereInicioLista(aux, h);
		aux = (Valor*)calloc(1,sizeof(Valor));
	}
	fclose(fp);
	return h;
}
#pragma endregion

#pragma endregion

#pragma region METODOS_ARRAYS

/// <summary>
/// Verifica se valor existe num array
/// </summary>
/// <param name="valores"></param>
/// <param name="n"></param>
/// <param name="novo"></param>
/// <returns></returns>
bool Existe(int valores[], int n, int novo) {
	bool encontrou = false;
	for (int i = 0; i < n; i++) {
		if (valores[i] == novo) {
			encontrou = true;
			break;
		}
	}
	return(encontrou);
}

/// <summary>
/// Insere um valor num array
/// </summary>
/// <param name="valores"></param>
/// <param name="tot"></param>
/// <param name="novo"></param>
/// <returns></returns>
int InsereFinal(int valores[], int tot, int novo) {
	//Verificar outras regras..
	valores[tot] = novo; tot++;
	return tot;
}

#pragma endregion

int main() {

#pragma region ARRAYS

	int valor[N] = { 2,4,6,8,0,123,-4,5};
	int tot = 8;						//inicio tenho 8 elementos no array
	int novo = 98;

	//no inicio
	valor[0] = novo;

	//inserir valor no final do array
	valor[tot] = novo; tot++;

	//inserir valor no final do array se não existir
			//verificar se esse valor existe
			//se não existe, inserir valor no final do array

	//H1	
	//Verificar se esse valor existe
	bool encontrou = false;
	for (int i = 0; i < tot; i++) {
		if (valor[i] == novo) {
			encontrou = true;
			break; 
		}
	}
	//se não existe, inserir valor no final do array
	if (encontrou==false) {
		valor[tot] = novo; tot++;
	}

	novo = 980;

	//Verificar se esse valor existe
	encontrou = false;
	for (int i = 0; i < tot; i++) {
		if (valor[i] == novo) {
			encontrou = true;
			break;
		}
	}
	if (encontrou == false) {
		valor[tot] = novo; tot++;
	}

	//H2 - Reutilização
	novo = 200;
	//Verificar se esse valor existe
	if (Existe(valor, tot, novo) != true) {
		//se não existe, inserir valor no final do array
		tot = InsereFinal(valor, tot, novo);
	}

	novo = 230;
	if (Existe(valor, tot, novo) != true) {
		tot = InsereFinal(valor, tot, novo);
	}
#pragma endregion

#pragma region LISTAS

	//Valor varios[N];	//array de structs

	Valor* head;		//inicio da lista

	//Cria uma struct
	Valor v1;
	v1.v = 12;
	strcpy(v1.nome, "Porto");
	v1.proximo = NULL;

	head = &v1;			//inserir Valor na lista
	printf("Numero: %d\n", head->v);

	//Criei um apontador para struct
	Valor* novoValor;
	novoValor = (Valor*)calloc(1,sizeof(Valor));
	novoValor->v = v1.v*2;
	strcpy(novoValor->nome,v1.nome);

	//Inserir novo Valor na Lista
			//verificar se esse valor existe
			//se não existe, inserir valor na lista
	//H1
	//verificar se esse valor existe
	encontrou = false;
	if (head!=NULL)
	{ 
		Valor* auxLista = head;
		while (auxLista != NULL) {
			if (auxLista->v == novoValor->v) {
				encontrou = true;
				break;
			}
			auxLista = auxLista->proximo;
		}
	}
	//se não existe, inserir valor na lista
	if (encontrou == false) {
		//inserir no inico da lista
		novoValor->proximo = head;
		head = novoValor;
	}

	//H2 - Reutilização
	if (ExisteLista(novoValor->v, head) == false) {
		head = InsereInicioLista(novoValor, head);
	}
	if (ExisteLista(v1.v, head) == false) {
		head = InsereInicioLista(&v1, head);
	}

	MostraLista(head);


#pragma region LISTAS_FICHEIRO_BINÁRIO
	FILE* fp;
	ValorFicheiro aux;
	//H1
	//Criar ficheiro e gravar dados
	fp = fopen("Dados.bin", "wb");
	if (fp != NULL) {
		aux.v = novoValor->v;
		strcpy(aux.nome, novoValor->nome);
		fwrite(&aux, sizeof(ValorFicheiro), 1, fp);
		fclose(fp);
	}
	//fseek(fp, 0, SEEK_SET);
	//novoValor = (Valor*)calloc(sizeof(Valor));
	//fread(novoValor, sizeof(Valor), 1, fp);
	//fclose(fp);

	//Abrir ficheiro e ler dados
	//head = NULL;
	fp = fopen("Dados.bin", "rb");
	if (fp != NULL) {
		fread(&aux, sizeof(ValorFicheiro), 1, fp);
		novoValor = (Valor*)calloc(sizeof(Valor));
		novoValor->v = aux.v;
		strcpy(novoValor->nome, aux.nome);
		if (ExisteLista(novoValor->v, head) == false) {
			head = InsereInicioLista(novoValor, head);
		}
		fclose(fp);
	}
	MostraLista(head);

	//H2
	GravaFicheiro("Dados.bin", head);
	head = NULL;
	head = LeFicheiro("Dados.bin", head);
	MostraLista(head);
#pragma endregion

#pragma endregion

}

