#ifndef MAIN_CPP_BST_H
#define MAIN_CPP_BST_H

#include <bits/stdc++.h>

using namespace std;

template <class T>
class BST {
private:

    class BSTNode{
    public:
        T key;
        BSTNode* left;
        BSTNode* right;
        BSTNode(T value) {
            key = value;
            left = right = NULL;
        }
    };

    BSTNode* root;
    int SIZE;

    void destroy(BSTNode*& r) {
        if (r != NULL) {
            destroy(r->left);
            destroy(r->right);
            delete r;
            r = NULL;
        }
    }

    void inorder(BSTNode* r){
        if(r != NULL){
            inorder(r->left);
            cout << r->key << ' ';
            inorder(r->right);
        }
    }

    void preorder(BSTNode* r) {
        if(r != NULL){
            cout << r->key << ' ';
            preorder(r->left);
            preorder(r->right);
        }
    }

    void postorder(BSTNode* r) {
        if(r != NULL){
            postorder(r->left);
            postorder(r->right);
            cout << r->key << ' ';
        }
    }


    BSTNode* insert(BSTNode* r, T value){
        if(r == nullptr){
            r = new BSTNode(value);
            return r;
        }

        if(value < r->key){
            r->left = insert(r->left, value);
        }
        else if(value > r->key){
            r->right = insert(r->right, value);
        }
        return r;
    }


    BSTNode* findMin(BSTNode* r) {
        while (r->left != NULL) {
            r = r->left;
        }
        return r;
    }

    BSTNode* deleteNode(BSTNode* r, T value){
        if (r == NULL) {
            return r;
        }
        else if (value < r->key) {
            r->left = deleteNode(r->left, value);
        }
        else if (value > r->key) {
            r->right = deleteNode(r->right, value);
        }
        else {
             if (r->left == NULL) {
                BSTNode* temp = r->right;
                delete r;
                return temp;
            } else if (r->right == NULL) {
                 BSTNode* temp = r->left;
                 delete r;
                 return temp;
            } else {
                BSTNode* temp = findMin(r->right);
                 r->key = temp->key;
                 r->right = deleteNode(r->right, temp->key);
            }
        }
        return r;
    }


public:

    BST() : root(NULL), SIZE(0){}

    int size(){
        return SIZE;
    }

    bool empty(){
        return SIZE == 0;
    }

    void insert(T value) {
        root = insert(root, value);
        SIZE++;
    }

    void remove(T value){
        root = deleteNode(root, value);
        SIZE--;
    }

    void clear(){
        destroy(root);
        SIZE = 0;
    }

    void inorder() {
        inorder(root);
    }

    void preorder(){
        preorder(root);
    }

    void postorder(){
        postorder(root);
    }

    ~BST() {
        destroy(root);
        SIZE = 0;
    }

};

#endif //MAIN_CPP_BST_H
