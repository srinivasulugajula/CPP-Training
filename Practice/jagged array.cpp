#include<bits/stdc++.h>
using namespace std;
int main(){
    int rows=3;
    int*jaggedarray[rows];
    jaggedarray[0]=new int[2];
    jaggedarray[1]=new int[5];
    jaggedarray[2]=new int[3];
    for(int i=0;i<rows;i++){
        for(int j=0;j<(i==0?2:i==1?5:3);j++){
            jaggedarray[i][j]=i*j+1;
        }
    }
    cout<<"jaggedarray is"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<(i==0?2:i==1?5:3);j++){
            cout<<jaggedarray[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<rows;i++){
    delete[] jaggedarray[i];
    }
    return 0;

}


