#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	char letter = 'A';
	int number = 0;
	for(int i = 0; i < a; ++i){
		cout << letter;
		++letter;
		if(letter > 'Z'){
			letter -= 26;
		}
	}
	letter += 'a' - 'A';
	for(int j = 0; j < b; ++j){
		cout << letter;
		++letter;
		if(letter > 'z'){
			letter -= 26;
		}
	}
	for(int k = 0; k < n - a - b; ++k){
		cout << number;
		++number;
		if(number > 9){
			number -= 10;
		}
	}
	return 0;
}
