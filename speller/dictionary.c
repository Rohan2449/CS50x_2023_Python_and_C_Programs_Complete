// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// function prototype
void unloader(node *p);

// TODO: Choose number of buckets in hash table
const unsigned int N = 26 * 26 * 26 * 26;

// Hash table and variables
node *table[N];
int dictSize = 0;
bool loaded = false;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashIndex = hash(word);
    node *trav = table[hashIndex];

    while (trav != NULL)
    {
        char *dictWord = trav->word;
        if (strcasecmp(word, dictWord) == 0)
        {
            return true;
        }
        trav = trav->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int len = strlen(word);
    if (len > 2)
    {
        return (tolower(word[0]) - 'a') * (tolower(word[1]) - 'a') % N;
    }

    // int a = 1;
    // int index = 0;
    // while(word[index] != '\0' && index < 3)
    // {
    //      a *= (tolower(word[index]) - 'a');
    //      index++;
    // }
    return 1;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *f = fopen(dictionary, "r");
    if (f == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];

    while (fscanf(f, "%s", word) == 1)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 0;
        }
        int hashIndex = hash(word);

        strcpy(n->word, word);
        n->next = table[hashIndex];
        table[hashIndex] = n;
        dictSize++;
    }

    fclose(f);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (!loaded)
    {
        return 0;
    }
    return dictSize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    node *p;
    for (int i = 0; i < N; i++)
    {
        p = table[i];
        unloader(p);
        table[i] = NULL;
        if (table[i] != NULL)
        {
            return false;
        }
    }
    return true;
}

void unloader(node *p)
{
    if (p == NULL)
    {
        return;
    }
    unloader(p->next);
    free(p);
    p = NULL;
}
