#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string alphabet = "0A23456789TJQK";
	size_t a[10][10];
	for(int i = n - 1; i >= 0; --i){
		for(int j = 0; j < n; ++j){
			string card;
			cin >> card;
			a[i][j] = alphabet.find(card[0]);
		}
	}
	size_t psum[10][10] = {};
	psum[0][0] = a[0][0];
	for(int j = 1; j < n; ++j){
		psum[0][j] = psum[0][j - 1] + a[0][j];
	}
	for(int i = 1; i < n; ++i){
		psum[i][0] = psum[i - 1][0] + a[i][0];
	}
	for(int i = 1; i < n; ++i){
		for(int j = 1; j < n; ++j){
			psum[i][j] = max(psum[i - 1][j], psum[i][j - 1]) + a[i][j];
		}
	}
	cout << psum[n - 1][n - 1];
	return 0;
}
