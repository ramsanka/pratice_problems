/*Ternary tree 

  Best of BST and trie

*/

#include <bits/stdc++.h>

using namespace std;

struct node {

   char data;
   bool eow;
   struct node *left, *right, *eq;
};


struct node * newNode(char data) {
   
   struct node *tmp = new node;
   tmp->data = data;
   tmp->eow = false;
   tmp->left  = NULL;
   tmp->right = NULL;
   tmp->eq    = NULL;
   return tmp;

}


//insert function

void insert(struct node **root, char *word) {


    if (!(*root)) {
	*root = newNode(*word);
    }

    if ((*word) < (*root)->data) {
       insert((&(*root)->left), word);
    } else if ((*word) > (*root)->data) {
       insert((&(*root)->right), word);
    } else {
       //check if the eow
       if (*(word+1)) {
         insert((&(*root)->eq), word+1);
       } else {
         (*root)->eow = true;
       }
    }
}


void traverse_temp(struct node *root, char *buffer, int depth) {

    if (root) {

       //recursive function
       traverse_temp(root->left, buffer, depth);

       buffer[depth] = root->data;
       if (root->eow == true) {

          buffer[depth+1]='\0';
          printf("%s\n",buffer);
       }

       traverse_temp(root->eq, buffer, depth+1);

       traverse_temp(root->right, buffer, depth);
    }
}

//traverse the ternary tree
void traverse(struct node *root) {

 char buffer[50];
 traverse_temp(root, buffer,0);
}


//search

int search_ternary(struct node *root, char *word) {

      if (!root)
         return 0;


      if (*word < (root)->data) 
         return search_ternary(root->left, word);

      else if (*word > (root)->data)
         return search_ternary(root->right, word);

      else 
      {
          if (*(word+1) == '\0')
             return 1;
     
          return search_ternary(root->eq, word+1);
      }
}


//driver code.
int main()
{

   struct node *root = NULL;

   insert(&root, "code");
   insert(&root, "is");
   insert(&root, "fun");


   printf("\n the traversal of the ternary tree \n");
   traverse(root);

   printf("\n the search results of the ternary tree \n");
   if (search_ternary(root, "code")) 
	printf("\n found the code for the word code");
   else 
	printf("\n did not found the code for the word code");
   

   if (search_ternary(root,"dod"))
	printf("\n found the code for the word dod");
   else 
	printf("\n did not find the code for the word dod");
  
   
   //ternary operator

   search_ternary(root,"fun")?printf("\n code found for fun\n"):printf("\n not found");


   return 0;
}
   
    
    


    
   
