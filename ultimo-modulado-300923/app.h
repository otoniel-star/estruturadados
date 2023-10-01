//Otoniel Serafim & Eduardo Cesar
#define NUM_CONTAS 3
#define TAM_CPF 12

typedef enum TipoConta {
    CONTA_CORRENTE = 1,
    CONTA_POUPANCA = 2
} TipoConta;

typedef struct Conta {
    int numero_conta;
    int agencia;
    TipoConta tipo_conta;
    float saldo;
} Conta;

typedef struct Cliente {
    char cpf[TAM_CPF];
    Conta contas_associadas;  // Lista de contas associadas
    int total_contas;  // Número total de contas associadas
    float saldo;  // Saldo
} Cliente;

void display_menu(Cliente *clientes, int *total_clientes);
