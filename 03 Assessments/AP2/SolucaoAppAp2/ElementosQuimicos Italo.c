#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <unistd.h>


//Struct do elemento
typedef struct{
    char nome[30]; //Nome do elemento

    //Propriedades periódicas
    float raioAtomico; //SI pm
    float energiaIonizacao; //SI kJ/mol
    float eletronegatividade; //adimensional
    float eletropositividade; //adimensional
    float eletroafinidade; //kJ/mol

    //Propriedades da tabela (calculados automaticamente pelo programa)
    char periodo[20]; //1º ao 7º período ou série dos lantanídeos e dos actinídeos
    char familia[3]; //Família 1A a 8A (elementos representativos) e 1B a 8B (elementos de transição/metais de transição)

    //Propriedades físicas
    float pontoFusao; //SI K
    float pontoEbulicao; //SI K
    float densidade; //SI kg/m³
    float volumeMolar; //m³/mol

    //link próximo item da lista
    struct Elemento *link;

}Elemento;

//Declaração das funções do Programa
int menu();
void opcao(Elemento *lista, int opt);
void insereElemento(Elemento *lista);
void inicia(Elemento *lista);
void exibeQuant(Elemento *lista);
int vazia(Elemento *lista);
void alterarElemento(Elemento *lista);
void deletarElemento(Elemento *lista);
void consultarElemento(Elemento *lista);
void exibirTudo(Elemento *lista);
void leitura(Elemento *lista);
void exportar(Elemento *lista);
void limpartela();

//Declaração da variável global do Arquivo
FILE *arq;


int main (){
    setlocale(LC_ALL, "");

    int opt; //Variável da opção do menu
    char opt2; //Variável da opção "Carregar dados da sessão anterior?"

    Elemento *lista;
    lista = (Elemento *) malloc(sizeof(Elemento)); //Aloca nó Head da lista

    //Checa se possui memória disponível para alocar o nó head
    if(!lista){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }

    inicia(lista);

    printf("Bem vindo ao programa de cadastro de Elementos Químicos.\n\n");

    //Verifica se o programa já foi utilizado. Verificação acontece ao checar a existência do arquivo cadastroQuimico.txt.
    if (access("cadastroQuimico.txt", F_OK) != -1){
        printf("Identificamos que você já usou o programa pelo menos uma vez.\nDeseja carregar as informações da sua sessão anterior? Sim [S] ou Não [N]: ");
        setbuf(stdin,NULL);
        scanf(" %c", &opt2);
        //Se identificada a utilização prévia do programa, pergunta ao usuário se deseja carregar as informações salvas.
        if (opt2 == 's' || opt2 == 'S') {
            leitura(lista);

            if (vazia(lista)){
                printf("O arquivo foi carregado com sucesso, no entanto o mesmo não possui nenhum elemento cadastrado.\n");
                printf("Se deseja tentar novamente, reinicie o programa.\n");
                printf("Caso contrário, aguarde que o programa iniciará como se fosse a primeira vez que o estivesse utilizando.\n\n");
                Sleep(4000);
            } else {
                printf("O arquivo foi carregado com sucesso.");
            }
        }
   }
    //Chama o menu e repete até o usuário selecionar a opção 8 (Fechar aplicação).
    do{
        opt = menu();
        opcao(lista, opt);
    }
    while (opt!=8);

    free(lista);
    return 0;
}

//Função menu
int menu(){
    int opt;

    printf("\n|-------    Cadastro de Elementos Químicos     -------|");
    printf("\n|                                                     |");
    printf("\n|      1. Exibir quantidade de elementos cadastrados  |");
    printf("\n|      2. Inserir novo elemento                       |");
    printf("\n|      3. Alterar elemento já cadastrado              |");
    printf("\n|      4. Deletar elemento já cadastrado              |");
    printf("\n|      5. Consultar elemento                          |");
    printf("\n|      6. Exibir todos os elementos cadastrados       |");
    printf("\n|      7. Exportar os elementos cadastrados           |");
    printf("\n|      8. Fechar aplicação                            |");
    printf("\n|                                                     |");
    printf("\n|-----------------------------------------------------|");


    printf("\n\nSelecione uma opção do menu: ");
    scanf("%d", &opt);


    return opt;
}//end menu

