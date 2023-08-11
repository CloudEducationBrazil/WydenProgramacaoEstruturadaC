#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_TRANSPORTADORAS 1000
#define MAX 150
#define VALOR_CONTROL -1



/* ESTRUTURAS*/
struct transportadora{
int codigo;
char nome[MAX];
char endereco[MAX];
char cnpj[MAX];
char telefone[MAX];
char site[MAX];
char email[MAX];
};
typedef struct transportadora Transportadora;


Transportadora transportadoras[MAX_TRANSPORTADORAS];
int proximo = 0;

char carregou = 0;




/* opções do menu*/
void menuPrincipal();
void menuInserir();
void menuConsultar();
void menuMostrar();
void menuEditar();
void menuEliminar();
void menuCarregar();
void menuSalvar();
// funções//
int existeTransportadora(int codigoTransportadora); // verifica se existe//
char inserirTransportadora(Transportadora transportadora); //insere novo cadastro//
char eliminarTransportadora(int codigoTransportadora); //elimina codigo da transportadora do arquivo//
char editarTransportadora(Transportadora transportadora); //modifica dados do cadastro//
char carregarArquivo();
char salvarArquivo();
 
// funcao de leitura de strings//
char linha[MAX];
int main()
{
  for (int i = 0; i < MAX_TRANSPORTADORAS; ++i)
  {
    transportadoras[i].codigo = -1;
  }
  setlocale(LC_ALL, "portuguese"); /* Permite imprimir caracteres con til */
  menuPrincipal();
  return 0;
}
void menuPrincipal()
{
char repetir = 1;
int opcao = -1;
// quando o usuario digita um texto ao inves de inserir uma opcao//
do {
    system("clear");
    printf("\n\t\t\t\tMENU PRINCIPAL\n");
    printf("\n\t\t[1]. Inserir uma nova transportadora\n");
    printf("\t\t[2]. Mostrar lista de transportadoras\n");
    printf("\t\t[3]. Deletar uma transportadora\n");
    printf("\t\t[4]. Buscar uma transportadora por nome\n");
    printf("\t\t[5]. Editar um cadastro\n");
    printf("\t\t[6]. Carregar um arquivo\n");
    printf("\t\t[7]. Salvar arquivo\n");
    printf("\t\t[8]. Sair\n");
    printf("\n\t\t Insira uma opcao: ");
     
     //leitura de um numero inteiro//
     scanf(" %d", &opcao);
     switch (opcao) {
         case 1:
            menuInserir();
            break;
         case 2:
             menuMostrar();
             break;
         case 3:
             menuEliminar();
             break;
         case 4:
             menuConsultar();
             break;
         case 5:
            menuEditar();
            break;
         case 6:
            menuCarregar();
            break;
        case 7:
            menuSalvar();
            break;
         case 8:
            repetir = 0;
         break;

     }
} while (repetir);
}
void menuCarregar(){

  char nome[1000];
  system("clear");
  printf("\n\t\t\t==> CARREGAR UM ARQUIVO <==\n");
  // solicita o nome do arquivo/
  printf("\n\tDigite o nome do arquivo: ");
  scanf(" %s", nome);

  if(carregarArquivo(nome)){
    printf("\nEstrutura carregada com sucesso\n");
  }
  else{
    printf("\n\tOcorreu um erro ao carregar o arquivo.\n");
    printf("\tTente novamente\n");
  }

  printf("\n\tDigite SAIR & tecle enter para voltar ao menu...\n");
  scanf(" %s", nome);
  while(strcmp(nome, "SAIR") != 0){
    printf("\n\tDigite SAIR & tecle enter para voltar ao menu...\n");
    scanf(" %s", nome);
  }

}

