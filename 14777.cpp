#include <iostream>
#define MAX 401

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int p[MAX];
	for(int i = 1; i <= n; ++i){
		cin >> p[i];
	}
	int g[MAX][MAX];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			cin >> g[i][j];
		}
	}
	int f[MAX] = {};
	for(int i = 1; i <= n; ++i){
		if(g[1][i] <= p[i]){
			f[i] = 1;
		}
	}
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				if(i != j && p[i] + g[i][j] <= p[j] && f[j] <= f[i]){
					f[j] = f[i] + 1;
					flag = true;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		if(ans < f[i]){
			ans = f[i];
		}
	}
	cout << ans;
	return 0;
}
