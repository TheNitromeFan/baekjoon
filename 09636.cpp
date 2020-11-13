#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		int x = 0, y = 0, q = 0;
		for(char c : s){
			switch(c){
				case 'R':
					++x;
					break;
				case 'L':
					--x;
					break;
				case 'U':
					++y;
					break;
				case 'D':
					--y;
					break;
				case '?':
					++q;
					break;
			}
		}
		printf("%d %d %d %d\n", x - q, y - q, x + q, y + q);
	}
	return 0;
}
