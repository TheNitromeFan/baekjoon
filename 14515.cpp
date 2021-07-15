#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int white = 0, black = 0;
	for(char c : s){
		if(c == 'B'){
			++black;
		}else{
			++white;
		}
	}
	cout << (white == black) << '\n';
	return 0;
}
