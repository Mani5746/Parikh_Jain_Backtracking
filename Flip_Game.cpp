#include <bits/stdc++.h> 

int solve(int ind,string& str,int count)
{
    int n=str.size();
    if(ind==n)
    {
        if(count%2==0) return 0;

        for(int i=1;i<n;i++)
        {
            if(str[i]=='$'&&str[i-1]=='$') return 0;
        }

        return 1;
    }

   int pick=0,nonpick=0;

   // Non Pick

   nonpick=solve(ind+1,str,count);

   // Pick

   if(ind<n-1&&str[ind]=='$'&&str[ind+1]=='$')
   {
       str[ind]='*';
       str[ind+1]='*';

      pick= solve(ind+1,str,count+1);
      str[ind]='$';
       str[ind+1]='$';
   }

   return pick|nonpick;



}

bool canNinjaWin(string& str) 
{
    // Write your code here.
    return solve(0,str,0);
}
