#ifndef FRACOES_H
#define FRACOES_H

typedef struct sfracoes
{
    int n; // numerador 
    int d; // denominador
} fracoes;

int mdc(int a, int b);
fracoes criafracao(int n, int d);
fracoes soma(fracoes f1, fracoes f2);
fracoes sub(fracoes f1, fracoes f2);
fracoes multiplicar(fracoes f1, fracoes f2);
fracoes dividir(fracoes f1, fracoes f2);
void simplificar(fracoes* f);
void imprimirf(fracoes f);
double decimal(fracoes f);

#endif
