#include <iostream>

using namespace std;

bool blackjack(int k){
	for(int d = 2; d * d <= 2 * k; ++d){
		if(2 * k % d == 0 && d % 2 != 2 * k / d % 2){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		cout << (blackjack(k) ? "Gazua" : "GoHanGang") << "\n";
	}
	return 0;
}
