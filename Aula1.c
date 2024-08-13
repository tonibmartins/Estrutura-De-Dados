// Array Dinâmico
// Autor: Prof. Diego Marconi

// Funções :
    // Create --> Criar um array
    // Insert --> Inserir um elemento
    // Remove --> Remover um elemento
    // Search --> Buscar um elemento
    // Print --> Imprimir o array
    // Destroy --> Destruir o array


// Importar bibliotecas
#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <stdlib.h> // Biblioteca padrão do sistema

// Declaração de variáveis

int * values; // Array de valores
int size; // Tamanho atual
int capacity; // Capacidade máxima
float grow_factor = 2.0; // Fator de crescimento


void Array_Create(int capacity){ 
    // Aloca memória para o array
    values = (int *) malloc(capacity * sizeof(int)); // Aloca memória para o array de valores com a capacidade definida pelo usuário

}

void Array_Destroy(){
    // Libera a memória alocada para o array
    free(values); // Libera a memória alocada para o array de valores

}

void grow(){
    int newCapacity;
    // Aumenta a capacidade do array
    newCapacity = capacity * grow_factor;


    values = (int *) realloc(values, newCapacity * sizeof(int));
    
    int * newValues = (int *) malloc(newCapacity * sizeof(int));

    for (int i = 0; i < size; i++){
        *(newValues + i) = *(values + i); // Copia os valores do array antigo para o novo
    }

    Array_Destroy();
    values = newValues;
    capacity = newCapacity;
}

void Array_Print(){
    // Imprime o Array
    for(int i = 0; i < capacity; i++){
        if (i < size){
            printf("%d\n", *(values + i));
        } else {
            printf("x\n");
        }
        printf("\n");
    }

}

void Array_Insert(int value){
    // Insere um valor no array
    if(size == capacity){
        grow();
    }
    *(values + size) = value;
        size ++;
}







int main(){
    scanf("%d", &capacity);
    scanf("%f", &grow_factor);
    Array_Create(capacity);
    Array_Destroy();
    Array_Print();
    Array_Insert(values);
    Array_Print();
    return 0;
}