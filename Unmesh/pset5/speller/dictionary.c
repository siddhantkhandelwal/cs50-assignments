// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "dictionary.h"

int count=0;

typedef struct node
{
   int valid;
   struct node * child[27];
}node;

node * root;
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int len=strlen(word);
    node* temp=root;
    for(int i=0;i<len;i++)
    {
        int h=word[i];
        if(isalpha(word[i])){if(h<=90) h-=64;else h-=96;}
        else h=0;
        if (temp->child[h]==NULL) return false;
        else temp=temp->child[h];
    }
    if(temp->valid==1)
    return true;
    else return false;
}



// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
   root=malloc(sizeof(node));
   FILE* dict= fopen(dictionary,"r");
   if(dict==NULL)
   return false;
   else
   {
       node* temp=root;
       while(!feof(dict))
       {
           char ch=fgetc(dict);
           if(ch!='\n')
           {
               int h=ch;
               if(isalpha(ch)){if(h<=90) h-=64;else h-=96;}
               else h=0;
               if(temp->child[h]==NULL)
               {
                   node* n=malloc(sizeof(node));
                   temp->child[h]=n;
               }
               temp=temp->child[h];
           }
           else{
               count++;temp->valid=1;temp=root;
           }
       }
       return true;
   }
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

void del(node*node)
{
    for(int i=0;i<27;i++)
    {
        if(node->child[i]!=NULL)
            del(node->child[i]);
    }
    free(node);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    del(root);
    return true;
}


