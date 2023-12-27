#include<iostream>
using namespace std;

int queue[10], size, front = -1, rear = -1, data;

void enqueue(){
    if (rear == size - 1){
        cout << "\nQueue Overflow!\n";
    }
    else if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        cout << "\nEnter element : ";
        cin >> queue[rear];
        cout << "Element enqued!\n";
    }
    else
    {
        rear++;
        cout << "\nEnter element : ";
        cin >> queue[rear];
        cout << "Element enqued!\n";
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        cout << "\nQueue Underflow!\n";
    } else if (front == rear) {
        front = -1;
        rear = -1;
        cout << "\nElement dequeued!\n";
    } else {
        cout << "\nElement dequeued!\n";
        front++;
    }
}

void peek(){
    if (front == -1 && rear == -1){
        cout << "\nQueue is empty!\n";
    }
    else{
        cout << "\nPeak element : " << queue[front] << endl;
    }
}

void print(){
    if (front == -1 && rear == -1){
        cout << "\nQueue is empty!\n";
    }
    else{
        cout << "\nQueue elements : ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    int loop = -1;

    while (loop != 0)
    {
        cout << "\nEnter size of stack (max : 10) : ";
        cin >> size;
        if (size > 0 && size < 11)
        {
            loop = 0;
            break;
        }
        else if (size > 10)
        {
            cout << "\nSize exceeding... Try again!\n\n";
            continue;
        }
        else
        {
            cout << "\nSize subceeding... Try again!\n\n";
            continue;
        }
    }

    int ch = -1;

    while (ch != 0)
    {
        cout << "\n****MENU****\n0. Exit\n1. Enque\n2. Dequeue\n3. Peek\n4. Print\nEnter choice : ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            cout << "\nExiting...";
            break;

        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            print();
            break;

        default:
            cout << "\nInvalid Input!\n";
            break;
        }
    }
    
    cout << "ThankYou!!!\n\n";
    return 0;
    
}
