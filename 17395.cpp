#include <iostream>
#include <vector>

using namespace std;

void solve(long long x, unsigned n){
	vector<int> ones;
	int cnt = 0;
	long long y = x;
	while(y > 0){
		if(y % 2 == 1){
			ones.push_back(cnt);
		}
		y /= 2;
		++cnt;
	}
	if(ones.size() < n){
		cout << -1;
		return;
	}
	unsigned i = 0;
	for(; i + n <= ones.size(); ++i){
		x -= 1LL << ones[i];
	}
	cout << x << ' ';
	for(; i < ones.size(); ++i){
		x -= 1LL << ones[i];
		cout << x << ' ';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long x0;
	unsigned n;
	cin >> x0 >> n;
	solve(x0, n);
	return 0;
}
