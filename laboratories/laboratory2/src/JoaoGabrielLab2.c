#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void movement (int lines, int columns, char array[lines][columns]);
static void fill_array (int lines, int columns, char array[lines][columns]); 
static void display_array (int lines, int columns, char array[lines][columns]);

int main (int argc, char** argv)
{
    int lines;
    int columns;

    do
    {
        scanf ("%d %d", &lines, &columns);

        if ((lines && columns) == 0)
            break;

        char array[lines][columns];
        fill_array (lines, columns, array); 
        movement(lines, columns, array);
        display_array (lines, columns, array);
    } while (true);

    return EXIT_SUCCESS;
}

static void
movement (int lines, int columns, char array[lines][columns])
{
    int x;
    int y;
    int row = 0;
    int column = 0;
    int x_total = 0;
    int y_total = 0;
    int x_times = 0;
    int y_times = 0;
    char tmp;

    do
    {
        
        scanf("%d %d", &y, &x);
        x_total += x;
        y_total += y;
    } while (y || x);

    x_times = x_total%columns < 0? x_total%columns + columns: x_total%columns;
    y_times = y_total%lines < 0? y_total%lines + lines: y_total%lines;
    printf("X times = %d\n", x_times);
    
    if (y_total != 0)
    {
        for (column = 0; column < columns; column++)
        {
            for (int turns = 0; turns < y_times; turns++)
            {
                printf("Numbers: %d\n", turns+1);
                for (row = 0; row < lines - 1; row++)
                {
                    tmp = array[row][column];
                    array[row][column] = array[row + 1][column];
                    array[row + 1][column] = tmp;
                }
            }
        }
    }

    if (x_total != 0)
    {
        for (row = 0; row < lines; row++)
        {
            for (int turns = 0; turns < x_times; turns++)
            {
                for (column = columns - 1; column > 0; column--)
                {
                    tmp = array[row][column];
                    array[row][column] = array[row][column - 1];
                    array[row][column - 1] = tmp;
                }
            }
        }
    }
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
