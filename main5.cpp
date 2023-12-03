#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;

    NoArvore(int valor) : data(valor), esquerda(NULL), direita(NULL) {}
};

const int MAX_CAMINHO = 100; // Tamanho máximo do caminho

void caminhosDaRaizParaFolhas(NoArvore *raiz, int caminho[], int profundidade) {
    if (raiz == NULL) {
        return;
    }

    // Adiciona o nó atual ao caminho
    caminho[profundidade] = raiz->data;

    // Se o nó atual é uma folha, imprime o caminho
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        cout << "Caminho: ";
        for (int i = 0; i <= profundidade; ++i) {
            cout << caminho[i];
            if (i < profundidade) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    // Continua percorrendo as subárvores recursivamente
    caminhosDaRaizParaFolhas(raiz->esquerda, caminho, profundidade + 1);
    caminhosDaRaizParaFolhas(raiz->direita, caminho, profundidade + 1);
}

int main() {
    NoArvore *raiz = new NoArvore(1);
    NoArvore *num1 = new NoArvore(2);
    NoArvore *num2 = new NoArvore(3);

    raiz->esquerda = num1;
    raiz->direita = num2;

    NoArvore *num3 = new NoArvore(5);

    num1->direita = num3;

    int caminho[MAX_CAMINHO];
    caminhosDaRaizParaFolhas(raiz, caminho, 0);

    return 0;
}

