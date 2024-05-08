#include <iostream>
using namespace std;
#include "arraylist.h"

int main(){

    Arraylist<int> arr = Arraylist<int>();
   

    arr.add(1);
    arr.add(3);
    arr.add(59);
    arr.add(120);
    arr.add(0);
    arr.add(20);


    for(int i = 0; i < arr.sizeOf(); i++){
        cout << arr.get(i) << endl;
    }
    cout << arr.sizeOf() << endl;

    arr.remove(2);

    for(int i = 0; i < arr.sizeOf(); i++){
        cout << arr.get(i) << endl;
    }
    cout << arr.sizeOf() << endl;

    return 1;
}