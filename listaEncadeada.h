#include "stdafx.h"
#include "structsLista.h"


void inserirListaEncadeadaPrimeiro(Encadeada **enc, Encadeada **primeiro, EncadComp *encadcomp, int *tamanho, char *nome, int rg)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	*enc = (Encadeada*) malloc (sizeof(Encadeada));
	if(!(*enc)) 
	{
		perror("Não há espaço na memória!\n");
		exit(1);
	}
	encadcomp->me++;
	encadcomp->ce++;
	
	printf("\nInserindo em...\n%d| %s,%08d", 1, nome, rg);
	strcpy((*enc)->nome,nome);
	(*enc)->rg = rg;
	(*enc)->proximo = *primeiro;
	*primeiro = *enc;
	(*tamanho)++;
	encadcomp->me+=5;

	printf("\n\nPrimeiro registro incluido na lista.");
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}



void inserirListaEncadeadaUltimo(Encadeada **enc, Encadeada **ultimo, EncadComp *encadcomp, int *tamanho, char *nome, int rg)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	*enc = (Encadeada*) malloc (sizeof(Encadeada));
	if(!(*enc)) 
	{
		perror("Não há espaço na memória!\n");
		exit(1);
	}
	(*tamanho)++;
	encadcomp->me+=2;
	encadcomp->ce++;

	printf("\nInserindo em...\n%d| %s,%08d", (*tamanho), nome, rg);
	strcpy((*enc)->nome,nome);
	(*enc)->rg = rg;
	(*enc)->proximo=NULL;
	(*ultimo)->proximo = *enc;
	(*ultimo) = *enc;
	encadcomp->me+=5;
	printf("\n\nÚltimo registro incluido na lista.");
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}



void inserirListaEncadeadaPosicao(Encadeada **enc, Encadeada **primeiro, Encadeada **ultimo, EncadComp *encadcomp, int *tamanho, int posicao, char *nome, int rg)
{
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	int linha=1, encontrou=0;
	Encadeada *atual, *anterior;
	*enc = (Encadeada*) malloc (sizeof(Encadeada));
	if(!enc) 
	{
		perror("Não há espaço na memória!\n");
		exit(1);
	}
	(*tamanho)++;
	encadcomp->me+=2;
	encadcomp->ce++;
	
	printf("\nInserindo em...\n%d| %s,%08d", posicao, nome, rg);
	if(posicao==1)
	{
		strcpy((*enc)->nome,nome);
		(*enc)->rg = rg;
		(*enc)->proximo = *primeiro;
		*primeiro = *enc;
		encadcomp->me+=4;
	}
	else if(posicao==(*tamanho))
	{
		strcpy((*enc)->nome,nome);
		(*enc)->rg = rg;
		(*enc)->proximo=NULL;
		(*ultimo)->proximo = *enc;
		(*ultimo) = *enc;
		encadcomp->me+=5;
	}
	else
	{
		atual = *primeiro;
		encadcomp->me++;
		while(enc!=NULL && encontrou==0)
		{
			
			if(linha==posicao-1)
			{
				strcpy((*enc)->nome,nome);
				(*enc)->rg = rg;
				(*enc)->proximo = atual->proximo;
				atual->proximo = *enc;
				encontrou=1;
				encadcomp->me+=5;
			}
			else
			{
				atual = atual->proximo;
				linha++;
				encadcomp->me+=2;
			}
			encadcomp->ce+=3;
		}
		if(encontrou==0)
		{
			printf("\nPosição não encontrada.\n");
		}
		encadcomp->ce+=2;
	}
	encadcomp->ce+=2;
	printf("\n\nRegistro incluido na %d° posição.", posicao);
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}


	
void deletarListaEncadeadaPrimeiro(Encadeada **enc, Encadeada **primeiro, EncadComp *encadcomp, int *tamanho)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	printf("\nDeletando...\n%d| %s,%08d", 1, (*primeiro)->nome, (*primeiro)->rg);
	*enc = *primeiro;
	*primeiro = (*enc)->proximo;
	*enc = NULL;
	free(*enc);
	(*tamanho)--;
	encadcomp->me+=4;
	printf("\n\nPrimeiro registro excluído.");
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}



