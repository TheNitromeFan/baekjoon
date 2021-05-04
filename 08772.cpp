#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int z;
	cin >> z;
	for(int a0 = 0; a0 < z; ++a0){
		int n;
		string s;
		char t;
		cin >> n >> s >> t;
		int shift = (int)t - (int)s[0];
		if(shift < 0){
			shift += 26;
		}
		for(char c : s){
			int d = (int)c + shift;
			if(d > 'z'){
				d -= 26;
			}
			cout << (char)d;
		}
		cout << '\n';
	}
	return 0;
}