void menuSalvar(){

  char nome[1000];
  system("clear");
  printf("\n\t\t\t==> SALVAR EM UM ARQUIVO <==\n");
  // solicita o nome do arquivo/
  printf("\n\tDigite o nome do arquivo: ");
  scanf(" %s", nome);

  if(salvarArquivo(nome)){
    printf("\nEstrutura salva com sucesso\n");
  }
  else{
    printf("\n\tOcorreu um erro ao salvar o arquivo.\n");
    printf("\tTente novamente\n");
  }

  printf("\n\tDigite SAIR & tecle enter para voltar ao menu...\n");
  scanf(" %s", nome);
  while(strcmp(nome, "SAIR") != 0){
    printf("\n\tDigite SAIR & tecle enter para voltar ao menu...\n");
    scanf(" %s", nome);
  }

}

void menuMostrar(){
  system("clear");

  for (int i = 0; i < MAX_TRANSPORTADORAS; ++i)
  {
    if(transportadoras[i].codigo != -1){
      printf("\tCódigo:   %i\n", transportadoras[i].codigo);
      printf("\tNome:     %s\n", transportadoras[i].nome);
      printf("\tEndereço: %s\n", transportadoras[i].endereco);
      printf("\tCNPJ:     %s\n", transportadoras[i].cnpj);
      printf("\tTelefone: %s\n", transportadoras[i].telefone);
      printf("\tSite:     %s\n", transportadoras[i].site);
      printf("\tEmail:    %s\n", transportadoras[i].email);
      printf("\n");
    }    
  }

  char nome[10];
  printf("\n\tDigite SAIR & tecle enter para voltar ao menu...\n");
  scanf(" %s", nome);
  while(strcmp(nome, "SAIR") != 0){
    printf("\n\tDigite SAIR & tecle enter para voltar ao menu...\n");
    scanf(" %s", nome);
  }


}

char salvarArquivo(char* nomeArquivo){
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "wb");  
 
    if (arquivo == NULL) { 
        return 0;
 
    } else {
      for (int i = 0; i < MAX_TRANSPORTADORAS; ++i)
      {
        fwrite(&transportadoras[i], sizeof(transportadoras[i]), 1, arquivo);
      }       
    }
    /* fecha o arquivo */
    fclose(arquivo);
    return 1;
}

char carregarArquivo(char* nomeArquivo){
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "rb");  
 
    if (arquivo == NULL) { 
        return 0;
 
    } else {
      for (int i = 0; i < MAX_TRANSPORTADORAS; ++i)
      {
        fread(&transportadoras[i], sizeof(transportadoras[i]), 1, arquivo);
      }       
    }
    /* fecha o arquivo */
    fclose(arquivo);
    return 1;
}

void menuInserir()
{
Transportadora transportadora;
int codigoTransportadora = 0;
char repetir = 1;
char resposta[MAX];
do{
 system("clear");
     printf("\n\t\t\t==> INSERIR TRANSPORTADORA <==\n");
 //solicita codigo do produto//
 printf("\n\tCódigo da transportadora: ");
     scanf(" %d", &codigoTransportadora);
 //verifica se a transportadora ja foi cadastrada//
if (existeTransportadora(codigoTransportadora) == -1) {
  transportadora.codigo = codigoTransportadora;
  // solicita os demais dados da transportadora//
  printf("\tNome da transportadora: ");
  scanf(" %s", transportadora.nome);
  printf("\tCNPJ da Transportadora: ");
  scanf(" %s", transportadora.cnpj);
  printf("\tTelefone da transportadora: ");
  scanf(" %s", transportadora.telefone);
  printf("\tSite da transportadora: ");
  scanf(" %s", transportadora.site);
  printf("\tEmail da transportadora: ");
  scanf(" %s", transportadora.email);
  printf("\tEndereco da transportadora: ");
  scanf(" %s", transportadora.endereco);

//insere a transportadora no arquivo//
if (inserirTransportadora(transportadora)) {
              printf("\n A transportadora foi cadastrada com sucesso\n");
          } else {
              printf("\n\tOcorreu um erro ao cadastrar a transportadora\n");
              printf("\tTente novamente\n");
          }
      } else {
 //se o registro ja existe, não pode ser inserida//
 printf("\n\t A transportadorade codigo %d ja existe.\n", codigoTransportadora);
          printf("\tNão é possivel registrar duas transportadoras com o mesmo codigo.\n");
      }
      printf("\n\tDeseja continuar cadastrando? [S/N]: ");
      scanf(" %s", resposta);
      if (!(strcmp(resposta, "S") == 0 || strcmp(resposta, "s") == 0)) {
          repetir = 0;
      }
  } while (repetir);
}

