/* 
canvaslist.h
Starter code created by Dr. Adam T. Koehler
File completed by Rovia Simmons
canvaslist.h is used to implement a class used to store shape objects into a singly linked list.
draws out information about shapes in the canvas.
*/

#pragma once

#include "shape.h"
#include <iostream>

using namespace std;

class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront;

    public:
        CanvasList();
        CanvasList(const CanvasList &);
        CanvasList operator=(const CanvasList &);
        
        virtual ~CanvasList();
        void clear();
        
        void insertAfter(int, Shape *);
        void push_front(Shape *);
        void push_back(Shape *);
        
        void removeAt(int);
        Shape* pop_front();
        Shape* pop_back();

        ShapeNode* front() const;
        bool isempty() const;
        int size() const;

        int find(int x, int y) const;
        Shape* shapeAt(int) const;
        
        void draw() const;
        void printAddresses() const;
};

//default constructor
CanvasList::CanvasList() {
    listSize = 0;
    listFront = nullptr;
}

//deep copy constructor
CanvasList::CanvasList(const CanvasList &other) {
    // listSize = other.listSize;
    // // listFront = new ShapeNode;
    // if(other.listFront == nullptr) {
    //     listFront = nullptr;
    //     return;
    // }

    // ShapeNode *curr = other.listFront;
    // while(curr != nullptr) {
    //     push_back(curr->value->copy());
    //     curr = curr->next;
    // }

    listFront = nullptr;
    listSize = other.listSize;

    ShapeNode* curr = other.listFront;
    ShapeNode* prev = nullptr;

    while (curr != nullptr) {
        ShapeNode* temp = new ShapeNode;
        temp->value = curr->value->copy();
        if (prev == nullptr) {
            listFront = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
        curr = curr->next;
    }
}


// = assign operator, copies existing canvaslist onto another.
CanvasList CanvasList:: operator=(const CanvasList &other) {
    clear();

    listSize = other.listSize;
    listFront = nullptr;

    ShapeNode* curr = other.listFront;
    ShapeNode* prev = nullptr;

    while (curr != nullptr) {
        ShapeNode* temp = new ShapeNode;
        temp->value = curr->value->copy();
        if (prev == nullptr) {
            listFront = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
        curr = curr->next;
    }

    // if(other.listFront == nullptr) {
    //     listFront = nullptr;
    //     listSize = 0;
    //     return *this;
    // }

    // ShapeNode *curr = other.listFront;
    // ShapeNode *prev = nullptr;

    // while(curr != nullptr) {
    //     ShapeNode *temp = new ShapeNode;
    //     temp->value = curr->value->copy();
    //     if(prev == nullptr) {
    //         listFront = temp;
    //     }
    //     else {
    //         prev->next = temp;
    //     }
    //     prev = temp;
    //     curr = curr->next;
    // }

    // listSize = other.listSize;
    return *this;
}

//destructor
CanvasList::~CanvasList() {
    clear();
}

//clears list
void CanvasList:: clear() {
    while(listFront != nullptr) {
        ShapeNode *prev = listFront;
        listFront = listFront->next;
        delete prev->value;
        delete prev;
    }
    listFront = nullptr;
    listSize = 0;
}

//inserts shape at index
void CanvasList::insertAfter(int index, Shape *s) {
    if(index >= listSize || index < 0) {
        return;
    }

    ShapeNode *temp = new ShapeNode;
    temp->value = s;

    ShapeNode *curr = listFront;
    for(int i = 0; i < index; i++) {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;
    listSize++;
}

//inserts shape at the beginning of the list
void CanvasList::push_front(Shape *s) {
    ShapeNode *temp = new ShapeNode;
    temp->value = s;
    temp->next = listFront;
    listFront = temp;
    listSize++;
}

//inserts shape at the end of the list
void CanvasList::push_back(Shape *s) {
    ShapeNode *temp = new ShapeNode;
    temp->value = s;
    temp->next = nullptr;

    if(listFront == nullptr) {
        listFront = temp;
    }
    else {
        ShapeNode *curr = listFront;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
    }
    listSize++;
}

//removes shape at index
void CanvasList::removeAt(int index) {
    if(index >= listSize || index < 0) {
        return;
    }
    else if(index == 0) {
        delete pop_front();
        return;
    }

    ShapeNode *curr = listFront;

    for(int i = 0; i < index - 1 && curr != nullptr; i++) {
        curr = curr->next;
    }

    ShapeNode *next = curr->next->next;
    delete curr->next->value;
    delete curr->next;
    curr->next = next;
    listSize--;
}

//removes shape at the beginning of the list and returns the deleted shape address
Shape* CanvasList::pop_front() {
    if(listFront == nullptr) {
        return nullptr;
    }

    ShapeNode *next = listFront->next;
    Shape *result = listFront->value;

    delete listFront;

    listFront = next;
    listSize--;

    return result;
}

//removes shape at the end of the list and returns the deleted shape address
Shape* CanvasList::pop_back() {
    if(listFront == nullptr) {
        return nullptr;
    }

    if(listFront->next == nullptr) {    //list has 1 element
        listSize--;
        return nullptr;
    }

    ShapeNode *curr = listFront;

    while(curr->next->next != nullptr) {
        curr = curr->next;
    }

    Shape *result = curr->next->value;
    delete curr->next;
    curr->next = nullptr;
    listSize--;

    return result;
}

//returns front of the list
ShapeNode* CanvasList::front() const {
    return listFront;
}

//checks if list is empty
bool CanvasList::isempty() const {
    if(listSize == 0) {
        return true;
    }
    return false;
}

//returns listSize value
int CanvasList::size() const {
    return listSize;
}

//returns index of first shape at this x and y location or -1
int CanvasList::find(int x, int y) const {
    int count = 0;
    ShapeNode *curr = listFront;
    while(curr != nullptr) {
        if(curr->value->getX() == x && curr->value->getY() == y) {
            return count;
        }
        curr = curr->next;
        count++;
    }
    return -1;
}

//returns nullptr or a pointer to the shape at the given linked list index.
Shape* CanvasList::shapeAt(int index) const {
    if(index < 0 || index >= listSize) {
        return nullptr;
    }

    ShapeNode *curr = listFront;
    for(int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->value;
}

//prints canvaslist data about shapes.
void CanvasList::draw() const {
    ShapeNode *curr = listFront;
    while(curr != nullptr) {
        curr->value->printShape();
        curr = curr->next;
    }
}

void CanvasList::printAddresses() const {
    ShapeNode *curr = listFront;
    while(curr != nullptr) {
        cout << "Node Address: " << curr << "\tShape Address: " << curr->value << endl;
        curr = curr->next;
    }
}