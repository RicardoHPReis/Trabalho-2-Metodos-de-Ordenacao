#include "stdafx.h"
#include "structsLista.h"


void aparenciaMenu(void)
{
	system(LIMPA);
	printf("*****************************************************\n");
	printf("                LISTA DE PESSOAS E RGS\n");
	printf("*****************************************************\n\n\n\n");
}



void aparenciaLista(void)
{
	system(LIMPA);
	printf("-------------------------------\n");
	printf(" POSIÇÃO |   NOME   |    RG    \n");
	printf("-------------------------------\n");
}



void aparenciaMenuDescricao(int descricao)
{
	switch(descricao)
	{
		case 1:
		{
			printf("Listas:\n");
			break;
		}
		case 2:
		{
			printf("Ações: \n");
			break;
		}
		case 3:
		{
			printf("Inserir:\n");
			break;
		}
		case 4:
		{
			printf("Deletar:\n");
			break;
		}
		case 5:
		{
			printf("Procurar:\n");
			break;
		}
		case 6:
		{
			printf("Leitura do arquivo:\n");
			break;
		}
		case 7:
		{
			printf("Posição:\n");
			break;
		}
		case 8:
		{
			printf("Registro Geral:\n");
			break;
		}
		case 9:
		{
			printf("Salvar arquivo como:\n");
			break;
		}
		case 10:
		{
			printf("Como funciona o programa:\n");
			break;
		}
		case 11:
		{
			printf("Ordenação Sequencial:\n");
			break;
		}
	}
	printf("-----------------------------------------------------\n\n");
}



void ler_string(char *resposta)
{
	int tamanho;
    char letra, *string;
	string = (char*) malloc (2*sizeof(char));
    
	scanf(" %c", &letra);

    for (tamanho = 0; letra != '\n'; tamanho++)
    {
        string[tamanho] = letra;
        string = (char*) realloc(string, (tamanho+3)*sizeof(char));

        scanf("%c", &letra);
    }
    string[tamanho+1] = '\0';
	*resposta = string[0];
	free(string);
}


void digiteAlgo()
{
	char continuar;
	printf("\n\nDigite qualquer tecla para continuar:\n");
	ler_string(&continuar);
}
	

void tipoDeErro(int erro)
{
	system(LIMPA);
	aparenciaMenu();
	switch(erro)
	{
		case 1:
		{
			aparenciaMenuDescricao(1);
			printf("Digite o número da lista novamente!!!\n"
			       "O número da lista precisa estar presente no menu de\n"
			       "seleção!\n");
			break;
		}
		case 2:
		{
			aparenciaMenuDescricao(2);
			printf("Digite o número da ação novamente!!!\n"
			       "O número da ação precisa estar presente no menu de\n"
				   "seleção!\n");
			break;
		}
		case 3:
		{
			aparenciaMenuDescricao(2);
			printf("Digite o número da ação novamente!!!\n"
			       "É preciso ler uma lista pelo menu de seleção antes\n"
				   "de escolher outras ações!\n");
			break;
		}
		case 4:
		{
			aparenciaMenuDescricao(6);
			printf("Digite o arquivo novamente!!!\n"
			       "O arquivo precisa existir no sistema!\n");
			break;
		}
		case 5:
		{
			aparenciaMenuDescricao(7);
			printf("Digite a posição novamente!!!\n"
			       "A posição precisa estar entre os limites\n"
			       "de tamanho!\n");
			break;
		}
		case 6:
		{
			aparenciaMenuDescricao(8);
			printf("Digite a RG novamente!!!\n"
			       "O RG só pode ter no máximo 8 caracteres de tamanho!\n");
			break;
		}
		case 7:
		{
			aparenciaMenuDescricao(2);
			printf("Digite o número da ação novamente!!!\n"
			       "Esta opção só está habilitada para as listas\n"
				   "sequenciais!\n");
			break;
		}
		case 8:
		{
			aparenciaMenuDescricao(2);
			printf("Digite o número da ação novamente!!!\n"
			       "É necessário ordenar a lista antes de procurá-la\n"
				   "por binário!\n");
			break;
		}
		case 9:
		{
			aparenciaMenuDescricao(11);
			printf("Digite o número da ordenação novamente!!!\n"
			       "O número da ordenação precisa estar presente no\n"
				   "menu de seleção!\n");
			break;
		}
	}
	sleep(3);
	system(LIMPA);
}



