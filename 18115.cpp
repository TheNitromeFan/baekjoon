#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> moves(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> moves[i];
	}
	reverse(moves.begin() + 1, moves.end());
	deque<int> deck;
 	for(int i = 1; i <= n; ++i){
		if(moves[i] == 1){
			deck.push_front(i);
		}else if(moves[i] == 3){
			deck.push_back(i);
		}else{
			int card = deck.front();
			deck.pop_front();
			deck.push_front(i);
			deck.push_front(card);
		}
	}
	while(!deck.empty()){
		cout << deck.front() << ' ';
		deck.pop_front();
	}
	return 0;
}
