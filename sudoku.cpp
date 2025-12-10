#include<bits/stdc++.h>
using namespace std;
bool safe(vector<vector<int>> &arr,int row,int col,int val)
{
    bool  presentrow=false,presentcol=false,presentbox=false;
   for(int j=0;j<9;j++)
        {
           if(arr[row-1][j]==val)
           {
            return false;
           }
        }
        ///checking colums
        for(int j=0;j<9;j++)
        {
            if(arr[j][col-1]==val)
            {
              return false;
            }
        }
        //checking 3x3 boxes
        int c,r;
        c=((col-1)/3)*3;
        r=((row-1)/3)*3;
        int c1=0,c2=0;
        for(int j=r;c1<3;j++)
        {
            for(int k=c;c2<3;k++)
            {
                if(arr[j][k]==val)
                {
                   return false;
                }
                c2++;
            }
            c2=0;
            c1++;
        }
        return true;
}
bool solve(vector<vector<int>> &arr)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr[i][j]==0)
            {
                for(int k=1;k<=9;k++)
                {
                    if(safe(arr,i+1,j+1,k))
                    {
                             arr[i][j]=k;
                            if(solve(arr))return true;
                            arr[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<vector<int>>sudoku(9,vector<int>(9));
    cout<<"ENTER SUDOKU :"<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>sudoku[i][j];
        }
    }
    cout<<"\n"<<"ANSWER :"<<"\n";
    if(solve(sudoku))
    {
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}
}