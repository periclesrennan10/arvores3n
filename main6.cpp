#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

int obterProfundidadeMaxima(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int profundidadeDaArvore(NoArvore *raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        int profundidadeEsquerda = profundidadeDaArvore(raiz->esquerda);
        int profundidadeDireita = profundidadeDaArvore(raiz->direita);

        return obterProfundidadeMaxima(profundidadeEsquerda, profundidadeDireita) + 1;
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

    NoArvore *num5 = new NoArvore(6);

    num2->esquerda = num5;

    NoArvore *num6 = new NoArvore(7);

    num2->direita = num6;

    int profundidade = profundidadeDaArvore(raiz);

    cout << "A profundidade da arvore eh: " << profundidade << endl;

    return 0;
}

