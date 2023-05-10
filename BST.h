#ifndef MAIN_CPP_BST_H
#define MAIN_CPP_BST_H

#include <bits/stdc++.h>
#include "student.h"


using namespace std;

class BST {
private:

    class BSTNode{
    public:
        student key;
        BSTNode* left;
        BSTNode* right;
        BSTNode(student value) {
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

    void inorder(BSTNode* r, map <string, int>& Departments){
        if(r != nullptr){
            inorder(r->left, Departments);
            Departments[r->key.getDep()]++;
            cout << r->key << ' ';
            inorder(r->right, Departments);
        }
    }


    BSTNode* insert(BSTNode* r, student value){
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

    BSTNode* deleteNode(BSTNode* r, student value){
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

    void insert(student value) {
        root = insert(root, value);
        SIZE++;
    }

    void remove(student value){
        root = deleteNode(root, value);
        SIZE--;
    }

    student search(int id) {

        BSTNode* cur = root;
        while(cur != nullptr){
            if(id < cur->key.getId()){
                cur = cur->left;
            }
            else if(id > cur->key.getId()){
                cur = cur->right;
            }
            else{
                break;
            }
        }
        return cur->key;
    }

    bool has(int id){

        BSTNode* cur = root;
        while(cur != nullptr){
            if(id < cur->key.getId()){
                cur = cur->left;
            }
            else if(id > cur->key.getId()){
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

    void inorder(map <string, int>& Departments) {
        inorder(root, Departments);
    }


    ~BST() {
        destroy(root);
        SIZE = 0;
    }

};

#endif //MAIN_CPP_BST_H
