#include <bits/stdc++.h> 
void solve(vector<int> &arr1, vector<int> &arr2, int k,int &ans,int ind1,
int ind2,int prev)
{
    int m=arr1.size();
    int n=arr2.size();
    if(k==0)
    {
          ans=prev;
          return;
    }

    if(ind2>=n||(ind1<m&&arr1[ind1]<=arr2[ind2]))
    {
        solve(arr1,arr2,k-1,ans,ind1+1,ind2,arr1[ind1]);
    }

    else if(ind1>=m||(ind2<n&&arr1[ind1]>arr2[ind2]))
    {
        solve(arr1,arr2,k-1,ans,ind1,ind2+1,arr2[ind2]);

    }
}
int findKthElement(vector<int> &arr1, vector<int> &arr2, int k)
{
    // Write your code here.
    int ans=0;
    solve(arr1,arr2,k,ans,0,0,-1);
    return ans;
}
