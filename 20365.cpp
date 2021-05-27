#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, b = 0, r = 0;
	char prev = s[0], change_b = 'B', change_r = 'R';
	for(char c : s){
		if(c != prev){
			++a;
			prev = c;
		}
		if(c == 'B'){
			if(change_b == 'B'){
				++b;
				change_b = 'R';
			}
			change_r = 'R';
		}else{
			if(change_r == 'R'){
				++r;
				change_r = 'B';
			}
			change_b = 'B';
		}
	}
	cout << min(a, min(b, r)) + 1;
	return 0;
}
