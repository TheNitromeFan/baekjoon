#include <iostream>
#include <string>

using namespace std;

int main(){
	string format;
	cin >> format;
	int ans = 1;
	char prev = 'x';
	for(unsigned i = 0; i < format.length(); ++i){
		if(format[i] == prev){
			if(format[i] == 'd'){
				ans *= 9;
			}else{
				ans *= 25;
			}
		}else{
			if(format[i] == 'd'){
				ans *= 10;
			}else{
				ans *= 26;
			}
		}
		prev = format[i];
	}
	cout << ans;
	return 0;
}
