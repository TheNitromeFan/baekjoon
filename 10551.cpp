#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int ans[8] = {};
	for(char c : s){
		if(c == '1' || c == 'Q' || c == 'A' || c == 'Z'){
			++ans[0];
		}else if(c == '2' || c == 'W' || c == 'S' || c == 'X'){
			++ans[1];
		}else if(c == '3' || c == 'E' || c == 'D' || c == 'C'){
			++ans[2];
		}else if(c == '4' || c == 'R' || c == 'F' || c == 'V' || c == '5' || c == 'T' || c == 'G' || c == 'B'){
			++ans[3];
		}else if(c == '6' || c == 'Y' || c == 'H' || c == 'N' || c == '7' || c == 'U' || c == 'J' || c == 'M'){
			++ans[4];
		}else if(c == '8' || c == 'I' || c == 'K' || c == ','){
			++ans[5];
		}else if(c == '9' || c == 'O' || c == 'L' || c == '.'){
			++ans[6];
		}else{
			++ans[7];
		}
	}
	for(int i = 0; i < 8; ++i){
		cout << ans[i] << '\n';
	}
	return 0;
}
