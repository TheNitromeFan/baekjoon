#include <iostream>
#include <vector>

using namespace std;

void sum_of_two_squares(int s){
	vector<int> squares;
	for(int i = 0; i < 50; ++i){
		squares.push_back(i * i);
	}
	for(int i = 0; squares[i] <= s; ++i){
		for(int j = 0; j <= i; ++j){
			if(squares[j] + squares[i] == s){
				cout << 0 << ' ' << j << '\n' << i << ' ' << 0 << '\n'
				<< i + j << ' ' << i << '\n' << j << ' ' << i + j;
				return;
			}
		}
	}
	cout << "Impossible";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s;
	cin >> s;
	sum_of_two_squares(s);
	return 0;
}
