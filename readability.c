#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_word(string text);
int count_sentence(string text);

int main(void)
{
    string text = get_string("Text: ");
    float n = (float)count_letters(text);
    float w = (float)count_word(text);
    float s = (float)count_sentence(text);
    float avg_letters =  ((float)(n / w)) * 100;
    float avg_sentence = ((float)(s / w)) * 100;
    int index = round(0.0588 * avg_letters - 0.296 * avg_sentence - 15.8);
    
    if(index < 1)
    {
        printf("Before Grade 1\n");
    }else if(index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    
}

int count_letters(string text)
{
    int counter = 0;
    for(int i = 0; i < strlen(text); i++ )
    {
        char lower = tolower(text[i]);
        if(lower >= 97 && lower <= 122)
        {
            counter++;
        }
    }
    return counter;
    }


int count_word(string text)
{
    int counter = 0;
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == 32)
        {
            counter++;
        }
    }
    return counter + 1;
}

int count_sentence(string text)
{
    int counter = 0;
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counter++;
        }
    }
    return counter;
}
