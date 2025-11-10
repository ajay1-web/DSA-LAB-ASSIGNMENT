#include <iostream>
using namespace std;
int main() {
    string s="hello world this is cpp";
    string s2="";
for(int i=0;i<s.length();i++)
{
   if(s[i]!='a' && s[i]!='e' && s[i]!='i' &&  s[i]!='o' &&  s[i]!='u' && 
        s[i]!='A' &&  s[i]!='E' &&  s[i]!='I' &&  s[i]!='O' &&  s[i]!='U')
        {
            s2=s2+s[i];
        }

    }
    cout<<s2;
}
