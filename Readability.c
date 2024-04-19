#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);

    int words = count_words(text);

    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index

    float L = 100 * ((float) letters / words);
    float S = 100 * ((float) sentences / words);
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    index = round(index);
    int grade = (int) index;

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isblank(text[i]))
        {
            ;
        }
        else if (ispunct(text[i]))
        {
            ;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
        else if (ispunct(text[i]))
        {
            ;
        }
        else if (isalpha(text[i]))
        {
            ;
        }
    }
    words++;
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        else if (isalpha(text[i]))
        {
            ;
        }
        else if (isblank(text[i]))
        {
            ;
        }
    }
    return sentences;
}
