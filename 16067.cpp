#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

void monsters(vector<pair<int, int>> &m, int n, vector<int> &fibs){
	int i = 0, j = 1;
	for(unsigned k = 0; k + 1 < fibs.size(); ++k){
		while(i < n && m[i].first < fibs[k]){
			++i;
		}
		while(j < n && m[j].first < fibs[k + 1]){
			++j;
		}
		if(m[i].first == fibs[k] && m[j].first == fibs[k + 1]){
			cout << m[i].second << " " << m[j].second;
			return;
		}
	}
	cout << "impossible";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> fibs = {1, 1};
	while(fibs.back() <= 10000000){
		fibs.push_back(fibs[fibs.size() - 2] + fibs.back());
	}
	int n;
	cin >> n;
	vector<pair<int, int>> m(n);
	for(int i = 0; i < n; ++i){
		cin >> m[i].first;
		m[i].second = i + 1;
	}
	sort(m.begin(), m.end());
	monsters(m, n, fibs);
	return 0;
}
