#include<bits/stdc++.h>
using namespace std;
int main(){
    int row=2;
    int col=3;
    int depth=4;
    vector<vector<vector<int>>>vec(depth,vector<vector<int>>(row,vector<int>(col)));
    for(int i=0;i<depth;i++){
        for(int j=0;j<row;j++)
        {
            for(int k=0;k<col;k++)
            vec[i][j][k]=i*col+j+k;

           
        }
        cout<<endl;
    }
    cout<<"using range based for loop"<<endl;
    for(auto it1:vec){
        for(auto it2:it1){
            for(auto it3:it2){
                cout<<it3<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<"using iterator"<<endl;
    for(auto it1=vec.begin();it1!=vec.end();it1++){
        for(auto it2=it1->begin();it2!=it1->end();it2++){
            for(auto it3=it2->begin();it3!=it2->end();it3++){
             cout<<*it3<<" ";   
            }
            cout<<endl;
            
        }
        cout<<endl;
    }
}