void menudeSelecaoLista(Config *config)
{
	do
	{	
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(1);
		printf("1) Lista sequencial.\n");
		printf("2) Lista encadeada simples.\n");
		printf("3) Os dois juntos.\n");
		printf("Escolha uma lista: ");
		scanf("%d", &config->lista);
		if (config->lista<1 || config->lista>3)
			tipoDeErro(1);
	}
	while(config->lista<1 || config->lista>3);
}



void menuDeSelecaoAcao(Config *config)
{
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(2);
		printf("1) Inserir um nó no início da lista.\n");
		printf("2) Inserir um nó no fim da lista.\n");
		printf("3) Inserir um nó na posição N.\n");
		printf("4) Deletar um nó no início da lista.\n");
		printf("5) Deletar um nó no fim da lista.\n");
		printf("6) Deletar um nó na posição N.\n");
		printf("7) Procurar um nó pelo RG.\n");
		printf("8) Procurar um nó na posição N.\n");
		printf("9) Procurar um nó por pesquisa binária.\n");
		printf("10) Ordenar lista.\n");
		printf("11) Mostrar lista.\n");
		printf("12) Salvar lista.\n");
		printf("13) Ler lista.\n");
		printf("14) Comparar resultados.\n");
		printf("15) Como funciona?\n");
		printf("16) Sair do sistema.\n\n");
		printf("Escolha uma ação: ");
		scanf("%d", &config->acao);
		if (config->acao<1 || config->acao>16)
			tipoDeErro(2);
	}
	while(config->acao<1 || config->acao>16);
}



void menudeSelecaoInserir()
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(3);
}



void menudeSelecaoDeletar()
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(4);
}



void menudeSelecaoProcurar()
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(5);
}



void menudeSelecaoLer()
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(6);
}



void menuOrdenacao()
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(11);
}



void menudeSelecaoPosicaoInserir(Config *config)
{
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(7);
		switch(config->acao)
		{
			case 3:
			{
				printf("Escolha uma posição da lista para inserir (1 até %d): ", config->tamanho+1);
				break;
			}
		}
		scanf("%d", &config->posicao);	
		if (config->posicao<1 || config->posicao>config->tamanho+1)
			tipoDeErro(5);
	}
	while(config->posicao<1 || config->posicao>config->tamanho+1);
}



void menudeSelecaoPosicao(Config *config)
{
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(7);
		switch(config->acao)
		{
			case 6:
			{
				printf("Escolha uma posição da lista para deletar (1 até %d): ", config->tamanho);
				break;
			}
			case 8:
			{
				printf("Escolha uma posição da lista para procurar (1 até %d): ", config->tamanho);
				break;
			}
		}
		scanf("%d", &config->posicao);	
		if (config->posicao<1 || config->posicao>config->tamanho)
			tipoDeErro(5);
	}
	while(config->posicao<1 || config->posicao>config->tamanho);
}

void menudeSelecaoNomeRG(Config *config)
{
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(7);
	printf("Digite o nome: ");
	scanf("%s", config->nome);
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(7);
		printf("Digite o RG: ");
		scanf("%d", &config->rg);
		if (config->rg<1 || config->rg>99999999)
			tipoDeErro(6);
	}
	while(config->rg<1 || config->rg>99999999);
}

void menudeSelecaoRG(Config *config)
{
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(8);
		printf("Escolha um número de RG da lista para procurar\n(Até 8 dígitos): ");
		scanf("%d", &config->rg);		
		if (config->rg<1 || config->rg>99999999)
			tipoDeErro(6);
	}
	while(config->rg<1 || config->rg>99999999);
}

void menudeSelecaoOrdenacao(Config *config)
{
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(11);
		printf("1) Selection-Sort.\n");
		printf("2) Insertion-Sort.\n");
		printf("3) Bubble-Sort.\n");
		printf("4) Shell-Sort.\n");
		printf("5) Quick-Sort.\n");
		printf("6) Merge-Sort.\n\n");
		printf("Escolha um modelo de ordenação: ");
		scanf("%d", &config->ordenacao);
		if (config->ordenacao<1 || config->ordenacao>7)
			tipoDeErro(9);
	}
	while(config->ordenacao<1 || config->ordenacao>6);
}

