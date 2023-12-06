#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
    public:
        Node();
        Node(T* value, Node<T>* next);
        ~Node();

        T* getValue() const; void setValue (const T* value);
        Node<T>* getNext() const; void setNext (Node<T>* next);

    private:
        T* value_;
        Node<T>* next_;
};

// default constructor
template <class T>
Node<T>::Node() : value_(nullptr), next_(nullptr) { }

// constructor to create node and assign its next node
template <class T>
Node<T>::Node(T* value, Node<T>* next) : value_(value), next_(next) { }

// destuctor
template <class T>
Node<T>::~Node() { 
    this->value_ = nullptr;
    this->next_ = nullptr;
}

// gets the ndoe's value
template <class T>
T* Node<T>::getValue() const { return this->value_; }

// sets node value
template <class T>
void Node<T>::setValue(const T* value) { this->value_ = value; }

// gets the node that is next
template <class T>
Node<T>* Node<T>::getNext() const { return this->next_; }

// sets the next node
template <class T>
void Node<T>::setNext(Node<T>* next) { this->next_ = next; }

#endif