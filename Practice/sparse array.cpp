// //sparsearray:it will store only the indces with non zero values
// #include<bits/stdc++.h>
// using namespace std;
// class Sparsearray{
//     private:
//     unordered_map<int,int>data;

//     public:
//     void add(int index,int value){
//         if(value!=0){
//             data[index]=value;
//         }
//         else{
//             data.erase(index);
//         }
        
//     }
//     void getdata(){
//         for(auto it:data){
//             cout<<it.first<<" "<<it.second<<endl;        
            
//         }
//     }
// };
// int main(){
//     Sparsearray array;
//     for(int i=0;i<10;i++){
//         array.add(i,i*i-i);
//     }
//     array.getdata();
//     array.add(2,0);
//     cout<<"after adding 0 to index already exist"<<endl;
//     array.getdata();

// }
//sparsearray with operator overloading
#include<bits/stdc++.h>
using namespace std;
class Sparsearray{
    private:
    unordered_map<int,int>data;

    public:
    void operator()(int index,int value){
        if(value!=0){
            data[index]=value;
        }
        else{
            data.erase(index);
        }
        
    }
    void getdata(){
        for(auto it:data){
            cout<<it.first<<" "<<it.second<<endl;        
            
        }
    }
};
int main(){
    Sparsearray array;
    for(int i=0;i<10;i++){
        array(i,i*i-i);
    }
    array.getdata();
    array(2,0);
    cout<<"after adding 0 to index already exist"<<endl;
    array.getdata();

}