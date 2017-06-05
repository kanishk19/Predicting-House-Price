#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios:: sync_with_stdio(false), cin.tie(NULL)

int main(){
	fast_io;
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		int a=0,b=0;
		for(int i=0;i<s.size();i++)
		if(s[i]=='s' && (i>0 && s[i-1]=='m')){
			s[i]='b';
			s[i-1]='o';
		}
		else if (s[i]=='s' && (i<s.size()-1 && s[i+1]=='m')) {
			s[i]='b';
			s[i+1]='o';
		}
		for(int i=0;i<s.size();i++)
			if(s[i]=='s') a++;
			else if(s[i]=='m' || s[i]=='o') b++;
		if(a>b) cout<<"snakes\n";
		else if(a==b) cout<<"tie\n";
		else cout<<"mongooses\n";
	}
	return 0;
}