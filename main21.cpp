#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

NoArvore* buscaBinaria(NoArvore *raiz, int valor) {
    if (raiz == NULL || raiz->data == valor) {
        return raiz;
    }

    if (valor < raiz->data) {
        return buscaBinaria(raiz->esquerda, valor);
    }else {
        return buscaBinaria(raiz->direita, valor);
    }
}

int main() {
 
    NoArvore *raiz = new NoArvore (10);
	NoArvore *num1 = new NoArvore (3);
	NoArvore *num2 = new NoArvore (12);
	
	raiz -> esquerda = num1;
	raiz -> direita = num2;
	
	NoArvore *num3 = new NoArvore (2);
	NoArvore *num4 = new NoArvore (5);
	
	num1 -> esquerda = num3;
	num1 -> direita = num4;
	
	NoArvore *num5 = new NoArvore (11);
	NoArvore *num6 = new NoArvore (17);
	
	num2 -> esquerda = num5;
	num2 -> direita = num6;
	
	int valorBuscado = 3;

    NoArvore *noEncontrado = buscaBinaria(raiz, valorBuscado);

    if (noEncontrado != NULL) {
        cout << "O valor " << valorBuscado << " foi encontrado" << endl;
    } else {
        cout << "O valor " << valorBuscado << " nao foi encontrado" << endl;
    }

    return 0;
}

