#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

NoArvore* inverterArvore(NoArvore* raiz) {
    if (raiz == NULL) {
        return NULL;
    }
    NoArvore* temp = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = temp;

    inverterArvore(raiz->esquerda);
    inverterArvore(raiz->direita);

    return raiz;
}

void preOrdem(NoArvore *raiz) {
    if (raiz != NULL) {
    	cout << raiz->data << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

int main() {
    
    NoArvore *raiz = new NoArvore(2);
    NoArvore *num1 = new NoArvore(1);
    NoArvore *num2 = new NoArvore(3);

    raiz->esquerda = num1;
    raiz->direita = num2;
	
    cout << "arvore original em preOrdem: ";
    preOrdem(raiz);
    cout << endl;

    NoArvore* raizInvertida = inverterArvore(raiz);

    cout << "arvore invertida em preOrdem: ";
    preOrdem(raizInvertida);
    cout << endl;

    return 0;
}

