#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    string str="Data Structures";
    stack <char> rev;
    // int n=str.length()-1;
    for(int i=0;i<str.length();i++)
    {
        rev.push(str[i]);     
    }
    while(!rev.empty())
    {
        cout<<rev.top();
        rev.pop();
    }
    return 0;

}