#include "Dados.h"
#include <stdio.h>

#pragma warning (disable: 4996);
int main() {

#pragma region UM
	Carro c1;
	c1.ano = 2020;
	c1.seg = NULL;

	Carro c2;
	c2.ano = 2021;
	c2.seg = NULL;

	c2.seg = &c1;

	//mostrar todas as celulas...
	//h1
	Carro *inicio;		//PtrCarro inicio;
	inicio = &c2;
	printf("%d\n", inicio->ano);
	inicio = inicio->seg;
	printf("%d\n", inicio->ano);

	//h2
	Carro* aux;
	aux = &c2;
	while (aux != NULL)
	{
		printf("%d\n", aux->ano);
		aux = aux->seg;
	}
#pragma endregion

#pragma region DOIS
	int ano;
	Carro* ini;

	//h1 - aloco memoria
	ini = (Carro*)calloc(1*sizeof(Carro));
	ini->ano = 2020;

	//h2 - invoco função que aloca memória
	ini = NovoCarro(2021);

	//Criar memoria para N registos
	ano = -1;
	while(ano!=0) {
		printf("Ano do carro: ");
		scanf("%d", &ano);
		if (ano>0)
			ini = NovoCarro(ano);
	} 

	Carro* primeiro = NULL;

	/*if (primeiro == NULL) 
		primeiro = NovoCarro(2018);*/

	Carro* novo = NovoCarro(2018);
	primeiro = InsereCarroFinal(novo, primeiro);
	primeiro = InsereCarroFinal(NovoCarro(2017), primeiro);

	/*Carro* corrente = primeiro;
	while (corrente != NULL) {
		printf("Ano: %d\n", corrente->ano);
		corrente = corrente->seg;
	}*/

	MostraLista(primeiro);
	primeiro = InsereCarroFinal(NovoCarro(2016), primeiro);
	primeiro = InsereCarroFinal(NovoCarro(2021), primeiro);
	MostraLista(primeiro);

	primeiro = CarroSaiGaragem(2018, primeiro);
	MostraLista(primeiro);

#pragma endregion

}




