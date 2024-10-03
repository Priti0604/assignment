// Assignment 3
// Implement Circular Queue using Array. Perform following operations on it.
//a) Insertion (Enqueue)
//b) Deletion (Dequeue)
//c) Display
//(Note: Handle queue full condition by considering a fixed size of a queue.)

//.................................................................................................
#include <iostream>
using namespace std;
#define SIZE 10  //states the size of the queue

void enQueue(int);
void deQueue();
void display();

int cQueue[SIZE], front = -1, rear = -1;

int main()  
{
    int choice, value,i=0;
    char ch;

    while (1)  
    {
        cout << "\n*** MENU ***\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:  //calling insert queue method
            do
            {
                printf("\nEnter the value to be insert:  ");
                cin >> value;
                enQueue(value);
                i+=1;
                cout<<"Enter y to insert or n to exit : ";
                cin>>ch;
            }while(ch == 'y' || ch == 'Y');
            break;
        case 2:
            deQueue();  //calling delete queue method
            break;
        case 3:
            display();  //calling display method
            break;
        case 4:
            exit(0);
        default:
            cout << "\nPlease select the correct choice!!!\n";
        }
    }
}
void enQueue(int value)  //to insert elements in queue
{
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))  //for overflow detection
        cout << "\nCircular Queue is Full! Insertion not possible!!!\n";
    else
    {
        if (rear == SIZE - 1 && front != 0)   
            rear = -1;
        cQueue[++rear] = value;   //assigns element value
        cout << "\nInsertion Success!!\n";
        if (front == -1)
            front = 0;
    }
}
void deQueue()  //to delete elements from queue
{
    if (front == -1 && rear == -1) //for empty queue detection
    {
        cout << "\nCircular Queue is Empty! Deletion is not possible!!!\n";
    }
    else
    {
        cout << "\nDeleted element :" << cQueue[front++]; //deletes elements
        if (front == SIZE)
            front = 0;
        if (front - 1 == rear)
            front = rear = -1;
    }
}
void display()  //displays the elements in the queue
{
    if (front == -1)
        cout << "\nCircular Queue is Empty!!!\n";   //for empty queue detection
    else
    {
        int i = front;
        cout << "\nCircular Queue Elements are : \n";  //displays the elements on the output screen
        if (front <= rear)
        {
            while (i <= rear)
                cout << cQueue[i++]<<"\t";
        }
        else
        {
            while (i <= SIZE - 1)
                cout << cQueue[i++]<<"\t";
            i = 0;
            while (i <= rear)
                cout << cQueue[i++]<<"\t";
        }
    }
}
