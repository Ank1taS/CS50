// programe name substitution cypher

#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

bool keyValidation(string arr)
{
    int repeatCount[26] = {0};
    int length = strlen(arr);
    int count;

    if (length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }
    for (int i = 0; i < length; ++i)
    {
        // each character of the cypher must be alphabet
        if (!isalpha(arr[i]))
        {
            printf("Key must only contain alphabetic character.\n");
            return false;
        }

        // checking repeatation of alphabate
        // no alphabet must be repeated
        count = tolower(arr[i]) - 97;
        // whether ay index is > 0
        if (repeatCount[count] > 0)
        {
            printf("Key must not contain repeated characters.\n");
            return false;
        }
        ++repeatCount[count];
    }
    return true;
}

int main(int argc, string argv[])
{
    // checking numbers of argument in command line
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    //checking correctness of key
    if (keyValidation(argv[1]))
    {
        // input for plain text
        string text = get_string("plaintext: ");

        printf("ciphertext: ");

        // legnth of the plain text
        int lenght = strlen(text);

        for (int i = 0; i < lenght; ++i)
        {
            int index ;

            // if upper case alphabet
            if (isupper(text[i]))
            {
                index = (int)text[i] - 65;
                printf("%c", toupper(argv[1][index]));
            }
            // if lower case alphabet
            else if (islower(text[i]))
            {
                index = (int)text[i] - 97;
                printf("%c", tolower(argv[1][index]));
            }
            // if not a alphabet
            else
            {
                printf("%c", text[i]);
            }
        }
    }
    else
    {
        return 1;
    }
    printf("\n");
    return 0;
}