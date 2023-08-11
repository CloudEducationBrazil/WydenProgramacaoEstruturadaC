# INTRODUÇÃO

Essa aplicação foi desenvolvida para a realização de cadastro de Elementos Químicos contemplando as suas propriedades mais importantes para o desenvolvimento de pesquisas científicas.

As Propriedades Periódicas contemplam: Raio Atomico (pm); Energia de Ionizacao (kJ/mol); Eletronegatividade (adimensional); Eletropositividade (adimensional); e Eletroafinidade (kJ/mol).

As Propriedades Físicas contemplam: Ponto de Fusão (K); Ponto de Ebulição (K); Densidade (kg/m³); e Volume Molar (m³/mol).

As Propriedades da Tabela: Período (1º ao 7º período ou série dos lantanídeos e dos actinídeos); e Família (Família 1A a 8A (elementos representativos) e 1B a 8B (elementos de transição/metais de transição)).


# DESENVOLVIMENTO

A aplicação foi desenvolvida utilizando a linguagem de programação C, e conta com 13 funções além da função main. Destas, sete estão disponíveis para o usuário selecionar em um menu utilizando o Switch Case e as outras seis são funções complementares sendo repetidas em diversos momentos ao longo da aplicação.

O armazenamento das informações enquanto a aplicação está rodando é realizado dinamicamente através de lista simplesmente encadeada (utilizando ponteiros). Cada nó da lista é criado no momento que o usuário seleciona a função de incluir um novo elemento. Esse novo nó é inserido no início da lista.

Dentro do menu existe uma opção para o usuário exportar as informações que ele já cadastrou. De forma complementar, ao selecionar a opção de finalizar a aplicação o usuário é submetido a um lemrbete para exportar os seus dados cadastrados, para caso ele tenha esquecido de exportar.

Para carregar as informações já cadastradas em utilização prévia da aplicação é verificado sempre ao iniciar a aplicação a existência do arquivo de armazenamento (cadastroQuimico.txt). Caso o arquivo exista, o usuário é questionado se deseja carregar as informações desse arquivo ou se deseja iniciar como se fosse uma primeira utilização.

Adicionalmente, ao final de cada função selecionada através do menu é exibido ao usuário a possibilidade de limpar a tela.

# COMO UTILIZAR

O .exe da aplicação foi compilado no Code::Blocks ver 17.12 para Windows x64, caso o seu sistema operacional seja compatível com o apresentado, basta executar o arquivo .exe. Caso contrário, o código fonte em .c também está disponível para ser analisado e compilado em sistema de preferência.