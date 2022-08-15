#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    //Your program must prompt the user for a string of text using get_string.
    string text = get_string("Text: ");
    printf("%s\n", text);

    //Your program should count the number of letters, words, and sentences in the text.
    //You may assume that a letter is any lowercase character from a to z or any uppercase character from A to Z,
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') ||
            (text[i] >= 'A' && text[i] <= 'Z'))
        letters++;
    }
    printf("%i letters\n", letters);

    //any sequence of characters separated by spaces should count as a word
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        words++;
    }
    printf("%i words\n", words);

    //and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        sentences++;
    }
    printf("%i sentences\n", sentences);

    //Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
    float calculation = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;
    int index = round(calculation);
    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
    }
}