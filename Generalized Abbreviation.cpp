#include <bits/stdc++.h> 

bool is_digit(char ch)
{
    int count=(int)(ch-'0');
    if(count>=1&&count<=19) return true;

    return false;
}

  void solve(int ind,string & str,vector<string> &ans,string temp)
  {
      int n= str.size();
      if(ind==n)
      {
          ans.push_back(temp);
          return;
      }

      temp.push_back(str[ind]);
      solve(ind+1,str,ans,temp);
      temp.pop_back();

   int count=1;

   if(!temp.empty())
   {
   if(is_digit(temp.back()))
   {
       count+=(int)(temp.back()-'0');
       temp.pop_back();
   }
   }

   char ch=(char)(count+'0');
   temp.push_back(ch);
   solve(ind+1,str,ans,temp);

   //temp.pop_back();





  }
vector < string > findAbbr(string & str)
 {
    // Write your code here.
   vector<string> ans;
   string temp="";
   solve(0,str,ans,temp);
   sort(ans.begin(),ans.end());
   return ans;

}
