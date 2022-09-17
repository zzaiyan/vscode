#include<bits/stdc++.h>
using namespace std;
#define MAXN 10005

int N,V,dp[MAXN],v[MAXN],w[MAXN];

int main(){
	cin>>N>>V;
	for(int i=1;i<=N;i++)
		scanf("%d%d",w+i,v+i);
	
	for (int i = 1; i <= N; ++i)
		for (int j = V; j >= w[i]; --j)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	
	printf("%d",dp[V]);
	return 0;
}