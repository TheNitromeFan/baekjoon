#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string dir = "left";
	while(true){
		string s;
		cin >> s;
		if(s == "99999"){
			break;
		}
		int a = s[0] - '0', b = s[1] - '0';
		if((a + b) % 2 == 1){
			dir = "left";
		}else if(a + b != 0){
			dir = "right";
		}
		cout << dir << ' ' << s.substr(2, 3) << '\n';
	}
	return 0;
}
