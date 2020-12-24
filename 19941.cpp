#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<bool> eaten(n);
	for(int i = 0; i < n; ++i){
		if(s[i] == 'H'){
			continue;
		}
		for(int j = max(0, i - k); j <= min(n - 1, i + k); ++j){
			if(s[j] == 'H' && !eaten[j]){
				eaten[j] = true;
				break;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		if(eaten[i]){
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
