#include <iostream>
#include <vector>

using namespace std;

int coffee(vector<int> &scores){
	int sum = 0;
	vector<int> cmp = {100, 100, 200, 200, 300, 300, 400, 400, 500};
	for(int i = 0; i < 9; ++i){
		if(scores[i] > cmp[i]){
			return 2;
		}
		sum += scores[i];
	}
	return sum >= 100;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> scores(9);
	for(int i = 0; i < 9; ++i){
		cin >> scores[i];
	}
	int ans = coffee(scores);
	if(ans == 1){
		cout << "draw";
	}else if(ans == 2){
		cout << "hacker";
	}else{
		cout << "none";
	}
	return 0;
}
