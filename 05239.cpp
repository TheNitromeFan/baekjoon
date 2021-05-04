#include <iostream>
#include <vector>

using namespace std;

bool safe(vector<int> &cols, vector<int> &rows, int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			if(cols[i] == cols[j] || rows[i] == rows[j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int rooks;
		cin >> rooks;
		vector<int> cols(rooks), rows(rooks);
		for(int i = 0; i < rooks; ++i){
			cin >> cols[i] >> rows[i];
		}
		cout << (safe(cols, rows, rooks) ? "SAFE" : "NOT SAFE") << '\n';
	}
	return 0;
}
