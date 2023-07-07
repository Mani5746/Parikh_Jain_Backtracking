#include <bits/stdc++.h> 
void solve(int row,int col, vector<vector<int>> &ans,
 vector<vector<int>> &temp, vector<vector<int>> &maze)
 {
   int n=temp.size();

   if(row==n-1&&col==n-1)
   {
     vector<int> vec;
    // vec.push_back(1);
     for(int i=0;i<n;i++)
     {
       for(int j=0;j<n;j++)
       {
         if(i+j==0||(i==n-1&&j==n-1))
          vec.push_back(1);
          else
          vec.push_back(temp[i][j]);
       }
     }
     

     ans.push_back(vec);
     return;
   }

   if(maze[row][col]==2) return;

   // UP i-1,j

   if(row-1>=0 && maze[row-1][col]==1)
   {
       temp[row][col]=1;
       maze[row][col]=2;

       solve(row-1,col,ans,temp,maze);
        temp[row][col]=0;
       maze[row][col]=1;
   }

   // Down i+1,j

     if(row+1<n && maze[row+1][col]==1)
   {
       temp[row][col]=1;
       maze[row][col]=2;

       solve(row+1,col,ans,temp,maze);
        temp[row][col]=0;
       maze[row][col]=1;
   }


   // Left  i,j-1

      if(col-1>=0 && maze[row][col-1]==1)
   {
       temp[row][col]=1;
       maze[row][col]=2;

       solve(row,col-1,ans,temp,maze);
        temp[row][col]=0;
       maze[row][col]=1;
   }
   // Right  i,j+1
     if(col+1<n && maze[row][col+1]==1)
   {
       temp[row][col]=1;
       maze[row][col]=2;

       solve(row,col+1,ans,temp,maze);
        temp[row][col]=0;
       maze[row][col]=1;
   }

  
 }
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n)
{
  // Write your code here.
  vector<vector<int>> ans;
  vector<vector<int>>temp(n,vector<int>(n,0));
 
   solve(0,0,ans,temp,maze);
  return ans;

}
