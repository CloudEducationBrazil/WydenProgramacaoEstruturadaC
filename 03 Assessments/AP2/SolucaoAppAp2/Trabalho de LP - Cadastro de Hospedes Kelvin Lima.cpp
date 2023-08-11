#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

 typedef struct lista{
     char nome[40];
     char email[40];
     char cpf[20];
     char rg[20];
     char nacionalidade[20];
     char celular[16];
     char sexo [5];
     char nascimento [12];
     unsigned long int codigo;
     struct lista* prox;   
   }Lista;
   
   //Declaração de funções.
   Lista* inserir_clientes(Lista* primeiro);
   void listar_clientes(Lista* primeiro);
   Lista* excluir_clientes(Lista* primeiro);
   void alterar_clientes(Lista* primeiro);

main() 
{ 
   //Declaração de variáveis
   Lista *primeiro= NULL;
   char opcao;
     
   //Artifício para repetir o programa.
   while(opcao!='s')   
   {  
     //Menu de opcoes 
      printf(" ------------------------------------------------------------------------------\n");
      printf(" | ");printf("\t\t\t     CADASTRO DE HOSPEDES");printf("\t\t\t      |\n");
      printf(" ------------------------------------------------------------------------------\n");
      printf("\t       ------------\t\t\t\t       ");
      printf("\n               |   MENU   ");printf("|\t\t\t\t      \n");
      printf("   ------------------------------------- \n");
      printf("   | <A>  Novo cadastro                |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <B>  Listar                       |\n");      
      printf("   |-----------------------------------|\n");
      printf("   | <C>  Excluir cadastro             |\n");      
      printf("   |-----------------------------------|\n");
      printf("   | <D>  Alterar cadastro             |\n"); 
      printf("   |-----------------------------------|\n");     
      printf("   | <E>  Exportar cadastros           |\n");      
      printf("   |-----------------------------------|\n");
      printf("   | <S>  Sair                         |\n");
      printf("   -------------------------------------");
      printf("\n\n\n\n");
      printf("\t\t\t      Disciplina: Linguagem de Programacao\n");
      printf("\t\t\t      Codigo da Turma: 4 5LIEE-NT1 \n");
      printf("\t\t\t      Aluno: Kelvin Lima - 171031297\n");
      printf("\t\t\t      Professor: Heleno Filho");
      
      //Lendo a opcao do menu   
      fflush(stdin);
      opcao= getch(); 
      
      //Menu de opcoes
      switch(opcao)
      {
         case 'A':   
         case 'a':   
              //Inserindo os cliente.
              fflush(stdin);
              system("cls");
              printf(" ------------------------------------------------------------------------------\n");
              printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");
              printf(" ------------------------------------------------------------------------------\n");
              primeiro= inserir_clientes(primeiro);
         getch();
         system("cls"); 
         break;
         
         case 'B':   
         case 'b':       
              //Listando os cliente.
              system ("cls");
              printf(" ------------------------------------------------------------------------------\n");
              printf(" | ");printf("\t\t\t     CLIENTES CADASTRADOS");printf("\t\t\t      |\n");
              printf(" ------------------------------------------------------------------------------\n");
              listar_clientes(primeiro);
         getch();
         system("cls");
         break;
         
         case 'C':   
         case 'c':   
              //Excluindo clientes da lista.
              system ("cls");
              printf(" ------------------------------------------------------------------------------\n");
              printf(" | ");printf("\t\t\t        EXCLUIR CADASTROS");printf("\t\t\t      |\n");
              printf(" ------------------------------------------------------------------------------\n");
              primeiro= excluir_clientes(primeiro);
         getch();
         system("cls");
         break;

         case 'D':   
         case 'd':   
              //Alterando clientes da lista. 
              system ("cls");
              printf(" ------------------------------------------------------------------------------\n");
              printf(" | ");printf("\t\t\t       ALTERAR CADASTRADOS");printf("\t\t\t      |\n");
              printf(" ------------------------------------------------------------------------------\n");
              alterar_clientes(primeiro);
         getch();
         system("cls");
         break;
         
         case 'E':   
         case 'e':   
              //Exportando dados da lista.
              
              system ("cls");
              printf(" ------------------------------------------------------------------------------\n");
              printf(" | ");printf("\t\t\t        EXPORTAR CADASTROS");printf("\t\t\t      |\n");
              printf(" ------------------------------------------------------------------------------\n"); 
			     
			     struct lista;
			     Lista cl;
				 FILE *ArqLP;
                 ArqLP = fopen("Relatorio_LP.txt", "wt");
                
                 if ( ArqLP == NULL ) { printf("Erro ao abrir o arquivo"); return 0; };
                  fprintf(ArqLP," ------------------------------------------------------------------------------\n");
                  fprintf(ArqLP," | ");fprintf(ArqLP,"\t\t\t     CLIENTES CADASTRADOS");fprintf(ArqLP,"\t\t\t      |\n");
                  fprintf(ArqLP," ------------------------------------------------------------------------------\n");
                  
                 Lista* atual;
     
                 for(atual= primeiro ; atual!= NULL; atual= atual->prox){
                   fprintf(ArqLP,"\n  Nome: ");
                   fprintf(ArqLP,"%s", atual->nome);
                   fprintf(ArqLP,"\n  Sexo (M-Masculino ou F-Feminino): ",135);
                   fprintf(ArqLP,"%s", atual->sexo);
                   fprintf(ArqLP,"\n  Data de Nascimento: ",135);
                   fprintf(ArqLP,"%s", atual->nascimento);
                   fprintf(ArqLP,"\n  Email: ",135);
                   fprintf(ArqLP,"%s", atual->email);
                   fprintf(ArqLP,"\n  CPF: ",135);
                   fprintf(ArqLP,"%s", atual->cpf);
                   fprintf(ArqLP,"\n  RG: ",135);
                   fprintf(ArqLP,"%s", atual->rg);
                   fprintf(ArqLP,"\n  Nacionalidade: ",135);
                   fprintf(ArqLP,"%s", atual->nacionalidade);
                   fprintf(ArqLP,"\n  Celular: ",135);
                   fprintf(ArqLP,"%s", atual->celular);
                   fprintf(ArqLP,"\n  Código do Hospede: ",162 );
                   fprintf(ArqLP,"%u", atual->codigo);
                   fprintf(ArqLP,"\n\n");
                   fprintf(ArqLP," ------------------------------------------------------------------------------\n");
}
                 fclose(ArqLP);
                 
                 printf("\n");printf("Arquivo gerado com sucesso...");printf("\n");
                 
                 return 0;
                 
            getch();
            system("cls");
            break;
            
         
         case 'S':   
         case 's':       
              //Sair do programa.
              opcao='s';
         break;
         
         default:     
              //Previne a situação de um usuário qualquer, digitar uma opcão inexistente no menu.
              system("cls");        
         break; 
      } 
   }  
}

