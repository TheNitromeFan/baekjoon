#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	vector<int> cnt(n + 1);
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		++cnt[x];
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(cnt[i] > d){
			ans += (cnt[i] - d - 1) / (d - 1) + 1;
		}
	}
	cout << ans;
	return 0;
}
