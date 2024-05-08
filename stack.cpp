/*
    -pop top element
    -push element to top
    -first in last out
    -empty
    -get top
*/

#include<iostream>
using namespace std;

struct node{

    node *prev = NULL;
    int data;
    
};

class stack{

    private:
        node *top;
    
    public:

        stack(){
            top = NULL;
        }

        void push(int d){

            if(top == NULL){
                
                top = new node{NULL, d};
            }else{
                node *n = new node{top, d};
                top = n;
                
            }
        }

        int pop(){
            if(top == NULL){
                cout << "Stack Empty" << endl;
                return 0;
            }else{
                node *temp = top;
                top = temp->prev;
                return temp->data;
            }
        }

        int getTop(){
            if(top == NULL){
                cout << "Stack Empty" << endl;
                return 0;
            }
            return top->data;
        }

        bool isEmpty(){
            return top == NULL;
        }
};

int main(){

    stack s;

    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    cout << s.getTop() << endl;
    s.push(9);
    cout << s.getTop() << endl;
    s.push(3);
    cout << s.getTop() << endl;
    s.push(60);
    cout << s.getTop() << endl;
    s.push(29);
    cout << s.getTop() << endl;
    cout << s.isEmpty() << endl;
    cout << s.pop() << endl;
    cout << s.getTop() << endl;
}