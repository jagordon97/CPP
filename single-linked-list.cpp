/*
    -add item to front of list
    -remove item in list
    -add to end 

*/
#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int d){
            data = d;
            next = NULL;
        }
};

class singleLinkedList{
    private:
        node* head;
        
    public:
        //creates singley linked list
        singleLinkedList(){
            head = NULL;
        }

        //add new node to front of list
        void addFront(int n){
            node* temp1 = new node(n);
            if(head != NULL){
                node* temp2 = head;
                
                temp1->next = temp2;
                head = temp1; 
            }else{
                head = temp1;
            }
        }

        //add new node to end of list
        void addEnd(int n){
            node* temp1 = new node(n);
            if(head == NULL){

               head = temp1;

            }else{
                
                node* temp2 = head;
                while(temp2->next != NULL){
                    temp2 = temp2->next;
                }
                temp2->next = temp1;

            }
        }

        //delete node at offset
        void deleteNode(int offset){
            

            if(head->next == NULL){
                cout << "Nothing to remove. List Empy" << endl;
                return;
            }

            node* temp1 = head;
            int count = 0;
            //get list length
            while(temp1 != NULL){
                temp1 = temp1->next;
                count++;
            }

            if(count < offset){
                cout << "Index out of range" << endl;
                return;
            }

            if(offset == 1){
                head = head->next;
                delete temp1;
                return;
            }

            //set temp1 back to head
            temp1 = head;

            node* temp2 = temp1->next;
            while(offset-- > 1){
                temp2 = temp1;

                temp1 = temp1->next;
            }
            
            temp2->next = temp1->next;
            delete temp1;


        }
        void printList() 
        { 
            node* temp = head; 
        
            // Check for empty list. 
            if (head == NULL) { 
                cout << "List empty" << endl; 
                return; 
            } 
        
            // Traverse the list. 
            while (temp != NULL) { 
                cout << temp->data << " "; 
                temp = temp->next; 
            } 
        } 
        
};

  
// Driver Code 
int main() 
{ 
    singleLinkedList list; 
  
    // Inserting nodes 
    list.addEnd(1); 
    list.addEnd(2); 
    list.addEnd(3); 
    list.addEnd(4); 
  
    cout << "Elements of the list are: "; 
  
    // Print the list 
    list.printList(); 
    cout << endl; 
  
    // Delete node at position 2. 
    list.deleteNode(2); 
  
    cout << "Elements of the list are: "; 
    list.printList(); 
    cout << endl; 

    list.addFront(1); 
    list.addFront(2); 
    list.addFront(3); 
    list.addFront(4); 
    
    cout << "Elements of the list are: "; 
    list.printList(); 
    cout << endl; 
    
    return 0; 
}