#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	unordered_map<int, int> idx;
	for(int i = 0; i < n; ++i){
		cin >> v[i];
		idx[v[i]] = i;
	}
	vector<bool> found(n);
	found[0] = true;
	int ans = 0, cnt = 0;
	for(int i = 1; i < n; ++i){
		if(found[i]){
			continue;
		}
		++ans;
		int d = v[i] - 1;
		for(int x = v[i]; x <= v[n - 1]; x += d){
			int j = idx[x];
			if(!found[j]){
				found[j] = true;
				++cnt;
			}
		}
		if(cnt == n - 1){
			break;
		}
	}
	cout << ans;
	return 0;
}
