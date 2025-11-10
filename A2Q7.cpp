using namespace std;
#include <bits/stdc++.h>
int main()
{
    int arr[]={1,2,3,4,5,6,4,2,4,2,4,7};
    int count=0;
    for(int i=0;i<(sizeof(arr)/sizeof(int))-1;i++)
    {
        for(int j=i+1;j<sizeof(arr)/sizeof(int);j++)
        {
            if(arr[j]<arr[i])
            {
                count++;
            }
        }
    }
    cout<<count;
}