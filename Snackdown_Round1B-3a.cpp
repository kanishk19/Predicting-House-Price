#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios:: sync_with_stdio(false), cin.tie(NULL)

int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<string> a(2);
		cin>>a[0]; cin>>a[1];
		vector<int> res(n,0);
		for(int i=0;i<n;i++){
			if(a[0][i]=='*' && a[1][i]=='*') res[i]=2;
			else if(a[0][i]=='*' || a[1][i]=='*') res[i]=1;
			else res[i]=0;
		}
		int c=-1;
		bool flag=false;
		for(int i=0;i<n;i++){
			if(res[i]==2 && !flag) {c++; flag=true;}
			if(res[i]==1 || res[i]==2) c++;
		}
		if(c==-1) cout<<0<<endl;
		else cout<<c<<endl;
	}
	return 0;
}