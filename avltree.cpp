#include <iostream>
#include <stack>
#include <queue>
#include "avltree.h"

void avltree::inorder(Node* node){
    if(node){
        inorder(node->left);
        std::cout << "Node: " << node->value << " Height: " << node->height << std::endl;
        inorder(node->right);
    }
}

void avltree::inorder(){
    inorder(root);
    std::cout << std::endl;
}

//remove value from tree
void avltree::remove(int value){
    //if tree is empty
    if(!root)
        return;

    //create stack to store ancestors
    std::stack<Node*> stack;
    //find node and its parent
    Node* current = root;
    Node* parent = nullptr;
    while(current && current->value != value){
       stack.push(current);
       parent = current;
       if(current->value > value)
           current = current->left;
       else
           current = current->right;
    }
    //if value is not present
    if(!current)
        return;

    //root case
    if(!parent){
        //no child case
        if(!current->left && !current->right){
            root = nullptr;
            delete current;
            return;
        }
        //only left subtree case
        else if(current->left && !current->right){
            Node* oldRoot = root;
            root = current->left;
            delete oldRoot;
            return;
        }
        //only right subtree case
        else if(!current->left && current->right){
            Node* oldRoot = root;
            root = current->right;
            delete oldRoot;
            return;
        }
        //both subtree present case
        else{
            //find maximum in left subtree
            if(current->left->height >= current->right->height){
                Node* max = current->left;
                Node* maxParent = current;
                stack.push(current);
                while(max->right){
                    stack.push(max);
                    max = max->right;
                }
                maxParent = stack.top();
                int maxParentValue = maxParent->value;
                int maxValue = max->value;
                current->value = maxValue;
                if(maxParentValue > maxValue)
                    maxParent->left = max->left;
                else
                    maxParent->right = max->left;

                delete max;

                Node* temp = nullptr;
                Node* tempParent = nullptr;

                while(!stack.empty()){
                    temp = stack.top();
                    stack.pop();
                    temp->height = height(temp);
                    if(!stack.empty()){
                        tempParent = stack.top();
                        //balance temp
                        if(tempParent->value > temp->value)
                            tempParent->left = balance(temp);
                        else
                            tempParent->right = balance(temp);
                    }
                }
                root = balance(root);
            }else{
                //find min in right subtree
                Node* min = current->right;
                Node* minParent = current;
                stack.push(current);
                while(min->left){
                    stack.push(min);
                    min = min->left;
                }
                minParent = stack.top();
                int minParentValue = minParent->value;
                int minValue = min->value;
                current->value = minValue;
                if(minParentValue > minValue)
                    minParent->left = min->left;
                else
                    minParent->right = min->left;

                delete min;

                Node* temp = nullptr;
                Node* tempParent = nullptr;

                while(!stack.empty()){
                    temp = stack.top();
                    stack.pop();
                    temp->height = height(temp);
                    if(!stack.empty()){
                        tempParent = stack.top();
                        //balance temp
                        if(tempParent->value > temp->value)
                            tempParent->left = balance(temp);
                        else
                            tempParent->right = balance(temp);
                    }
                }
                root = balance(root);
            }
        }

    }
    //non root case
    else{
        //no child case
        if(!current->left && !current->right){
            if(parent->value > current->value)
                parent->left = nullptr;
            else
                parent->right = nullptr;


            delete current;

            Node* temp = nullptr;
            Node* tempParent = nullptr;

            while(!stack.empty()){
                temp = stack.top();
                stack.pop();
                temp->height = height(temp);
                if(!stack.empty()){
                    tempParent = stack.top();
                    //balance temp
                    if(tempParent->value > temp->value)
                        tempParent->left = balance(temp);
                    else
                        tempParent->right = balance(temp);
                }
            }
            root = balance(root);
        }
        //only left child case
        else if(current->left && !current->right){
            if(parent->value > current->value)
                parent->left = current->left;
            else
                parent->right = current->left;

            delete current;

            Node* temp = nullptr;
            Node* tempParent = nullptr;

            while(!stack.empty()){
                temp = stack.top();
                stack.pop();
                temp->height = height(temp);
                if(!stack.empty()){
                    tempParent = stack.top();
                    //balance temp
                    if(tempParent->value > temp->value)
                        tempParent->left = balance(temp);
                    else
                        tempParent->right = balance(temp);
                }
            }
            root = balance(root);
        }
        //only right child case
        else if(!current->left && current->right){
            if(parent->value > current->value)
                parent->left = current->right;
            else
                parent->right = current->right;

            delete current;

            Node* temp = nullptr;
            Node* tempParent = nullptr;

            while(!stack.empty()){
                temp = stack.top();
                stack.pop();
                temp->height = height(temp);
                if(!stack.empty()){
                    tempParent = stack.top();
                    //balance temp
                    if(tempParent->value > temp->value)
                        tempParent->left = balance(temp);
                    else
                        tempParent->right = balance(temp);
                }
            }
            root = balance(root);
        }
        //both child case
        else{
            //find maximum in left subtree
            if(current->left->height >= current->right->height){
                Node* max = current->left;
                Node* maxParent = current;
                stack.push(current);
                while(max->right){
                    stack.push(max);
                    max = max->right;
                }
                maxParent = stack.top();
                int maxParentValue = maxParent->value;
                int maxValue = max->value;
                current->value = maxValue;
                if(maxParentValue > maxValue)
                    maxParent->left = max->left;
                else
                    maxParent->right = max->left;

                delete max;

                Node* temp = nullptr;
                Node* tempParent = nullptr;

                while(!stack.empty()){
                    temp = stack.top();
                    stack.pop();
                    temp->height = height(temp);
                    if(!stack.empty()){
                        tempParent = stack.top();
                        //balance temp
                        if(tempParent->value > temp->value)
                            tempParent->left = balance(temp);
                        else
                            tempParent->right = balance(temp);
                    }
                }
                root = balance(root);
            }else{
                //find min in right subtree
                Node* min = current->right;
                Node* minParent = current;
                stack.push(current);
                while(min->left){
                    stack.push(min);
                    min = min->left;
                }
                minParent = stack.top();
                int minParentValue = minParent->value;
                int minValue = min->value;
                current->value = minValue;
                if(minParentValue > minValue)
                    minParent->left = min->left;
                else
                    minParent->right = min->left;

                delete min;

                Node* temp = nullptr;
                Node* tempParent = nullptr;

                while(!stack.empty()){
                    temp = stack.top();
                    stack.pop();
                    temp->height = height(temp);
                    if(!stack.empty()){
                        tempParent = stack.top();
                        //balance temp
                        if(tempParent->value > temp->value)
                            tempParent->left = balance(temp);
                        else
                            tempParent->right = balance(temp);
                    }
                }
                root = balance(root);
            }
        }
    }

}

