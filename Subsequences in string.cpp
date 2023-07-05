#include <bits/stdc++.h> 
 void solve(int ind,string s,string str,vector<string> &ans)
 {
	 int n=str.size();
	 if(ind==n)
	 {
		 if(s.size()>0)
		 ans.push_back(s);
		 return;
	 }

	 // Non Pick
	 solve(ind+1,s,str,ans);

	 s.push_back(str[ind]);

	 solve(ind+1,s,str,ans);
	 s.pop_back();
 }
vector<string> subsequences(string str)
{
	
	// Write your code here
	vector<string> ans;
	string s;
	solve(0,s,str,ans);
	return ans;

	
}
