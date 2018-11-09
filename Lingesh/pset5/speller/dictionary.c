/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

#define CHILDREN_LENGTH 27

/**
 * Trie structure for storing words in the dictionary
 */
typedef struct node{
    bool isWord;
    struct node *children[CHILDREN_LENGTH]; //For 26 letters of the alphabet and apostrophe
}node;

//The root node
node *root;

//The dictionary file
FILE *dict = NULL;

//Word counter
int words = 0;

/**
 * Hash Function
 */
int hash(char c){
    return (c != '\'')? c - 'a' : CHILDREN_LENGTH - 1;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    int len = strlen(word); //Length of word passed
    char curr; //Variable to store a letter in the word
    
    //Temporary travelling pointer
    node *trav = root;
    
    //Iterating over the word, character by character till end of word is reached
    for(int i = 0; i < len; i++){
        //Getting the current character in the word and case insentizing it
        curr = tolower(*(word + i));
        
        //Checking if sequence of letters (so far) exists
        if(trav -> children[hash(curr)] == NULL)
            return false; //No word exists if current part of the word does not exist
        
        //In case it is not null, update traveller
        else
            trav = trav -> children[hash(curr)];
    }
    
    //Checking if given word is in dictionary
    if(trav -> isWord)
        return true;
    else
        return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    root = calloc(1, sizeof(node));
    
    //Load the dictionary file
    dict = fopen(dictionary, "r");
    if(dict == NULL){
        fprintf(stderr, "Could not open\n");
        unload();
        return false;
    }
    
    node *trav = root; //Temporary travelling pointer
    
    for(char c = fgetc(dict); c != EOF; c = fgetc(dict)){
        //Checking only for characters and apostrophes
        if(isalpha(c) || c == '\''){
            
            trav = root;
            
            //Iterates over characters of file until it hits a new line
            while(c != '\n'){
                int indx =  hash(c);//Mini hash function
                
                //Allocate memory if NULL
                if(trav -> children[indx] == NULL){
                    trav -> children[indx] = calloc(1, sizeof(node));
                    
                    //Error checking
                    if(trav -> children[indx] == NULL){
                        fprintf(stderr, "Load unsuccessful\n");
                        unload();
                        return false;
                    }
                }
                //Update travelling pointer
                trav = trav -> children[indx];
                //Scan the next character
                c = fgetc(dict);
            }
            //Setting isWord true when end of word is reached and increasing number of words
            if(c == '\n'){
                trav -> isWord = true;
                words++;
            }
        }
      
    }
    
    return true;
}

/**Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return words;
}

void clean(node* trav){
    //Iterate over the trie structure
    for(int i=0; i<CHILDREN_LENGTH; i++){
        //Recursively delete deeper nodes if curent node is not null
        if(trav->children[i] != NULL)
            clean(trav->children[i]);
    }
    //Free up memory
    free(trav);
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    clean(root); //Delete the trie
    fclose(dict); //Close the dictionary
    return true;
}


