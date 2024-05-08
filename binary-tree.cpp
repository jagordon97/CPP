/*
    -insert node
    -remove node
    -search
    -left, right,parent nodes
*/

#include<iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

class binaryTree{
    private:
        node *root;

    public:
        binaryTree(){
            root = NULL;
        }

        void insert(int d){
            node *newNode = new node;
            newNode->data = d;
            node *parent;
            if(root == NULL){
                root = newNode;
                return;
            }
            else{
                node *ptr;
                ptr = root;
                while(ptr != NULL){
                    parent = ptr;
                    if(d > ptr->data){
                        ptr = ptr->right;
                    }else{
                        ptr = ptr->left;
                    }
                }
                if(d < parent->data){
                    parent->left = newNode;
                }else{
                    parent->right = newNode;
                }
            }
        }

        void displayBST(){
            printBST(root);
        }

        void printBST(node *ptr){
            if(ptr != NULL){
                printBST(ptr->left);
                cout << "  " << ptr->data << "     ";
                printBST(ptr->right);
            }
        }

        bool search(int d){
            if(root == NULL){
                cout << "BST Empty" << endl;
                return false;
            }
            node *ptr = root;
            while(ptr != NULL){
                if(ptr->data == d){
                    cout << "node returned: " << ptr->data << " left: " << ptr->left << " right: " << ptr->right << endl;
                    return true;
                }
                if(d > ptr->data){
                    ptr = ptr->right;
                }
                else{
                    ptr = ptr->left;
                }
            }
            
            return false;
        }
};

int main(){
    binaryTree b;
    b.insert(20);
    b.insert(10);
    b.insert(5);
    b.insert(15);
    b.insert(40);
    b.insert(45);
    b.insert(30); 
     
    cout << "Binary tree created: " << endl;
    b.displayBST(); 
    cout << endl;
    b.search(15);
    b.search(5);
    b.search(20);
}