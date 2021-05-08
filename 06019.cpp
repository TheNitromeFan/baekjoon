#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, e, n;
	cin >> k >> e >> n;
	vector<int> x(n), f(n), c(n);
	for(int i = 0; i < n; ++i){
		cin >> x[i] >> f[i] >> c[i];
	}
	vector<pair<int, int>> cexf(n);
	for(int i = 0; i < n; ++i){
		cexf[i].first = c[i] + e - x[i];
		cexf[i].second = f[i];
	}
	sort(cexf.begin(), cexf.end());
	long long cost = 0;
	for(int i = 0; i < n; ++i){
		if(k > cexf[i].second){
			cost += cexf[i].first * cexf[i].second;
			k -= cexf[i].second;
		}else{
			cost += cexf[i].first * k;
			break;
		}
	}
	cout << cost;
	return 0;
}
