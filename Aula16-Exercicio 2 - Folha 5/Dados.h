/*
Lista Ligada Simples
*/

typedef struct Carro
{
	int ano;
	struct Carro* seg;
}Carro, * PtrCarro;


Carro* NovoCarro(int ano);
Carro* InsereCarroFinal(Carro* novo, Carro* inicio);
//void MostraLista(Carro* inicio);
Carro* CarroSaiGaragem(int ano, Carro* inicio);