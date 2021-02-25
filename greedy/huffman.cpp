#include <bits/stdc++.h>

using namespace std;

struct node {

    char data;
    int	 freq;

    struct node *right;
    struct node *left;


    node (char data, int freq) {
       left = right = NULL;
       this->data = data;
       this->freq  = freq;
    }

};

struct compare {

    bool operator()(node* l, node* r)
    {
       return (l->freq > r->freq);
    }
};


void printcode (struct node* root, string str) {

    if (!root)
       return;
  

    if (root->data != '$')
       cout<< root->data << ":"<< str << "\n";

    printcode (root->left, str + "0");
    printcode (root->right, str + "1");
}


void huffman (char data[], int freq[], int size)
{

    struct node *left, *right, *top;
    priority_queue<node *, vector<node*>, compare> minheap; //stl


    for (int i =0; i<size; ++i) 
       minheap.push(new node(data[i], freq[i]));

    while (minheap.size()  != 1) {

      left = minheap.top();
      minheap.pop();

      right = minheap.top();
      minheap.pop();
 
      top = new node('$',left->freq + right->freq);

      top->left = left;
      top->right = right;

      minheap.push(top);
    }


    printcode(minheap.top(), "");

}



int main() {

   char arr[] = {'r','a','m','c','t'};
   int  freq[]  = { 1,2,7,4,2};

   int size = sizeof(arr)/sizeof(arr[0]);

   huffman(arr, freq, size);
  
   return 0;
}
