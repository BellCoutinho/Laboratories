#include <stdio.h>
#include <stdlib.h>

int main (int argc, char** argv[])
{
    int fibonacci = 0;
    int f0 = 0;
    int f1 = 1;
    int numero;

    printf("Digite um número positivo: ");
    scanf("%d", &numero);

    if (numero < 0)
        return EXIT_FAILURE;

    while (f0 <= numero)
    {
        fibonacci = f0 + f1;
        f0 = f1;
        f1 = fibonacci;

        printf("%d ", f0);
    }

    printf("\n");
    return EXIT_SUCCESS;
}
