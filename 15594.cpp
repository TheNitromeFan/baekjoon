#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int swaps(vector<int> &v, int n){
	vector<int> w = v;
	sort(w.begin(), w.end());
	vector<bool> stay(n);
	for(int i = 0; i < n; ++i){
		stay[i] = (w[i] == v[i]);
	}
	int idx = 0;
	int ans = 0;
	while(true){
		if(stay[idx]){
			++idx;
			continue;
		}
		int next = idx + 1;
		while(next < n && !(!stay[next] && w[next] == v[idx])){
			++next;
		}
		if(idx >= n || next >= n){
			break;
		}
		stay[next] = true;
		swap(v[idx], v[next]);
		++ans;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	cout << swaps(v, n);
	return 0;
}
