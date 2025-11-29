//Linked Queue  C++ program
#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedQueue
{
    Node * front;
    Node *rear;
};

LinkedQueue  CreaLinkedQueue ()
{LinkedQueue p;
    p.front = p.rear = nullptr;
    return p;
}

void enqueue (int data, LinkedQueue &p)
{
    Node *newNode = new Node ();
    newNode->data = data;
    newNode->next = nullptr;

    if (p.front == nullptr)
    {
        p.front = p.rear = newNode;
    }
    else
    {
        p.rear->next = newNode;
        p.rear = newNode;
    }

    cout << data << " has been enqueued." << endl;
}

void dequeue (LinkedQueue &p)
{
    if (p.front == nullptr)
    {
        cout << "Queue is empty." << endl;
    }
    else if (p.front == p.rear)
    {
        Node *temp = p.front;
        p.front = p.rear = nullptr;
        delete temp;
    }
    else
    {
        Node *temp = p.front;
        p.front = p.front->next;
        delete temp;
    }
}

void display (LinkedQueue p)
{
    if (p.front == nullptr)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        Node *temp = p.front;
        cout << "Linked Queue: ";
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != NULL);
        cout << endl;
    }
};

int main ()
{
    LinkedQueue q;
    q=CreaLinkedQueue();
    enqueue (10,q);
    enqueue (20,q);
    enqueue (30,q);
    enqueue (40,q);
    display (q);

    dequeue (q);
    dequeue (q);
    display (q);

    enqueue (50,q);
    enqueue (60,q);
    display (q);

    return 0;
}