void menuConsultar()
{
  Transportadora transportadora;
  int codigoTransportadora;
  char repetir = 1;
  char resposta[MAX];  
   do {
      system("clear");
      printf("\n\t\t\t==> CONSULTAR TRANSPORTADORA POR CODIGO <==\n");
// solicita o codigo da transportadora a ser consultada//
  printf("\n\tCodigo da transportadora: ");
      scanf(" %d", &codigoTransportadora);
// verifica se a transportadora existe//
  if (existeTransportadora(codigoTransportadora) != -1) {
          /* Mostam os dados da transportadora */
          printf("\n\tCodigo da transportadora: %d\n", transportadora.codigo);
          printf("\tNome da transportadora: %s\n", transportadora.nome);          
          printf("\tCNPJ da transportadora: %s\n", transportadora.cnpj);
          printf("\tTelefone da transportadora: %s\n", transportadora.telefone);
          printf("\t Endereco: %s\n", transportadora.endereco);
      } else {
// se o cadastro não existir//
  printf("\n\tA Transportadora de codigo %d nao existe.\n", codigoTransportadora);
      }
printf("\n\tDeseja continuar consultando? [S/N]: ");
      scanf(" %s", resposta);
      if (!(strcmp(resposta, "S") == 0 || strcmp(resposta, "s") == 0)) {
          repetir = 0;
      }
  } while (repetir);
}
void menuEliminar()
{
   Transportadora transportadora;
   int codigoTransportadora;
   char repetir = 1;
   char resposta [MAX];
   do {
       system("clear");
       
       printf("\n\t\t\t==> DELETAR CADASTRO POR CODIGO <==\n");
// pede o codigo da transportadora//
printf("\n\tCódigo da transportadora: ");
       scanf(" %d", &codigoTransportadora);
 
       // verifica se o cadastro existe //
       if (existeTransportadora(codigoTransportadora) != -1) {
           /* Exibe os dados da transportadora */
           printf("\n\tCódigo da transportadora: %d\n", transportadora.codigo);
           printf("\tNome da transportadora: %s\n", transportadora.nome);           
           printf("\tCNPJ da transportadora: %s\n", transportadora.cnpj);
           printf("\tTelefone da transportadora: %s\n", transportadora.telefone);
          
           printf("\n\tDeseja excluir cadastro? [S/N]: ");
           scanf(" %s", resposta);
           if (strcmp(resposta, "S") == 0 || strcmp(resposta, "s") == 0) {
               if (eliminarTransportadora(codigoTransportadora)) {
                   printf("\n\tCadastro eliminado.\n");
               } else {
                   printf("\n\tO cadastro nao pode ser eliminado.\n");
               }
           }
 
           } else {
           /* Se o cadastro nao existir */
           printf("\n\tA transportadora de codigo %d no existe.\n", codigoTransportadora);
       }
       printf("\n\tDeseja eliminar outro cadastro? [S/N]: ");
       scanf(" %s", resposta);
       if (!(strcmp(resposta, "S") == 0 || strcmp(resposta, "s") == 0)) {
           repetir = 0;
       }
   } while (repetir);
}

