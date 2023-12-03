#include <iostream>

using namespace std;

const int menor = -2147483647;

struct NoArvore {
    int dados;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : dados(valor), esquerda(NULL), direita(NULL) {}
};

int calcularMaiorSomaSubarvore(NoArvore *raiz, int &maiorSoma) {
    if (raiz == NULL) {
        return 0;
    }

    int somaEsquerda = calcularMaiorSomaSubarvore(raiz->esquerda, maiorSoma);
    int somaDireita = calcularMaiorSomaSubarvore(raiz->direita, maiorSoma);
    int somaAtual = raiz->dados + somaEsquerda + somaDireita;

    if (somaAtual > maiorSoma) {
        maiorSoma = somaAtual;
    }
    if (somaEsquerda > maiorSoma) {
        maiorSoma = somaEsquerda;
    }
    if (somaDireita > maiorSoma) {
        maiorSoma = somaDireita;
    }

    int raizComEsquerda = raiz->dados + somaEsquerda;
    int raizComDireita = raiz->dados + somaDireita;

    if (raizComEsquerda > raiz->dados && raizComEsquerda > raizComDireita) {
        return raizComEsquerda;
    } else if (raizComDireita > raiz->dados) {
        return raizComDireita;
    } else {
        return raiz->dados;
    }
}

int maiorSomaSubarvores(NoArvore *raiz) {
    int maiorSoma = menor;
    calcularMaiorSomaSubarvore(raiz, maiorSoma);
    return maiorSoma;
}


int main() {
    
    NoArvore *raiz = new NoArvore (1);
	NoArvore *num1 = new NoArvore (4);
	NoArvore *num2 = new NoArvore (3);
	
	raiz -> esquerda = num1;
	raiz -> direita = num2;
	
	NoArvore *num3 = new NoArvore (2);
	NoArvore *num4 = new NoArvore (4);
	
	num1->esquerda = num3;
	num1 -> direita = num4;
	
	NoArvore *num5 = new NoArvore (2);
	NoArvore *num6 = new NoArvore (5);
	
	num2 -> esquerda = num5;
	num2 -> direita = num6;
	
	NoArvore *num7 = new NoArvore (4);
	NoArvore *num8 = new NoArvore (6);
	
	num6 -> esquerda = num7;
	num6 -> direita = num8;

    int resultado = maiorSomaSubarvores(raiz);
    cout << "Maior soma de todas as subarvores: " << resultado << endl;

    return 0;
}

