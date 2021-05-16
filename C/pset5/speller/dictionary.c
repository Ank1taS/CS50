// Implements a dictionary's functionality
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// to track total number of nodes in hash table ie total word in dictionary
unsigned int count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // to get hash key
    node *cursor = table[hash(word)];

    // searching the word in the linkedlist present at insex
    while (cursor != NULL)
    {
        // if word found
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // to store the hash key value of word
    int n = (int) tolower(word[0]) - 97;
    return n;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    int index;
    char buf[LENGTH];
    // Opens the required dictionary
    FILE *fp1 = fopen(dictionary, "r");

    //Checks if file is successfully opened or not
    if (fp1 == NULL)
    {
        printf("File opening error\n");
        fclose(fp1);
        return false;
    }

    while ((fscanf(fp1, "%s", buf)) != EOF)
    {
        // creating new node for word
        node *newNode = (node *) malloc(sizeof(node));

        // checks if any error in creating new node
        if (newNode == NULL)
        {
            printf("node creation error.");
            return false;
        }

        // updating count
        ++count;

        // stroring word in node
        strcpy(newNode->word, buf);

        index = hash(buf);

        // storing node addresses in array
        newNode->next = table[index];
        table[index] = newNode;
    }
    // closing opened dictionary file
    fclose(fp1);

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = NULL;
    node *temp = NULL;

    for (int i = 0; i < N; ++i)
    {
        // cursor and temp pointing to the binging of each linkedlist
        temp = table[i];
        cursor = table[i];

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
