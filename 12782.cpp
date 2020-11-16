#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		string n, m;
		cin >> n >> m;
		int a = 0, b = 0;
		for(unsigned j = 0; j < n.length(); ++j){
			if(n[j] == '0' && m[j] == '1'){
				++a;
			}else if(n[j] == '1' && m[j] == '0'){
				++b;
			}
		}
		cout << max(a, b) << '\n';
	}
	return 0;
}
