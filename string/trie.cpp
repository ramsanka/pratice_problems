#include <bits/stdc++.h>

using namespace std;

const int ALPH_SIZE =  26;

//trie structure

struct trie_node {
  
   struct trie_node *children[ALPH_SIZE];
   bool eow;
};


//generate a new node
struct trie_node * getNode() {

   struct trie_node *node = new trie_node;

   node->eow = false;

   //develop the children
   for (int i =0; i < ALPH_SIZE; i++) 
      node->children[i] = NULL;
  
 
   return node;
}



//insert operation
//take the length of the string and parse down 
//the trie structure.

void insert(struct trie_node *root, string key) {

    struct trie_node *node = root;

    for (int i = 0; i < key.length(); i++) 
    {
       int index = key[i]-'a'; //get the index by subtracting the base ascii val

       //if the node does not exist  
       if (!node->children[index]) 
            node->children[index] = getNode();

       node = node->children[index];
    }

    //this is the last node of the string.
    //mark it.
    node->eow = true;
}



//search operation
//return type : true/false (bool)
//inputs -: node, key

bool search(struct trie_node *root, string key) {

     struct trie_node *node = root;
     
     //parse through the key length
     printf("\n search start\n");


     for (int i = 0; i < key.length(); i++) {

         int index = key[i]-'a';
         if (!node->children[index])
            return false;
      
         node = node->children[index];
         printf("\n index %d",index);

     }

     //option that the trie is over before the key lengt
     if (node != NULL && node->eow == true)
        return true;

     return false;
}



//driver code.

int main() {

    string keys[] = {"coding","is","a","great",
		     "exercise","to","mind","if",
		     "done","properly"
                    };


    int n = sizeof(keys)/sizeof(keys[0]);

    struct trie_node *root = getNode();

    for (int i = 0; i < n; i++) 
        insert(root,keys[i]);

    bool ret = search(root, "the");
  
    if (ret == true) 
       printf("\n found the key\n");

    ret = search(root,"coding");
    if (ret == true)
       printf("\n found the key\n");

    return 0;
}
   
    

 



