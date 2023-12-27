#include <iostream>
using namespace std;

int stack[10], size, top = -1, data;

void push()
{
    if (top == size - 1)
    {
        cout << "\nStack Overflow!\n";
    }
    else
    {
        cout << "\nEnter the value : ";
        cin >> data;
        top++;
        stack[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "\nStack Underflow!\n";
    }
    else
    {
        cout << "\nPopped value : " << stack[top] << endl;
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        cout << "\nStack is Empty!\n";
    }
    else
    {
        cout << "\nTop element is : " << stack[top] << endl;
    }
}

void print()
{
    if (top == -1)
    {
        cout << "\nStack is Empty!\n";
    }
    else
    {
        cout << "\nStack elements :\n";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
        cout << endl;
    }
}

int main()
{
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

    int ch;

    while (ch != 0)
    {
        cout << "\n****MENU****\n0. Exit\n1. Push\n2. Pop\n3. Peek\n4. Print\nEnter choice : ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            cout << "\nExiting...";
            break;

        case 1:
            push();
            break;

        case 2:
            pop();
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
