#include <iostream>
#include <vector>

using namespace std;

int max_capacity(vector<int> &w, int n, int c, int pos){
	if(pos == n){
		return 0;
	}
	int ret = max_capacity(w, n, c, pos + 1);
	if(w[pos] <= c){
		int cmp = w[pos] + max_capacity(w, n, c - w[pos], pos + 1);
		if(ret < cmp){
			ret = cmp;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c, n;
	cin >> c >> n;
	vector<int> w(n);
	for(int i = 0; i < n; ++i){
		cin >> w[i];
	}
	cout << max_capacity(w, n, c, 0);
	return 0;
}
