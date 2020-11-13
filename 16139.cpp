#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin >> s;
	static int pre[200000][26] = {}; // pre[i][j]: # of times j appears up to ith index
	pre[0][s[0] - 'a'] = 1;
	for(unsigned i = 1; i < s.length(); ++i){
		for(int j = 0; j < 26; ++j){
			if(s[i] - 'a' == j){
				pre[i][j] = pre[i - 1][j] + 1;
			}else{
				pre[i][j] = pre[i - 1][j];
			}
		}
	}
	int q;
	cin >> q;
	for(int k = 0; k < q; ++k){
		char alpha;
		int l, r;
		cin >> alpha >> l >> r;
		if(l == 0){
			cout << pre[r][alpha - 'a'];
		}else{
			cout << pre[r][alpha - 'a'] - pre[l - 1][alpha - 'a'];
		}
		cout << '\n';
	}
	return 0;
}
