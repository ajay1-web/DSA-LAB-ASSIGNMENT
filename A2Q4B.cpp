#include <iostream>
using namespace std;
int main() {

string s="hello";
string s2="";
for(int i=0;i<s.length();i++)
{
    s2=s2+s[s.length()-1-i];
}
cout<<s2;

}