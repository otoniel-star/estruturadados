//Otoniel Serafim & Eduardo Cesar
#include <stdio.h>
#include <string.h>
#include "app.h"


void criar_conta(Cliente *clientes, int *total_clientes) {
    if (*total_clientes < NUM_CONTAS) {
        int idx_cliente;

        // Obter o CPF
        printf("Digite o CPF do cliente (11 dígitos): ");
        scanf("%s", clientes[*total_clientes].cpf);

        // Encontrar pelo CPF
        for (idx_cliente = 0; idx_cliente < *total_clientes; idx_cliente++) {
            if (strcmp(clientes[idx_cliente].cpf, clientes[*total_clientes].cpf) == 0) {
                break;
            }
        }

        // se encontrado
        if (idx_cliente == *total_clientes) {
            // Novo cliente
            strcpy(clientes[*total_clientes].cpf, clientes[*total_clientes].cpf);
            idx_cliente = (*total_clientes)++;
            clientes[idx_cliente].total_contas = 0;
        }

        // Adicionar a conta
        printf("Digite o número da nova conta (entre 1000 e 9999): ");
        scanf("%d", &clientes[idx_cliente].contas_associadas.numero_conta);

        if (clientes[idx_cliente].contas_associadas.numero_conta < 1000 || clientes[idx_cliente].contas_associadas.numero_conta > 9999) {
            printf("Número de conta inválido. Deve estar entre 1000 e 9999.\n");
            return;
        }

        printf("Digite o número da agência (entre 1 e 999): ");
        scanf("%d", &clientes[idx_cliente].contas_associadas.agencia);

        if (clientes[idx_cliente].contas_associadas.agencia < 1 || clientes[idx_cliente].contas_associadas.agencia > 999) {
            printf("Número da agência inválido. Deve estar entre 1 e 999.\n");
            return;
        }

        printf("Escolha o tipo da conta:\n");
        printf("1 - Conta Corrente\n");
        printf("2 - Conta Poupança\n");
        printf("Opção: ");
        int tipo;
        scanf("%d", &tipo);

        if (tipo == 1) {
            clientes[idx_cliente].contas_associadas.tipo_conta = CONTA_CORRENTE;
        } else if (tipo == 2) {
            clientes[idx_cliente].contas_associadas.tipo_conta = CONTA_POUPANCA;
        } else {
            printf("Tipo de conta inválido.\n");
            return;
        }

        printf("Digite o saldo inicial: ");
        scanf("%f", &clientes[idx_cliente].contas_associadas.saldo);

        // Incrementar o número total de contas associadas ao cliente
        clientes[idx_cliente].total_contas++;
    } else {
        printf("Número máximo de contas atingido (%d contas).\n", NUM_CONTAS);
    }
}





// Função busca binária
int compare(const void *a, const void *b) {
    return strcmp(((Cliente *)a)->cpf, ((Cliente *)b)->cpf);
}

void depositar(Cliente *clientes, int total_clientes) {
    int numero_conta;
    float valor;

    printf("Digite o número da conta: ");
    scanf("%d", &numero_conta);

    for (int i = 0; i < total_clientes; i++) {
        if (clientes[i].contas_associadas.numero_conta == numero_conta) {
            printf("Digite o valor a ser depositado: ");
            scanf("%f", &valor);
            clientes[i].contas_associadas.saldo += valor;
            printf("Depósito realizado com sucesso. Saldo atual: %.2f\n", clientes[i].contas_associadas.saldo);
            return;
        }
    }

    printf("Conta não encontrada.\n");
}

void sacar(Cliente *clientes, int total_clientes) {
    int numero_conta;
    float valor;

    printf("Digite o número da conta: ");
    scanf("%d", &numero_conta);

    for (int i = 0; i < total_clientes; i++) {
        if (clientes[i].contas_associadas.numero_conta == numero_conta) {
            printf("Digite o valor a ser sacado: ");
            scanf("%f", &valor);

            if (clientes[i].contas_associadas.saldo >= valor) {
                clientes[i].contas_associadas.saldo -= valor;
                printf("Saque realizado com sucesso. Saldo atual: %.2f\n", clientes[i].contas_associadas.saldo);
            } else {
                printf("Saldo insuficiente.\n");
            }
            return;
        }
    }

    printf("Conta não encontrada.\n");
}

