#include <iostream>
#include <vector>
#include <algorithm>
#define MAXITEMS 3403
#define MAXRATING 12881

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> w(MAXITEMS), d(MAXITEMS);
	for(int i = 1; i <= n; ++i){
		cin >> w[i] >> d[i];
	}
	vector<int> prev(MAXRATING), cur(MAXRATING);
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= m; ++j){
			cur[j] = prev[j];
			if(j >= w[i]){
				cur[j] = max(cur[j], prev[j - w[i]] + d[i]);
			}
		}
		prev = cur;
	}
	cout << cur[m];
	return 0;
}