void menudeSelecaoArquivo(Config *config)
{
	FILE *arquivo;
	char txt[5]= ".txt";
	do
	{
		system(LIMPA);
		aparenciaMenu();
		aparenciaMenuDescricao(6);
		printf("Digite o nome do arquivo aqui: ");
		scanf("%s", config->nomeArquivo);
		strcat(config->nomeArquivo, txt);
		arquivo = fopen(config->nomeArquivo, "r");
		if(!arquivo)
		{
			tipoDeErro(4);
		}
	}
	while(!arquivo);
	fclose(arquivo);
}

void menudeSelecaoSalvar(Config *config)
{
	FILE *arquivo;
	char txt[5]= ".txt";
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(10);
	printf("Digite o nome do arquivo para salvar: ");
	scanf("%s", config->arqSalvo);
	strcat(config->arqSalvo, txt);
}

void contadorLista(Config *config)
{
	FILE *arquivo;
	config->tamanho=0;
	char caracter;
	arquivo = fopen(config->nomeArquivo, "r");
	for (caracter=fgetc(arquivo); caracter!=EOF; caracter=fgetc(arquivo))
	{
		if (caracter == '\n')
            config->tamanho++;
	}
	fclose(arquivo);
}

void comparacoesListaSequencial(SeqComp *seqcomp)
{
	printf("Lista Sequencial\n");
	printf("-----------------------------------------------------\n\n");
	printf("Comparações | Movimentações | Tempo\n\n");
	printf("Inserir no início:      %lu | %lu | %fs\n", seqcomp[0].cs, seqcomp[0].ms, seqcomp[0].tempo);
	printf("Inserir no fim:         %lu | %lu | %fs\n", seqcomp[1].cs, seqcomp[1].ms, seqcomp[1].tempo);
	printf("Inserir na posição N:   %lu | %lu | %fs\n", seqcomp[2].cs, seqcomp[2].ms, seqcomp[2].tempo);
	printf("Deletar no início:      %lu | %lu | %fs\n", seqcomp[3].cs, seqcomp[3].ms, seqcomp[3].tempo);
	printf("Deletar no fim:         %lu | %lu | %fs\n", seqcomp[4].cs, seqcomp[4].ms, seqcomp[4].tempo);
	printf("Deletar na posição N:   %lu | %lu | %fs\n", seqcomp[5].cs, seqcomp[5].ms, seqcomp[5].tempo);
	printf("Procurar pelo RG:       %lu | %lu | %fs\n", seqcomp[6].cs, seqcomp[6].ms, seqcomp[6].tempo);
	printf("Procurar pela posição:  %lu | %lu | %fs\n", seqcomp[8].cs, seqcomp[7].ms, seqcomp[7].tempo);
	printf("Mostrar lista:          %lu | %lu | %fs\n", seqcomp[15].cs, seqcomp[8].ms, seqcomp[8].tempo);
	printf("Salvar arquivo:         %lu | %lu | %fs\n", seqcomp[16].cs, seqcomp[9].ms, seqcomp[9].tempo);
	printf("Ler arquivo:            %lu | %lu | %fs\n", seqcomp[17].cs, seqcomp[10].ms, seqcomp[10].tempo);
	printf("Apagar arquivo:         %lu | %lu | %fs\n", seqcomp[18].cs, seqcomp[11].ms, seqcomp[11].tempo);
	printf("-----------------------------------------------------\n\n");
}

