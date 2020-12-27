#include <iostream>
#include <vector>

using namespace std;

void feed(vector<int> &v, int n, int limit, int idx, int cur, int &ans){
	if(idx == n){
		if(ans < cur){
			ans = cur;
		}
		return;
	}
	feed(v, n, limit, idx + 1, cur, ans);
	if(cur + v[idx] <= limit){
		feed(v, n, limit, idx + 1, cur + v[idx], ans);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, b;
	cin >> c >> b;
	vector<int> v(b);
	for(int i = 0; i < b; ++i){
		cin >> v[i];
	}
	int ans = 0;
	feed(v, b, c, 0, 0, ans);
	cout << ans;
	return 0;
}
