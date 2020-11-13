#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		string parens;
		int p = 0;
		for(int a1 = 0; a1 < n; ++a1){
			int x;
			cin >> x;
			while(p < x){
				parens += '(';
				++p;
			}
			parens += ')';
		}
		for(int i = 0; i < parens.length(); ++i){
			if(parens[i] == ')'){
				int ans = 1;
				int counter = 1;
				for(int j = i-1; j >= 0; --j){
					if(parens[j] == '('){
						--counter;
						if(counter == 0){
							break;
						}
					}else{
						++ans;
						++counter;
					}
				}
				cout << ans << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}
