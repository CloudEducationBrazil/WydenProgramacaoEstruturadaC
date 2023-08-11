#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
  /*Criando a struct */
    struct produto
    {
    int id;
    char nome[20];
    char descricao[1000];
    int qtd;
    };
    struct produto;

    int controle = 0;
    int controleID = 1;
    struct produto produtos[100];
    FILE *estoque;
    char linha[500];
    int size = 1;
    estoque = fopen("estoque.txt", "r");
    if(estoque){
        while(fgets(linha, 500, estoque)){

        struct produto registro;
        char *comeco, *fim;
        const char *s = linha;

        char *id = NULL;
        const char *comecoid = "id-";
        const char *fimid = "-id";

        if ( comeco = strstr( s, comecoid ) )
        {
            comeco += strlen( comecoid );
            if ( fim = strstr( comeco, fimid ) )
            {
                id = ( char * )malloc( fim - comeco + 1 );
                memcpy( id, comeco, fim - comeco );
                id[fim - comeco] = '\0';
            }
        }
        registro.id =atoi(id);
        free( id );


        char *nome = NULL;

        const char *comecoNome = "n-";
        const char *fimNome = "-n";




        if ( comeco = strstr( s, comecoNome ) )
        {
            comeco += strlen( comecoNome );
            if ( fim = strstr( comeco, fimNome ) )
            {
                nome = ( char * )malloc( fim - comeco + 1 );
                memcpy( nome, comeco, fim - comeco );
                nome[fim - comeco] = '\0';
            }
        }
        strcpy(registro.nome, nome);//registro.nome = &nome[20];

        free( nome );

        char *descricao = NULL;
        const char *comecoDescricao = "des-";
        const char *fimDescricao = "-des";

        if ( comeco = strstr( s, comecoDescricao ) )
        {
            comeco += strlen( comecoDescricao );
            if ( fim = strstr( comeco, fimDescricao ) )
            {
                descricao = ( char * )malloc( fim - comeco + 1 );
                memcpy( descricao, comeco, fim - comeco );
                descricao[fim - comeco] = '\0';
            }
        }
        strcpy(registro.descricao, descricao);

        free( descricao );


        char *quantidade = NULL;
        const char *comecoqtd = "qtd-";
        const char *fimqtd = "-qtd";

        if ( comeco = strstr( s, comecoqtd ) )
        {
            comeco += strlen( comecoqtd );
            if ( fim = strstr( comeco, fimqtd ) )
            {
                quantidade = ( char * )malloc( fim - comeco + 1 );
                memcpy( quantidade, comeco, fim - comeco );
                quantidade[fim - comeco] = '\0';
            }
        }
        registro.qtd =atoi(quantidade);
        free( quantidade );
        controleID = registro.id;
        produtos[(size - 1)] = registro;
        size++;


        }
        controleID +=1;
    }

    printf("proximo id: %d", controleID);
    if(estoque!= NULL)
        fclose(estoque);




    printf("\n---------- Bem vindo ao controle de produtos -----------\n\n\n");
    do{
        fflush(stdin);
        printf("\n------ Lista de acoes -----------\n\n\n");
        printf("1 - Inserir um produto no estoque\n");
        printf("2 - Alterar um produto no estoque\n");
        printf("3 - Excluir um produto no estoque\n");
        printf("4 - Consultar o estoque\n");
        printf("5 - Salvar as alteracoes\n");
        printf("0 - Sair\n");

        printf("Digite uma opcao.\n");

        scanf("%d", &controle);

        if(controle == 1){

            int confirma = 0;
            struct produto novoProduto;

            printf("Nome do produto ......: ");
            fflush(stdin);
            fgets(novoProduto.nome, 20, stdin);



            printf("Descricao ......: ");
            fflush(stdin);
            fgets(novoProduto.descricao, 100, stdin);

            printf("Quantidade ......: ");
            fflush(stdin);
            scanf("%d", &novoProduto.qtd);

            printf("Por favor, confirme os dados do produto.\n\n");
            printf("Nome: %sDescricao: %s\nQuantidade: %d\n", novoProduto.nome, novoProduto.descricao, novoProduto.qtd);
            printf("Digite 1 para confirmar os dados do produto\n");
            fflush(stdin);

            scanf("%d", &confirma);

            if(confirma == 1){
                char linhaNova[500];

                char *pos;
                if ((pos=strchr(novoProduto.nome, '\n')) != NULL){
                    *pos = '\0';
                }

                 if ((pos=strchr(novoProduto.descricao, '\n')) != NULL){
                    *pos = '\0';
                }
                novoProduto.id = controleID;
                produtos[(size-1)] = novoProduto;
                controleID++;
                size++;

            }
            else{
                printf("\nOperacao de insercao cancelada.\n");
            }
          }

        else if(controle == 2){
                int id;
                printf("\nDigite o ID do produto:");
                fflush(stdin);
                scanf("%d", &id);
                if(id < 1){
                    printf("ID invalido.\n");
                }
                else if(id >= (controleID - 1)){
                    printf("Produto nao existente");
                }
                else{
                    int selecao;
                     int pos = -1;
                     for(int i = 0; i < controleID - 1; i++){
                        if(produtos[i].id == id) pos = i;
                    }
                    struct produto registroSelecionado = produtos[pos];
                    printf(" ID: %d\n nome: %s\n descricao:%s\n\n", registroSelecionado.id, registroSelecionado.nome, registroSelecionado.descricao);
                    printf("O que deseja alterar?\n    Digite 1 para alterar o nome\n    Digite 2 para alterar a descricao\n    Digite 3 para alterar a quantidade\n Digite qualquer outra tecla para cancelar.\n");
                    fflush(stdin);
                    scanf("%d", &selecao);

                    if(selecao == 1){
                        char novoNome[20];
                        printf("Digite o novo nome para o produto.\n");
                        fflush(stdin);
                        fgets(novoNome, 20, stdin);

                        char *posicao;
                        if ((posicao=strchr(novoNome, '\n')) != NULL){
                            *posicao = '\0';
                        }
                        strcpy(registroSelecionado.nome, novoNome);

                        produtos[pos] = registroSelecionado;

                    }
                    else if(selecao == 2){
                        char novaDescricao[100];
                        printf("Digite a nova descricao para o produto.\n");
                        fflush(stdin);
                        fgets(novaDescricao, 100, stdin);

                        char *posicao;
                        if ((posicao=strchr(novaDescricao, '\n')) != NULL){
                            *posicao = '\0';
                        }
                        fflush(stdin);
                        strcpy(registroSelecionado.descricao, novaDescricao);
                        produtos[pos]= registroSelecionado;

                    }
                    else if(selecao == 3){
                        int qtd;
                        printf("Digite o novo nome para o produto.\n");
                        fflush(stdin);
                        scanf("%d", &qtd);
                        registroSelecionado.qtd = qtd;
                        produtos[pos] = registroSelecionado;
                    }
                    else{
                        printf("\nOperacao cancelada.\n");
                        fflush(stdin);

                    }

                }
        }
        else if(controle == 3){
                int id;
                printf("\nDigite o ID do produto:");
                scanf("%d", &id);
                if(id < 1){
                    printf("ID invalido.\n");
                }
                else if(id >= (controleID - 1)){
                    printf("Produto nao existente");
                }
                else{
                    int selecao;
                     int pos = -1;
                     for(int i = 0; i < controleID - 1; i++){
                        if(produtos[i].id == id) pos = i;
                    }
                    struct produto registroSelecionado = produtos[pos];
                    printf(" ID: %d\n nome: %s\n descricao:%s\n\n", registroSelecionado.id, registroSelecionado.nome, registroSelecionado.descricao);
                    printf("Pressione 1 para confirmar a exclusao do produto, ou qualquer tecla para cancelar.\n");
                    fflush(stdin);
                    scanf("%d", &selecao);

                        if(selecao == 1){
                            for(int i = pos; i< controleID - 2; i++){
                                produtos[i] = produtos[i+1];
                            }
                            size--;
                        }
                        else{
                            printf("Operacao cancelada.\n");
                        }


                }
        }
        else if(controle == 4){
            for(int i = 0; i < size - 1; i++){
                printf("\nID: %d\n", produtos[i].id);
                printf("Nome: %s\n", produtos[i].nome);
                printf("Descricao: %s\n", produtos[i].descricao);
                printf("Quantidade em estoque: %d\n\n", produtos[i].qtd);
            }
            printf("Pressione qualquer tecla pra continuar");
            getch();

        }
        else if(controle == 5){
            printf("Salvando as alteracoes, nao feche o programa.\n");
            estoque = fopen("estoque.txt", "w");
            for(int i = 0; i < size - 1;i++){
                char linhaNova[500];

                struct produto registro = produtos[i];
                char novoNome[20];
                char novaDescricao[100];

                sprintf(novoNome, "n-%s-n", registro.nome);
                sprintf(novaDescricao, "des-%s-des", registro.descricao);

                strcpy(registro.nome,novoNome);
                strcpy(registro.descricao,novaDescricao);

                sprintf(linhaNova, "id-%d-id %s %s qtd-%d-qtd\n", registro.id, registro.nome, registro.descricao, registro.qtd);

                //salva no txt

                fprintf(estoque, "%s", linhaNova);

            }
            //usando fclose para fechar o arquivo
            fclose(estoque);
            printf("Dados gravados com sucesso! Pressione qualquer tecla pra continuar");
            getch();
        }


        else if(controle == 0){
        printf("\nPressione 0 mais uma vez para confirmar a saida.\n");
        fflush(stdin);
        scanf("%d", &controle);

        }
        else{
            printf("Opcao invalida.\n");
        }

    }while(controle != 0);

}



