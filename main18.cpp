#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

NoArvore* arrayParaBST(int array[], int inicio, int fim) {
    if (inicio > fim) {
        return NULL;
    }

    int meio = (inicio + fim) / 2;
    
    NoArvore *raiz = new NoArvore(array[meio]);

    raiz->esquerda = arrayParaBST(array, inicio, meio - 1);
    raiz->direita = arrayParaBST(array, meio + 1, fim);

    return raiz;
}

void emOrdem(NoArvore *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        cout << raiz->data << " ";
        emOrdem(raiz->direita);
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int tamanho = sizeof(array) / sizeof(array[0]);

    NoArvore *raiz = arrayParaBST(array, 0, tamanho - 1);
    
    cout << "Arvore Binaria resultante em ordem: ";
    emOrdem(raiz);
    cout << endl;

    return 0;
}

