void solve(int ind,string& s,vector<string>&ans)
{
    int n=s.size();
    if (ind >= n)
    {
      ans.push_back(s); return;
    }
    
    // non pick

    solve(ind+1,s,ans);

    // pick
    s[ind]='1';
    solve(ind+2,s,ans);
    s[ind]='0';

}

 vector<string> generateString(int n)
 {
    // Write your code here.
     string s;
     for(int i=0;i<n;i++) s.push_back('0');

     vector<string>ans;
     solve(0,s,ans);

     return ans;
     
     
     
 }
