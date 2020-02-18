#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#include "IntVector.h"

IntVector::IntVector(){
    sz = 0;
    cap = 0;
    data = NULL;
}

IntVector::IntVector(unsigned size){
    sz = size;
    cap = size;
    data = new int[size];
    for (unsigned int i = 0; i < size; ++i){
        data[i] = 0;
    }
}

IntVector::IntVector(unsigned size, int value){
    sz = size;
    cap = size;
    data = new int[size];
    for (unsigned int i = 0; i < size; ++i){
        data[i] = value;
    }
}

IntVector::~IntVector(){
    delete []data;
}

unsigned int IntVector::size() const {
    return sz;
}

unsigned int IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    if (sz != 0) {
        return false;
    } 
    else {
        return true;
    }
}

const int& IntVector::at(unsigned int index) const{
    if (index >= sz){
        throw out_of_range("IntVector::at_range_check");
    }
    else return data[index];
}

const int& IntVector::front() const{
    return data[0];
}

const int& IntVector::back() const{
    return data[sz-1];
}

void IntVector::expand(){
    cap *= 2; 
    if (cap == 0){
        cap = 1;
    }
    int* temp = new int[cap];      
        for( unsigned int i = 0; i < sz; i++ ) {
            temp[i] = data[i];
        }
    
    delete [] data;     
    data = temp;       
    }


    

void IntVector::expand(unsigned amount){    
        int* temp = new int[cap + amount];
        cap = cap + amount;
        for( unsigned int i = 0; i < sz; i++ ) {
        temp[i] = data[i];  
        } 
        
        delete [] data;     
        data = temp;       
    }


void IntVector::insert(unsigned index, int value){
    if (index > sz){
        throw out_of_range("IntVector::insert_range_check");
    }
    if (sz + 1 > cap) {
        expand();
    }
    for (unsigned int i = index; i < sz; ++i){
        data[i + 1] = data[i];
    }
    data[index] = value;
    ++sz;
}

void IntVector::erase(unsigned index){
    if (index >= sz){
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned i = index; i < sz-1; ++i){
        swap(data[i] , data[i+1]);
    }
    --sz;
}

void IntVector::push_back(int value){
    if (cap == 0){
        expand(1);
    } else if (sz >= cap){
        expand();
    }
    data[sz] = value;
    ++sz;
}

void IntVector::pop_back(){
    --sz;
}

void IntVector::clear(){
    sz = 0;
}
    

void IntVector::resize(unsigned size, int value){
    if (size < sz){
        sz = size;
    }
    if (size > cap){
        if (size > (cap * 2)){
            expand(size-cap);
        }
        else {
            expand();
        }
    }
    if (size > sz){
        for (unsigned int i = sz; i < size; ++i){
            data[i] = value;

    }
        }
    sz = size;
}
    
void IntVector::reserve(unsigned n){

   if(n >= cap){
    expand(n - cap);
    }
}



void IntVector::assign(unsigned n, int value){
    if (n > (cap * 2)){
        expand (n-cap);
    }
    else if ((n>cap) && (n <= (cap*2))){
        expand();
    }
    sz = n;
    for (unsigned int i = 0; i < sz; ++i){
        data[i] = value;
    }
}

int& IntVector::front(){
    return data[0];
}

int& IntVector::back(){
    return data[sz-1];
}

int& IntVector::at(unsigned int index){
    if (index >= sz){
        throw out_of_range("IntVector::at_range_check");
    }
    else return data[index];
}
