#include<bits/stdc++.h>
using namespace std;


int main()
{
    int depth=3;
    int row=3;
    int col=4;
    
    int***arr=new int**[depth];
    for(int i=0;i<depth;i++){
        arr[i]=new int*[row];
        for(int j=0;j<row;j++){
            arr[i][j]=new int[col];
        }
    }
    for(int i=0;i<depth;i++){
        for(int j=0;j<row;j++){
            for(int k=0;k<col;k++){
                arr[i][j][k]=i*j*k+i+j+k;
                cout<<arr[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    for(int i=0;i<depth;i)

    return 0;
}