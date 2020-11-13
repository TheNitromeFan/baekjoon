#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string t;
	cin >> t;
	int key = 0;
	for(; key < (1 << 7); ++key){
		if((t[0] ^ key) == 'C'){
			break;
		}
	}
	for(char c : t){
		cout << static_cast<char>(c ^ key);
	}
	return 0;
}
