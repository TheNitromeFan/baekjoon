#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, q, m;
	cin >> n >> k >> q >> m;
	vector<bool> asleep(n + 3);
	for(int i = 0; i < k; ++i){
		int x;
		cin >> x;
		asleep[x] = true;
	}
	vector<bool> attend(n + 3);
	for(int j = 0; j < q; ++j){
		int x;
		cin >> x;
		if(asleep[x]){
			continue;
		}
  		for(int y = x; y <= n + 2; y += x){
			if(!asleep[y]){
				attend[y] = true;
			}
		}
	}
	vector<int> psum(n + 3);
	for(int y = 3; y <= n + 2; ++y){
		psum[y] = psum[y - 1];
		if(!attend[y]){
			++psum[y];
		}
	}
	for(int a0 = 0; a0 < m; ++a0){
		int s, e;
		cin >> s >> e;
		cout << psum[e] - psum[s - 1] << '\n';
	}
	return 0;
}
