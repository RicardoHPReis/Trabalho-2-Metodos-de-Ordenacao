#pragma once
#include "stdafx.h"

typedef struct
{
	char nomeArquivo[100], arqSalvo[100];
	char nome[20];
	int acao, posicao, lista, ordenacao;
	int tamanho, rg, leuLista, ordenouLista;
} Config;
Config config;


typedef struct
{
	unsigned long int me, ce; //movimentacoes, comparacoes
	struct timespec comeco, fim;
	double tempo;
} EncadComp;
EncadComp encadcomp[12];


struct Node
{
	char nome[20];
	int rg;
	struct Node *proximo;
};
typedef struct Node Encadeada;
Encadeada *enc, *primeiro, *ultimo;


typedef struct
{
	unsigned long int ms, cs; //movimentacoes, comparacoes
	struct timespec comeco, fim;
	double tempo;
} SeqComp;
SeqComp seqcomp[12];


typedef struct
{
	char nome[15];
	int rg;
} Sequencial;
Sequencial *seq;


typedef struct
{
	unsigned long int mo, co; //movimentacoes, comparacoes
	struct timespec comeco, fim;
	double tempo;
}OrdComp;
OrdComp ordcomp[11];


typedef struct
{
	Sequencial *ordem;
} Ordenada;
Ordenada *ord;


void comparacoes(unsigned long int comp, unsigned long int mov, double tempo)
{
	printf("\nComparações: %lu\n", comp);
	printf("Movimentações: %lu\n", mov);
	printf("Tempo: %fs\n", tempo);
}