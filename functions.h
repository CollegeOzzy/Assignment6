#include <iostream>
#include "bstnode.h"
#pragma once

using std::cout;
using std::endl;

// I originally imagined this not in a seperate function then add node but because of recursion I thought it would impact memory heavily
BSTNode* create_node(int data){
    BSTNode* Node = new BSTNode();
    Node-> data = data;
    Node-> left = NULL;
    Node-> right = NULL;
    return Node;
}

/*void add_node(BSTNode** ptrToRoot, int data){
    BSTNode* current_node = * ptrToRoot;
	
    if(* ptrToRoot == NULL) { // start the tree
		* ptrToRoot = create_node(data);
        return;
	}
	// if data is less than or equal to 
	else if(data <= current_node->data) {
        while(current_node->left != nullptr && current->next->data != value_to_be_removed){
        current = current ->next;

} 
I'm leaving this code here so you can see my thought process
I'm having trouble thinking of a way to use recursion while using a pointer to pointer
I'm at the conclusion that I can either just return a node and not use a pointer to pointer or just not use rescursion
I can kinda imagine using while loops and if statements but ultimately recursion seems a lot more elegant of a solution*/

BSTNode* add_node(BSTNode* root, int data){
    // if empty start the tree
    if(root == NULL){
        root = create_node(data);
    }
    // if the data is less than or equal what's stored in the node go left
    else if(data <= root -> data){
        root->left = add_node(root->left, data);
    }
    // if the data is greater then or equal what's stored in the node go right
    else if(data > root -> data){
        root->right = add_node(root->right, data);
    }
    return root;
}
//This function have been provided by Joseph Jess as part of his data structure course
void in_order_traversal(BSTNode *current) {
    if(current != nullptr) {
        in_order_traversal(current->left);
        cout << "current->value: " << current->data << endl;
        in_order_traversal(current->right);
    }
}

/*
in the case with 2 children there are two options for a sucessor:
find the maximum value in the left side of the tree as replacement
or find the minimum value in the right side of the tree as replacement */

BSTNode* find_max(BSTNode* root){
	while(root -> right != NULL) {
        root = root -> right;
    }
	return root;
}

BSTNode* remove(BSTNode* root, int data){
    if (root == NULL){
        return NULL;
    }
    else if(data < root->data){
        root -> left = remove(root -> left, data);
        return root;
    }
    else if(data > root->data){
        root -> right = remove(root -> right, data);
        return root;
    }
    // this means that we found the value and have to deal with the 3 cases
    else {
        //when we are at a leaf node
        if(root -> left == NULL && root -> right  == NULL){
            delete root;
            root = NULL;
            }
        //when there is a child on the right
        else if (root -> left == NULL){
            BSTNode* node_to_be_deleted = root;
            root = root -> right;
            delete node_to_be_deleted;
            }
        //when there is a child on the left
        else if (root -> right == NULL){
            BSTNode* node_to_be_deleted = root;
            root = root -> left;
            delete node_to_be_deleted;
            }   
        // when there is 2 children...
        // I will find the maximum value starting left...
        else { 
            BSTNode* node_to_be_deleted = find_max(root -> left);
            root -> data = node_to_be_deleted -> data;
            root -> left = remove(root -> left, node_to_be_deleted -> data);

        }
    return root;
    }
}
