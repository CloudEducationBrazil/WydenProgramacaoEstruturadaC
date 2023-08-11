void salvar(Aluno lista_alunos[])
{
	int i;
	int len_vet = sizeof(lista_alunos) - 1;//tamanho do vetor
	FILE * arq;

	// abre o arquivo para escrita no modo append (adiciona ao final)
	arq = fopen("bancodedados.txt", "ab");
	if(arq != NULL){
		for(i = 0; i < len_vet; i++)
			// escreve cada elemento do vetor no arquivo
			fwrite(&lista_alunos[i], sizeof(Aluno), 1, arq);
		fclose(arq); // aborta o programa
	}
	else
	{
		printf("\nNAO FOI POSSIVEL ABRIR O ARQUIVO DE ALUNOS!\n");
		exit(1); // aborta o programa
	}
}
// função para ler do arquivo
// recebe o vetor que ela irá preencher
// retorna a quantidade de elementos preenchidos
int carrega(Aluno aux_lista_alunos[MAXALUNO])
{
	// abre o arquivo para leitura
	FILE * arq = fopen("bancodedados.txt", "rb");
	if(arq != NULL)
	{
		int indice = 0;
		while(1==1){
			Aluno p;
			// retorna a quantidade de elementos lidos com sucesso
			size_t r = fread(&p, sizeof(Aluno), 1, arq);
			// se retorno for menor que o count, então sai do loop
			if(r < 1)
				break;
			else
				aux_lista_alunos[indice++] = p;
		}
		fclose(arq); // fecha o arquivo
		return indice;
	}
	else
	{
		printf("\nErro ao acessar a base de dados\n");
		arq = fopen("bancodedados.txt", "ab");
		menu();
	}
}




