void solve(int open,int close,string &temp,vector<string> &ans)
{
    if(open==0&&close==0)
    {
        ans.push_back(temp);
    }

    // Opening Bracket
    if(open>0)
    {
        temp.push_back('(');
        solve(open-1,close,temp,ans);
        temp.pop_back();
    }
   // Closing Bracket
    if(close>0)
    {
        if(open<close)
        {
        temp.push_back(')');
        solve(open,close-1,temp,ans);
        temp.pop_back();
        }
    }
}
vector<string> validParenthesis(int n)
{
    // Write your code here.
    int open=n,close=n;
    vector<string> ans;
    string temp;
    solve(open,close,temp,ans);
    return ans;
}
