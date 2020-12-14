#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	string word;
	cin >> word;
	vector<string> blurred(m);
	for(int i = 0; i < m; ++i){
		cin >> blurred[i];
		sort(blurred[i].begin(), blurred[i].end());
	}
	reverse(blurred.begin(), blurred.end());
	vector<unsigned> positions;
	for(unsigned idx = 0; idx < word.length(); ++idx){
		if(word[idx] == '#'){
			positions.push_back(idx);
		}
	}
	reverse(positions.begin(), positions.end());
	--x;
	for(int i = 0; i < m; ++i){
		word[positions[i]] = blurred[i][x % k];
		x /= k;
	}
	cout << word;
	return 0;
}
