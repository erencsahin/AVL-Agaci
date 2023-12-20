#ifndef stack_hpp
#define stack_hpp

class stack
{
private:
    int* data;
    int capacity;
    int size;
public:
    stack();
    ~stack();
    void push(int value);
    int pop();
    int top() const;
    bool bosmu()const;
    int getsize()const;
};


#endif