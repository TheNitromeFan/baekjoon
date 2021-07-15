#include <iostream>
#include <cstring>
#define MAX 1002

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, k;
		cin >> n >> k;
		if(n == 0 && k == 0){
			break;
		}
		int a[MAX], p[MAX];
		memset(a, -1, sizeof(a));
		memset(p, -1, sizeof(p));
		int node_cnt = -1, idx = -1;
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
			if(a[i] == k){
				idx = i;
			}
			if(a[i] > a[i - 1] + 1){
				++node_cnt;
			}
			p[i] = node_cnt;
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i){
			if(p[i] != p[idx] && p[p[i]] == p[p[idx]]){
				++ans;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
