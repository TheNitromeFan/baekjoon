#include <iostream>
#include <algorithm>

using namespace std;

int calc(int n, int fr, int corners, int edges, int cc, int ec){
	int ret = 0;
	n -= fr;
	if(n > 0){
		ret += min(corners, n) * cc;
		n -= corners;
	}
	if(n > 0){
		ret += min(edges, n) * ec;
		n -= edges;
	}
	if(n > 0){
		ret += n * 4;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int r, c, n;
		cin >> r >> c >> n;
		int ans = 0;
		if(r == 1 || c == 1){
			int corner_cost = 1, edge_cost = 2;
			int fr = (r * c + 1) / 2;
			int corners = (r * c % 2 == 0);
			int edges = r * c / 2 - corners;
			ans = calc(n, fr, corners, edges, corner_cost, edge_cost);
		}else{
			int corner_cost = 2, edge_cost = 3;
			int fr = (r * c + 1) / 2;
			int corners = 2 * (r * c % 2 == 0);
			int edges = r * c % 2 == 0 ? r + c - 2 * corners : 2 * (r / 2) * (c / 2);
			ans = calc(n, fr, corners, edges, corner_cost, edge_cost);
			if(r * c % 2 == 1){
				fr = r * c / 2;
				corners = 4;
				edges = r + c + 2 - 2 * corners;
				ans = min(ans, calc(n, fr, corners, edges, corner_cost, edge_cost));
			}
		}
		cout << "Case #" << a0 << ": " << ans << "\n";
	}
	return 0;
}
