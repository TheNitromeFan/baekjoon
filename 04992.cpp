#include <iostream>
#include <stack>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, r;
		cin >> n >> r;
		if(n == 0 && r == 0){
			break;
		}
		stack<int> deck;
		for(int i = 1; i <= n; ++i){
			deck.push(i);
		}
		for(int a0 = 0; a0 < r; ++a0){
			int p, c;
			cin >> p >> c;
			stack<int> deck1, deck2;
			for(int a1 = 1; a1 < p; ++a1){
				deck1.push(deck.top());
				deck.pop();
			}
			for(int a2 = 0; a2 < c; ++a2){
				deck2.push(deck.top());
				deck.pop();
			}
			for(int a1 = 1; a1 < p; ++a1){
				deck.push(deck1.top());
				deck1.pop();
			}
			for(int a2 = 0; a2 < c; ++a2){
				deck.push(deck2.top());
				deck2.pop();
			}
		}
		cout << deck.top() << '\n';
	}
	return 0;
}
