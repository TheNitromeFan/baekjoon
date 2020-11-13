#include <iostream>
#include <string>

using namespace std;

int main(){
	while(true){
		string s;
		getline(cin, s);
		if(s == "START" || s == "END"){
			continue;
		}
		if(s == "ENDOFINPUT"){
			break;
		}
		for(int i = 0; i < s.length(); ++i){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				s[i] -= 5;
				if(s[i] < 'A'){
					s[i] += 26;
				}
			}
			cout << s[i];
		}
		cout << '\n';
	}
	return 0;
}
