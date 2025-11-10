using namespace std;
#include <bits/stdc++.h>
int main()
{
    vector <int> noDuplicate;
    int arr[]={1,4,3,2,1,5,7,9,7,5,3,5,6,3,7,3,8,2,7,5,3};
    noDuplicate.push_back(arr[0]);
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        int flag=false;
        for(int j=0;j<noDuplicate.size();j++)
        {
            if(arr[i]==noDuplicate[j])
            {
                flag=true;
            }
        }
        if(!flag)
        {
            noDuplicate.push_back(arr[i]);
        }
               
        
    }

    for(int i=0;i<noDuplicate.size();i++)
    {
        cout<<noDuplicate[i];
    }
return 0;
}