#include <stdio.h>
#include <stdlib.h>

static void movement (int, int);
static void fill_array (int lines, int columns, char array[lines][columns]); 
static void display_array (int lines, int columns, char array[lines][columns]);

int main (int argc, char** argv)
{
    int lines;
    int columns;

    scanf ("%d %d", &lines, &columns);

    char array[lines][columns];
    fill_array (lines, columns, array); 
    display_array (lines, columns, array);

    return EXIT_SUCCESS;
}

static void
movement (int x, int y)
{
    if (x && y == 0)
        return;

}

static void
fill_array (int lines, int columns, char array[lines][columns])
{
    for (int row = 0; row < lines; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            scanf(" %c", &array[row][column]);
        }
    }
}

static void
display_array (int lines, int columns, char array[lines][columns])
{
    for (int row = 0; row < lines; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("%c ", array[row][column]);
        }
        printf("\n");
    }
    printf("\n");
}
