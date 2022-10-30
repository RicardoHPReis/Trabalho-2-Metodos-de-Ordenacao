#include "stdafx.h"
#include "structsLista.h"

void procurarListaOrdenadaRG(Ordenada *ord, OrdComp *ordcomp, int tamanho, int rg)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	int encontrou=0;
	ordcomp->mo++;
	ordcomp->co++;
	for(int e=0; e<tamanho && encontrou==0; e++)
	{
		if(ord[e].ordem->rg==rg)
		{
			printf("RG encontrado!!\n");
			printf("%d| %s,%08d\n", e+1, ord[e].ordem->nome, ord[e].ordem->rg);
			encontrou=1;
			ordcomp->mo++;
		}
		ordcomp->co+=2;
	}
	ordcomp->co++;
	if(encontrou!=1)
		printf("RG não encontrado");
	
    clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(ordcomp->co, ordcomp->mo, ordcomp->tempo);
}

void procurarListaOrdenadaPosicao(Ordenada *ord, OrdComp *ordcomp, int posicao)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	printf("%d| %s,%08d\n", posicao, ord[posicao-1].ordem->nome, ord[posicao-1].ordem->rg);
	
    clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(ordcomp->co, ordcomp->mo, ordcomp->tempo);
}

void procurarListaPesquisaBinaria(Ordenada *ord, OrdComp *ordcomp, int tamanho, int rg)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	int minimo=0, meio=(tamanho-1)/2, maximo=tamanho-1;
	int encontrou=0;
	ordcomp->mo+=4;
	ordcomp->co++;
	while(maximo>minimo && encontrou!=1)
	{
		if(ord[meio].ordem->rg > rg)
		{
			if(meio == minimo)
			{
				maximo = 0;
				meio = 0;
				ordcomp->mo+=2;
			}
			maximo = meio;
			ordcomp->co++;
			ordcomp->mo++;
		}
		else if(ord[meio].ordem->rg < rg)
		{
			if(meio == minimo)
			{
				minimo = maximo;
				meio = maximo;
				ordcomp->mo+=2;
			}
			minimo = meio;
			ordcomp->co++;
			ordcomp->mo++;
		}
		if(ord[meio].ordem->rg == rg)
		{
			printf("RG encontrado!!\n");
			printf("%d| %s,%08d\n", meio+1, ord[meio].ordem->nome, ord[meio].ordem->rg);
			encontrou=1;
			ordcomp->mo++;
		}
		meio=(maximo-minimo)/2 + minimo;
		ordcomp->co+=5;
		ordcomp->mo++;
	}
	
	if(encontrou==0)
		printf("RG não encontrado");
	ordcomp->co++;
    clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(ordcomp->co, ordcomp->mo, ordcomp->tempo);
}



void alocarOrdenacao(Ordenada **ord, int tamanho)
{
	*ord = (Ordenada*) malloc (tamanho*sizeof(Ordenada));
	for(int a=0; a<tamanho; a++)
	{
		(*ord)[a].ordem = &seq[a];
	}
}



void selectionSort(Ordenada **ord, OrdComp *ordcomp, int tamanho)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	Ordenada aux;
	int menor, posicao;
	ordcomp->mo++;
	for(int a=0; a<tamanho-1; a++)
	{
		menor = (*ord)[a].ordem->rg;
		for(int b=a; b<tamanho; b++)
		{
			if(menor > (*ord)[b].ordem->rg)
			{
				menor =(*ord)[b].ordem->rg;
				aux.ordem =(*ord)[b].ordem;
				posicao = b;
				ordcomp->mo+=3;
			}
			ordcomp->co+=2;
			ordcomp->mo++;
		}
		(*ord)[posicao].ordem = (*ord)[a].ordem;
		(*ord)[a].ordem = aux.ordem;
		ordcomp->mo+=4;
	}
	printf("\n\nLista ordenada com sucesso.\n");
	clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(ordcomp->co, ordcomp->mo, ordcomp->tempo);
}



