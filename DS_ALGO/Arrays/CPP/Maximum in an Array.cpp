#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];int m=0;
    for(int i=0;i<n;i++)
    {cin>>arr[i];
        m=max(n,arr[i]);
    }
    cout<<"maximum is: "<<m;
    return 0;
}