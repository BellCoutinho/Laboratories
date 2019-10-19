#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MEANING_SIZE 30
#define BEGINNING_MEANING 0
#define MESSAGE_SIZE 60
#define BEGINNING_MESSAGE 0
#define COLUMNS 2
#define KEY 0
#define VALUE 1

static void 
fill_dictionary (int number_words, char dict[number_words][COLUMNS][MEANING_SIZE]);

static void 
fill_message (int number_lines, char message[number_lines][MESSAGE_SIZE]);

static void
decode_message (int number_words, int number_lines, 
                char dict[number_words][COLUMNS][MEANING_SIZE], char message[number_lines][MESSAGE_SIZE]);
static void
search_value (char str[MESSAGE_SIZE], int number_words, char dict[number_words][COLUMNS][MEANING_SIZE]);

static void
show_dictionary (int number_words, char dict[number_words][COLUMNS][MEANING_SIZE]);

static void
show_message (int number_lines, char message[number_lines][MESSAGE_SIZE]);

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
                fill_dictionary (number_words, dict);

                scanf(" %d", &number_lines);
                if (abs(number_lines) > 0 && abs(number_lines) <= 100)
                {
                    char message[number_lines][MESSAGE_SIZE];
                    fill_message (number_lines, message);
                    decode_message (number_words, number_lines, dict, message);
                    
                }
            }

        } while (--number_times);
    }
    return EXIT_SUCCESS;
}

static void
fill_dictionary (int number_words, char dict[number_words][COLUMNS][MEANING_SIZE])
{
    for (int row = 0; row < number_words; row++)
    {
        setbuf(stdin, NULL);
        fgets(&dict[row][KEY][BEGINNING_MEANING], MEANING_SIZE, stdin);
	strtok(&dict[row][KEY][BEGINNING_MEANING], "\n");
        setbuf(stdin, NULL);
        fgets(&dict[row][VALUE][BEGINNING_MEANING], MEANING_SIZE, stdin);
	strtok(&dict[row][VALUE][BEGINNING_MEANING], "\n");
    }
}

static void
fill_message (int number_lines, char message[number_lines][MESSAGE_SIZE])
{
    for (int row = 0; row < number_lines; row++)
    {
        setbuf(stdin, NULL);
        fgets(&message[row][BEGINNING_MESSAGE], MESSAGE_SIZE, stdin);
	strtok(&message[row][BEGINNING_MESSAGE], "\n");
    }
}

static void
decode_message (int number_words, int number_lines, 
                char dict[number_words][COLUMNS][MEANING_SIZE], char message[number_lines][MESSAGE_SIZE])
{
    char tmp[MESSAGE_SIZE];

    for (int row = 0; row < number_lines; row++)
    {
        for (int column = 0, index = 0; message[row][column] != '\0'; column++, index++)
        {
		
		if (message[row][column] != ' ')
			tmp[index] = message[row][column];
		else
		{
			tmp[index] = '\0';
			search_value (tmp, number_words, dict);
			index = -1;

		}

		if (message[row][column+1] == '\0')
		{
			tmp[index+1] = '\0';
			search_value (tmp, number_words, dict);
		}
        }
        printf("\n");
    }
}

static void
search_value (char str[MESSAGE_SIZE], int number_words, char dict[number_words][COLUMNS][MEANING_SIZE])
{
    for (int row = 0; row < number_words; row++)
    {
        if (strcmp(str, &dict[row][KEY][BEGINNING_MEANING]) == 0)
        {
            printf("%s ", &dict[row][VALUE][BEGINNING_MEANING]);
	    return;
        }
    }

    printf("%s ", str);
}

static void
show_dictionary (int number_words, char dict[number_words][COLUMNS][MEANING_SIZE])
{
	for (int row = 0; row < number_words; row++)
	{
		printf("Key: %s\n", &dict[row][KEY][BEGINNING_MEANING]);
		printf("Value: %s\n", &dict[row][VALUE][BEGINNING_MEANING]);
	}	
}

static void
show_message (int number_lines, char message[number_lines][MESSAGE_SIZE])
{
	for (int row = 0; row < number_lines; row++)
	{
		printf("Message: %s\n", &message[row][BEGINNING_MESSAGE]);
	}
}
