#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

bool verificaSomaFilhos(NoArvore* raiz) {
    if (raiz == NULL) {
        return false;
    }

    int somaFilhos = 0;
    if (raiz->esquerda != NULL) {
        somaFilhos += raiz->esquerda->data;
    }
    if (raiz->direita != NULL) {
        somaFilhos += raiz->direita->data;
    }

    return (somaFilhos == raiz->data);
}

int main() {

    NoArvore *raiz = new NoArvore(10);
    NoArvore *num1 = new NoArvore(4);
    NoArvore *num2 = new NoArvore(6);

    raiz->esquerda = num1;
    raiz->direita = num2;

    bool resultado = verificaSomaFilhos(raiz);

    if (resultado) {
        cout << "A soma dos filhos eh igual ao valor da raiz (TRUE)" << endl;
    } else {
        cout << "A soma dos filhos eh diferente do valor da raiz (FALSE)" << endl;
    }

    return 0;
}

