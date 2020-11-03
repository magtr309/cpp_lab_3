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

    Node* tempNode = new Node{number, nullptr};

    //Tom lista
    if(is_empty()){
        head = tempNode;
    }
    else {
        
        current = head;
        previous = nullptr;

        //Körs tills den hittar en plats där current är större
        //än den nya noden.
        findInsertPos(tempNode);

        //Först
        if(current == head){
            tempNode->next = head;
            head = tempNode;
        }
        //Inte först
        else {
            tempNode->next = current;
            previous->next = tempNode;
        }

        //Resettar värdena inför nästa add
        current = head;
        previous = nullptr;
        count++;
    }
}

void Sorted_List::findInsertPos(Node* node){
    if(current != nullptr){
        //Stannar när current->value är större än temp->value.
        //Sätter previous och current för att senare kunna stoppa in temp.
        if(node->value > current->value){
            previous = current;
            current = current->next;
            findInsertPos(node);
        }else{
            return;
        }
    }
}


//Returns true if the list has no elements.
bool Sorted_List::is_empty()
{
    return count == 0;
}

//Removes a specific number in the list
bool Sorted_List::remove()
{
    if(is_empty())
    {
        throw logic_error("List is empty");
    }


    count--;
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

    Node* temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
}

//Returns the number of elements in the list
int Sorted_List::size()
{
    return count;
}