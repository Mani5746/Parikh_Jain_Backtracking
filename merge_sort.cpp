  
  void merge(int low,int mid,int high,vector < int > & arr)
  {
        int left=low,right=mid+1;

        vector<int> temp;
        while(left<=mid&&right<=high)
        {
            if(arr[left]<=arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }

            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left<=mid)
        {
             temp.push_back(arr[left]);
                left++;
        }

        while(right<=high)
        {
            temp.push_back(arr[right]);
                right++;
        }

        for(int i=low;i<=high;i++)
        {
            arr[i]=temp[i-low];
        }
  }
  void mergesolve(int low,int high,vector < int > & arr)
  {
      if(low>=high) return;

      int mid=(low+high)/2;

      mergesolve(low,mid,arr);
      mergesolve(mid+1,high,arr);
      merge(low,mid,high,arr);
  }

void mergeSort(vector < int > & arr, int n) 
{
    // Write your code here.
    mergesolve(0,n-1,arr);
}
