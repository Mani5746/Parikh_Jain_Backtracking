void solve(int ind,int B,vector<int> &ARR,
vector<vector<int>> &ans,vector<int> &ds)
{
    int n=ARR.size();
    if(ind==n||B==0)
    {
        if(B==0)
        {
        ans.push_back(ds);
       
        }
         return;

    }

    // Pick

    if(ARR[ind]<=B)
    {
        ds.push_back(ARR[ind]);
        solve(ind,B-ARR[ind],ARR,ans,ds);
        ds.pop_back();
    }

    // Nonpick
    
    solve(ind+1,B,ARR,ans,ds);
}

vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    // Write your code here.
    sort(ARR.begin(),ARR.end());

    vector<vector<int>> ans;
    vector<int> ds;
      solve(0,B,ARR,ans,ds);

      sort(ans.begin(),ans.end());

      return ans;
}
