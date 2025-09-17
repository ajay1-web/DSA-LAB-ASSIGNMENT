#include <iostream>
using namespace std;

const int QUEUE_CAPACITY = 20;

class MyQueue
{
    int qFront, qRear;

public:
    MyQueue()
    {
        qFront = -1;
        qRear = -1;
    }
    int queueArray[QUEUE_CAPACITY];

    bool isEmpty()
    {
        return ((qFront > qRear) || qRear == -1);
    }

    bool isFull()
    {
        return (qFront == (qRear + 1) % QUEUE_CAPACITY);
    }

    void enqueue(int item)
    {
        if (this->isFull())
        {
            cout << "Queue Overflow";
        }
        else
        {
            if (qFront == -1)
            {
                qFront++;
            }
            qRear = (qRear + 1) % QUEUE_CAPACITY;
            queueArray[qRear] = item;
        }
    }

    int dequeue()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty";
            return -1;
        }
        else
        {
            int dequeuedValue = queueArray[qFront];
            if (qFront == qRear)
            {
                qFront = qRear = -1;
            }
            else
            {
                qFront = (qFront + 1) % QUEUE_CAPACITY;
            }
            return dequeuedValue;
        }
    }

    int peek()
    {
        if (this->isEmpty()) {
            cout << "Queue is empty";
            return -1;
        }
        return queueArray[qFront];
    }

    void display()
    {
        if (this->isEmpty())
        {
            cout << "Queue is empty";
        }
        else
        {
            int tempFront = qFront;
            while (true)
            {
                cout << queueArray[tempFront] << " ";
                if (tempFront == qRear)
                    break;
                tempFront = (tempFront + 1) % QUEUE_CAPACITY;
            }
        }
    }
};

int main()
{
    MyQueue my_queue;
    int userChoice, inputValue;

    do
    {
        cout << "\n\n--- Queue Operations Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            cout << "Enter an integer value to enqueue: ";
            cin >> inputValue;
            my_queue.enqueue(inputValue);
            break;
        case 2:
            inputValue = my_queue.dequeue();
            if (inputValue != -1)
            {
                cout << inputValue << " was dequeued from the queue." << endl;
            }
            break;
        case 3:
            inputValue = my_queue.peek();
            if (inputValue != -1)
            {
                cout << "Front element is: " << inputValue << endl;
            }
            break;
        case 4:
            cout << "Queue elements: ";
            my_queue.display();
            cout << endl;
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (userChoice != 0);

    return 0;
}