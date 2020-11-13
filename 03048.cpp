#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n1, n2;
	cin >> n1 >> n2;
	string ants1, ants2;
	cin >> ants1 >> ants2;
	vector<pair<char, int>> ants;
	ants.resize(n1 + n2);
	reverse(ants1.begin(), ants1.end());
	for(int i = 0; i < n1; ++i){
		ants[i] = make_pair(ants1[i], 1);
	}
	for(int i = n1; i < n1 + n2; ++i){
		ants[i] = make_pair(ants2[i - n1], -1);
	}
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		vector<int> places_to_swap;
		for(int i = 0; i < n1 + n2 - 1; ++i){
			if(ants[i].second == 1 && ants[i + 1].second == -1){
				places_to_swap.push_back(i);
			}
		}
		for(int x : places_to_swap){
			swap(ants[x], ants[x + 1]);
		}
	}
	for(int i = 0; i < n1 + n2; ++i){
		cout << ants[i].first;
	}
	return 0;
}