void insertionSort(Ordenada **ord, OrdComp *ordcomp, int tamanho)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	Ordenada aux;
	int c, d;
	for(c=1; c<tamanho; c++)
	{
		aux.ordem = (*ord)[c].ordem;
		for(d=c-1; d>=0 && aux.ordem->rg < (*ord)[d].ordem->rg; d--)
		{
			(*ord)[d+1].ordem = (*ord)[d].ordem;
			ordcomp->mo++;
		}
		(*ord)[d+1].ordem = aux.ordem;
		ordcomp->mo+=2;
		ordcomp->co+=3;
	}
	ordcomp->co++;
	printf("\n\nLista ordenada com sucesso.\n");
	clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(ordcomp->co, ordcomp->mo, ordcomp->tempo);
}



void bubbleSort(Ordenada **ord, OrdComp *ordcomp, int tamanho)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	int ordenou=0;
	Ordenada aux;
	ordcomp->mo++;
	while(ordenou!=1)
	{
		ordenou=1;
		for(int e=0; e<tamanho-1; e++)
		{
			if((*ord)[e].ordem->rg > (*ord)[e+1].ordem->rg)
			{
				aux.ordem = (*ord)[e].ordem;
				(*ord)[e].ordem = (*ord)[e+1].ordem;
				(*ord)[e+1].ordem = aux.ordem;
				ordenou=0;
				ordcomp->mo+=4;
			}
			ordcomp->co+=2;
			ordcomp->mo++;
		}
		ordcomp->mo+=2;
		ordcomp->co+=2;
	}
	ordcomp->co++;
	printf("\n\nLista ordenada com sucesso.\n");
	clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(ordcomp->co, ordcomp->mo, ordcomp->tempo);
}



void shellSort(Ordenada **ord, OrdComp *ordcomp, int tamanho)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	int a, b, c;
	int max;
	Ordenada aux;
	for(max = 1; max < tamanho; max = 3*max+1)
	{
		ordcomp->mo++;
		ordcomp->co++;
	}
	ordcomp->co++;
	for(a = max/3; a>=1; a/=3)
	{
		for(b=a; b<tamanho; b++)
		{
			aux.ordem = (*ord)[b].ordem;
			for(c= b-a; c>=0 && aux.ordem->rg < (*ord)[c].ordem->rg; c-=a)
			{
				(*ord)[c+a].ordem = (*ord)[c].ordem;
				ordcomp->mo+=2;
				ordcomp->co+=2;
			}
			(*ord)[c+a].ordem = aux.ordem;
			ordcomp->mo+=2;
			ordcomp->co+=2;
		}
		ordcomp->mo++;
		ordcomp->co++;
	}
	ordcomp->co++;
	printf("\n\nLista ordenada com sucesso.\n");
	clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(ordcomp->co, ordcomp->mo, ordcomp->tempo);
}



void qksort(Ordenada **ord, OrdComp *ordcomp, int esquerda, int direita)
{
	int pivo;
	int meio;
	int i, j;
	Ordenada aux;
     
    i = esquerda;
    j = direita;
	meio = (esquerda + direita)/2;
    pivo = ((*ord)[esquerda].ordem->rg + (*ord)[direita].ordem->rg + (*ord)[meio].ordem->rg) / 3;
	ordcomp->mo+=4;
	
    while(i <= j) 
	{
        while((*ord)[i].ordem->rg < pivo && i < direita) 
		{
            i++;
			ordcomp->mo++;
			ordcomp->co+=3;
        }
        while((*ord)[j].ordem->rg > pivo && j > esquerda) 
		{
            j--;
			ordcomp->mo++;
			ordcomp->co+=3;
        }
        if(i <= j)
		{
            aux.ordem = (*ord)[i].ordem;
            (*ord)[i].ordem = (*ord)[j].ordem;
            (*ord)[j].ordem = aux.ordem;
            i++; j--;
			ordcomp->mo+=5;
        }
		ordcomp->co+=6;
    }
	ordcomp->co++;
	
    if(j > esquerda)
		qksort(&(*ord), ordcomp, esquerda, j);
    if(i < direita)
		qksort(&(*ord), ordcomp, i, direita);
	ordcomp->co+=2;
}

