#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios:: sync_with_stdio(false), cin.tie(NULL)

void print_array(vector< vector<char> > a){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[0].size();j++) cout<<a[i][j];
		cout<<endl;
	}
}

int main(){
	fast_io;
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int x=0,y=0,c=0;
		bool flag=false;
		vector< string > a(2);
		vector< vector<int> > r(2, vector<int> (n,0));
		for(int i=0;i<2;i++) {
			/*for(int j=0;j<n;j++) {
				cin>>a[i][j];
				if(i==0 && a[i][j]=='*') x++;
				if(i==1 && a[i][j]=='*') y++;
			}*/
			cin>>a[i];
		}
		/*if(n==1){
			cout<<0<<endl;
			continue;
		}*/
		//if(x && y) c++, flag=true;
		int i=0,j=0;
		while(i<n && !(a[0][i]=='*' || a[1][i]=='*')) i++;
		if(!flag && a[0][i]=='*' && a[1][i]=='*'){
			c++;
			flag=true;
		}
		j=i+1;
		while(j<n){
			while(j<n && a[0][j]!='*' && a[1][j]!='*') j++;
			if(j>=n) break;
			c++;
			if(!flag && a[0][j]=='*' && a[1][j]=='*'){
				flag=true;
				c++;
			}
			i=j;
			j+=1;
		}
		cout<<c<<endl;
	}
	return 0;
}