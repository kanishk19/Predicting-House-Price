#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios :: sync_with_stdio(false), cin.tie(NULL)

void print_array(vector< vector<int> >a){
	for(int i=0;i<a.size();i++){
		for(int j=0; j<a[0].size();j++) cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

int fun(vector< vector<int> > &a, queue< pair<int,int> > q ){
	int n=a.size(), m=a[0].size();
	vector<vector<bool> > vis(n, vector<bool> (m,false));
	int l=q.size(),c,s=0;
	pair<int,int> p=q.front();
	int X=a[p.first][p.second];
	while(q.size()){
		c=0;
		while(l--){
			p=q.front();
			q.pop();
			int x=p.first; int y=p.second;
			if(x>0 && !vis[x-1][y] && a[x-1][y]!=X) {q.push(make_pair(x-1,y)); c++; a[x-1][y]=X; vis[x-1][y]=true;}
			if(y>0 && !vis[x][y-1] && a[x][y-1]!=X) {q.push(make_pair(x,y-1)); c++; a[x][y-1]=X; vis[x][y-1]=true;}
			if(x>0 && y>0 && !vis[x-1][y-1] && a[x-1][y-1]!=X) {q.push(make_pair(x-1,y-1)); c++; a[x-1][y-1]=X; vis[x-1][y-1]=true;}
			if(x<n-1 && !vis[x+1][y] && a[x+1][y]!=X) {q.push(make_pair(x+1,y)); c++; a[x+1][y]=X; vis[x+1][y]=true;}
			if(y<m-1 && !vis[x][y+1] && a[x][y+1]!=X) {q.push(make_pair(x,y+1)); c++; a[x][y+1]=X; vis[x][y+1]=true;}
			if(x<n-1 && y<m-1 && !vis[x+1][y+1] && a[x+1][y+1]!=X) {q.push(make_pair(x+1,y+1)); c++; a[x+1][y+1]=X; vis[x+1][y+1]=true;}
			if(x>0 && y<m-1 && !vis[x-1][y+1] && a[x-1][y+1]!=X) {q.push(make_pair(x-1,y+1)); c++; a[x-1][y+1]=X; vis[x-1][y+1]=true;}
			if(x<n-1 && y>0 && !vis[x+1][y-1] && a[x+1][y-1]!=X) {q.push(make_pair(x+1,y-1)); c++; a[x+1][y-1]=X; vis[x+1][y-1]=true;}
		}
		l=c;
		if(c>0) s++;
		//cout<<s<<"---"<<c<<"---"<<endl;
		//print_array(a);
	}
	return s;
}

int main(){
	fast_io;
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		vector< vector<int> > a(n, vector<int> (m));
		for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>a[i][j];
		int ma=a[0][0],x=0,y=0;
		//bool flag=false;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i][j]>ma){
					ma=a[i][j];
					//flag=true;
					x=i; y=j;
				}
		queue<pair<int, int> > q;
		for(int i=0;i<n;i++) for(int j=0;j<m;j++){
			if(a[i][j]==ma) q.push(make_pair(i,j));
		}
		//cout<<x<<" "<<y<<endl;
		//if(!flag) cout<<"0\n";
		cout<<fun(a,q)<<endl;
	}
	return 0;
}