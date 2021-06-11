#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	long long population = 0;
	for(int i = 0; i < n; ++i){
		int x, a;
		cin >> x >> a;
		population += a;
		v[i] = make_pair(x, a);
	}
	sort(v.begin(), v.end());
	long long psum = 0;
	for(int i = 0; i < n; ++i){
		psum += v[i].second;
		if(psum >= (population + 1) / 2){
			cout << v[i].first;
			break;
		}
	}
	return 0;
}
