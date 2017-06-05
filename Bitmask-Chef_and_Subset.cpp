#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios:: sync_with_stdio(false), cin.tie(NULL)

bool fun(vector<int> a){
	int n=a.size();
	for(int i=1;i<=(1<<n);i++){
		int s=0;
		for(int j=1;j<=n;j++) 
			if((i&(1<<j))!=0) s+=a[j-1];
		if(s==0) return true;
	}
	return false;
}

int main(){
	fast_io;
	int t; cin>>t;
	while(t--){
		vector<int> a(4,0);
		for(int i=0;i<4;i++) cin>>a[i];
		if(fun(a)) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}