#include "Sorted_List.h"
#include <stdexcept>

using namespace std;

//Move constructor
Sorted_List::Sorted_List(Sorted_List && other) : head{other.head}
{
    other.head = nullptr;
}

//Copy constructor
//Sorted_List::Sorted_List(Sorted_List const& other) : head{copy(other.head)} {}


/* Sorted_List::Node* Sorted_List::copy(Sorted_List::Node const * node) const
{
    return new Node{n->value, n->next};
} */

//Destructor. Iterates until the list is empty.
Sorted_List::~Sorted_List()
{
    while (!is_empty())
    {
        pop();
    }
}

//Adds an element in the listed, sorted in ascending order.
void Sorted_List::add(int number){

    //Adds element first if list empty.
    if(is_empty()){
        head = new Node{number, nullptr};
        return;
    }
    else {
        current = head;
        add(number, nullptr);
    }
}

void Sorted_List::add(int number, Node *node){
    
    //Adds first
    if(number < current->value){
        head = new Node{number, head};
    }

    //Adds last if the end is found
    if(current->next == nullptr){
        current->next = new Node{number, nullptr};
    }
}

//Returns true if the list has no elements.
bool Sorted_List::is_empty()
{
    return head == nullptr;
}

//Removes a specific number in the list
bool Sorted_List::remove()
{
    if(is_empty())
    {
        throw logic_error("List is empty");
    }

    return 0;
}


//Used to destruct the entire list when destructor is called. 
//Removes the first element and removes the allocated space.
void Sorted_List::pop()
{
    if(is_empty())
    {
        throw logic_error("List is empty");
    }

    Node* tmp = head;
    head = head->next;
    tmp->next = nullptr;
    delete tmp;
}

//Returns the number of elements in the list
int Sorted_List::size()
{
    return count;
}