void consultar_saldo(Cliente *clientes, int total_clientes) {
    int numero_conta;

    printf("Digite o número da conta: ");
    scanf("%d", &numero_conta);

    for (int i = 0; i < total_clientes; i++) {
        if (clientes[i].contas_associadas.numero_conta == numero_conta) {
            printf("Saldo da conta %d: %.2f\n", clientes[i].contas_associadas.numero_conta, clientes[i].contas_associadas.saldo);
            return;
        }
    }

    printf("Conta não encontrada.\n");
}
void depositar_para_cpf(Cliente *clientes, int total_clientes, const char *cpf) {
    // Procurar o cliente com base no CPF 
    for (int i = 0; i < total_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            float valor;

            // Exibir informações do cliente
            printf("Cliente encontrado!\n");
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Número da Conta: %d\n", clientes[i].contas_associadas.numero_conta);
            printf("Agência: %d\n", clientes[i].contas_associadas.agencia);
            printf("Tipo de Conta: %s\n", 
                   clientes[i].contas_associadas.tipo_conta == CONTA_CORRENTE ? "Conta Corrente" : "Conta Poupança");
            printf("Saldo atual: %.2f\n", clientes[i].contas_associadas.saldo);

            // o valor do depósito
            printf("Digite o valor a ser depositado: ");
            scanf("%f", &valor);

            // Realizar o depósito
            if (valor > 0) {
                clientes[i].contas_associadas.saldo += valor;
                printf("Depósito realizado com sucesso. Novo saldo: %.2f\n", clientes[i].contas_associadas.saldo);
            } else {
                printf("Valor de depósito inválido. O valor deve ser maior que zero.\n");
            }

            return;
        }
    }

    printf("Cliente não encontrado para o CPF fornecido.\n");
}
void sacar_pelo_cpf(Cliente *clientes, int total_clientes, const char *cpf) {
    // Procurar o cliente com base no CPF fornecido
    for (int i = 0; i < total_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            float valor;

            // Exibir informações do cliente
            printf("Cliente encontrado!\n");
            printf("CPF: %s\n", clientes[i].cpf);
            printf("Número da Conta: %d\n", clientes[i].contas_associadas.numero_conta);
            printf("Agência: %d\n", clientes[i].contas_associadas.agencia);
            printf("Tipo de Conta: %s\n", 
                   clientes[i].contas_associadas.tipo_conta == CONTA_CORRENTE ? "Conta Corrente" : "Conta Poupança");
            printf("Saldo atual: %.2f\n", clientes[i].contas_associadas.saldo);

            // Solicitar o valor do saque
            printf("Digite o valor a ser sacado: ");
            scanf("%f", &valor);

            // Realizar o saque
            if (valor > 0) {
                if (clientes[i].contas_associadas.saldo >= valor) {
                    clientes[i].contas_associadas.saldo -= valor;
                    printf("Saque realizado com sucesso. Novo saldo: %.2f\n", clientes[i].contas_associadas.saldo);
                } else {
                    printf("Saldo insuficiente para o saque.\n");
                }
            } else {
                printf("Valor de saque inválido. O valor deve ser maior que zero.\n");
            }

            return;
        }
    }

    printf("Cliente não encontrado para o CPF fornecido.\n");
}
void buscar_cliente_por_cpf(Cliente *clientes, int total_clientes) {
    char cpf_busca[TAM_CPF];
    int opcao_busca;

    printf("Escolha o método de busca:\n");
    printf("1. Busca sequencial\n");
    printf("2. Busca binária\n");
    printf("Opção: ");
    scanf("%d", &opcao_busca);

    // Limpar o buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (opcao_busca == 1 || opcao_busca == 2) {
        printf("Digite o CPF do cliente para busca (11 dígitos): ");
        fgets(cpf_busca, TAM_CPF, stdin);
        // Remover a quebra de linha do final da string
        cpf_busca[strcspn(cpf_busca, "\n")] = '\0';

        Cliente *result = NULL;

        if (opcao_busca == 1) {
            for (int i = 0; i < total_clientes; i++) {
                if (strcmp(clientes[i].cpf, cpf_busca) == 0) {
                    result = &clientes[i];
                    break;
                }
            }
        } else if (opcao_busca == 2) {
            // Ordenar os clientes por CPF para a busca binária funcionar corretamente
            qsort(clientes, total_clientes, sizeof(Cliente), compare);
            result = (Cliente *)bsearch(cpf_busca, clientes, total_clientes, sizeof(Cliente), compare);
        }

        if (result != NULL) {
            printf("Cliente encontrado!\n");
            printf("CPF: %s\n", result->cpf);
            printf("Número da Conta: %d\n", result->contas_associadas.numero_conta);
            printf("Agência: %d\n", result->contas_associadas.agencia);
            printf("Tipo de Conta: %s\n",
                   result->contas_associadas.tipo_conta == CONTA_CORRENTE ? "Conta Corrente" : "Conta Poupança");
            printf("Saldo atual: %.2f\n", result->contas_associadas.saldo);

            int opcao_operacao;
            do {
                // Exibir menu para sacar ou depositar
                printf("\nEscolha a operação:\n");
                printf("1. Depositar\n");
                printf("2. Sacar\n");
                printf("0. Voltar\n");
                printf("Opção: ");
                scanf("%d", &opcao_operacao);

                switch (opcao_operacao) {
                    case 1:
                        depositar_para_cpf(clientes, total_clientes, cpf_busca);
                        break;
                    case 2:
                        sacar_pelo_cpf(clientes, total_clientes, cpf_busca);
                        break;
                    case 0:
                        printf("Retornando ao menu anterior...\n");
                        break;
                    default:
                        printf("Opção inválida. Tente novamente.\n");
                        break;
                }
            } while (opcao_operacao != 0);
        } else {
            printf("Cliente não encontrado para o CPF fornecido.\n");
        }
    } else {
        printf("Opção inválida.\n");
    }
}

