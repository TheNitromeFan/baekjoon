#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int a = 0;
	for(char c : s){
		if(c == 'A'){
			++a;
		}
	}
	int n = 1;
	while(n * (n + 1) / 2 <= a){
		++n;
	}
	cout << n - 1;
	return 0;
}
