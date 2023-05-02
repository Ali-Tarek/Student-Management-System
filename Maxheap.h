#ifndef AVL_H_MAXHEAP_H
#define AVL_H_MAXHEAP_H

#include <bits/stdc++.h>
#include "student.h"

using namespace std;

class Maxheap{
private:

    vector <student> students;

    int left(int i){
        if(2 * i + 1 >= students.size())
            return -1;
        else
            return 2 * i + 1;
    }
    int right(int i){
        if(2 * i + 2 >= students.size())
            return -1;
        else
            return 2 * i + 2;
    }
    int parent(int i){
        if((i - 1) / 2 < 0)
            return -1;
        else
            return (i-1)/2;
    }

    student extarctMax() {

        if (!students.empty()) {
            student ret = students.front();
            students.front().Gpa = FLT_MIN;
            maxHeapfiy(students.size(), 0);
            students.pop_back();
            return ret;
        }

    }

    void maxHeapfiy(int n, int idx){

        int largest = idx;

        if(left(idx) < n && students[left(idx)].Gpa > students[largest].Gpa)
            largest = left(idx);

        if(right(idx) < n && students[right(idx)].Gpa > students[largest].Gpa)
            largest = right(idx);

        if(largest != idx){
            swap(students[idx], students[largest]);
            maxHeapfiy(n, largest);
        }

    }

public:

    Maxheap() = default;

    void insert(student s){

        students.push_back(s);
        int idx = students.size()-1;

        while(parent(idx) != -1 && students[parent(idx)].Gpa < students[idx].Gpa) {
            swap(students[idx], students[parent(idx)]);
            idx = parent(idx);
        }
    }

    void print(){

    }

};

#endif //AVL_H_MAXHEAP_H
