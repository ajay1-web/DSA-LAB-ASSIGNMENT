#include <iostream>
using namespace std;

const int ARRAY_SIZE = 20;

class SimpleQueue
{
    int head, tail;

public:
    SimpleQueue()
    {
        head = -1;
        tail = -1;
    }
    int queueData[ARRAY_SIZE];

    bool isEmpty()
    {
        return ((head > tail) || tail == -1);
    }

    bool isFull()
    {
        return (tail == ARRAY_SIZE - 1);
    }

    void enqueue(int element)
    {
        if (this->isFull())
        {
            cout << "overflow";
        }
        else
        {
            if (head == -1)
            {
                head++;
            }
            queueData[++tail] = element;
        }
    }

    int dequeue()
    {
        if (this->isEmpty())
        {
            cout << "empty";
            return -1;
        }
        else
        {
            return queueData[head++];
        }
    }

    int peek()
    {
        if (this->isEmpty()) {
            cout << "empty";
            return -1;
        }
        return queueData[head];
    }

    void display()
    {
        if (this->isEmpty())
            cout << "empty";
        else
        {
            int currentIndex = head;
            while (currentIndex <= tail)
                cout << queueData[currentIndex++] << " ";
        }
    }
};

int main()
{
    SimpleQueue dataQueue;
    int option, num;

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
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter an integer value to enqueue: ";
            cin >> num;
            dataQueue.enqueue(num);
            break;
        case 2:
            num = dataQueue.dequeue();
            if (num != -1)
            {
                cout << num << " was dequeued from the queue." << endl;
            }
            break;
        case 3:
            num = dataQueue.peek();
            if (num != -1)
            {
                cout << "Front element is: " << num << endl;
            }
            break;
        case 4:
            dataQueue.display();
            break;
        case 0:
            cout << "Exiting program. Good work tonight from Patiala!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (option != 0);

    return 0;
}