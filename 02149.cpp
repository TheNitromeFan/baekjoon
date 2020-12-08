#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string keyword, ciphertext;
	cin >> keyword >> ciphertext;
	unsigned m = keyword.length();
	vector<unsigned> col_order(m);
	for(unsigned i = 0; i < m; ++i){
		unsigned rank = 0;
		for(unsigned j = 0; j < m; ++j){
			if(keyword[j] < keyword[i] || (keyword[j] == keyword[i] && j < i)){
				++rank;
			}
		}
		col_order[rank] = i;
	}
	char c[1001][1001];
	unsigned n = ciphertext.length() / m;
	for(unsigned idx = 0; idx < ciphertext.length(); ++idx){
		c[idx % n][col_order[idx / n]] = ciphertext[idx];
	}
	for(unsigned i = 0; i < n; ++i){
		for(unsigned j = 0; j < m; ++j){
			cout << c[i][j];
		}
	}
	return 0;
}
