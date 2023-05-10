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
        student ret;
        if (!students.empty()) {
            ret = students.front();
            students.front() = students.back();
            students.pop_back();
            maxHeapfiy(0);
        }
        return ret;
    }

    void maxHeapfiy(int idx){

        int largest = idx;

        if(left(idx) != -1 && students[left(idx)].getGpa()  > students[largest].getGpa() )
            largest = left(idx);

        if(right(idx) != -1 && students[right(idx)].getGpa()  > students[largest].getGpa() )
            largest = right(idx);

        if(largest != idx){
            swap(students[idx], students[largest]);
            maxHeapfiy(largest);
        }

    }

public:

    Maxheap() = default;

    int size(){
        return students.size();
    }

    bool empty(){
        return students.size() == 0;
    }

    void insert(student s){

        students.push_back(s);
        int idx = students.size()-1;

        while(parent(idx) != -1 && students[parent(idx)].getGpa() < students[idx].getGpa()) {
            swap(students[idx], students[parent(idx)]);
            idx = parent(idx);
        }
    }

    void print(map<string, int>& Departments){

        int n = students.size();
        vector <student> temp;

        for(int i = 0; i < n; i++)
            temp.push_back(extarctMax());

        for(auto s : temp) {
            Departments[s.getDep()]++;
            cout << s;
        }
        cout << '\n';

        for(int i = 0; i < n; i++){
            this->insert(temp[i]);
        }
    }

};

#endif //AVL_H_MAXHEAP_H
