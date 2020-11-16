#include <iostream>
#include <string>

using namespace std;

bool pikachu(string s){
	unsigned i = 0;
	while(i < s.length()){
		if(i + 1 < s.length() && s[i] == 'p' && s[i + 1] == 'i'){
			i += 2;
		}else if(i + 1 < s.length() && s[i] == 'k' && s[i + 1] == 'a'){
			i += 2;
		}else if(i + 2 < s.length() && s[i] == 'c' && s[i + 1] == 'h' && s[i + 2] == 'u'){
			i += 3;
		}else{
			return false;
		}
	}
	return true;
}

int main(){
	string s;
	cin >> s;
	cout << (pikachu(s) ? "YES" : "NO");
	return 0;
}
