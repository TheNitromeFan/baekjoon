#include <iostream>
#include <string>

using namespace std;

int main(){
	string bullets;
	cin >> bullets;
	unsigned m = 0;
	for(char c : bullets){
		if(c == '1'){
			++m;
		}
	}
	unsigned n = bullets.length();
	bullets += bullets[0];
	int k = 0, l = 0;
	for(unsigned i = 0; i < n; ++i){
		if(bullets[i] == '0'){
			++k;
			if(bullets[i + 1] == '1'){
				++l;
			}
		}
	}
	if(m * k > l * n){
		cout << "SHOOT";
	}else if(m * k < l * n){
		cout << "ROTATE";
	}else{
		cout << "EQUAL";
	}
	return 0;
}
