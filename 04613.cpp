#include <iostream>
#include <string>

using namespace std;

unsigned code(char c){
	if(c == ' '){
		return 0;
	}else{
		return c - 'A' + 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string line;
		getline(cin, line);
		if(line == "#"){
			break;
		}
		unsigned ans = 0;
		for(unsigned idx = 0; idx < line.length(); ++idx){
			ans += (idx + 1) * code(line[idx]);
		}
		cout << ans << '\n';
	}
	return 0;
}
