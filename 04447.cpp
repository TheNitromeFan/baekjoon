#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string line;
	getline(cin, line);
	for(int i = 0; i < n; ++i){
		getline(cin, line);
		int g = 0, b = 0;
		for(char c : line){
			if(c == 'G' || c == 'g'){
				++g;
			}else if(c == 'B' || c == 'b'){
				++b;
			}
		}
		cout << line << " is ";
		if(g > b){
			cout << "GOOD\n";
		}else if(g < b){
			cout << "A BADDY\n";
		}else{
			cout << "NEUTRAL\n";
		}
	}
	return 0;
}
