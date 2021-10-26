#include <iostream>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data) {
        this->data = data;
        left=right=NULL;
    }
};

void printPreOrder(struct Node* root)
{

    struct Node* node = root;
    //base case.
    if (node == NULL) {
        return;
    }

    printPreOrder(node->left);
    printPreOrder(node->right);

    cout<<node->data<<"->>";

}

void printPostOrder(struct Node* root)
{
    struct Node* node = root;
    if (node == NULL) {
        return;
    }

    cout<<node->data<<"->";
    printPostOrder(node->left);
    printPostOrder(node->right);
}

//driver code.
int main()
{

    struct Node* node = new Node(1);
    node->left = new Node(2);
    node->right = new Node(3);

    node->left->left = new Node(4);
    node->left->right = new Node(5);

    cout <<"preorder traversal of the tree" << endl;

    printPreOrder(node);


    cout <<"postoder traversal of the tree" << endl;

    printPostOrder(node);
}
