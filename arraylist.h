template <class T> 
class Arraylist{
    public:
        //constructor
        Arraylist();

        //get element at given index
        T get(int index); 

        //add stored address of data to end of list
        void add(T const &d);

        //remove the item at a given index
        bool remove(int index);

        //get size of arraylist
        int sizeOf();

    private:
        int size;
        int arraysize;
        T *arr;

        //checks if the arraylist has space to fit in another value
        bool needsSpace();

        //doubles the size of the arraylist
        void doubleSpace();
};

/*
    get index number
    add item - if array not large enough double size
    remove index - shift other indicies down  
    construct new arraylist
    get size of arraylist
*/
template<class T>
Arraylist<T>::Arraylist() {
    arraysize = 2;
    size = 0;
    arr = new T[arraysize];
}

template<class T> 
int Arraylist<T>::sizeOf(){
    return size;
}

template<class T> 
void Arraylist<T>::add(T const &d){
    if(needsSpace()){
        doubleSpace();
    }
    arr[size] = d;
    size += 1;
}
template<class T> 
T Arraylist<T>::get(int index){
    return arr[index];
}

template<class T> 
bool Arraylist<T>::remove(int index){
    for(int i = index + 1; i < size; i++){
        arr[i - 1] = arr[i];
    }
    size -= 1;
    
    return true;
}

template<class T> 
bool Arraylist<T>::needsSpace(){
        return size >= arraysize;
    
}

template<class T> 
void Arraylist<T>::doubleSpace(){
    arraysize *= 2;
    T *tempArr = new T[arraysize];
    for(int i = 0; i < size; i++){
        tempArr[i] = arr[i];
    }
    arr = tempArr;
}