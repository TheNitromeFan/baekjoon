#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

char letter(int n, int x, int y){
	int k = (x - n + 1) / (2 * n - 1);
	int l = (y - n + 1) / (2 * n - 1);
	int dist = min(abs(x - (n - 1 + (2 * n - 1) * k)), abs(x - (n - 1 + (2 * n - 1) * (k + 1))))
	+ min(abs(y - (n - 1 + (2 * n - 1) * l)), abs(y - (n - 1 + (2 * n - 1) * (l + 1))));
	if(dist >= n){
		return '.';
	}
	dist %= 26;
	return 'a' + dist;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, row1, col1, row2, col2;
	cin >> n >> row1 >> col1 >> row2 >> col2;
	for(int i = row1; i <= row2; ++i){
		for(int j = col1; j <= col2; ++j){
			cout << letter(n, i, j);
		}
		cout << '\n';
	}
	return 0;
}
