#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int n = 5e8,t=10;
auto per=CLOCKS_PER_SEC;
void fun1(){
    for (int i=0;i<=n;i++)
        i&1;
}
void fun2(){
    for (int i=0;i<n;i++)
        i%2;
}
int main(){
    auto t1=clock();
    for (int i=0;i<t;++i)fun1();
    auto t2=clock();
    for (int i=0;i<t;++i)fun2();
    auto t3=clock();

    cout<<endl<<(t2-t1)/per<<" s\n"<<(t3-t2)/per<<" s\n";
    //for (ll i=0;i<n;i++)cout<<"\b\b\b\b\b"<<(double)clock()/per<<"ms";

    return 0;
}