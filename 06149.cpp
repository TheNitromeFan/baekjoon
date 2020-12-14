#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, p;
	cin >> n >> k >> p;
	queue<int> deck;
	for(int i = 1; i <= k; ++i){
		deck.push(i);
	}
	vector<int> cards;
	while(true){
		for(int j = 1; j < n; ++j){
			deck.pop();
			for(int a0 = 0; a0 < p; ++a0){
				deck.push(deck.front());
				deck.pop();
			}
		}
		cards.push_back(deck.front());
		deck.pop();
		if(deck.empty()){
			break;
		}
		for(int a0 = 0; a0 < p; ++a0){
			deck.push(deck.front());
			deck.pop();
		}
	}
	sort(cards.begin(), cards.end());
	for(int card : cards){
		cout << card << '\n';
	}
	return 0;
}
