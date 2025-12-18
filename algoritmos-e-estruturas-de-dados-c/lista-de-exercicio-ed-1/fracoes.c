#include <stdio.h>
#include <stdlib.h>
#include "fracoes.h"

int mdc(int a, int b)
{
    if (b == 0)
        return abs(a); 
    return mdc(b, a % b);
}

void simplificar(fracoes *f)
{
    int divisor = mdc(f->n, f->d);
    f->n /= divisor;
    f->d /= divisor;
    if (f->d < 0)
    {
        f->n *= -1;
        f->d *= -1;
    }
}

fracoes criafracao(int n, int d)
{
    fracoes f;
    f.n = n;
    f.d = (d == 0) ? 1 : d;
    simplificar(&f);
    return f;
}

fracoes soma(fracoes f1, fracoes f2)
{
    fracoes fr;
    fr.n = f1.n * f2.d + f2.n * f1.d;
    fr.d = f1.d * f2.d;
    simplificar(&fr);
    return fr;
}

fracoes sub(fracoes f1, fracoes f2)
{
    fracoes fr;
    fr.n = f1.n * f2.d - f2.n * f1.d;
    fr.d = f1.d * f2.d;
    simplificar(&fr);
    return fr;
}

fracoes multiplicar(fracoes f1, fracoes f2)
{
    fracoes fr;
    fr.n = f1.n * f2.n;
    fr.d = f1.d * f2.d;
    simplificar(&fr);
    return fr;
}

fracoes dividir(fracoes f1, fracoes f2)
{
    fracoes fr;
    fr.n = f1.n * f2.d;
    fr.d = f1.d * f2.n;
    simplificar(&fr);
    return fr;
}

void imprimirf(fracoes f)
{
    printf("%d/%d\n", f.n, f.d);
}

double decimal(fracoes f)
{
    return (double)f.n / f.d;
}

int main()
{
    fracoes f1 = criafracao(2, 3);
    fracoes f2 = criafracao(4, 5);

    printf("Fração 1:\n");
    imprimirf(f1);

    printf("Fração 2:\n");
    imprimirf(f2);

    fracoes somar = soma(f1, f2);
    printf("Soma:\n");
    imprimirf(somar);

    fracoes subtrair = sub(f1, f2);
    printf("Subtração:\n");
    imprimirf(subtrair);

    fracoes mult = multiplicar(f1, f2);
    printf("Multiplicação:\n");
    imprimirf(mult);

    fracoes div = dividir(f1, f2);
    printf("Divisão:\n");
    imprimirf(div);

    printf("Decimal de f1: %.4lf\n", decimal(f1));
    printf("Decimal de f2: %.4lf\n", decimal(f2));

    return 0;
}