//insert new value in tree
void avltree::insert(int value){
    //if tree is empty
    if(!root){
        root = new Node(value);
        return;
    }

    //find parent node to insert into
    std::stack<Node*> stack;
    Node* parent = nullptr;
    Node* current = root;

    while(current){
        if(current->value == value)
            return;

        parent = current;
        stack.push(parent);

        if(current->value > value)
            current = current->left;
        else
            current = current->right;

    }

    //insert into parent
    if(parent->value > value){
        parent->left = new Node(value);
    }
    else{
        parent->right = new Node(value);
    }

    Node* temp = nullptr;
    Node* tempParent = nullptr;

    while(!stack.empty()){
        temp = stack.top();
        stack.pop();
        temp->height = height(temp);
        if(!stack.empty()){
            tempParent = stack.top();
            //balance temp
            if(tempParent->value > temp->value)
                tempParent->left = balance(temp);
            else
                tempParent->right = balance(temp);
        }
    }
    root = balance(root);
}

//print tree in levelorder
void avltree::print(){
    if(!root)
        return;

    std::queue<Node*> queue;
    queue.push(root);
    queue.push(nullptr);

    while(!queue.empty()){
        Node* current = queue.front();
        queue.pop();
        if(current){
            std::cout << current->value << "[h:" << current->height << "]" << "  ";
            if(current->left)
                queue.push(current->left);
            if(current->right)
                queue.push(current->right);
        }else{
            if(queue.empty())
                break;
            //append next null and print on new line
            queue.push(nullptr);
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

//find height of node
int avltree::height(Node* node){
    if(!node)
        return 0;
    else if(!node->left && !node->right)
        return 1;
    else if(node->left && !node->right)
        return  1 + node->left->height;
    else if(!node->left && node->right)
        return 1 + node->right->height;
    else
        return 1 + std::max(node->left->height, node->right->height);
}

//right rotation
Node* avltree::rotateRight(Node* x){
    if(!x || !x->left)
        return x;

    Node* y = x->left;
    Node* T = y->right;

    x->left = T;
    y->right = x;

    //update heights
    x->height = height(x);
    y->height = height(y);

    return y;
}

//left rotation
Node* avltree::rotateLeft(Node* y){
    if(!y || !y->right)
        return y;

    Node* x = y->right;
    Node* T = x->left;

    y->right = T;
    x->left = y;

    //update heights
    y->height = height(y);
    x->height = height(x);

    return x;
}

//get balance factor
int avltree::getBalanceFactor(Node* node){
    if(!node)
        return 0;
    else if(!node->left && !node->right)
        return 0;
    else if(node->left && !node->right)
        return node->left->height;
    else if(!node->left && node->right)
        return -node->right->height;
    else
        return node->left->height - node->right->height;
}

//height balance a node
Node* avltree::balance(Node* node){
    if(!node)
        return node;

    int balancefactor = getBalanceFactor(node);

    if(balancefactor > 1){
        //left left case
        if(height(node->left->left) > height(node->left->right))
            node = rotateRight(node);
        //left right case
        else{
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
    }

    if(balancefactor < -1){
        //right right case
        if(height(node->right->right) > height(node->right->left))
            node = rotateLeft(node);
        //right left case
        else{
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }
    }

    return node;
}

//check for balance
bool avltree::isBalanced(Node* node){
    if(!node)
        return true;
    int balancefactor = getBalanceFactor(node);
    if(balancefactor > 1 || balancefactor < -1)
        return false;
    else
        return isBalanced(node->left) && isBalanced(node->right);
}





















