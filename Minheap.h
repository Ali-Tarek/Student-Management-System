#ifndef MAIN_CPP_MINHEAP_H
#define MAIN_CPP_MINHEAP_H

#include <bits/stdc++.h>
#include "student.h"

using namespace std;

class Minheap{
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

    student extarctMin() {

        student ret;
        if (!students.empty()) {
            ret = students.front();
            students.front() = students.back();
            students.pop_back();
            minHeapfiy(0);

        }
        return ret;
    }

    void minHeapfiy(int idx){

        int smallest = idx;

        if(left(idx) != -1 && students[left(idx)].getGpa() < students[smallest].getGpa() )
            smallest = left(idx);

        if(right(idx) != -1 && students[right(idx)].getGpa()  < students[smallest].getGpa() )
            smallest = right(idx);

        if(smallest != idx){
            swap(students[idx], students[smallest]);
            minHeapfiy(smallest);
        }

    }

public:

    Minheap() = default;

    int size(){
        return students.size();
    }

    bool empty(){
        return students.size() == 0;
    }

    void insert(student s){

        students.push_back(s);
        int idx = students.size()-1;

        while(parent(idx) != -1 && students[parent(idx)].getGpa()  > students[idx].getGpa() ) {
            swap(students[idx], students[parent(idx)]);
            idx = parent(idx);
        }
    }

    void print(map<string, int>& Departments){

        int n = students.size();
        vector <student> temp;

        for(int i = 0; i < n; i++)
            temp.push_back(extarctMin());

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

#endif //MAIN_CPP_MINHEAP_H
