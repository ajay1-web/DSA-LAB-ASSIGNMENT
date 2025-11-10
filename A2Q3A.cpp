#include <iostream>
using namespace std;
int main() {
    int arr[]={1,2,3,4,5,6,8,9};
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=i+1)

        {
            cout<<"missing is "<<i+1;
            return 0;
        }
    }
    return 0;
}