Lista* inserir_clientes (Lista *primeiro){ 
     Lista cliente;
     Lista *atual= primeiro;
     char identificador= 'F';
     
     //Lendo as informações do cliente.
     printf("  Nome: ");
     fflush (stdin); fgets(cliente.nome, 40, stdin); printf ("\n");
     printf("  Sexo (M-Masculino ou F-Feminino): ");
     fflush (stdin); fgets(cliente.sexo, 5, stdin); printf ("\n");
     printf("  Data de Nascimento: ");
     fflush (stdin); fgets(cliente.nascimento, 12, stdin); printf ("\n");
     printf("  Email: ",135);
     fflush (stdin); fgets(cliente.email, 40, stdin); printf ("\n");
     printf("  CPF: ");
     fflush (stdin); fgets(cliente.cpf, 20, stdin); printf ("\n");
     printf("  RG: ");
     fflush (stdin); fgets(cliente.rg, 20, stdin); printf ("\n");
     printf("  Nacionalidade: ");
     fflush (stdin); fgets(cliente.nacionalidade, 20, stdin); printf ("\n");
     printf("  Celular: ");
     fflush (stdin); fgets(cliente.celular, 16, stdin); printf ("\n");
     printf("  C%cdigo do Hospede (Somente Numeros): ",162);
     scanf("%u",&cliente.codigo);printf ("\n");
     
     //Verificando se o cadastro já existe.
     for(atual=primeiro; atual!=NULL; atual=atual->prox){
        if(atual->codigo==cliente.codigo){
            identificador= 'V'; 
            break;
        }    
     }

     if(identificador!='V' && (strlen(cliente.nome)!=1 && strlen(cliente.email)!=1)){
         //Alocando os espaços e guardando as informações do cliente.
         Lista* NovoCliente=(Lista*) malloc (sizeof(Lista));       
         strcpy(NovoCliente->nome, cliente.nome);
         strcpy(NovoCliente->sexo, cliente.sexo);
         strcpy(NovoCliente->nascimento, cliente.nascimento);
         strcpy(NovoCliente->email, cliente.email);
         strcpy(NovoCliente->cpf, cliente.cpf);
         strcpy(NovoCliente->rg, cliente.rg);
         strcpy(NovoCliente->nacionalidade, cliente.nacionalidade);
         strcpy(NovoCliente->celular, cliente.celular);
         
         
         NovoCliente->codigo= cliente.codigo;
         NovoCliente->prox= primeiro;
         printf("  Cadastro realizado com sucesso.");
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
         return NovoCliente;    
     }else{
         printf("  Cadastro inv%clido.",160);
         printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
         return primeiro;
     }
}

