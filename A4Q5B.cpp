#include <iostream>
#include <queue>
using namespace std;

class StackViaQueue
{
    queue<int> internalQueue;

public:
    void push(int data)
    {
        internalQueue.push(data);
    }

    int peek()
    {
        if (!internalQueue.empty())
        {
            int elementCount = internalQueue.size();
            for (int i = 0; i < elementCount - 1; i++)
            {
                internalQueue.push(internalQueue.front());
                internalQueue.pop();
            }
            int topValue = internalQueue.front();
            internalQueue.push(internalQueue.front());
            internalQueue.pop();
            return topValue;
        }
        return -1; // Indicates stack is empty
    }

    void pop()
    {
        if (!internalQueue.empty())
        {
            int elementCount = internalQueue.size();
            for (int i = 0; i < elementCount - 1; i++)
            {
                internalQueue.push(internalQueue.front());
                internalQueue.pop();
            }
        }
        internalQueue.pop();
    }
};

int main()
{
    StackViaQueue s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << endl;
    s.pop();
    cout << "Top: " << s.peek() << endl;
    s.pop();
    cout << "Top: " << s.peek() << endl;
    s.pop();
    cout << "Top: " << s.peek() << endl;
    
    return 0;
}