void menuEditar()
{
    Transportadora transportadora;
    int codigoTransportadora;
    char repetir = 1;
    char resposta[MAX];
 
    do {
        system("clear");
        
        printf("\n\t\t\t==> EDITAR CADASTRO POR CODIGO: <==\n");

//pede o codigo do produto a ser modificado//
printf("\n\tCódigo da transportadora: ");
        scanf(" %d", &codigoTransportadora);

// verifica se o cadastro existe//
        int posicao = existeTransportadora(codigoTransportadora);
if (posicao != -1) {

  Transportadora transportadora = transportadoras[posicao];
 
/* mostra os dados da transportadora */
printf("\n\tNome da Transportadora: %s\n", transportadora.nome);
printf("\tCNPJ da transportadora: %s\n", transportadora.cnpj);
printf("\tTelefone da transportadora: %s\n", transportadora.telefone);
 
printf("\n\tSelecione os dados para modificar:\n");

/* Editar o nome da transportadora */
            printf("\n\tNome atual da Transportadora: %s\n", transportadora.nome);
            printf("\tDeseja modificar o nome da Transportadora? [S/N]: ");
            scanf(" %s", resposta);
            if (strcmp(resposta, "S") == 0 || strcmp(resposta, "s") == 0) {
                printf("\tNovo nome da Transportadora: ");
                scanf(" %s", transportadora.nome);
            }
/* Editar o cnpj */
            printf("\n\tCnpj atual da empresa: %s\n", transportadora.cnpj);
            printf("\tDeseja mudar o cnpj da empresa? [S/N]: ");
             scanf(" %s", resposta);
            if (strcmp(resposta, "S") == 0 || strcmp(resposta, "s") == 0) {
                printf("\tNovo cnpj da empresa: ");
                scanf(" %s", transportadora.cnpj);
            }

printf("\n\tTem certeza que deseja modificar os dados? [S/N]: ");
             scanf(" %s", resposta);
 
            if (strcmp(resposta, "S") == 0 || strcmp(resposta, "s") == 0) {

                /* Muda os dados do cadastro no arquivo */
                if (editarTransportadora(transportadora)) {
                    printf("\n\tO cadastro foi editado com sucesso\n");
 
                } else {
                    printf("\n\tOcorreu um erro ao editar o cadastro\n");
                    printf("\tTente mais tarde\n");
                }
            }
        } else {

        /* O cadastro nao existe */
            printf("\n\tO cadastro de codigo %d nao existe.\n", codigoTransportadora);
        }
 
        printf("\n\tDeseja modificar algum outro cadastro? [S/N]: ");
        scanf(" %s", resposta);
 
        if (!(strcmp(resposta, "S") == 0 || strcmp(resposta, "s") == 0)) {
            repetir = 0;
        }
 
    } while (repetir);
}

 
int existeTransportadora(int codigoTransportadora)
{
  for (int i = 0; i < MAX_TRANSPORTADORAS; ++i)
  {
    if(transportadoras[i].codigo == codigoTransportadora){
      return i;
    }
  }
  return -1;
   
}
 
char inserirTransportadora(Transportadora transportadora)
{

  for (int i = 0; i < MAX_TRANSPORTADORAS; ++i)
  {
    if(transportadoras[i].codigo == -1){
      transportadoras[i] = transportadora;
      return 1;
    }
  }
  printf("Ta cheio, parça.\n");
  return 0;
}
 /* eliminacao de um casastro */
char eliminarTransportadora(int codigoTransportadora)
{
  for (int i = 0; i < MAX_TRANSPORTADORAS; ++i){
     
     if(transportadoras[i].codigo == codigoTransportadora){
        transportadoras[i].codigo = -1;
        printf("Transportadora %d eliminada.\n", codigoTransportadora);
        return 1;
     }
  }
  printf("código inexistente\n");
  return 0;
}
char editarTransportadora(Transportadora transportadora)
{
  for (int i = 0; i < MAX_TRANSPORTADORAS; ++i)
  {
    if(transportadoras[i].codigo == transportadora.codigo){
      transportadoras[i] = transportadora;
      return 1;
    }
  }
  return 0;
}
 
 