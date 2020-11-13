#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<char, int> values = {{'A', 4}, {'K', 3}, {'Q', 2}, {'J', 1}, {'X', 0}};
	int n;
	cin >> n;
	int score = 0;
	for(int i = 0; i < n; ++i){
		string hand;
		cin >> hand;
		for(char card : hand){
			score += values[card];
		}
	}
	cout << score;
	return 0;
}
