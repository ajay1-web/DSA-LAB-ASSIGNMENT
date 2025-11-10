#include <iostream>
using namespace std;
int main() {
    int arr[]={1,2,3,4,5,6,7,8,10};
    int n=sizeof(arr)/sizeof(int);
    int s=0,e=n-1;
    int ans=arr[0];
    int m;
    while(s<=e)
    {
         m=s+(e-s)/2;
        if(arr[m]>m+1)
        {
            ans=m+1;
            e=m-1;
        }
        else
        {
            s=m+1;
        }
    }
    cout<<ans;
    return 0;
}