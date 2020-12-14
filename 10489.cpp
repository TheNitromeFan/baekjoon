#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> cards;
	for(int i = 0; i < n; ++i){
		int card;
		cin >> card;
		cards.push_back(card);
		while(cards.size() >= 2 && cards.back() % 2 == cards[cards.size() - 2] % 2){
			cards.pop_back();
			cards.pop_back();
		}
	}
	cout << cards.size();
	return 0;
}
