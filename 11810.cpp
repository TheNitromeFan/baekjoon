#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	vector<int> cnt(26);
	int prev = 0;
	bool cw = true;
	int pos = 25;
	for(int a0 = 0; a0 < q; ++a0){
		string op;
		int n;
		cin >> op >> n;
		int diff = n - prev;
		int quot = diff / 26, rem = diff % 26;
		for(int i = 0; i < 26; ++i){
			cnt[i] += quot;
		}
		for(int j = 0; j < rem; ++j){
			if(cw){
				pos = (pos + 1) % 26;
			}else{
				pos = (pos + 25) % 26;
			}
			++cnt[pos];
		}
		if(op == "UPIT"){
			char letter;
			cin >> letter;
			cout << cnt[letter - 'a'] << "\n";
		}else{
			cw = !cw;
		}
		prev = n;
	}
	return 0;
}
