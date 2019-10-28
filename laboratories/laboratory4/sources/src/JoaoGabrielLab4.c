/**
 * @file JoaoGabrielLab4.c
 * @brief implementa os protótipos de JoaoGabrielLab4.h
 * @author João Gabriel Silva Coutinho (Bell Coutinho)
 * @bug Nenhum bug encontrado.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "JoaoGabrielLab4.h"

int main (int argc, char** argv)
{
    char names[NUMBER_STUDENTS][NUMBER_COLUMNS][NAME_SIZE];

    printf (">>>> INSIRA OS DADOS DOS ALUNOS\n\n");
    student_names (names);
    show (names);

    return EXIT_SUCCESS;
}

/**
 *
 * Função receber o nome do aluno, coleta as notas do mesmo para calcular a média 
 * e retorna sua situação, aprovado caso a média seja superior a 7.0, do contrário
 * retorna reprovado.
 * 
 * @return Retorna uma constante literal com a situação do aluno. Aprovado 
 * caso tenha passado, docontrário reprovado.
 */
char *
student_status (const char name[NAME_SIZE])
{
    float average = 0;
    float note = 0;

    for (int i = 0; i < 4; i++)
    {
        printf ("Nota %d DE %s ", i + 1, name);
        scanf ("%f", &note);

        average += note;
        
    }

    average /= 4.0;
    printf (">> MEDIA DE %s: %.2f\n\n", name, average); 

    if (average >= 7.0)
        return "APROVADO";
    else
        return "REPROVADO";

}

/**
 *
 * Função pega os nomes dos alunos para o array3D e passa para a 
 * função de calcular a situação do aluno onde o valor de retorno é
 * colocar no array3D.
 */
void 
student_names (char names[][NUMBER_COLUMNS][NAME_SIZE])
{
    for (int i = 0; i < NUMBER_STUDENTS; i++)
    {
        printf ("Nome ");
        setbuf (stdin, NULL);
        fgets (&names[i][0][0], NAME_SIZE, stdin);
        strtok (&names[i][0][0], "\n");
        int j = 0;
        while(names[i][0][j])
        {
            names[i][0][j] = toupper(names[i][0][j]);
            j++;
        }

        strcpy (&names[i][1][0], student_status (&names[i][0][0]));
    }
}

/**
 *
 * Mostra os nomes e situação dos alunos na saida padrão. Pegando o nome
 * na primeira coluna do array3D e a situação do mesmo na coluna 1 do
 * array3D.
 */
void 
show (char names[][NUMBER_COLUMNS][NAME_SIZE])
{
    printf (">>>> SITUAÇÂO FINAL\n\n");

    for (int i = 0; i < NUMBER_STUDENTS; i++)
    {
        printf ("%s %s\n", &names[i][0][0], &names[i][1][0]);
    }
}
