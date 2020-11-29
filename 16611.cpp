#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	string plain, cipher;
	cin >> plain >> cipher;
	plain = string(m - n, ' ') + plain;
	string key = string(m, ' ');
	int idx = m - 1;
	while(idx >= 0){
		int val = cipher[idx] - plain[idx];
		if(val < 0){
			val += 26;
		}
		key[idx] = (char)(val + 'a');
		if(idx - n >= 0){
			plain[idx - n] = key[idx];
		}
		--idx;
	}
	cout << plain;
	return 0;
}