void deletarListaEncadeadaUltimo(Encadeada **enc, Encadeada *primeiro, Encadeada **ultimo, EncadComp *encadcomp, int *tamanho)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	*enc = primeiro;
	encadcomp->me++;
	while(*enc!=NULL)
	{
		if((*enc)->proximo==(*ultimo))
		{
			*ultimo = *enc;
			*enc = (*ultimo)->proximo;
			(*ultimo)->proximo=NULL;
			encadcomp->me+=5;
			printf("\nDeletando...\n%d| %s,%08d", (*tamanho), (*enc)->nome, (*enc)->rg);
			*enc = NULL;
			free(*enc);
		}
		else
		{
			*enc = (*enc)->proximo;
			encadcomp->me++;
		}
		encadcomp->ce+=3;
	}
	(*tamanho)--;
	encadcomp->me++;
	encadcomp->ce++;
	printf("\n\nÚltimo registro excluído.");
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}



void deletarListaEncadeadaPosicao(Encadeada **enc, Encadeada **primeiro, Encadeada **ultimo, EncadComp *encadcomp, int *tamanho, int posicao)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	Encadeada *anterior, *atual;
	int linha=1, encontrou=0;
	*enc = *primeiro;
	encadcomp->me++;
	if(posicao==1)
	{
		printf("\nDeletando...\n%d| %s,%08d", 1, (*primeiro)->nome, (*primeiro)->rg);
		*primeiro = (*enc)->proximo;
		*enc = NULL;
		free(*enc);
		(*tamanho)--;
		encadcomp->me+=3;
	}
	else if(posicao==(*tamanho))
	{
		while(*enc!=NULL)
		{
			if((*enc)->proximo==(*ultimo))
			{
				*ultimo = *enc;
				*enc = (*ultimo)->proximo;
				(*ultimo)->proximo=NULL;
				printf("\nDeletando...\n%d| %s,%08d", posicao, (*enc)->nome, (*enc)->rg);
				*enc = NULL;
				free(*enc);
				encadcomp->me+=5;
			}
			else
			{
				*enc = (*enc)->proximo;
				encadcomp->me++;
			}
			encadcomp->ce+=3;
		}
		(*tamanho)--;
		encadcomp->me++;
		encadcomp->ce++;
	}
	else
	{
		while(enc!=NULL && encontrou==0)
		{
			if(linha==posicao-1)
			{
				anterior = *enc;
				*enc = (*enc)->proximo;
				printf("\nDeletando...\n%d| %s,%08d", posicao, (*enc)->nome, (*enc)->rg);
				atual = (*enc)->proximo;
				free(*enc);
				anterior->proximo = atual;
				encontrou=1;
				encadcomp->me+=6;
			}
			else
			{
				*enc = (*enc)->proximo;
				linha++;
				encadcomp->me+=2;
			}
			encadcomp->ce+=3;
		}
		(*tamanho)--;
		encadcomp->me++;
		encadcomp->ce++;
	}
	encadcomp->ce+=3;
	printf("\n\n%d° registro excluído.", posicao);
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}



void procurarListaEncadeadaRG(Encadeada *enc, Encadeada *primeiro, Encadeada *ultimo, EncadComp *encadcomp, int rg)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	int linha=1, encontrou=0;
	enc = primeiro;
	encadcomp->me++;
	while(enc!=NULL && encontrou==0)
	{
		if(rg==enc->rg)
		{
			encontrou=1;
			printf("RG encontrado!!\n");
			printf("%d| %s,%08d\n", linha, enc->nome, enc->rg);
			encadcomp->me++;
		}
		enc = enc->proximo;
		linha++;
		encadcomp->me+=2;
		encadcomp->ce+=2;
	}
	if(encontrou==0)
	{
		printf("RG não encontrado!!\n");
	}
	encadcomp->ce+=2;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}



void procurarListaEncadeadaPosicao(Encadeada *enc, Encadeada *primeiro, Encadeada *ultimo, EncadComp *encadcomp, int tamanho, int posicao)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	int linha=1, encontrou=0;
	enc = primeiro;
	encadcomp->me++;
	if(posicao==tamanho)
	{
		enc=ultimo;
		linha=posicao;
		encadcomp->me+=2;
	}
	encadcomp->ce++;
	while(enc!=NULL && encontrou==0)
	{
		if(linha==posicao)
		{
			printf("%d| %s,%08d\n", linha, enc->nome, enc->rg);
			encontrou=1;
			encadcomp->me++;
			break;
		}
		enc = enc->proximo;
		linha++;
		encadcomp->me+=2;
		encadcomp->ce+=2;
	}
	encadcomp->ce++;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}



