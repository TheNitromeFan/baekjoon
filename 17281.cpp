#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51

using namespace std;

int simulate(vector<int> &order, int hit[][10], int innings){
	int score = 0;
	int inning = 1;
	bool base1 = false, base2 = false, base3 = false;
	int outs = 0;
	int idx = 0;
	while(true){
		int player = order[idx];
		if(hit[inning][player] == 1){
			if(base3){
				++score;
			}
			base3 = base2;
			base2 = base1;
			base1 = true;
		}else if(hit[inning][player] == 2){
			if(base3){
				++score;
			}
			if(base2){
				++score;
			}
			base3 = base1;
			base2 = true;
			base1 = false;
		}else if(hit[inning][player] == 3){
			if(base3){
				++score;
			}
			if(base2){
				++score;
			}
			if(base1){
				++score;
			}
			base3 = true;
			base2 = false;
			base1 = false;
		}else if(hit[inning][player] == 4){
			if(base3){
				++score;
			}
			if(base2){
				++score;
			}
			if(base1){
				++score;
			}
			++score;
			base3 = false;
			base2 = false;
			base1 = false;
		}else{
			++outs;
			if(outs == 3){
				++inning;
				base1 = false;
				base2 = false;
				base3 = false;
				outs = 0;
				if(inning > innings){
					break;
				}
			}
		}
		idx = (idx + 1) % 9;
	}
	return score;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int hit[MAX][10];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 9; ++j){
			cin >> hit[i][j];
		}
	}
	vector<int> players(8);
	for(int j = 0; j < 8; ++j){
		players[j] = j + 2;
	}
	int max_score = 0;
	do{
		vector<int> order = players;
		order.insert(order.begin() + 3, 1);
		max_score = max(max_score, simulate(order, hit, n));
	}while(next_permutation(players.begin(), players.end()));
	cout << max_score << '\n';
	return 0;
}
