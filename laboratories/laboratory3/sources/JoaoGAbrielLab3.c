#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MEANING_SIZE 30
#define BEGINNING_MEANING 0
#define MESSAGE_SIZE 60
#define BEGINNING_MESSAGE 0
#define COLUMNS 2
#define KEY 1
#define VALUE 0

static void 
fill_dictionary(int number_words, char dict[number_words][COLUMNS][MEANING_SIZE]);

static void 
fill_message(int number_lines, char message[number_lines][MESSAGE_SIZE]);

int main (int argc, char** argv)
{
    int number_times = 0;
    int number_words = 0;
    int number_lines = 0;

    scanf(" %d", &number_times);

    if (abs(number_times > 0))
    {
        do 
        {
            scanf(" %d", &number_words);
            if (abs(number_words) > 0 && abs(number_words) <= 100)
            {
                char dict[number_words][COLUMNS][MEANING_SIZE];
                fill_dictionary(number_words, dict);

                scanf(" %d", &number_lines);
                if (abs(number_lines) > 0 && abs(number_lines) <= 100)
                {
                    char message[number_lines][MESSAGE_SIZE];
                    fill_message(number_lines, message);
                    
                }
            }

        } while (--number_times);
    }
    return EXIT_SUCCESS;
}

static void
fill_dictionary(int number_words, char dict[number_words][COLUMNS][MEANING_SIZE])
{
    for (int row = 0; row < number_words; row++)
    {
        fgets(&dict[row][VALUE][BEGINNING_MEANING], MEANING_SIZE, stdin);
        fgets(&dict[row][KEY][BEGINNING_MEANING], MEANING_SIZE, stdin);
    }
}

static void
fill_message(int number_lines, char message[number_lines][MESSAGE_SIZE])
{
    for (int row = 0; row < number_lines; row++)
    {
        fgets(&message[row][BEGINNING_MESSAGE], MESSAGE_SIZE, stdin);
    }
}