//Função Switch Case do menu
void opcao(Elemento *lista, int opt){
    int opt3 = 0; //Variável para exportar ou não os elementos cadastrados antes de encerrar a aplicação
    switch (opt){
        case 1:
            exibeQuant(lista);
            break;

        case 2:
            insereElemento(lista);
            break;

        case 3:
            alterarElemento(lista);
            break;

        case 4:
            deletarElemento(lista);
            break;

        case 5:
            consultarElemento(lista);
            break;

        case 6:
            exibirTudo(lista);
            break;

        case 7:
            exportar(lista);
            break;

        case 8:
            printf("\n\nLembre-se de exportar os elementos cadastrados antes de encerrar a aplicação.");
            printf("\nCaso deseje exportar os elementos selecione [1], caso não deseje exportar ou já tenha exportado selecione [2]: ");
            setbuf(stdin,NULL);
            scanf("%d", &opt3);
            if (opt3 == 1){
                exportar(lista);
                printf("\n\nElementos exportados com sucesso.");
            }
            printf("Aplicação sendo encerrada...");
            Sleep(3000);
            exit(1);

        default: printf("Comando inválido.\n\n");
    }

}//end opcao


//Função para iniciar uma lista simplesmente encadeada.
void inicia(Elemento* lista){
    lista->link = NULL;
}

//Função para inserir novo elemento no começo da lista
void insereElemento(Elemento *lista){
    Elemento *p;                                //Declara novo nó na lista
    p = (Elemento *) malloc (sizeof(Elemento)); //Aloca novo nó na memória

    //Checa se possui memória disponível para alocar o novo nó
    if(!p){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }

    printf("\n\nTodos os campos são obrigatórios, caso não possua a informação sobre algum campo preencha com o valor 0 (zero)");

    setbuf(stdin,NULL);
    printf("\nDigite o nome do elemento: ");
    fgets(p->nome, 30, stdin);
    p->nome[strcspn(p->nome, "\n")] = 0;

    printf("\n-- Propriedades periódicas --");
    printf("\nDigite o raio atômico do elemento: ");
    scanf("%f", &p->raioAtomico);
    printf("\nDigite a energia de ionização do elemento: ");
    scanf("%f", &p->energiaIonizacao);
    printf("\nDigite a eletronegatividade do elemento: ");
    scanf("%f", &p->eletronegatividade);
    printf("\nDigite a eletropositividade do elemento: ");
    scanf("%f", &p->eletropositividade);
    printf("\nDigite a eletroafinidade do elemento: ");
    scanf("%f", &p->eletroafinidade);

    printf("\n-- Propriedades físicas --");
    printf("\nDigite o ponto de fusão do elemento: ");
    scanf("%f", &p->pontoFusao);
    printf("\nDigite o ponto de ebulição do elemento: ");
    scanf("%f", &p->pontoEbulicao);
    printf("\nDigite a densidade do elemento: ");
    scanf("%f", &p->densidade);
    printf("\nDigite o volume molar do elemento: ");
    scanf("%f", &p->volumeMolar);

    setbuf(stdin,NULL);
    printf("\nDigite o período ao qual o elemento pertence: ");
    fgets(p->periodo, 30, stdin);
    p->periodo[strcspn(p->periodo, "\n")] = 0;

    setbuf(stdin,NULL);
    printf("\nDigite a família a qual o elemento pertence (1A a 8B): ");
    fgets(p->familia, 30, stdin);
    p->familia[strcspn(p->familia, "\n")] = 0;

    Elemento *svlink;
    svlink = lista->link; //Cria um Salva link para armazenar o link de Head
    lista->link = p;                //Armazena p no link de Head
    p->link = svlink;               //Armazena o anterior link de head em p

    limpartela();
}

//Função para exibir a quantidade de elementos já cadastrados
void exibeQuant(Elemento *lista){
    if(vazia(lista)){
        printf("\nNenhum elemento cadastrado.");
        return;
    }

    int count = 0;
    Elemento *svlink;
    svlink = lista->link;
    while (svlink != NULL){
        count++;
        svlink = svlink->link;
    }

    printf("\nO cadastro já possui %d elementos", count);
    limpartela();
}

//Função para checar se a lista encontra-se vazia, ou seja, nenhum elemento foi cadastrado
int vazia(Elemento *lista){
    if(lista->link == NULL)
        return 1;
    else
        return 0;
}