void comparacoesListaEncadeada(EncadComp *encomp)
{
	printf("Lista Encadeada\n");
	printf("-----------------------------------------------------\n\n");
	printf("Comparações | Movimentações | Tempo\n\n");
	printf("Inserir no início:      %lu | %lu | %fs\n", encomp[0].ce, encomp[0].me, encomp[0].tempo);
	printf("Inserir no fim:         %lu | %lu | %fs\n", encomp[1].ce, encomp[1].me, encomp[1].tempo);
	printf("Inserir na posição N:   %lu | %lu | %fs\n", encomp[2].ce, encomp[2].me, encomp[2].tempo);
	printf("Deletar no início:      %lu | %lu | %fs\n", encomp[3].ce, encomp[3].me, encomp[3].tempo);
	printf("Deletar no fim:         %lu | %lu | %fs\n", encomp[4].ce, encomp[4].me, encomp[4].tempo);
	printf("Deletar na posição N:   %lu | %lu | %fs\n", encomp[5].ce, encomp[5].me, encomp[5].tempo);
	printf("Procurar pelo RG:       %lu | %lu | %fs\n", encomp[6].ce, encomp[6].me, encomp[6].tempo);
	printf("Procurar pela posição:  %lu | %lu | %fs\n", encomp[7].ce, encomp[7].me, encomp[7].tempo);
	printf("Mostrar lista:          %lu | %lu | %fs\n", encomp[8].ce, encomp[8].me, encomp[8].tempo);
	printf("Salvar arquivo:         %lu | %lu | %fs\n", encomp[9].ce, encomp[9].me, encomp[9].tempo);
	printf("Ler arquivo:            %lu | %lu | %fs\n", encomp[10].ce, encomp[10].me, encomp[10].tempo);
	printf("Apagar arquivo:         %lu | %lu | %fs\n", encomp[11].ce, encomp[11].me, encomp[11].tempo);
	printf("-----------------------------------------------------\n\n");
}


void comparacoesListaOrdenada(OrdComp *ordcomp)
{
	printf("Lista Ordenada\n");
	printf("-----------------------------------------------------\n\n");
	printf("Comparações | Movimentações | Tempo\n\n");
	printf("Selection-Sort:         %lu | %lu | %fs\n", ordcomp[0].co, ordcomp[0].mo, ordcomp[0].tempo);
	printf("Insertion-Sort:         %lu | %lu | %fs\n", ordcomp[1].co, ordcomp[1].mo, ordcomp[1].tempo);
	printf("Bubble-Sort:            %lu | %lu | %fs\n", ordcomp[2].co, ordcomp[2].mo, ordcomp[2].tempo);
	printf("Shell-Sort:             %lu | %lu | %fs\n", ordcomp[3].co, ordcomp[3].mo, ordcomp[3].tempo);
	printf("Quick-Sort:             %lu | %lu | %fs\n", ordcomp[4].co, ordcomp[4].mo, ordcomp[4].tempo);
	printf("Merge-Sort:             %lu | %lu | %fs\n", ordcomp[5].co, ordcomp[5].mo, ordcomp[5].tempo);
	printf("Pesquisa pelo RG:       %lu | %lu | %fs\n", ordcomp[6].co, ordcomp[6].mo, ordcomp[6].tempo);
	printf("Procurar pela posição:  %lu | %lu | %fs\n", ordcomp[7].co, ordcomp[7].mo, ordcomp[7].tempo);
	printf("Pesquisa Binária:       %lu | %lu | %fs\n", ordcomp[8].co, ordcomp[8].mo, ordcomp[8].tempo);
	printf("Mostrar Lista:          %lu | %lu | %fs\n", ordcomp[9].co, ordcomp[9].mo, ordcomp[9].tempo);
	printf("Apagar Ordenação:       %lu | %lu | %fs\n", ordcomp[10].co, ordcomp[10].mo, ordcomp[10].tempo);
	printf("-----------------------------------------------------\n\n");
}

void explicacaoPrograma(void)
{
	char continuar;
	system(LIMPA);
	aparenciaMenu();
	aparenciaMenuDescricao(11);
	printf("Ideia: Utilizar o trabalho passado e adicionar as\n"
		   "operações de busca e ordenação com as diversas\n"
		   "combinações, para assim saber escolher a melhor para\n"
		   "cada situação.\n\n");
	
	printf("Ordenação: Existem dois tipos de ordenação,\n"
		   "sendo eles: Direta e Indireta\n\n");
	
	printf("Métodos de Ordenação: Existem dois tipos de métodos\n"
		   "para ordenar uma lista (interna), sendo eles: Simples\n"
		   "e eficientes.\n\n");
	
	printf("Busca Binária:\n\n");
	
	printf("\n\nDigite qualquer tecla para continuar:\n");
	ler_string(&continuar);
}



void fimDoPrograma(void)
{
	system(LIMPA);
	printf("*****************************************************\n");
	printf("                    FIM DO PROGRAMA\n");
	printf("*****************************************************\n");
	sleep(3);
}