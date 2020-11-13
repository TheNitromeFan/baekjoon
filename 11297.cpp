#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int d, m, y;
		cin >> d >> m >> y;
		if(d == 0 && m == 0 && y == 0){
			break;
		}
		int shift = (d + m + y) % 25 + 1;
		string line;
		getline(cin, line);
		getline(cin, line);
		for(char c : line){
			if(c >= 'a' && c <= 'z'){
				char ans = c - shift;
				if(ans < 'a'){
					ans += 26;
				}
				cout << ans;
			}else{
				cout << c;
			}
		}
		cout << '\n';
	}
	return 0;
}
