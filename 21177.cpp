#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> cards(n);
	for(int i = 0; i < n; ++i){
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());
	int idx = 0;
	long long points = 0;
	while(idx < n){
		int start = idx;
		while(idx < n && cards[idx] == cards[start] + (idx - start)){
			++idx;
		}
		points += cards[start];
	}
	cout << points;
	return 0;
}
