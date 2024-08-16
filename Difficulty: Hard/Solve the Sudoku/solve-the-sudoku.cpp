//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
      bool isOkk(int i,int j,int value,int grid[N][N]){
        for(int s=0;s<9;s++){
            if(grid[s][j]==value)
                return false;
            if(grid[i][s]==value)
                return false;
        }
        
        int l=(i/3)*3;
        int r=(j/3)*3;
        
       for(int s=l;s<l+3;s++){
           for(int t=r;t<r+3;t++){
               if(grid[s][t]==value)
                  return false;
           }
           
       }
    return true;    
        
    }
    
    
    
    bool fun(int grid[N][N]){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(grid[i][j]==0){
                    for(int value=1;value<=9;value++){
                        if(isOkk(i,j,value,grid)){
                            grid[i][j]=value;
                            if(fun(grid))
                                return true;
                            grid[i][j]=0;
                            
                        }
                        
                    }
                    
                    
                }
                if(grid[i][j]==0)
                    return false;
            }
            
        }
        return true;
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return fun(grid);
        
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
            
        }
        return;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends