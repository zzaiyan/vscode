#include<bits/stdc++.h>
using namespace std;

template<typename T>
void Sort(T* A,int n,bool f){
    for(int i=0;i<n;++i){
        int p=i;
        for(int j=i+1;j<n;++j)
            if(!f^(A[j]<A[p]))p=j;
        swap(A[p],A[i]);
    }
}

template<typename T>
void check(T* A,int n){
    cout<<"原始数据：";
    for(int i=0;i<n;++i)cout<<A[i]<<' ';
    Sort(A,n,1);
    cout<<"\n递增排序：";
    for(int i=0;i<n;++i)cout<<A[i]<<' ';
    Sort(A,n,0);
    cout<<"\n递减排序：";
    for(int i=0;i<n;++i)cout<<A[i]<<' ';
    putchar('\n');
}

int main(){
    int arr[]={4,2,5,3,1};
    cout<<"--现在测试int数组--\n";
    check(arr,5);
    char str[]="bcaef";
    cout<<"\n--现在测试char数组--\n";
    check(str,5);
    double darr[]={2.5,-1.1,3.14,5.25,-2.123};
    cout<<"\n--现在测试double数组--\n";
    check(darr,5);
    return 0;
}