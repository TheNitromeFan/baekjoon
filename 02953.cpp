#include <iostream>

using namespace std;

int main(){
	int max_index, max_score = 0;
	int scores[6] = {};
	int score;
	for(int i = 1; i <= 5; ++i){
		for(int j = 0; j < 4; ++j){
			cin >> score;
			scores[i] += score;
		}
		if(scores[i] > max_score){
			max_score = scores[i];
			max_index = i;
		}
	}
	cout << max_index << ' ' << max_score << endl;
}
