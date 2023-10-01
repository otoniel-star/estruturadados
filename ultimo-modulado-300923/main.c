//Otoniel Serafim & Eduardo Cesar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"app.h"
#define NUM_CONTAS 3
#define TAM_CPF 12

int main() {
    Cliente clientes[NUM_CONTAS];  // numero maximo de contas
    int total_clientes = 0;

    display_menu(clientes, &total_clientes);

    return 0;
}
