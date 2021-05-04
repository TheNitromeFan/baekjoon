#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> g(n);
	for(int i = 0; i < n; ++i){
		cin >> g[i];
	}
	sort(g.begin(), g.end(), greater<int>());
	int score = 0;
	for(int j = 0; j < k; ++j){
		score += g[j];
	}
	cout << score;
	return 0;
}
