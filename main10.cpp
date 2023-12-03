#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

const int maior = 99999999;  
const int menor = -99999999 - 1;  

bool verificaBST(NoArvore *raiz, int &valorAnterior) {
    if (raiz == NULL) {
        return true;
    }

    if (!verificaBST(raiz->esquerda, valorAnterior)) {
        return false;
    }

    if (raiz->data <= valorAnterior) {
        return false;
    }

    valorAnterior = raiz->data;

    return verificaBST(raiz->direita, valorAnterior);
}

bool isBST(NoArvore *raiz) {
    int valorAnterior = menor; 
    return verificaBST(raiz, valorAnterior);
}

int main() {

    NoArvore *raiz = new NoArvore(3);
    NoArvore *num1 = new NoArvore(1);
    NoArvore *num2 = new NoArvore(5);

    raiz->esquerda = num1;
    raiz->direita = num2;

    NoArvore *num3 = new NoArvore(0);
    NoArvore *num4 = new NoArvore(2);

    num1->esquerda = num3;
    num1->direita = num4;

    NoArvore *num5 = new NoArvore(4);

    num2->esquerda = num5;

    if (isBST(raiz)) {
        cout << "A arvore eh uma BST" << endl;
    } else {
        cout << "A arvore nao eh uma BST" << endl;
    }

    return 0;
}

