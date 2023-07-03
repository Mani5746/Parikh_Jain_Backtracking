#include <bits/stdc++.h> 
int partition (vector<int> &arr,int low,int high)
{
    int i=low,j=high;
    int pivot=arr[low];

    while(i<j)
    {
        while(arr[i]<=pivot && i<high) i++;
        while(arr[j]>pivot && j>low) j--;

        if(i<j) swap(arr[i],arr[j]);
        
    }

    swap(arr[j],arr[low]);
    return j;
}
void quicksolve(vector<int>&arr,int low,int high)
{
    if(low>=high) return;
    
    int part=partition(arr,low,high);
    quicksolve(arr,low,part-1);
    quicksolve(arr,part+1,high);
    
}
vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    int n=arr.size();

    quicksolve(arr,0,n-1);
    return arr;

}