void quickSort(Ordenada **ord, OrdComp *ordcomp, int tamanho)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	
	qksort(&(*ord), ordcomp, 0, tamanho-1);
	
	printf("\n\nLista ordenada com sucesso.\n");
	clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(ordcomp->co, ordcomp->mo, ordcomp->tempo);
}



void merge(Ordenada **ord, Ordenada *aux, OrdComp *ordcomp, int inicio, int meio, int fim)
{
	for (int h = inicio; h<=fim; h++)
	{
		aux[h].ordem = (*ord)[h].ordem;
		ordcomp->mo+=2;
		ordcomp->co++;
	}
	ordcomp->co++;
	
	int i = inicio;
	int j = meio+1;
	int k = inicio;
	ordcomp->mo+=3;
	
	while (i <= meio && j <= fim)
	{
    	if (aux[i].ordem->rg <= aux[j].ordem->rg)
		{
			(*ord)[k].ordem = aux[i].ordem;
			ordcomp->mo+=2;
			i++;
		}
    	else
		{
			(*ord)[k].ordem = aux[j].ordem;
			ordcomp->mo+=2;
			j++;
		}
		ordcomp->co+=3;
		k++;
		ordcomp->mo++;
	}
	ordcomp->co++;

	while (i <= meio)
	{
		(*ord)[k].ordem = aux[i].ordem;
		i++; k++;
		ordcomp->mo+=3;
		ordcomp->co++;
	}
	ordcomp->co++;
		
	while (j <= fim)
	{
		(*ord)[k].ordem = aux[j].ordem;
		j++; k++;
		ordcomp->mo+=3;
		ordcomp->co++;
	}
	ordcomp->co++;
}

void msort(Ordenada **ord, Ordenada *aux, OrdComp *ordcomp, int inicio, int fim) 
{
	int meio;
	if (inicio >= fim)
		return;
	else
	{
		meio = (inicio+fim)/2;
		ordcomp->mo++;
		msort(&(*ord), aux, ordcomp, inicio, meio);
		msort(&(*ord), aux, ordcomp, meio+1, fim);
		merge(&(*ord), aux, ordcomp, inicio, meio, fim);
	}
	ordcomp->co++;
}

void mergeSort(Ordenada **ord, OrdComp *ordcomp, int tamanho)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	
	Ordenada *aux;
	aux = (Ordenada*) malloc (tamanho*sizeof(Ordenada));
  	msort(&(*ord), aux, ordcomp, 0, tamanho-1);
	free(aux);

	ordcomp->mo+=2;
	printf("\n\nLista ordenada com sucesso.\n");
	clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(ordcomp->co, ordcomp->mo, ordcomp->tempo);
}



void mostrarListaOrdenada(Ordenada *ord, OrdComp *ordcomp, int tamanho)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	for(int z=0; z<tamanho; z++)
	{
		printf("%d| %s,%08d\n", z+1, ord[z].ordem->nome, ord[z].ordem->rg);
		ordcomp->co++;
	}
	ordcomp->co++;
	printf("\n\n--- FIM DA LISTA ---\n\n");
    clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
	comparacoes(ordcomp->co, ordcomp->mo, ordcomp->tempo);
}



void apagarListaOrdenada(Ordenada **ord, OrdComp *ordcomp)
{
	ordcomp->mo=0;
	ordcomp->co=0;
	clock_gettime(CLOCK_REALTIME, &ordcomp->comeco);
	free(*ord);
	ordcomp->mo++;
	clock_gettime(CLOCK_REALTIME, &ordcomp->fim);
    ordcomp->tempo = (ordcomp->fim.tv_sec-ordcomp->comeco.tv_sec) + (ordcomp->fim.tv_nsec-ordcomp->comeco.tv_nsec)/1000000000.0;
}