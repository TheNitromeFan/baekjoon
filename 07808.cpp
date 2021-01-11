#include <iostream>
#include <algorithm>
#define MAX 1002

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	string message;
	while(getline(cin, message)){
		unsigned k;
		cin >> k;
		int a[MAX];
		for(unsigned i = 0; i < k; ++i){
			cin >> a[i];
		}
		unsigned col[MAX];
		for(unsigned i = 0; i < k; ++i){
			col[i] = i;
		}
		char grid[MAX][MAX] = {};
		for(unsigned j = 0; j < message.length(); ++j){
			grid[j / k][j % k] = message[j];
		}
		sort(col, col + k, [&a](unsigned x, unsigned y){
			return a[x] < a[y];
		});
		for(unsigned i = 0; i < k; ++i){
			for(unsigned j = 0; grid[j][col[i]] != 0; ++j){
				cout << grid[j][col[i]];
			}
		}
		cout << '\n';
		getline(cin, message);
	}
	return 0;
}
