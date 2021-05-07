#pragma once


typedef struct Carro
{
	int ano;
	struct Carro* seg;
}Carro, *PtrCarro;


Carro* NovoCarro(int ano);
Carro* InsereCarroFinal(Carro* novo, Carro* inicio);
//void MostraListaCarro(Carro* inicio);
Carro* CarroSaiGaragem(int ano, Carro* inicio);
