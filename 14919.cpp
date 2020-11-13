#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

int main(){
	int m;
	cin >> m;
	string b;
	int ans[MAX] = {};
	while(cin >> b){
		long long num = 0, den = 1;
		bool decimal = false;
		for(char c : b){
			if(c == '.'){
				decimal = true;
				continue;
			}
			if(decimal){
				den *= 10;
			}
			num = 10 * num + (c - '0');
		}
		++ans[(num * m) / den];
	}
	for(int i = 0; i < m; ++i){
		cout << ans[i] << ' ';
	}
	return 0;
}
