#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

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

    raiz->direita = num1;
    num1->esquerda = num2;

    cout << "Em ordem: ";
    emOrdem(raiz);
    cout << endl;

    return 0;
}
