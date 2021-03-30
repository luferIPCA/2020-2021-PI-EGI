#pragma once

typedef struct Maquina {
	int num;
	struct Maquina* prox;
}Maquina, *PtrMaquina;

Maquina* CriaMaquinaNova(int num);
void MostraLinhaMontagem(Maquina* h);
Maquina* InsereNovaInicio(Maquina* head, Maquina* nova);
Maquina* InsereNovaFim(Maquina* head, Maquina* nova);
Maquina* InserePorOrdem(Maquina* head, Maquina* nova);
