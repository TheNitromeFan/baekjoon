#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

int dp[21][21][21][21];

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int h,w; cin >> h >> w;
	vector<string> s(h);
	for(int i=0;i<h;i++){
		cin >> s[i];
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<h;j++){
			for(int k=0;k<w;k++){
				for(int l=0;l<w;l++){
					dp[i][j][k][l]=-1;
				}
			}
		}
	}
	auto solve=[&](auto solve,int x,int xx,int y,int yy)->int{
		if(x>xx or y>yy)return 0;
		if(dp[x][xx][y][yy]>=0)return dp[x][xx][y][yy];
		set<int> st;
		for(int i=x;i<=xx;i++){
			for(int j=y;j<=yy;j++){
				if(s[i][j]=='.'){
					st.insert(solve(solve,x,i-1,y,j-1)^solve(solve,x,i-1,j+1,yy)^solve(solve,i+1,xx,y,j-1)^solve(solve,i+1,xx,j+1,yy));
				}
			}
		}
		int mex=0;
		while(st.find(mex)!=st.end())mex++;
		dp[x][xx][y][yy]=mex;
		return mex;
	};
	if(solve(solve,0,h-1,0,w-1)){
		printf("First\n");
	}
	else{
		printf("Second\n");
	}
}
