#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (int argc, char** argv)
{
    int opcao_de_menu;
    int opcao;
    bool sair = false;

    do 
    {
        puts("====================================");
        printf("1. Sequência de fibonacci\n");
        printf("2. Sequência de termos\n");
        printf("3. Operações aritméticas\n");
        printf("4. Dobras\n");
        printf("5. Sair do programa\n");
        puts("====================================");

        printf("Digite sua escolha: ");
        scanf("%d", &opcao_de_menu);

        switch (opcao_de_menu)
        {
            case 1:
                printf("Digite um número positivo: ");
                scanf("%d", &opcao);

                if (opcao < 0)
                    puts("0");
                else if (opcao == 0)
                    puts("0 1");
                else 
                {
                    int tmp1 = 0;
                    int tmp2 = 1;
                    int soma = 0;

                    printf("0 1 ");
                    while (soma <= opcao)
                    {
                        soma = tmp1 + tmp2;
                        tmp1 = tmp2;
                        tmp2 = soma;
                        printf("%d ", soma);
                    }
                    puts("");
                }
                break;

            case 2:
                printf("Digite um número positivo: ");
                scanf("%d", &opcao);

                if (opcao < 1)
                    puts("1");
                else
                {
                    while (opcao != 1)
                    {
                        if (opcao % 2 == 0)
                            opcao /= 2;
                        else
                            opcao = 3*opcao + 1;

                        if (opcao != 1)
                            printf("%d -> ", opcao);
                        else
                            puts("1");
                    }
                }


                break;
            case 5:
                sair = true;
                puts("Saindo do programa...");
                break;
                
        }

    } while (!sair);

    return EXIT_SUCCESS;
}
