//
// Created by willi on 6/20/2018.
//

.
//TODO Finish Exception.


#ifndef MYDATASTRUCTS_DYNAMICARRAY_H
#define MYDATASTRUCTS_DYNAMICARRAY_H
//class DynamicArrayException(){};
template <class T>
class DynamicArray{
protected:
    int limit;
    int currIndex;
    T *darr;


public:
    DynamicArray();
    ~DynamicArray();
    T& operator[](unsigned int i);

    void append(T e);
    void remove(int i);

};
template<class T>
DynamicArray<T>::DynamicArray() {
    darr = new T[10];
    limit = 9;
    currIndex = 0;
}
template<class T>
DynamicArray<T>::~DynamicArray() {
    delete[] darr;
}
template<class T>
void DynamicArray<T>::append(T e) {
    if(this->currIndex == this->limit){
        limit = limit + (limit % 3);
        T *temp;
        temp = new T[limit];

        for(int i = 0; i < currIndex; i++){
            temp[i] = darr[i];
        }

        delete[] darr;
        darr = temp;
        darr[currIndex++] = T(e);

        delete[] temp;
    }
    else{
        darr[currIndex++] = T(e);
    }
}
template<class T>
void DynamicArray<T>::remove(int i) {
    if(i>=0 && i < currIndex + 1){
        T *temp;
        temp = new T[limit];

        int x = 0;
        int target = i + 1;

        while(true){

            if(x < i){
                temp[x] = darr[x];
                x++;
            }
            else if(x == i){
                temp[x] = darr[target];
                x++;
            }
            else if(x > i && x < currIndex){
                target = target + 1;
                temp[x] = darr[target];
                x++;
            }
            else{
                currIndex--;
                break;
            }
        }
        delete[] darr;
        darr = temp;
        delete[] temp;
    }
    else{
        //throw DynamicArrayException();
    }
}
template<class T>
T& DynamicArray<T>::operator[](unsigned int i) {
    if(i < 0 || i >= currIndex){
        //throw DynamicArrayException();
    }
    else{
        return darr[i];
    }
}


#endif //MYDATASTRUCTS_DYNAMICARRAY_H