void listar_clientes (Lista* primeiro){
     Lista* atual;//Ponteiro para percorrer a lista sem perder a referência do primeiro elemento da lista.
     
     //Imprimindo os cliente da lista, e suas repectivas informações.
     for(atual= primeiro ; atual!= NULL; atual= atual->prox){
        printf("\n  Nome: ");
        printf("%s", atual->nome);
        printf("\n  Sexo (M-Masculino ou F-Feminino): ",135);
        printf("%s", atual->sexo);
        printf("\n  Data de Nascimento: ",135);
        printf("%s", atual->nascimento);
        printf("\n  Email: ",135);
        printf("%s", atual->email);
        printf("\n  CPF: ",135);
        printf("%s", atual->cpf);
        printf("\n  RG: ",135);
        printf("%s", atual->rg);
        printf("\n  Nacionalidade: ",135);
        printf("%s", atual->nacionalidade);
        printf("\n  Celular: ",135);
        printf("%s", atual->celular);
        printf("\n  C%cdigo do Hospede: ",162 );
        printf("%u", atual->codigo);
        printf("\n\n");
        printf(" ------------------------------------------------------------------------------\n");
     }
     if(primeiro==NULL)
        printf("  Nenhum cliente cadastrado.");
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}

Lista* excluir_clientes(Lista *primeiro){
     
     Lista *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
     Lista *atual= primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
     unsigned long int codigo=0;
     
     //Requisitando e lendo o código do cliente a ser excluído.
     printf("  C%cdigo do  a ser exclu%cdo: ", 162,161);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Procurando o cliente na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        anterior= atual;
        atual= atual->prox;
     }
     
     //Mensagem caso o cliente não seja encontrado.
     if(atual==NULL){
        printf("\n  Cliente n%co encontrado.", 198); 
        printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
        return primeiro;
     }
     
     //Excluindo o primeiro cliente da lista.   
     if(anterior==NULL){
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161); 
        primeiro= atual->prox;
     //Excluindo um cliente do meio da lista.
     }else{
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161);
        anterior->prox= atual->prox;
     }
     
     //Desalocando o espaço da memória.
     free(atual);
     printf("\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
     return primeiro;     
}

//Função para alterar clientes.
void alterar_clientes(Lista* primeiro){     
     char nome_substituto[40], email_substituto[40], cpf_substituto[20], celular_substituto[16],rg_substituto[20],sexo_substituto[5],nascimento_substituto[12],nacionalidade_substituto[20];
     unsigned long int codigo;  
     Lista* atual=primeiro;
     
     //Requisitando e lendo o código do cliente a ser alterado.
     printf("  C%cdigo do cliente a ser alterado: ", 162);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Procurando o cliente na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        atual= atual->prox;
     }
     
     //Alterando os dados do cliente.
     if(atual!=NULL){
        printf("\n  Novo nome: ");
        fflush (stdin); fgets(nome_substituto, 40, stdin); 
        strcpy(atual->nome,nome_substituto);
        printf("\n  Novo Sexo (M-Masculino ou F-Feminino): ");
        fflush (stdin); fgets(sexo_substituto, 5, stdin); 
        strcpy(atual->sexo,sexo_substituto);
        printf("\n  Nova Data de Nascimento: ");
        fflush (stdin); fgets(nascimento_substituto, 12, stdin); 
        strcpy(atual->nascimento,nascimento_substituto);
        printf("\n  Novo email: ",135);
        fflush (stdin); fgets(email_substituto, 40, stdin);
        strcpy(atual->email,email_substituto);
        printf("\n  Novo CPF: ");
        fflush (stdin); fgets(cpf_substituto, 20, stdin); 
        strcpy(atual->cpf,cpf_substituto);
        printf("\n  Novo RG: ");
        fflush (stdin); fgets(rg_substituto, 20, stdin); 
        strcpy(atual->rg,rg_substituto);
        printf("\n  Nova Nacionalidade: ");
        fflush (stdin); fgets(nacionalidade_substituto, 20, stdin); 
        strcpy(atual->nacionalidade,nacionalidade_substituto);
        printf("\n  Novo Celular: ");
        fflush (stdin); fgets(celular_substituto, 16, stdin); 
        strcpy(atual->celular,celular_substituto);
        printf ("\n");
        printf("  Dados alterados com sucesso.");
     }else{
        printf("\n  Cliente n%co encontrado.",198);
     }
     printf("\n\n\n  PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU PRINCIPAL.");
}
