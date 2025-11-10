#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    string exp="{hello(123[343(3((3)4))])}";
    stack <char> braces;
    for(int i=0;i<exp.length();i++)
    {
        char ch=exp[i];
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
        {
            braces.push(exp[i]);
        }
        else if(ch==')'||ch==']'||ch=='}')
        {
            if (braces.empty()) { 
                cout << "Not Balanced";
                return 0;
            }
            if ((ch == ')' && braces.top() != '(') ||
            (ch == '}' && braces.top() != '{') ||
            (ch == ']' && braces.top() != '[')) {
                cout<<"not  balanced";
                return 0;
            }
            braces.pop();
            }
    }
    if (braces.empty())
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}