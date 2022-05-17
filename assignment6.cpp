#include <iostream>
#include "functions.h"

using std::cout;
using std::endl;

// numbers to be added: 1 3 4 5 7 9 11
int main(){
    BSTNode* root = NULL;
    root = add_node(root, 5);
    root = add_node(root, 3);
    root = add_node(root, 9);
    root = add_node(root, 4);
    root = add_node(root, 1);
    root = add_node(root, 7);
    root = add_node(root, 11);

    //These print statements have been provided by Joseph Jess as part of his data structure course
    cout << "root->data: " << root->data << endl;

    cout << "root->left->data: " << root->left->data << endl;
    cout << "root->right->data: " << root->right->data << endl;
    
    cout << "root->left->left->data: " << root->left->left->data << endl;
    cout << "root->left->right->data: " << root->left->right->data << endl;
    cout << "root->right->left->data: " << root->right->left->data << endl;
    cout << "root->right->right->data: " << root->right->right->data << endl;

    cout << "***************************************" << endl;
    
    in_order_traversal(root);

    cout << "***************************************" << endl;
    root = remove(root, 5);
    cout << "root->data: " << root->data << endl;

    cout << "root->left->data: " << root->left->data << endl;
    cout << "root->right->data: " << root->right->data << endl;
    
    cout << "root->left->left->data: " << root->left->left->data << endl;
    cout << "root->right->left->data: " << root->right->left->data << endl;
    cout << "root->right->right->data: " << root->right->right->data << endl;

    cout << "***************************************" << endl;
    
    in_order_traversal(root);

    cout << "***************************************" << endl;

    root = remove(root, 9);
    cout << "root->data: " << root->data << endl;

    cout << "root->left->data: " << root->left->data << endl;
    cout << "root->right->data: " << root->right->data << endl;
    
    cout << "root->left->left->data: " << root->left->left->data << endl;
    cout << "root->right->right->data: " << root->right->right->data << endl;

    cout << "***************************************" << endl;
    
    in_order_traversal(root);

    cout << "***************************************" << endl;
}


