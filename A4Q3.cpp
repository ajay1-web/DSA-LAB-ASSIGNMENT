#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int elementCount;
    queue<int> mainQueue, auxQueue;

    cout << "enter number of elements: ";
    cin >> elementCount;

    for (int i = 1; i <= elementCount; i++)
    {
        cout << "enter element number " << i << " : ";
        int inputVal;
        cin >> inputVal;
        mainQueue.push(inputVal);
        cout << endl;
    }

    for (int i = 1; i <= (elementCount + 1) / 2; i++)
    {
        auxQueue.push(mainQueue.front());
        mainQueue.pop();
    }

    while (!mainQueue.empty())
    {
        auxQueue.push(auxQueue.front());
        auxQueue.pop();
        auxQueue.push(mainQueue.front());
        mainQueue.pop();
    }

    if (elementCount % 2 == 1)
    {
        auxQueue.push(auxQueue.front());
        auxQueue.pop();
    }

    while (!auxQueue.empty())
    {
        cout << auxQueue.front() << " ";
        auxQueue.pop();
    }

    return 0;
}