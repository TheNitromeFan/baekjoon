#include <iostream>
#include <string>

using namespace std;

bool valid(string &s){
	unsigned n = s.length();
	if(!(s[0] == '1' && s[n - 1] == '2')){
		return false;
	}
	for(unsigned i = 0; i + 1 < n; ++i){
		if(!((s[i] == '1' && s[i + 1] == '4') || (s[i] == '1' && s[i + 1] == '5')
		|| (s[i] == '3' && s[i + 1] == '4') || (s[i] == '3' && s[i + 1] == '5')
		|| (s[i] == '4' && s[i + 1] == '2') || (s[i] == '4' && s[i + 1] == '3')
		|| (s[i] == '5' && s[i + 1] == '8')
		|| (s[i] == '6' && s[i + 1] == '2') || (s[i] == '6' && s[i + 1] == '3')
		|| (s[i] == '7' && s[i + 1] == '8')
		|| (s[i] == '8' && s[i + 1] == '6') || (s[i] == '8' && s[i + 1] == '7'))){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while(true){
		string pieces;
		cin >> pieces;
		if(pieces == "0"){
			break;
		}
		++t;
		cout << t << ". " << (valid(pieces) ? "VALID" : "NOT") << "\n";
	}
	return 0;
}
