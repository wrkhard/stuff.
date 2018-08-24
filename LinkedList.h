//
// Created by willi on 6/24/2018.
//


#ifndef MYDATASTRUCTS_LINKEDLIST_H
#define MYDATASTRUCTS_LINKEDLIST_H





template<class T>
class LinkedList{
    struct Node{
        T *element;
        Node *nextNode;
    };
protected:
    Node *headNode;
    unsigned int length;

public:
    LinkedList();
    ~LinkedList();

    void add(T e);
    void remove(T e);
    void reverse();

};
template<class T>
LinkedList<T>::LinkedList() {
    headNode = nullptr;
    length = 0;


}
template<class T>
LinkedList<T>::~LinkedList() {
    Node *temp, *next;
    temp = headNode;
    if(temp == nullptr){
        return;
    }

    while(temp){
        next = temp->nextNode;
        delete temp;
        temp = next;
    }
}
template<class T>
void LinkedList<T>::add(T e) {
    Node *last, *temp;


    if(headNode == nullptr){
        headNode = new Node;
        headNode->element = e;
        headNode->nextNode = nullptr;

        length++;
        return;
    }
    last= headNode;
    while(last->nextNode != nullptr){
        last = last->nextNode;
    }
    temp = new Node;
    temp->element = e;
    temp->nextNode = nullptr;
    last->nextNode = temp;

}
template <typename T>
void LinkedList<T>::remove(T e) {
    Node *last, *temp;
    temp = headNode;
    if(temp == nullptr){
        return;
    }
    if(temp->nextNode == nullptr){
        delete temp;
    }
    while(temp){
        last = temp;
        temp = temp->nextNode;
        if(temp->nextNode == nullptr){
            delete last;
            temp = nullptr;
        }

    }

}
template <typename T>
void LinkedList<T>::reverse() {
    if(headNode == nullptr || headNode->nextNode == nullptr){
        return;
    }
    Node *start = headNode;
    Node *curr = headNode->nextNode;
    Node *next = curr->nextNode;

    headNode->nextNode = nullptr;
    curr->nextNode = headNode;

    while(next != nullptr){
        curr->nextNode = start;
        start = curr;
        curr = next;
        next = next->nextNode;
    }
    headNode = curr;
    headNode->nextNode = start;
}

#endif //MYDATASTRUCTS_LINKEDLIST_H
