#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
    string inputStream = "aabc", resultString = "";

    int freqMap['z' - 'a' + 1] = {0};
    queue<char> charQueue;

    for (int i = 0; i < inputStream.length(); i++)
    {
        freqMap[inputStream[i] - 'a']++;
        charQueue.push(inputStream[i]);
    }

    while (!charQueue.empty())
    {
        if (freqMap[charQueue.front() - 'a'] > 1)
        {
            freqMap[charQueue.front() - 'a']--;
            resultString += "#"; // Using '#' instead of "-1" for a single character marker
            charQueue.pop();
        }
        else
        {
            resultString += charQueue.front();
            charQueue.pop();
        }
    }

    cout << resultString;
    return 0;
}
