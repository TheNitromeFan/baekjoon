#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string pass;
	long long k;
	cin >> pass >> k;
	--k;
	for(char &c : pass){
		if(c == '6'){
			c = '1';
		}else if(c == '7'){
			c = '2';
		}
	}
	reverse(pass.begin(), pass.end());
	for(char &c : pass){
		if(c == '0' || c == '3' || c == '4' || c == '5' || c == '8' || c == '9'){
			continue;
		}
		if((c == '1' || c == '6') && k % 2 == 0){
			c = '1';
		}else if(c == '1' || c == '6'){
			c = '6';
		}else if((c == '2' || c == '7') && k % 2 == 0){
			c = '2';
		}else{
			c = '7';
		}
		k /= 2;
	}
	reverse(pass.begin(), pass.end());
	if(k == 0){
		cout << pass;
	}else{
		cout << -1;
	}
	return 0;
}
