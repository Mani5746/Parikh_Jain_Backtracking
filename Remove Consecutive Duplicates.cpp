void solve(int ind,string &s,string &ans)
{
    int n=s.size();
    if(ind>=n) return;

    ans.push_back(s[ind]);
    char ch=s[ind];
    while(ind<n&&s[ind]==ch) ++ind;

    solve(ind,s,ans);


}

string removeDuplicate(string &s)
{
    // Write your code here
    string ans;
    solve(0,s,ans);
    return ans;
}
