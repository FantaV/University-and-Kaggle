#include <iostream>
using namespace std;
//Circular queue  C++ program
#include<iostream>
#define MAX_SIZE 8
// Maximum size of the queueusing namespace std;

struct CircularQueue
{int front, rear;
    int arr[MAX_SIZE]; } ;

CircularQueue CreaCircularQueue()  {CircularQueue p;    p.front = -1;    p.rear = -1;  return p;
}
// Function to check if the queue is full
bool isFull (CircularQueue p)  {    if ((p.front == 0 && p.rear == MAX_SIZE - 1)|| (p.rear == (p.front - 1)))
{return true;}    return false;  }

// Function to check if the queue is empty
bool isEmpty (CircularQueue p)  {    if (p.front == -1) {return true; }    return false;  }

// Function to add an element to the queue
void enQueue (int value, CircularQueue &p)  {    if (isFull (p))
{cout << "Queue is full." << endl;      }
else      {	if (p.front == -1) {p.front = 0;}
    p.rear = (p.rear + 1) % MAX_SIZE;
    p.arr[p.rear] = value;
    cout << "Enqueued element: " << value << endl;      }  }

// Function to remove an element from the queue
int deQueue (CircularQueue &p)  {   int element;
    if (isEmpty (p))      {cout << "Queue is empty." << endl; return -1; }
    else      {element =p.arr[p.front];
        if (p.front == p.rear) {p.front = -1; p.rear = -1;	  }
        else	  {p.front = (p.front + 1) % MAX_SIZE;}
        cout << "Dequeued element: " << element << endl;
        return element;      }  }

// Function to display the elements in the queue
void display (CircularQueue p)  {if (isEmpty (p)) {cout << "Queue is empty." << endl;}
else      {	cout << "Elements in the queue: ";
    int i;
    for (i = p.front; i != p.rear; i = (i + 1) % MAX_SIZE) {cout <<p.arr[i] << " ";}
    cout << p.arr[i] << endl;      }  };

int main () {
    CircularQueue q;
    q=CreaCircularQueue( );
    enQueue (10,q);
    enQueue (20,q);
    enQueue (30,q);
    enQueue (40,q);
    display (q);
    deQueue (q);
    deQueue (q);
    display (q);
    enQueue (50,q);
    enQueue (60,q);
    display (q);
    return 0;
}

