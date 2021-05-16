//  readability programe that computes the Coleman-Liau index of the text.

#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int gradeCalculaion(string arr)
{
    // storing the length of the string
    int length = strlen(arr);
    int countLetter = 0, countWord = 0, countSentence = 0;

    for (int i = 0; i < length ; ++i)
    {
        // counting numbers of letters
        if (isalpha(arr[i]))
        {
            ++countLetter;
        }

        //counting numbers of sentence
        if (arr[i] == 33 || arr[i] == 63 || arr[i] == 46)
        {
            ++countSentence;
        }

        // counting numbers of words
        if (i == 0 && isalpha(arr[i]))
        {
            // for the 0th index of string
            ++countWord;
        }
        else if (i != (length - 1) && arr[i] == 32 && arr[i + 1] != 32)
        {
            ++countWord;
        }
    }

    //average number of letters per 100 words in the text
    float l = (countLetter / (float)countWord) * 100;

    //average number of sentences per 100 words in the text
    float s = (countSentence / (float)countWord) * 100;

    //grade level computed by the Coleman-Liau formula
    float index = 0.0588 * l - 0.296 * s - 15.8;

    // returning grade
    //ie round the resulting index number to the nearest whole number
    return (round(index));
}

int main()
{
    // taling input using get_string()
    string text = get_string("Text: ");

    // checking whether a null string
    if (text == NULL)
    {
        return 1;
    }

    // calling gradeCalculation to calculate grade level
    int grade = gradeCalculaion(text);

    // checking cases of possible grade
    if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else if (grade > 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %d", grade);
    }
    printf("\n");
}