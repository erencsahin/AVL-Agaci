#include "stack.hpp"
#include<iostream>
using namespace std;

stack::stack()
{
    this->data=nullptr;
    this->capacity=20;
    this->size=0;
    data=new int[capacity];
}

stack::~stack()
{
    delete [] data;
}

void stack::push(int value)
{
    if (size==capacity)
    {
        int *newData=new int[capacity*2];
    
        for (int i = 0; i < size; i++)
        {
            newData[i]=data[i];
        }
        delete []data;
        data=newData;
        capacity*=2;
    }
    data[size++]=value;
}

int stack::pop()
{
    if (bosmu())
    {
        return 0;
    }
    return data[--size];
}

bool stack::bosmu() const
{
    return size==0;
}

int stack::getsize() const 
{
    return size;
}
int stack::top() const {
    if (bosmu()) {
        return 0;
    }
    return data[size - 1];
}