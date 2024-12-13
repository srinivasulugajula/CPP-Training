#include<bits/stdc++.h>
using namespace std;
template <typename T>
class Myvector{
    private:
    T *arr;
    int current;
    int capacity;
    public:
    Myvector()
    {
        arr=new T[1];
        current=0;
        capacity=1;
    }
    void push_back(T data)
    {
        if(current==capacity)
        {
            T *temp=new T[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                temp[i]=arr[i];
            }
            delete[] arr;
            capacity=capacity*2;
            arr=temp;
        }
        arr[current]=data;
        current++;
    }
    void pop_back(){
        if(current>0)
        current--;
    }
    void display()
    {
        for(int i=0;i<=current;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
    int size()
    {
        return current+1;
    }
    int capasity()
    {
        return capacity;
    }
};
int main()
{
    Myvector<int> nums;
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    nums.push_back(40);
    nums.display();
    nums.pop_back();
    nums.pop_back();
    nums.display();
    
    cout<<"nums size is:"<<nums.size()<<endl;
    cout<<"nums.capacity:"<<nums.capasity()<<endl;
    return 0;
}