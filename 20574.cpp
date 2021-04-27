#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	char c;
	int r;
	cin >> a >> b >> c >> r;
	if(a < b){
		swap(a, b);
	}
	vector<pair<char, int>> squares;
	for(char col = 'a'; col <= 'h'; ++col){
		for(int row = 1; row <= 8; ++row){
			if((abs(col - c) == a && abs(row - r) == b) || (abs(col - c) == b && abs(row - r) == a)){
				squares.push_back(make_pair(col, row));
			}
		}
	}
	cout << squares.size() << '\n';
	for(pair<char, int> square : squares){
		cout << square.first << square.second << ' ';
	}
	return 0;
}
