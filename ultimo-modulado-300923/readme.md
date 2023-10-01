O Banco ENCO  realizar o cadastro de contas bancárias com os seguintes dados:

número da conta (chave) - valor numérico inteiro que não pode ser repetido, que varia de 1000 e 9999;
agência - valor numérico, com valores entre 001 a 999;
tipo da conta: valor numérico, que pode ser 1 - Conta Corrente ou 2 - Conta poupança
CPF do Cliente - alfanumérico, com tamanho 11;
saldo - valor numérico real
O banco permitirá o cadastramento de apenas 15 contas, independente do tipo. Os clientes, representados pelo CPF, podem ter mais de uma conta.

A aplicação implementa os seguintes serviços, disponibilizados em telas aos usuário por meio de itens do menu de opções:
Cadastro de contas: com todos os seus dados;
busca de clientes pelo CPF, que em caso de sucesso, retornar também o número da agência e da conta e tipo;
Realização de depósito: procedimento de acréscimo no saldo, mediante resultado positivo de busca por CPF do cliente;
Realização de saque: procedimento de descréscimo no saldo, mediante resultado positivo de busca por CPF do cliente. Considere que os saques não podem ser realizado com saldo menor que o valor requisitado do saque;
emissão dos seguintes relatórios em tela:
Listagem de Clientes, pela ordem crescente dos seus CPF. Trazer informações de agência, conta e saldo;
Listagem de Clientes pela ordem descrescente de saldo, com informações de CPF, agência e conta;

Observações:
O insucesso das buscas apresentam a mensagem "cliente não localizado!";
Utilizar, para as buscas, o algoritmo da busca binária;
Nas opções de relatórios e busca, devem ser utilizados algoritmos de ordenação das categorias básica (seleção, inserção ou troca) e sofisticada (merge sort e quick sort), na proporção de 50% para cada categoria;
Todos os módulos do programa devem prototipados no arquivo de cabeçalho (.h) e desenvolvidos no arquivo espelho(arquivo .c, espelho do arquivo de cabeçalho .h);
A definição da estrutura deve ser realizada no arquivo de cabeçalho;
O arquivo que contém a função principal (main) deve conter apenas alguma definição de variáveis e a chamada ao menu de opções, que estará prototipado em app.h e desenvolvido em app.c.
