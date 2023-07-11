bool solve(vector<int> &ans,vector<bool> &vis,int ind,int n)
 {
   
     if(ind==ans.size()) return true;

     if(ans[ind]!=0)
     {
         return solve(ans,vis,ind+1,n);
     }

     for(int j=n;j>=1;j--)
     {
         if(!vis[j] && (j==1||(ind+j<ans.size() && ans[ind+j]==0)))
         {
            
             ans[ind]=j;

             if(j!=1) ans[ind+j]=j;
              vis[j]=true;

              if(solve(ans,vis,ind+1,n))  return true;

                ans[ind]=0;

             if(j!=1) ans[ind+j]=0;
              vis[j]=false;
          
         }
     }

     return false;
 }


vector<int> validSequence(int n) 
{
    // Write your code here.
     vector<int> ans(2*n-1,0);
        vector<bool> vis(n+1,false);
        solve(ans,vis,0,n);
        return ans;
}
