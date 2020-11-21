#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		string n;
		cin >> n;
		string s = n;
		if(next_permutation(s.begin(), s.end())){
			cout << "Case #" << i << ": " << s << "\n";
		}else{
			unsigned nonzero_idx = n.length() - 1;
			while(n[nonzero_idx] == '0'){
				--nonzero_idx;
			}
			string t = n.substr(0, nonzero_idx) + string(n.length() - nonzero_idx, '0') + n[nonzero_idx];
			reverse(t.begin(), t.end());
			cout << "Case #" << i << ": " << t << "\n";
		}
	}
	return 0;
}
