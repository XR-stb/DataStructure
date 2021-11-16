#ifndef LIST_CPP__
#define LIST_CPP__

#include <iostream>
#include <set>
#include "list.h"

template<class T>
void List<T>:: init(){
    this->length = 0;
}

template<class T>
void List<T>:: destroy(){
    this->length = 0;
}

template<class T>
int List<T>:: getlength(){
    std:: cout << "your List length = ";
    return this->length;
}

template<class T>
T List<T>:: getElem(int idx){
    return this->list[idx];
}

template<class T>
int List<T>:: locate(T loc){
    for(int i = 0; i < this->length; i++){
        if(this->list[i] == loc) return i;
    }
    return -1;
}

template<class T>
bool List<T>:: insert(T val, int idx){
    if(idx < 0 || idx > this->length || this->length == MAX) return false;
    for(int i = this->length-1; i >= idx; i--){
        this->list[i+1] = this->list[i];
    }
    this->list[idx] = val;
    this->length++;
    return true;
}

template<class T>
bool List<T>:: delElem(int idx){
    if(idx < 0 || idx >= this->length) return false;


    this->length--;
    return true;
}

template<class T>
void List<T>:: disp_List(){
    std::cout << "your List is"<< std::endl;
    for(int i = 0; i < this->length; i++){
        std::cout << this->list[i] << " \n"[ i == this->length -1];
    }
}

template<class T>
void List<T>:: del_another(List<T>& del_List){
    std::set<T> st;
    for(int i = 0; i < del_List.length; i++) st.insert(del_List.list[i]);

    for(int j = 0; j < this->length; j++){
        if(st.count(this->list[j])){
            for(int i = j; i < this->length; i++){
                this->list[i] = this->list[i+1];
            }
            this->length--;
        }
    }
    std::cout << "your list form a to b delete successful:" << std::endl;
            
    this->disp_List();
}

#endif
