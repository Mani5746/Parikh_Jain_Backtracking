
bool is_safe(int row,int col,vector<vector<int>> &board)
{
    int n=board.size();
    int duprow=row,dupcol=col;
    while(duprow>=0&&dupcol>=0)
    {
        if(board[duprow][dupcol]==1) return false;
        duprow--; dupcol--;
    }

    // lower Diagonal
    duprow=row,dupcol=col;
    while(duprow<n&&dupcol>=0)
    {
        if(board[duprow][dupcol]==1) return false;
        duprow++; dupcol--;
    }

    // Left Side
    duprow=row,dupcol=col;
    while(dupcol>=0)
    {
         if(board[duprow][dupcol]==1) return false;
         dupcol--;
    }

    return true;

}
void solve(int col,vector<vector<int>> &temp,vector<vector<int>> &ans)
{
    int n=temp.size();

    if(col==n)
    {
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                v.push_back(temp[i][j]);
            }
            
        }
        ans.push_back(v);

        return;
    }

     for(int row=0;row<n;row++)
     {
         if(is_safe(row,col,temp))
         {
             temp[row][col]=1;
             solve(col+1,temp,ans);
              temp[row][col]=0;

         }
     }
}
vector<vector<int>> solveNQueens(int n)
 {
    // Write your code here.
   vector<vector<int>> ans;
    vector<vector<int>> temp (n,vector<int>(n,0));
 

    solve(0,temp,ans);
    return ans;
    
}
