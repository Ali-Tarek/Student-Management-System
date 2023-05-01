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
            left = right = nullptr;
        }
    };

    BSTNode* root;
    int SIZE;

    void destroy(BSTNode*& r) {
        if (r != nullptr) {
            destroy(r->left);
            destroy(r->right);
            delete r;
            r = nullptr;
        }
    }

    void inorder(BSTNode* r){
        if(r != nullptr){
            inorder(r->left);
            cout << r->key << ' ';
            inorder(r->right);
        }
    }

    void preorder(BSTNode* r) {
        if(r != nullptr){
            cout << r->key << ' ';
            preorder(r->left);
            preorder(r->right);
        }
    }

    void postorder(BSTNode* r) {
        if(r != nullptr){
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
        while (r->left != nullptr) {
            r = r->left;
        }
        return r;
    }

    BSTNode* deleteNode(BSTNode* r, T value){
        if (r == nullptr) {
            return r;
        }
        else if (value < r->key) {
            r->left = deleteNode(r->left, value);
        }
        else if (value > r->key) {
            r->right = deleteNode(r->right, value);
        }
        else {
             if (r->left == nullptr) {
                BSTNode* temp = r->right;
                delete r;
                return temp;
            } else if (r->right == nullptr) {
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

    BST() : root(nullptr), SIZE(0) {}

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

    T search(T value) {

        BSTNode* cur = root;
        while(cur != nullptr){
            if(value < cur->key){
                cur = cur->left;
            }
            else if(value > cur->key){
                cur = cur->right;
            }
            else{
                return cur->key;
            }
        }
    }

    bool has(T value){

        BSTNode* cur = root;
        while(cur != nullptr){
            if(value < cur->key){
                cur = cur->left;
            }
            else if(value > cur->key){
                cur = cur->right;
            }
            else{
                return 1;
            }
        }
        return 0;
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
