void solve(int n, int src,int des,int aux, vector<vector<int>>&ans)
{
    if(n==1)
    {
         ans.push_back({src,des});
         return;
    }

    solve(n-1,src,aux,des,ans);
    ans.push_back({src,des});
    solve(n-1,aux,des,src,ans);
}

vector<vector<int>> towerOfHanoi(int n)
{
    //    Write your code here.
    vector<vector<int>> ans;
    solve(n,1,3,2,ans);
    return ans;
}
