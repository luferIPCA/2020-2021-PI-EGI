/*
* lufer
* P-ESI
* 2020-2021
* Manipulação de Arrays em C (revisão)
* Funções e parâmetros
*/
#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable: 4996);

//ATENÇÃO: passar para *.h
//-------------------------------------------------------
typedef enum {False, True} boolean;
#define true True
#define false False
#define MAX 5
#define M 20
#define N 30
#define MAXALUNOSTURMA 45

const float PI = 3.14;

typedef struct Morada {
	char rua[M];
	int numeroPorta;
}Morada;

typedef struct Aluno {
	char nome[N];
	int numero;
	Morada morada;
} Aluno;


void mostraArray(int n[], int nElementos);	//asssinatura
boolean getValues(int v[], int nElementos);
void alteraArray(int v[], int n);
int* getArray(int v[], int s);
void SimpleRandDemo(int n);
//-------------------------------------------------------

int main(void) {

	int x1, x2, x3, x4, x5;
	x1 = x2 = x3 = x4 = x5 = 0;

	//tipo nome[tamanho]
	int valores[MAX];		//declarar um array de 5 posições!
	float valores1[MAX * 2];	//posições: MAX; última=MAx-1; primeira=0
	//printf("Tamanho do Array: %d", sizeof(valores));
	int notas[MAX] = { 12,13,7,2,12 };
	char car[50] = { 'a','b','c','\0' };
	Aluno alunos[MAXALUNOSTURMA];

	char* nomes[10];

	//char car1[20][10];
	//strcpy(nomes[0], "ola mundo")
	//char* s; //malloc()

	notas[0] = 12;
	notas[0] = notas[1] + 1;
	notas[1]++;	//notas[1] = notas[1]+1
	printf("%d\n", notas[2] * 3);
	//notas++; //Erro!!!

	valores[0] = 0;
	valores[1] = 0;
	valores[2] = 0;

	//valores[i]=0;
	int i = 0;
	do {
		valores[i] = 0;
		i++;
	} while (i<MAX);

	//for
	for (i = 0; i < MAX; i++) {
		valores[i] = 0;
	}

	//while
	i = 0;
	while (i < MAX)
	{
		valores[i++] = 0;
	}

	//mostrar array
	for (i = 0; i < MAX; i++) {
		printf("%d\n", valores[i]);
	}

	//tamanho de um array
	printf("%d\n", (int)sizeof(i));
	printf("%d\n", (int)sizeof(valores));
	printf("%d\n", (int)(sizeof(valores) / sizeof(valores[0])));

	//mostrar array com função
	mostraArray(valores, MAX);

	alteraArray(valores, MAX,2,127);

	int *aux = getArray(valores, MAX);
	//mostraArray(getArray(aux, MAX), MAX);
	mostraArray(aux, MAX);

	printf("Ler valores para Array\n");
	time(NULL);
	//srand((unsigned)time(NULL));
	//srand(1);
	SimpleRandDemo(10);
 	printf("\n");
	//srand(1);
	SimpleRandDemo(10);

	//Mostrar o conteudo do array de alunos
	i = 0;
	do {
		printf("Nome: %s\n", alunos[i].nome);
		printf("Numero: %d\n", alunos[i].numero);
		printf("Morada - Rua: %s\n", alunos[i].morada.rua);
		printf("Morada - Porta: %d\n", alunos[i].morada.numeroPorta);
		i++;
	} while (i < MAXALUNOSTURMA);

	//getValues(valores, MAX);

	//mostraArrayII(valores, MAX);
}

#pragma region FUNCOES
/**
 * .
 * 
 * \param n
 * \param nElementos
 */
void mostraArray(int n[], int nElementos) {
	for (int i = 0; i < nElementos; i++) {
		printf("%d\n", n[i]);
	}
}
/**
 * Apresenta o array caso seja possível
 * 
 * \param n
 * \param nElementos
 * \return 
 */
