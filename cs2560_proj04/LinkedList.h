#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class LinkedList {
    public:
        LinkedList ();
        ~LinkedList ();

        bool add(T* value);
        int getLength() const;

        T* findNode(const T* value);
        void display();

    private:
        Node<T>* head_;
        int length_;
};


// default constructor
template <class T>
LinkedList<T>::LinkedList () : head_(nullptr), length_(0) { }

// destructor
template <class T>
LinkedList<T>::~LinkedList () {
    Node<T>* temp = this->head_;
    while (temp != NULL) {
        this->head_ = this->head_->getNext();
        delete temp;
        temp = this->head_;
    }
}

// adds a value to the linked list (at the beginning)
template <class T>
bool LinkedList<T>::add(T* value) {
    if (value == nullptr) {
        return false;  // cannot add a null pointer
    }

    Node<T>* node = new Node<T>(value, this->head_);
    this->head_ = node; // makes node the head
    ++this->length_;
    return true;

}

// gets the length of the linked list
template <class T>
int LinkedList<T>::getLength() const { return this->length_; }

// finds an equivalent node
// operator == was overwriiten for book object to compare isbn
template <class T>
T* LinkedList<T>::findNode(const T* value) {
    Node<T>* temp = this->head_;
    while (temp != NULL) {
        
        T* compareNode = temp->getValue();

        // dereference to use the overwitten operator
        if (*(value) == *(compareNode)) return compareNode;

        // iterate
        this->head_ = this->head_->getNext();
        temp = this->head_;
    }

    return nullptr;
}

// iterates through the linked list to display the nodes
template <class T>
void LinkedList<T>::display() {
    Node<T>* temp = this->head_;

    while (temp != NULL) {
        cout << temp->getValue() << endl;

        // iterate
        this->head_ = this->head_->getNext();
        temp = this->head_;
    }
}

#endif