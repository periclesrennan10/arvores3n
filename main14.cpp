#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore* primeiroFilho;  
    NoArvore* proximoIrmao;   

    NoArvore(int valor) : data(valor), primeiroFilho(NULL), proximoIrmao(NULL) {}
};

void posOrdem(NoArvore* raiz) {
    if (raiz != NULL) {
	    posOrdem(raiz->primeiroFilho);
	    posOrdem(raiz->proximoIrmao);
	    cout << raiz->data << " ";
	}
}

int main() {

    NoArvore* raiz = new NoArvore(1);
    raiz->primeiroFilho = new NoArvore(2);
    raiz->primeiroFilho->proximoIrmao = new NoArvore(3);
    raiz->primeiroFilho->proximoIrmao->proximoIrmao = new NoArvore(4);

    raiz->primeiroFilho->primeiroFilho = new NoArvore(5);
    raiz->primeiroFilho->primeiroFilho->proximoIrmao = new NoArvore(6);

    raiz->primeiroFilho->proximoIrmao->proximoIrmao->primeiroFilho = new NoArvore(7);

    cout << "Valores dos nos em posOrdem: ";
    posOrdem(raiz);
    cout << endl;

    return 0;
}