boolean mostraArrayII(int n[], int nElementos) {
	//int sizeArray = (sizeof(n) / sizeof(n[0]));	//"não é possível pois int n[]==int *n" calcula o tamanho do array
	//if ((nElementos <= 0) || (nElementos > sizeArray))  //caso nElementos exceda o tamanho do array -> False
	if ((nElementos <= 0) || (nElementos > MAX)) 
		return False;									//caso nElementos seja 0 ou negativo -> Falso
	mostraArray(n, nElementos);
	return True;
}

/**
 * Carrega um array com valores inserido do teclado
 * 
 * \param v
 * \param nElementos
 * \return 
 */
boolean getValues(int v[], int nElementos) 
{
	if (nElementos <= 0) return false;
	//testar nElementos;
	for (int i = 0; i < nElementos; i++) {
		printf("%dº valor - ", i);
		scanf("%d", v[i]);
	}
	return True;
}

/**
 * Devolve array com todos os pares existentes no array de entrada!
 * Array qie entra não é alterado
 * \param v
 * \param nElementos
 * \return 
 */
int* getValoresPares(int v[], int nElementos, int outro[])
{
	//Testar condições
	//if (nElementos<0 || nElementos>MAX) return NULL;

	int aux[MAX];
	//for(int i=0I i<nElementos;i++)
	//testar nElementos;
	
	return aux;
}

/// <summary>
/// Altera determinada posição do array
/// </summary>
/// <param name="v"></param>
/// <param name="n"></param>
/// 
void alteraArray(int v[], int n, int pos, int valor) {
	if(pos>0 && pos<n)
		v[pos] =valor;
}

/**
 * Devolver um array com os valores ímpares...como apontaddor
 * 
 * \param v
 * \param n
 * \return 
 */
int* getOddNumbers(int v[], int n) {
	static int aux[MAX];
	int j = 0;

	if (n >= MAX) return NULL;
	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 0) aux[j++] = v[i];
	}
	return aux;
}


/// <summary>
/// Define a capacidade de um array no interior da função
/// </summary>
/// <param name="v"></param>
/// <param name="s"></param>
/// <returns></returns>
int* getArray(int v[], int s) {

	//int aux[s];
	int* aux = (int*)malloc(sizeof(int) * s);
	for (int i = 0; i < s; i++) {
		aux[i] = v[i];
	}
	return aux;
}

/// <summary>
/// Altera um array no interior e é devolvido como parâmetro
/// </summary>
/// <param name="v"></param>
/// <param name="s"></param>
/// <param name="out"></param>
/// <returns></returns>
boolean getArrayII(const int v[], const int s, int *out)
{
	if (s < 0) return false;
	for (int i = 0; i < s; i++)
	{
		out[i] = v[i];
	}
	return true;
}


#pragma region ValoresAleatórios
/* 
O que faz esta função 
*/
int* getRandom() {

	static int  r[10];
	int i;

	/* set the seed */
	srand((unsigned)time(NULL));

	for (i = 0; i < 10; ++i) {
		r[i] = rand();
		printf("r[%d] = %d\n", i, r[i]);
	}

	return r;
}

/// <summary>
/// Demonstração de geração de valores aleatórios
/// </summary>
/// <param name="n"></param>
void SimpleRandDemo(int n)
{
	// Print n random numbers.
	int i;
	for (i = 0; i < n; i++)
		printf("  %6d\n", rand());
}

#pragma endregion

//Função: mostrar Array!!!

/// <summary>
/// função que mostra um array de alunos
/// </summary>
/// <param name="a"></param>
/// <param name="tamanho"></param>
void MostraArrayAlunos(Aluno a[], int tamanho) {
	int i = 0;
	do {
		printf("Nome: %s\n", a[i].nome);
		printf("Numero: %d\n", a[i].numero);
		printf("Morada - Rua: %s\n", a[i].morada.rua);
		printf("Morada - Porta: %d\n", a[i].morada.numeroPorta);
		i++;
	} while (i < tamanho);
}


//TPC
//1) Reorganizar este código em ficheiros *.c e *.h
//2) Rever funções sobre arrays de inteiros
//3) Implementar outras funções sobre arrays
	//Procurar
	//Ordenar
	//Inserir
	//Remover

//Ordenar um array!!!
//Inverter um array
//Contar ocorrências num array

#pragma endregion
