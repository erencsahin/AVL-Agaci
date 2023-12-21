#ifndef stack_hpp
#define stack_hpp

class stack
{
private:
    int capacity;
    int size;
public:
    int* data;

    stack();
    ~stack();
    void push(int value);
    int pop();
    int top() const;
    bool bosmu()const;
    int getsize()const;
};


#endif