void ordenar_clientes_por_cpf(Cliente *clientes, int total_clientes) {
    int i, j, min_idx;
    Cliente temp;

    for (i = 0; i < total_clientes - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < total_clientes; j++) {
            if (strcmp(clientes[j].cpf, clientes[min_idx].cpf) < 0)
                min_idx = j;
        }

        temp = clientes[min_idx];
        clientes[min_idx] = clientes[i];
        clientes[i] = temp;
    }
}

void imprimir_relatorio(Cliente *clientes, int total_clientes) {
    // Ordenar os clientes por CPF usando ordenação por seleção
    ordenar_clientes_por_cpf(clientes, total_clientes);

    printf("\n=== Relatório de Clientes (Ordem Crescente de CPF) ===\n");
    printf("CPF\t\tAgência\tConta\tSaldo\n");

    for (int i = 0; i < total_clientes; i++) {
        printf("%s\t%d\t%d\t%.2f\n", clientes[i].cpf,
               clientes[i].contas_associadas.agencia,
               clientes[i].contas_associadas.numero_conta,
               clientes[i].contas_associadas.saldo);
    }
}
void merge(Cliente *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Criar arrays temporárias
    Cliente leftArr[n1], rightArr[n2];

    // Copiar dados para as arrays temporárias leftArr[] e rightArr[]
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Merge das arrays temporárias de volta para arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i].saldo >= rightArr[j].saldo) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    // Copiar os elementos restantes de leftArr[], se houver
    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    // Copiar os elementos restantes de rightArr[], se houver
    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(Cliente *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordenar as duas metades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Fazer o merge das duas metades ordenadas
        merge(arr, left, mid, right);
    }
}

void ordenar_clientes_por_saldo_decrescente(Cliente *clientes, int total_clientes) {
    mergeSort(clientes, 0, total_clientes - 1);
}
void imprimir_relatorio_ordem_saldo_decrescente(Cliente *clientes, int total_clientes) {
    // Ordenar os clientes por saldo em ordem decrescente
    ordenar_clientes_por_saldo_decrescente(clientes, total_clientes);

    printf("\n=== Relatório de Clientes (Ordem Decrescente de Saldo) ===\n");
    printf("CPF\t\tAgência\tConta\tSaldo\n");

    for (int i = 0; i < total_clientes; i++) {
        printf("%s\t%d\t%d\t%.2f\n", clientes[i].cpf,
               clientes[i].contas_associadas.agencia,
               clientes[i].contas_associadas.numero_conta,
               clientes[i].contas_associadas.saldo);
    }
}
void display_menu(Cliente *clientes, int *total_clientes) 
{
    int opcao;

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Criar nova conta\n");
        printf("2. Depositar\n");
        printf("3. Sacar\n");
        printf("4. Consultar saldo\n");
        printf("5. Buscar cliente por CPF\n");
        printf("6. Imprimir relatório (Ordem Crescente de CPF)\n");
        printf("7. Imprimir relatório (Ordem Decrescente de Saldo)\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criar_conta(clientes, total_clientes);
                break;
            case 2:
                depositar(clientes, *total_clientes);
                break;
            case 3:
                sacar(clientes, *total_clientes);
                break;
            case 4:
                consultar_saldo(clientes, *total_clientes);
                break;
            case 5:
                buscar_cliente_por_cpf(clientes, *total_clientes);
                break;
            case 6:
                imprimir_relatorio(clientes, *total_clientes);
                break;
            case 7:
                imprimir_relatorio_ordem_saldo_decrescente(clientes, *total_clientes);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

        // Limpar o buffer de entrada
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    } while (opcao != 0);
}