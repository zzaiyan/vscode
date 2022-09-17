#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Sort{
    T* arr;
    int len;
public:
    Sort(T*a,int b):arr(a),len(b){}
    void QuickSort(){
        for(int i=0;i<len;++i){
            int p=i;
            for(int j=i+1;j<len;++j)
                if(arr[j]<arr[p])p=j;
            swap(arr[p],arr[i]);
        }
    }
    void show(){
        for(int i=0;i<len;++i){
            cout<<arr[i]<<' ';
            if(i==len-1)putchar('\n');
        }
    }
};

int main(){
    int arr[]={4,2,5,3,1};
    Sort<int> a(arr,5);
    cout<<"原始：";
    a.show();
    a.QuickSort();
    cout<<"排序：";
    a.show();
    return 0;
}