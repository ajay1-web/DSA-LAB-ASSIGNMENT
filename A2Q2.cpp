#include <iostream> 
using namespace std;
int main()
{  
    int arr[]={64,34,25,12,22,11,90};
    int n=sizeof(arr)/4;
    for(int i=0;i<n-1;i++)
    {
          bool flag=false;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                flag=true;
            }
        }
        if(flag==false)
        {
            break;
        }
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}