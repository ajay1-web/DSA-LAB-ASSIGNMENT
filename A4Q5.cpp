#include <iostream>
#include <queue>
using namespace std;

class QueueStack
{
    queue<int> primaryQueue, helperQueue;

public:
    void push(int value)
    {
        primaryQueue.push(value);
    }

    int peek()
    {
        if (!isEmpty())
        {
            while (primaryQueue.size() > 1)
            {
                helperQueue.push(primaryQueue.front());
                primaryQueue.pop();
            }
            int topElement = primaryQueue.front();
            primaryQueue.pop();
            while (!helperQueue.empty())
            {
                primaryQueue.push(helperQueue.front());
                helperQueue.pop();
            }
            primaryQueue.push(topElement);
            return topElement;
        }
        return -1; // Indicates stack is empty
    }

    void pop()
    {
        if (!isEmpty())
        {
            while (primaryQueue.size() > 1)
            {
                helperQueue.push(primaryQueue.front());
                primaryQueue.pop();
            }
            primaryQueue.pop();
            while (!helperQueue.empty())
            {
                primaryQueue.push(helperQueue.front());
                helperQueue.pop();
            }
        }
    }

    bool isEmpty()
    {
        return primaryQueue.empty();
    }
};

int main()
{
    QueueStack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout << "Top element is: " << myStack.peek() << endl;
    myStack.pop();
    cout << "Top element is: " << myStack.peek() << endl;
    myStack.pop();
    cout << "Top element is: " << myStack.peek() << endl;
    myStack.pop();
    cout << "Top element is: " << myStack.peek() << endl;

    return 0;
}