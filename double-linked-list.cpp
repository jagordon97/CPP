/*
    -add to list at index
    -add to end
    -add to beginning
    -remove from list at index
    -
*/
#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;

        node(int d){
            data = d;
            next = NULL;
            prev = NULL;
        }
};

class doubleyLinkedList{
    private:
        node* list;
        node* head;
        node* tail;
    public:
        doubleyLinkedList(){
            head = NULL;
            tail = NULL;
        }

        //add to front
        void addToFront(int d){
            node* n = new node(d);
            node* temp = head;

            if(head == NULL){
                head = n;
                tail = n;
                return;
            }

            head = n;
            temp->prev = head;
            head->next = temp;
        }

        //add to end
        void addToEnd(int d){
            node* n = new node(d);
            node* temp = tail;

            if(tail == NULL){
                head = n;
                tail = n;
                return;
            }

            
            tail->next = n;
            n->prev = tail;
            tail = n;
        }


        //add at index
        void addIndex(int index, int d){
            node* n = new node(d);
            int count = 0;
            if(head == NULL){
                head = n;
                tail = n;
                cout << "List Empty node set as head/tail" << endl;
                return;
            } 
            if(index == 1){
                n->next = head;
                head->prev = n;
                head = n;
                return;
            }

            node* temp = head;
            

            while(index-- > 1){    
               if(temp->next == NULL){
                    cout << "Added to end of list" << endl;
                    temp->next = n;
                    n->prev = temp;
                    tail = n;
                    return;
               }else{
                    temp = temp->next;
               }
            }
            
            node* temp2 = temp->prev;
                
            temp2->next = n;
            n->prev = temp2;
            n->next = temp;
            temp->prev = n;
            

        }

        //remove at index
        void removeIndex(int index){
            node* temp = head;
            if(head == NULL){
                cout << "list empty" << endl;
                return;
            }
            if(index == 1){
                temp->next->prev = NULL;
                head = temp->next;
                delete temp;
                return;
            }

            while(index-- > 1){
                if(temp->next == NULL){
                    cout << "index out of range" << endl;
                    return;
                }
                temp = temp->next;
            }

            

            if(temp->next == NULL){
                temp->prev->next = NULL;
                delete temp;
            }else{
                node* temp2 = temp->prev;

                temp2->next = temp->next;
                temp->next->prev = temp2;
                delete temp;
            }

            


        }

        //print all
        void print(){
            node* temp = head;
            if(temp == NULL){
                cout << "No Items in List" << endl;
            }
            while(temp != NULL){
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
};

// Driver Code 
int main() 
{ 
    doubleyLinkedList list; 
  

    

    // Inserting nodes 
    list.addToEnd(1); 
    list.addToEnd(2); 
    list.addToEnd(3); 
    list.addToEnd(4); 

    list.addIndex(5, 5); 
    list.addIndex(2, 20); 
    list.addIndex(1, 10); 
    list.addIndex(4, 40); 

  
    cout << "Elements of the list are: "; 
  
    // Print the list 
    list.print(); 
    cout << endl; 
  
    // Delete node at position 2. 
    list.removeIndex(2); 
    list.removeIndex(1); 
    list.removeIndex(19); 
    list.removeIndex(6); 
  
    cout << "Elements of the list are: "; 
    list.print(); 
    cout << endl; 

    list.addToFront(1); 
    list.addToFront(2); 
    list.addToFront(3); 
    list.addToFront(4); 
    
    cout << "Elements of the list are: "; 
    list.print(); 
    cout << endl; 
    
    return 0; 
}