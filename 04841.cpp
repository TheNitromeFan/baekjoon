#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string seq;
		cin >> seq;
		int cnt = 1;
		char cur = seq[0];
		for(unsigned idx = 1; idx < seq.length(); ++idx){
			if(seq[idx] != cur){
				cout << cnt << cur;
				cnt = 1;
				cur = seq[idx];
			}else{
				++cnt;
			}
		}
		cout << cnt << cur << '\n';
	}
	return 0;
}
