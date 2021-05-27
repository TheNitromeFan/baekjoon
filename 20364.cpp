#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

long long blocked(long long x, unordered_set<long long> &estate){
	vector<long long> path;
	while(x > 0){
		path.push_back(x);
		x /= 2;
	}
	reverse(path.begin(), path.end());
	for(long long y : path){
		if(estate.find(y) != estate.end()){
			return y;
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	int q;
	cin >> n >> q;
	unordered_set<long long> estate;
	for(int i = 0; i < q; ++i){
		long long x;
		cin >> x;
		long long ans = blocked(x, estate);
		if(ans == 0){
			estate.insert(x);
		}
		cout << ans << '\n';
	}
	return 0;
}
