#include<iostream>
#include<cmath>
using namespace std;
bool canPlace(int mat[][n],int i,int j,int n,int number)
{
    for(int x=0;x<n;x++){
        if(mat[i][x]==number or mat[x][j]==number){
            return false;
        }
    }
    int rn = sqrt(n);
    int subgrid_x = (i/rn)*rn;
    int subgrid_y = (j/rn)*rn;
    for(int x=subgrid_x;x<subgrid_x+rn;x++){
        for(int y=subgrid_y;y<subgrid_y+rn;y++){
            if(mat[x][y]==number){
                return false;
            }
        }
    }
    return true;
}
bool solvesudoku(int mat[][n],int i,int j,int n)
{
    //base case
    if(i==n){
        //print the solution
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //case row end
    if(j==n){
        solvesudoku(mat,i+1,0,n);
    }
    if(mat[i][j]!=0){
        return solvesudoku(mat,i,j+1,n);
    }
    //recursive case
    //fill the current cell with possible options
    for(int number =1;number<=n;number++){
        if(canPlace(mat,i,j,n,number)){
            mat[i][j] = number;
            bool couldwesolve = solvesudoku(mat,i,j+1,n);
            if(couldwesolve){
                return true;
            }
        }
    }
    //backtrack here
    mat[i][j] = 0;
    return false;
}
int main()
{
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
	    cin>>mat[i][j];
	}
    }
    solvesudoku(mat,0,0,n);
    return 0;
}
