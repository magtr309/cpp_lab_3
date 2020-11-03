#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List
{
public:
    Sorted_List() = default;
    Sorted_List(Sorted_List const &);
    Sorted_List(Sorted_List &&);
    ~Sorted_List();


    void add(int number);
    bool is_empty();
    bool remove();
    int size();


private:
    struct Node
        {
            int value;
            Node* next;
        };

    void add(int number, Node *node);
    Node* head{};
    Node* current{};
    int count{};
    void pop();
};

#endif