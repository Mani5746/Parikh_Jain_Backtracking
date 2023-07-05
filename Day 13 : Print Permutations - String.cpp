#include <bits/stdc++.h> 
void solve(int ind,string &s,string ds,vector<int>&vec,vector<string> &ans)
{
    int n=s.size();
    if(ds.size()==n)
    {
        ans.push_back(ds);
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(vec[i]==0)
        {
            ds.push_back(s[i]);
            vec[i]=1;
            solve(ind+1,s,ds,vec,ans);
            vec[i]=0;
            ds.pop_back();
            
        }
    }
}
vector<string> findPermutations(string &s)
 {
    // Write your code here.
    int n=s.size();
    string ds;
    vector<int> vec(n,0);
    vector<string> ans;

    solve(0,s,ds,vec,ans);
    return ans;

    
}
