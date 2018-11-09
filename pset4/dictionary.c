// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
static int counter=0 ;
// Represents number of children for each node in a trie
#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word ;
    struct node *children[N];
}
node;

// Represents a trie
node *root;

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    root->is_word = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];
    node* current_node ;

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        current_node=root ;
        int i=0 ;
        while(word[i]!='\0'){
            int d = word[i] ;
            // conversion from ASCII to the form to be used in index where apostrophee is gonna be the last element
            if (d<91 && d>64){
                d = d-65 ;
            }else if(d<123 && d>96 ){
                d = d-97 ;
            }else if(d==39 ){
                d=26 ;
            }
            if(current_node->children[i]!=NULL){
                current_node=current_node->children[i] ;
            }else {
                node* n=malloc(sizeof(node));
                current_node->children[i]=n;
            }
            i++ ;
        }
        current_node->is_word = true ;
        counter++ ;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = strlen(word) ;
    node* current_node=root ;
    for (int i=0;i<n;i++){
        int d = word[i] ;
        // conversion from ASCII to the form to be used in index where apostrophee is gonna be the last element
        if (d<91 && d>64){
            d = d-65 ;
        }else if(d<123 && d>96 ){
            d = d-97 ;
        }else if(d==39 ){
            d=26 ;
        }
        if(current_node->children[d]==NULL){
            return false ;
        }else {
            current_node=current_node->children[d] ;
        }
    }
    if (current_node->is_word==true){
        return true ;
    }
    return false;
}
//delete the nodes recursively
void delete_node(node* current_node)
{
    for(int i=0;i<27;i++)
    {
        if(current_node->children[i]!=NULL){
            delete_node(current_node->children[i]); // recursive call to delete_node()
        }
    }
    free(current_node);
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    delete_node(root) ;
    return false;
}