//Função para alterar os dados de algum elemento já cadastrado.
void alterarElemento(Elemento *lista){
    if(vazia(lista)){
        printf("\nNenhum elemento cadastrado.");
        return;
    }

    char procurado[30];

    setbuf(stdin,NULL);
    printf("\nDigite o nome do elemento que deseja alterar: ");
    fgets(procurado, 30, stdin);

    Elemento *svlink;
    svlink = lista->link;
    while ((svlink != NULL) && (strcmp(svlink->nome,procurado) != 0)){
       svlink = svlink->link;
    }

    if (svlink == NULL){
        printf("\nElemento não cadastrado.");
        return;
    }

    printf("\n\n Lembre-se que todos os campos são obrigatórios, caso não possua a informação sobre algum campo preencha com o valor 0 (zero)");

    printf("\nAltere as propriedades do elemento %s", procurado);

    printf("\n\n-- Propriedades periódicas --");
    printf("\nDigite o raio atômico do elemento: ");
    scanf("%f", &svlink->raioAtomico);
    printf("\nDigite a energia de ionização do elemento: ");
    scanf("%f", &svlink->energiaIonizacao);
    printf("\nDigite a eletronegatividade do elemento: ");
    scanf("%f", &svlink->eletronegatividade);
    printf("\nDigite a eletropositividade do elemento: ");
    scanf("%f", &svlink->eletropositividade);
    printf("\nDigite a eletroafinidade do elemento: ");
    scanf("%f", &svlink->eletroafinidade);

    printf("\n\n-- Propriedades físicas --");
    printf("\nDigite o ponto de fusão do elemento: ");
    scanf("%f", &svlink->pontoFusao);
    printf("\nDigite o ponto de ebulição do elemento: ");
    scanf("%f", &svlink->pontoEbulicao);
    printf("\nDigite a densidade do elemento: ");
    scanf("%f", &svlink->densidade);
    printf("\nDigite o volume molar do elemento: ");
    scanf("%f", &svlink->volumeMolar);

    printf("\n\n-- Propriedades da Tabela --");
    setbuf(stdin,NULL);
    printf("\nDigite o período ao qual o elemento pertence: ");
    fgets(svlink->periodo, 30, stdin);
    svlink->periodo[strcspn(svlink->periodo, "\n")] = 0;

    setbuf(stdin,NULL);
    printf("\nDigite a família a qual o elemento pertence (1A a 8B): ");
    fgets(svlink->familia, 30, stdin);
    svlink->familia[strcspn(svlink->familia, "\n")] = 0;

    limpartela();
}

//Função para deletar algum elemento já cadastrado da lista
void deletarElemento(Elemento *lista){
    if(vazia(lista)){
        printf("Nenhum elemento cadastrado.");
        return;
    }

    char procurado[30];

    setbuf(stdin,NULL);
    printf("\nDigite o nome do elemento que deseja excluir: ");
    fgets(procurado, 30, stdin);

    Elemento *svlink;
    svlink = lista->link;
    Elemento *svlinkAnt;
    svlinkAnt = NULL;
    while ((svlink != NULL) && (strcmp(svlink->nome,procurado) != 0)){
       svlinkAnt = svlink;
       svlink = svlink->link;
    }

    if (svlink == NULL){
        printf("\n\nElemento não cadastrado.");
        return;
    }

    if (svlinkAnt == NULL){
        lista->link = svlink->link;
    } else {
        svlinkAnt->link = svlink->link;
    }

    free(svlink);
    printf("\n\nElemento %s foi deletado.", procurado);

    limpartela();
}

//Função para consultar os dados de apenas um elemento
void consultarElemento(Elemento *lista){
    if(vazia(lista)){
        printf("\nNenhum elemento cadastrado.");
        return;
    }

    char procurado[30];
    setbuf(stdin,NULL);
    printf("\nDigite o nome do elemento que deseja consultar: ");
    fgets(procurado, 30, stdin);

    Elemento *svlink;
    svlink = lista->link;
    while ((svlink != NULL) && (strcmp(svlink->nome,procurado) != 0)){
       svlink = svlink->link;
    }

    if (svlink == NULL){
        printf("\nElemento não cadastrado.");
        return;
    }

    printf("\nElemento: %s", procurado);

    printf("\n-- Propriedades periódicas --");
    printf("\nRaio atômico do elemento: %.2f pm", svlink->raioAtomico);
    printf("\nEnergia de ionização do elemento: %.2f kJ/mol", svlink->energiaIonizacao);
    printf("\nEletronegatividade do elemento: %.2f", svlink->eletronegatividade);
    printf("\nEletropositividade do elemento: %.2f", svlink->eletropositividade);
    printf("\nEletroafinidade do elemento: %.2f kJ/mol", svlink->eletroafinidade);

    printf("\n\n-- Propriedades físicas --");
    printf("\nPonto de fusão do elemento: %.2f K", svlink->pontoFusao);
    printf("\nPonto de ebulição do elemento: %.2f K", svlink->pontoEbulicao);
    printf("\nDensidade do elemento: %.2f kg/m³", svlink->densidade);
    printf("\nVolume molar do elemento: %.2f m³/mol", svlink->volumeMolar);

    printf("\n\nO elemento pertence ao período: %s", svlink->periodo);
    printf("\nO elemento pertence a família: %s", svlink->familia);

    limpartela();
}

