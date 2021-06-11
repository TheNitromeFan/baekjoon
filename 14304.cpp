#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int price(vector<int> &a, vector<int> &b, vector<int> &p, int m, int l, vector<int> &select){
	int low = 0, high = 0, cost = 0;
	for(int idx : select){
		low += a[idx];
		high += b[idx];
		cost += p[idx];
	}
	if(cost <= m && l >= low && l <= high){
		return cost;
	}else{
		return -1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n, m, l;
		cin >> n >> m >> l;
		vector<int> a(n), b(n), p(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i] >> b[i] >> p[i];
		}
		int ans = -1;
		for(int x = 1; x < (1 << n); ++x){
			int y = x;
			vector<int> select;
			for(int i = 0; i < n; ++i){
				if(y % 2 == 1){
					select.push_back(i);
				}
				y /= 2;
			}
			int cost = price(a, b, p, m, l, select);
			if(cost != -1 && (ans == -1 || ans > cost)){
				ans = cost;
			}
		}
		cout << "Case #" << a0 << ": ";
		if(ans != -1){
			cout << ans << "\n";
		}else{
			cout << "IMPOSSIBLE\n";
		}
	}
	return 0;
}
