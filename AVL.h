#ifndef MAIN_CPP_AVL_H
#define MAIN_CPP_AVL_H

#include <bits/stdc++.h>
#include "student.h"

using namespace std;

class AVL{

private:
    class AVLNode{
    public:
        student key;
        AVLNode* left;
        AVLNode* right;
        AVLNode(student value) {
            key = value;
            left = right = nullptr;
        }
    };

    AVLNode* root;
    int SIZE;

    void destroy(AVLNode*& r) {
        if (r != nullptr) {
            destroy(r->left);
            destroy(r->right);
            delete r;
            r = nullptr;
        }
    }

    void inorder(AVLNode* r){
        if(r != nullptr){
            inorder(r->left);
            cout << r->key << ' ';
            inorder(r->right);
        }
    }

    void preorder(AVLNode* r) {
        if(r != nullptr){
            cout << r->key << ' ';
            preorder(r->left);
            preorder(r->right);
        }
    }

    void postorder(AVLNode* r) {
        if(r != nullptr){
            postorder(r->left);
            postorder(r->right);
            cout << r->key << ' ';
        }
    }

    int height(AVLNode* node){
        if(node == nullptr)
            return -1;
        else
            return max(height(node->left), height(node->right)) + 1;
    }

    int getBalanceFactor(AVLNode* node){

        if(node == nullptr)
            return -1;
        else
            return height(node->left) - height(node->right);
    }

    AVLNode* leftRotate(AVLNode* node){
        AVLNode* rightChild = node->right;
        node->right = rightChild->left;
        rightChild->left = node;

        return rightChild;
    }

    AVLNode* rightRotate(AVLNode* node){

        AVLNode* leftChild = node->left;
        node->left = leftChild->right;
        leftChild->right = node;

        return leftChild;

    }

    AVLNode* insert(AVLNode* r, student value){
        if(r == nullptr){
            r = new AVLNode(value);
            return r;
        }

        if(value < r->key){
            r->left = insert(r->left, value);
        }
        else if(value > r->key){
            r->right = insert(r->right, value);
        }

        int BF = getBalanceFactor(r);

        if(BF > 1 && value < r->key)
            return rightRotate(r);

        if(BF < -1 && value > r->key)
            return leftRotate(r);

        if(BF > 1 && value < r->key) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        if(BF > 1 && value < r->key) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }


    AVLNode* findMin(AVLNode* r) {
        while (r->left != nullptr) {
            r = r->left;
        }
        return r;
    }

    AVLNode* deleteNode(AVLNode* r, student value){
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
                AVLNode* temp = r->right;
                delete r;
                return temp;
            } else if (r->right == nullptr) {
                AVLNode* temp = r->left;
                delete r;
                return temp;
            } else {
                AVLNode* temp = findMin(r->right);
                r->key = temp->key;
                r->right = deleteNode(r->right, temp->key);
            }
        }

        int BF = getBalanceFactor(r);

        if(BF == 2 && getBalanceFactor(r->left) >= 0)
            return rightRotate(r);

        else if(BF == 2 && getBalanceFactor(r->left) == -1) {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }

        else if(BF == -2 && getBalanceFactor(r->right) <= 0)
            return leftRotate(r);

        else if(BF == -2 && getBalanceFactor(r->right) == 1) {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

public:

    AVL() : root(nullptr), SIZE(0) {}

    int size(){
        return SIZE;
    }

    bool empty(){
        return SIZE == 0;
    }

    void insert(student value) {
        root = insert(root, value);
        SIZE++;
    }

    void remove(student value){
        root = deleteNode(root, value);
        SIZE--;
    }

    student search(int id) {

        AVLNode* cur = root;
        while(cur != nullptr){
            if(id < cur->key.Id){
                cur = cur->left;
            }
            else if(id > cur->key.Id){
                cur = cur->right;
            }
            else{
                return cur->key;
            }
        }
    }

    bool has(int id){

        AVLNode* cur = root;
        while(cur != nullptr){
            if(id < cur->key.Id){
                cur = cur->left;
            }
            else if(id > cur->key.Id){
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

    ~AVL() {
        destroy(root);
        SIZE = 0;
    }
};

#endif //MAIN_CPP_AVL_H
