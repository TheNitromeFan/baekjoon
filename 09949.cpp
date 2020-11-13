#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	while(true){
		++cnt;
		char a, b;
		cin >> a >> b;
		if(a == '#' && b == '#'){
			break;
		}
		int n;
		cin >> n;
		string line;
		getline(cin, line);
		cout << "Case " << cnt << '\n';
		for(int i = 0; i < n; ++i){
			getline(cin, line);
			for(char c : line){
				if(c == a || c == b || c - 'A' + 'a' == a || c - 'A' + 'a' == b){
					cout << '_';
				}else{
					cout << c;
				}
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}
