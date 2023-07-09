#include <bits/stdc++.h> 
bool isValid(string s1)
{

   if(s1.size()>3||s1.size()==0) return false;
   
   if(s1.size()>1 && s1[0]=='0') return false;
   

   
   if(s1.size() && stoi(s1)>255) return false;
   
   
   
   return true;
       
}

void recur(int i, int dots, string temp, vector<string>& ans, string s)
{
	
	
    if(dots==3)
    {
     
			
        if(isValid(s.substr(i)))
        {
       
            ans.push_back(temp+s.substr(i));
            
        }
        return;
    }
	
    // placing the dot at every valid position
	
    for(int j=i; j<s.size() ;j++)
    {

	if( isValid(s.substr(i, j-i+1)))
	{
		temp.push_back(s[j]);
		temp.push_back('.');

		recur(j+1, dots+1, temp, ans, s);

	   // removing the dot after calling recur function 

	   // note that we don't remove the last digit that was placed in temp string as we just have to change positions of dots only and not digits in string
		temp.pop_back();


        }
    }
    
    return;
    
}


vector<string> generateIPAddress(string s)
{
	// Write your code here
	 vector<string> ans;
    
    if(s.size()<4) return ans;
    
    recur(0, 0, "", ans, s);
    
    return ans;
}
