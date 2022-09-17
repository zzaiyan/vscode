#include<bits/stdc++.h>
using namespace std;

int main(){
    double fnum=31.415916536;
    cout<<cout.width()<<endl;
    cout<<cout.precision()<<endl;
    cout<<fnum<<endl;
    cout.setf(ios::scientific);
    cout<<fnum<<endl;
    cout.setf(ios::fixed,ios::floatfield);
    cout<<fnum<<endl;
    cout.precision(9);
    cout.setf(ios::scientific,ios::floatfield);
    cout<<fnum<<endl;

    return 0;
}