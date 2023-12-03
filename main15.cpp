#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore* esquerda;
    NoArvore* direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

int somaNosFolhas(NoArvore* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return raiz->data;
    }

    return somaNosFolhas(raiz->esquerda) + somaNosFolhas(raiz->direita);
}

int main() {
	
    NoArvore* raiz = new NoArvore(1);
    NoArvore* num1 = new NoArvore(3);
    NoArvore* num2 = new NoArvore(5);
    
    raiz->esquerda = num1;
    raiz->direita = num2;
    
    NoArvore* num3 = new NoArvore(2);
    
    num1->esquerda = num3;
    
    int resultado = somaNosFolhas(raiz);

    cout << "A soma dos nos folhas eh: " << resultado << endl;

    return 0;
}

