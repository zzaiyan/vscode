#include<bits/stdc++.h>
using namespace std;

int N,L,arr[10005];

bool check(int h){
	int i=0;
	while(++i){
		if(arr[i]>=h||i>=h)break;
	}
	int sum=0;
	for(int m=1;m<i;m++)sum+=h-arr[m];
	
	return sum<=L;
	
}

int main(){
	cin>>N>>L;
	for(int i=1;i<=N;i++)scanf("%d",arr+i);
	sort(arr+1,arr+1+N);
	int lf=0,rf=N;
	while(lf<rf){
		int mid=lf+rf>>1;
		if(check(mid))lf=mid;
		else rf=mid-1;
	}
	cout<<lf;
	
	return 0;
}