#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

int contarElementos(NoArvore *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return contarElementos(raiz->esquerda) + 1 + contarElementos(raiz->direita);
}

void copiarElementos(NoArvore *raiz, int *elementos, int &indice) {
    if (raiz != NULL) {
        copiarElementos(raiz->esquerda, elementos, indice);
        elementos[indice++] = raiz->data;
        copiarElementos(raiz->direita, elementos, indice);
    }
}

NoArvore *construirArvoreBalanceada(int *elementos, int inicio, int fim) {
    if (inicio > fim) {
        return NULL;
    }

    int meio = (inicio + fim) / 2;

    NoArvore *novoNo = new NoArvore(elementos[meio]);

    novoNo->esquerda = construirArvoreBalanceada(elementos, inicio, meio - 1);
    novoNo->direita = construirArvoreBalanceada(elementos, meio + 1, fim);

    return novoNo;
}

NoArvore *equilibrarArvore(NoArvore *raiz) {
    int numElementos = contarElementos(raiz);
    int *elementos = new int[numElementos];
    int indice = 0;
    copiarElementos(raiz, elementos, indice);

    int inicio = 0;
    int fim = numElementos - 1;
    NoArvore *arvoreBalanceada = construirArvoreBalanceada(elementos, inicio, fim);

    delete[] elementos;

    return arvoreBalanceada;
}

void emOrdem(NoArvore *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        cout << raiz->data << " ";
        emOrdem(raiz->direita);
    }
}

int main() {

    NoArvore *raiz = new NoArvore(1);
    NoArvore *num1 = new NoArvore(2);
    NoArvore *num2 = new NoArvore(3);

    raiz->esquerda = num1;
    raiz->direita = num2;

    NoArvore *num3 = new NoArvore(4);
    NoArvore *num4 = new NoArvore(5);

    num1->esquerda = num3;
    num1->direita = num4;

    NoArvore *num5 = new NoArvore(5);

    num4->esquerda = num5;

    NoArvore *num6 = new NoArvore(11);

    num4->direita = num6;

    NoArvore *num7 = new NoArvore(9);
    NoArvore *num8 = new NoArvore(4);

    num2->direita = num7;
    num7->esquerda = num8;

    NoArvore *arvoreBalanceada = equilibrarArvore(raiz);

    cout << "Arvore balanceada em ordem: ";
    emOrdem(arvoreBalanceada);
    cout << endl;

    return 0;
}

