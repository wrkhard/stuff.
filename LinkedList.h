//
// Created by willi on 6/24/2018.
//

#ifndef MYDATASTRUCTS_LINKEDLIST_H
#define MYDATASTRUCTS_LINKEDLIST_H

template<class T>
class Node{
    friend class LinkedList;
protected:
    T *element;
    Node *nextNode;

public:
    Node(T *element);
    ~Node();
};
template<class T>
Node<T>::Node(T *element) {
    this->element = element;
    nextNode = nullptr;
}



template<class T>
class LinkedList{
protected:
    Node<T> *headNode;
    Node<T> *tailNode;
    unsigned int length;

public:
    LinkedList();
    ~LinkedList();

    void add(T e);

};
template<class T>
LinkedList<T>::LinkedList() {
    headNode = nullptr;
    tailNode = nullptr;
    length = 0;


}
template<class T>
LinkedList<T>::~LinkedList() {
    for(int i = 0; i < length; i++){
        delete headNode;
    }
}
template<class T>
void LinkedList<T>::add(T e) {
    Node *temp = new Node(e);
    temp->element = e;
    temp->nextNode = nullptr;

    if(headNode == nullptr){
        headNode = temp;
        tailNode = temp;
        length++;
    }
    else{
        tailNode->nextNode = temp;
        tailNode = tailNode->nextNode;
    }

}

#endif //MYDATASTRUCTS_LINKEDLIST_H
