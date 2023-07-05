#include<bits/stdc++.h>

void solve(int ind,map<char,string> &mp,vector<string> &ans,string temp,string s)
{
	int n=s.size();
	if(ind==n)
	{
		ans.push_back(temp);

	     return;
	}

	if(s[ind]=='7'||s[ind]=='9')
	{
		for(int i=0;i<4;i++)
		{
			temp+=(mp[s[ind]][i]);
			solve(ind+1,mp,ans,temp,s);
			temp.pop_back();
		}
	}

	else
	{
		for(int i=0;i<3;i++)
		{
			temp+=(mp[s[ind]][i]);
			solve(ind+1,mp,ans,temp,s);
			temp.pop_back();
		}
	}
}

vector<string> combinations(string s)
{
	
	// Write your code here
	map<char,string> mp;
	mp['2']="abc",mp['3']="def",mp['4']="ghi",mp['5']="jkl",mp['6']="mno",mp['7']="pqrs",mp['8']="tuv",mp['9']="wxyz";
	string temp;
	vector<string>ans;

	solve(0,mp,ans,temp,s);
	return ans;
}
