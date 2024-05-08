/*
    -insert item
    -hash function
    -remove item
    -search item
*/
#include<iostream>
using namespace std;

const int tablesize = 5000;

class hashtableEntry{
    public:
    int key;
    int value;
    hashtableEntry(int k, int v){
        this->key = k;
        this->value = v;
    }
};

class hashtable {
    private:
        hashtableEntry *ht[tablesize];

    public:
        hashtable(){
            
        }

        void insert(int key, int value){
            int index = hash(key);
            while(ht[index] != NULL && ht[index]->key != key){
                index = hash(index + 1);
            }
            if(ht[index] != NULL){
                delete ht[index];
            }
            ht[index] = new hashtableEntry(key, value);
        }

        int search(int key){
            int index = hash(key);
            while(ht[index] != NULL && ht[index]->key != key){
                index = hash(index + 1);
            }
            if(ht[index] == NULL){
                return -1;
            }else{
                return ht[index]->value;
            }
        }

        void remove(int key){
            int index = hash(key);
            while(ht[index] != NULL){
                if(ht[index]->key == key){
                    break;
                }
                index = hash(index + 1);
            }
            if(ht[index] == NULL){
                cout << "No element found at key "<< key << endl;
            }else{
                ht[index] = NULL;
                cout << "element deleted" << endl;
            }
            
        }

        int hash(int key){
            cout << "hash: " << key%tablesize << endl;
            return key%tablesize;
        }
};

int main() {
   hashtable hash;
   int k, v;
   int c;
   while (1) {
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cout<<"Enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Enter element to be inserted: ";
            cin>>v;
            cout<<"Enter key at which element to be inserted: ";
            cin>>k;
            hash.insert(k, v);
         break;
         case 2:
            cout<<"Enter key of the element to be searched: ";
            cin>>k;
            if (hash.search(k) == -1) {
               cout<<"No element found at key "<<k<<endl;
               continue;
            } else {
               cout<<"Element at key "<<k<<" : ";
               cout<<hash.search(k)<<endl;
            }
            
         break;
         case 3:
            cout<<"Enter key of the element to be deleted: ";
            cin>>k;
            hash.remove(k);
         break;
         case 4:
            exit(1);
         default:
            cout<<"\nEnter correct option\n";
      }
   }
   return 0;
}
