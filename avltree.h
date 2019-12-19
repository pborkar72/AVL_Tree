#ifndef AVLTREE_H
#define AVLTREE_H

//avl tree node
struct Node{
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int value){
        this->value = value;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//avl tree
class avltree{
private:
    Node* root;
    void inorder(Node* node);
    //find height of a node
    int height(Node* node);
    //right rotation about a node
    Node* rotateRight(Node* x);
    //left rotation about a node
    Node* rotateLeft(Node* y);
    //height balance a node
    Node* balance(Node* node);
    //get balance factor of node
    int getBalanceFactor(Node* node);

public:
    //create empty tree
    avltree(){
        root = nullptr;
    }
    //print tree in levelorder
    void print();
    //inorder printing
    void inorder();
    //insert new value in tree and return new node
    void insert(int value);
    //remove a value from tree
    void remove(int value);
    //check if tree is balanced
    bool isBalanced(Node* node);
    bool isBalanced(){
        return isBalanced(root);
    }

};

#endif // AVLTREE_H
































