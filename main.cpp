#include <iostream>
#include "avltree.h"
#include <vector>

using namespace std;

int main()
{
    avltree tree;
    vector<int> data;
    //inserting sorted numbers
    for(int i = 0; i < 1000; i++){
        tree.insert(i);
        data.push_back(i);
        if(!tree.isBalanced()){
            cout << "failed to balance after a insertion" << endl;
            break;
        }
    }

    //printing the tree in level order
    tree.print();

    //testing for balance
    if(tree.isBalanced())
        cout << "tree is balanced after all insertions" << endl;

    //removing numbers 
    for(int i : data){
        tree.remove(i);
        if(!tree.isBalanced()){
            cout << "failed to balance after a deletion" << endl;
            break;
        }
    }

    //printing the tree in level order
    tree.print();

    //testing for balance
    if(tree.isBalanced())
        cout << "tree is balanced after all deletions" << endl;
    else
        cout << "tree is not balanced" << endl;

}
