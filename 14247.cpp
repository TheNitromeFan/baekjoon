#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> trees(n);
	for(int i = 0; i < n; ++i){
		cin >> trees[i].first;
	}
	for(int i = 0; i < n; ++i){
		cin >> trees[i].second;
	}
	sort(trees.begin(), trees.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second;
	});
	long long wood = 0;
	for(int i = 0; i < n; ++i){
		wood += trees[i].first + trees[i].second * i;
	}
	cout << wood;
	return 0;
}
