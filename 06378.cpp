#include <iostream>
#include <string>

using namespace std;

string root(string s){
	int sum = 0;
	for(int i = 0; i < s.length(); ++i){
		sum += s[i] - '0';
	}
	return to_string(sum);
}

int main(){
	while(true){
		string s;
		cin >> s;
		if(s == "0"){
			break;
		}
		while(s.length() > 1){
			s = root(s);
		}
		cout << s << '\n';
	}
	return 0;
}
