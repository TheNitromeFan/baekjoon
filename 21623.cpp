#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, n;
	cin >> k >> n;
	int score = n, rounds = 0;
	int rng;
	for(int i = 1; i < k; ++i){
		cin >> rng;
		if(rng <= score){
			score -= rng;
			if(score == 0){
				++rounds;
				score = n;
			}
		}
	}
	cin >> rng;
	if(rng <= score){
		score -= rng;
		if(score == 0){
			++rounds;
		}
	}
	cout << rounds << '\n' << score;
	return 0;
}
