// задача 3.2

#include <iostream>
using namespace std;

template <typename T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T data;
        Node* prev;
        Node* next;

        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~DoublyLinkedList()
    {
        clear();
    }

    void push_back(T value)
    {
        Node* newNode = new Node(value);

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    void push_front(T value)
    {
        Node* newNode = new Node(value);

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        size++;
    }

    bool pop_front()
    {
        if (!head) return false;

        Node* temp = head;

        head = head->next;

        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
        size--;

        return true;
    }

    bool pop_back()
    {
        if (!tail) return false;

        Node* temp = tail;

        tail = tail->prev;

        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
        size--;

        return true;
    }

    void printForward() const
    {
        Node* current = head;

        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printBackward() const
    {
        Node* current = tail;

        while (current)
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    int getSize() const
    {
        return size;
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

        head = tail = nullptr;
        size = 0;
    }
};

int main()
{
    DoublyLinkedList<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    list.printForward();   // 5 10 20
    list.printBackward();  // 20 10 5

    list.pop_front();
    list.printForward();   // 10 20

    cout << "Size: " << list.getSize() << endl;

    return 0;
}