void mostrarListaEncadeada(Encadeada *enc, Encadeada *primeiro, EncadComp *encadcomp)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	int linha=1;
	if (primeiro==NULL)
	{
	    printf("\n\n--- FIM DA LISTA ---\n\n");
    	return;
	}
	encadcomp->ce++;
	enc=primeiro;
	encadcomp->me++;
	while (enc!=NULL) 
	{
		printf("\n%d| %s,%08d", linha, enc->nome, enc->rg);
	    enc = enc->proximo;
		linha++;
		encadcomp->me+=2;
		encadcomp->ce++;
	}
	encadcomp->ce++;
	printf("\n\n--- FIM DA LISTA ---\n\n");
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}



void salvarListaEncadeada(Encadeada *enc, Encadeada *primeiro, EncadComp *encadcomp, char *arqSalvo)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	FILE *arquivo;
	arquivo = fopen(arqSalvo, "w");
	enc = primeiro;
	encadcomp->me+=2;
	while (enc!=NULL) 
	{
		fprintf(arquivo, "%s,%08d\n", enc->nome, enc->rg);
	    enc = enc->proximo;
		encadcomp->me++;
		encadcomp->ce++;
	}
	encadcomp->ce++;
	fclose(arquivo);
	printf("\n\nArquivo salvo!");
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;	
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}



void lerListaEncadeada(Encadeada **enc, Encadeada **primeiro, Encadeada **ultimo, EncadComp *encadcomp, char *nomeArquivo)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	FILE *arquivo;
	int rg, linha=1;
	char *token, buffer[200];
	arquivo = fopen(nomeArquivo, "r");
	encadcomp->me++;

	while(fgets(buffer, 200, arquivo))
	{
		*enc = (Encadeada*) malloc (sizeof(Encadeada));
		if(!(*enc)) 
		{
			perror("Não há espaço na memória!\n");
			exit(1);
		}
		encadcomp->me++;
		encadcomp->ce++;
		token = strtok(buffer, ",");
		rg = atoi(strtok(NULL, "\n"));
		strcpy((*enc)->nome, token);
		(*enc)->rg = rg;
		linha++;
		(*enc)->proximo = NULL;
		encadcomp->me+=6;
		if (*primeiro==NULL)
		{
			*primeiro = *enc;
			*ultimo = *enc;
			*enc = (*primeiro)->proximo;
			encadcomp->me+=3;
		}
	    else 
		{
			(*ultimo)->proximo = *enc;
			*ultimo = *enc;
			*enc = (*ultimo)->proximo;
			encadcomp->me+=3;
		}
		encadcomp->ce+=3;
	}
	fclose(arquivo);
	printf("%d nomes e RGs lidos!\n", linha-1);
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(encadcomp->ce, encadcomp->me, encadcomp->tempo);
}



void apagarListaEncadeada(Encadeada **enc, Encadeada **primeiro, Encadeada **ultimo, EncadComp *encadcomp)
{
	encadcomp->me=0;
	encadcomp->ce=0;
	clock_gettime(CLOCK_REALTIME, &encadcomp->comeco);
	*enc = *primeiro;
	encadcomp->me++;
	while(*enc!=NULL)
	{
		*primeiro = (*enc)->proximo;
		*enc = NULL;
		free(*enc);
		*enc = *primeiro;
		encadcomp->me+=3;
		encadcomp->ce++;
	}
	encadcomp->ce++;
	*enc = NULL;
	*primeiro = NULL;
	*ultimo = NULL;
	encadcomp->me+=3;
	
	clock_gettime(CLOCK_REALTIME, &encadcomp->fim);
    encadcomp->tempo = (encadcomp->fim.tv_sec-encadcomp->comeco.tv_sec) + (encadcomp->fim.tv_nsec-encadcomp->comeco.tv_nsec)/1000000000.0;
}