#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

bool saoIguais(NoArvore *raiz1, NoArvore *raiz2) {
    if (raiz1 == NULL && raiz2 == NULL) {
        return true;
    }

    if (raiz1 != NULL && raiz2 != NULL) {
        return (raiz1->data == raiz2->data) &&
               saoIguais(raiz1->esquerda, raiz2->esquerda) &&
               saoIguais(raiz1->direita, raiz2->direita);
    }

    return false;
}

void emOrdem(NoArvore *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        cout << raiz->data << " ";
        emOrdem(raiz->direita);
    }
}

int main() {
    NoArvore *raiz1 = new NoArvore(1);
    NoArvore *num1 = new NoArvore(2);
    NoArvore *num2 = new NoArvore(3);

    raiz1->direita = num1;
    num1->esquerda = num2;

    cout << "Em ordem da arvore 1: ";
    emOrdem(raiz1);
    cout << endl;

    NoArvore *raiz2 = new NoArvore(1);
    NoArvore *num3 = new NoArvore(2);
    NoArvore *num4 = new NoArvore(3);

    raiz2->direita = num3;
    num3->esquerda = num4;

    cout << "Em ordem da arvore 2: ";
    emOrdem(raiz2);
    cout << endl;

    if (saoIguais(raiz1, raiz2)) {
        cout << "As arvores sao iguais." << endl;
    } else {
        cout << "As arvores nao sao iguais." << endl;
    }

    return 0;
}