//Função para exibir o relatório com todos os elementos já cadastrados
void exibirTudo(Elemento *lista){
    if(vazia(lista)){
        printf("\nNenhum elemento cadastrado.");
        return;
    }

    printf("\n\nAbaixo estão apresentados a relação de todos os elementos cadastrados.");

    Elemento *svlink;
    svlink = lista->link;
    while (svlink != NULL){
      printf("\n\n|--------------------------------------------|");
        printf("\n Nome do elemento: %s", svlink->nome);
        printf("\n          -- Propriedades periódicas --");
        printf("\n Raio atômico do elemento: %.2f pm", svlink->raioAtomico);
        printf("\n Energia de ionização do elemento: %.2f kJ/mol", svlink->energiaIonizacao);
        printf("\n Eletronegatividade do elemento: %.2f", svlink->eletronegatividade);
        printf("\n Eletropositividade do elemento: %.2f", svlink->eletropositividade);
        printf("\n Eletroafinidade do elemento: %.2f kJ/mol\n", svlink->eletroafinidade);
        printf("\n          -- Propriedades físicas --");
        printf("\n Ponto de fusão do elemento: %.2f K", svlink->pontoFusao);
        printf("\n Ponto de ebulição do elemento: %.2f K", svlink->pontoEbulicao);
        printf("\n Densidade do elemento: %.2f kg/m³", svlink->densidade);
        printf("\n Volume molar do elemento: %.2f m³/mol\n", svlink->volumeMolar);
        printf("\n O elemento pertence ao período: %s", svlink->periodo);
        printf("\n O elemento pertence a família: %s", svlink->familia);
        printf("\n|--------------------------------------------|\n\n");
        svlink = svlink->link;
    }

    limpartela();
}

//Função que carrega os elementos salvos em txt na lista simplesmente encadeada do programa em execução
void leitura(Elemento *lista){
    char *result;

    arq = fopen("cadastroQuimico.txt", "rt");
    if (arq == NULL){
        printf("Ocorreu um problema na abertura do arquivo! Se deseja tentar novamente, reinicie o programa.\n");
        printf("Caso contrário, aguarde que o programa iniciará como se fosse a primeira vez que o estivesse utilizando.\n\n");
        Sleep(4000);
        return;
    }

    Elemento *p;                                //Declara novo nó na lista

    Elemento *svlink;
     //Cria um Salva link para armazenar o link de Head

    //Checa se possui memória disponível para alocar o novo nó
    if(!p){
        printf("Sem memoria disponivel!\n");
        exit(1);
    }

    while (!feof(arq)){
    p = (Elemento *) malloc (sizeof(Elemento));
    svlink = lista->link;
    result = fscanf(arq, "%s %f %f %f %f %f %f %f %f %f %s %s", &p->nome, &p->raioAtomico, &p->energiaIonizacao, &p->eletronegatividade, &p->eletropositividade, &p->eletroafinidade, &p->pontoFusao, &p->pontoEbulicao, &p->densidade, &p->volumeMolar, &p->periodo, &p->familia);

    lista->link = p;                //Armazena p no link de Head
    p->link = svlink;               //Armazena o anterior link de head em p
    }

    fclose(arq);
}

//Função que exporta os elementos cadastrados no programa para o arquivo txt
void exportar(Elemento *lista){
    char str[100];
    arq = fopen("cadastroQuimico.txt", "wt");
    if (arq == NULL){
        printf("\nProblemas na criação do arquivo. Verifique espaço em disco e tente novamente.");
        return;
    }

    Elemento *svlink;
    svlink = lista->link;
    while (svlink != NULL){
        fputs(svlink->nome, arq);
        fputs("\t", arq);
        str[0] = '\0';
        fprintf(arq, "%.2f\t", svlink->raioAtomico);
        fprintf(arq, "%.2f\t", svlink->energiaIonizacao);
        fprintf(arq, "%.2f\t", svlink->eletronegatividade);
        fprintf(arq, "%.2f\t", svlink->eletropositividade);
        fprintf(arq, "%.2f\t", svlink->eletroafinidade);
        fprintf(arq, "%.2f\t", svlink->pontoFusao);
        fprintf(arq, "%.2f\t", svlink->pontoEbulicao);
        fprintf(arq, "%.2f\t", svlink->densidade);
        fprintf(arq, "%.2f\t", svlink->volumeMolar);
        fputs(svlink->periodo, arq);
        fputs("\t", arq);
        str[0] = '\0';
        fputs(svlink->familia, arq);
        fputs("\t", arq);
        str[0] = '\0';
        svlink = svlink->link;
    }

    fclose(arq);
    printf("\nArquivos exportados com sucesso.");

    limpartela();
}

//Função que pergunta se o usuário gostaria de limpar a tela. Ela é chamada ao final de cada uma das outras funções.
void limpartela(){
    char opt;
    printf("\n\nDeseja limpar a tela? Sim [s] ou Não [n]: ");

    setbuf(stdin,NULL);
    scanf(" %c", &opt);

    if (opt == 's' || opt == 'S') {
        system("clear");
        system("cls");
    }
}
