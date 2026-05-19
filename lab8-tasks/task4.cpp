//Задача 4.2
#include <iostream>
using namespace std;

template <typename T>
class SinglyLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;

        Node(T value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    ~SinglyLinkedList()
    {
        clear();
    }

    void push_back(T value)
    {
        Node* newNode = new Node(value);

        if (!head)
        {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next)
            current = current->next;

        current->next = newNode;
    }

    void clear()
    {
        Node* current = head;

        while (current)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
    }

    class Iterator
    {
    private:
        Node* ptr;

    public:
        Iterator(Node* p = nullptr) : ptr(p) {}

        T& operator*()
        {
            return ptr->data;
        }

        Iterator& operator++()
        {
            if (ptr) ptr = ptr->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const
        {
            return ptr != other.ptr;
        }
    };

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }
};

int main()
{
    SinglyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);

    cout << "Елементи списку: ";

    for (SinglyLinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    auto it = list.begin();
    ++it;
    cout << "Другий елемент: " << *it << endl;

    return 0;
}