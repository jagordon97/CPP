/*
    -add to queue
    -remove from queue
    -get front
    -get end
    -empty?
    -full?
    -size
*/
#include<iostream>
using namespace std;

const int MAX = 5;

class queue{
    private:
        int arr[MAX];
        int front, end, size;

    public:

        queue(){
            size = 0;
            front = -1;
            end = -1;
        }

        void addToQueue(int d){
            
            if(size == MAX){
                cout << "Queue Full" << endl;
                return;
            }else{
                if(front == -1){
                    front = 0;
                }
                size++;
                end++;
                arr[end % MAX] = d;
            }
        }

        int removeFromQueue(){
            if(size == 0){
                cout << "Queue Empty" << endl;
                front = -1;
                end = -1;
                return -1;
            }else{
                int temp = front;
                front++;
                size--;
                if(size == 0){
                    front = -1;
                    end = -1;
                }
                return arr[temp % MAX];
            }
        }

        int getFront(){
            if(front == -1){
                cout << "Queue Empty" << endl;
                return -1;
            }
            return arr[front % MAX];
        }

        int getEnd(){
            if(end == -1){
                cout << "Queue Empty" << endl;
                return -1;
            }
            return arr[end % MAX];
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return (size == 0);
        }

        bool isFull(){
            return (size == MAX);
        }

};

int main(){

    queue q;

    q.addToQueue(1);
    q.addToQueue(2);
    q.addToQueue(3);
    q.addToQueue(4);
    q.addToQueue(5);
    q.addToQueue(6);

    cout << q.removeFromQueue() << endl;

    q.addToQueue(7);

    cout << q.removeFromQueue() << endl;

    q.addToQueue(8);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(9);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(10);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(11);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(12);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(13);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(14);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(15);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(16);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(17);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(18);
    cout << q.removeFromQueue() << endl;

    q.addToQueue(19);

    cout << q.removeFromQueue() << endl;
    cout << q.removeFromQueue() << endl;

    q.addToQueue(6);
    q.addToQueue(7);
    q.addToQueue(8);
    q.addToQueue(9);
    q.addToQueue(10);
    q.addToQueue(11);

    cout << q.removeFromQueue() << endl;

    q.addToQueue(11);
    cout << q.removeFromQueue() << endl;
    cout << q.removeFromQueue() << endl;
    cout << q.removeFromQueue() << endl;
    cout << q.removeFromQueue() << endl;
    cout << q.removeFromQueue() << endl;
    cout << q.removeFromQueue() << endl;
    cout << q.removeFromQueue() << endl;
    cout << q.removeFromQueue() << endl;
    cout << q.removeFromQueue() << endl;
    cout << q.removeFromQueue() << endl;
    q.addToQueue(11);
    q.addToQueue(12);
    q.addToQueue(13);
    q.addToQueue(14);
    cout << q.removeFromQueue() << endl;


    
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    cout << q.getFront() << endl;
    cout << q.getEnd() << endl;
    cout << q.getSize() << endl;
    
    q.addToQueue(1);

    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    cout << q.getFront() << endl;
    cout << q.getEnd() << endl;
    cout << q.getSize() << endl;

    cout << q.removeFromQueue() << endl;

    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    cout << q.getFront() << endl;
    cout << q.getEnd() << endl;
    cout << q.getSize() << endl;

    q.addToQueue(1);
    q.addToQueue(2);
    q.addToQueue(3);
    q.addToQueue(4);
    cout << q.removeFromQueue() << endl;
    q.addToQueue(5);
    
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    cout << q.getFront() << endl;
    cout << q.getEnd() << endl;
    cout << q.getSize() << endl;
    
    q.addToQueue(2);
    q.addToQueue(3);
    q.addToQueue(4);
    q.addToQueue(5);
    q.addToQueue(6);
    q.addToQueue(7);
    q.addToQueue(8);
    q.addToQueue(9);
    q.addToQueue(10);
    q.addToQueue(11);

    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    cout << q.getFront() << endl;
    cout << q.getEnd() << endl;
    cout << q.getSize() << endl;

    cout << q.removeFromQueue() << endl;

    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    cout << q.getFront() << endl;
    cout << q.getEnd() << endl;
    cout << q.getSize() << endl;

    
}