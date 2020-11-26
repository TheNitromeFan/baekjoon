#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ruminant(vector<int> &v, vector<int> &w, int c, int pos){
	vector<int> v1(c);
	copy(v.begin() + pos, v.begin() + pos + c, v1.begin());
	sort(v1.begin(), v1.end());
	for(int i = 0; i < c; ++i){
		if(w[i] - v1[i] != w[0] - v1[0]){
			return false;
		}
	}
	return true;
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
	int c;
	cin >> c;
	vector<int> w(c);
	for(int j = 0; j < c; ++j){
		cin >> w[j];
	}
	sort(w.begin(), w.end());
	vector<int> ans;
	for(int i = 0; i + c <= n; ++i){
		if(ruminant(v, w, c, i)){
			ans.push_back(i + 1);
		}
	}
	cout << ans.size();
	for(int x : ans){
		cout << '\n' << x;
	}
	return 0;
}
