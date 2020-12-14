#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string balanced_ternary(int n){
	if(n == 0){
		return "0";
	}
	string ret = "";
	while(n != 0){
		if((n > 0 && n % 3 == 0) || (n < 0 && -n % 3 == 0)){
			ret = "0" + ret;
		}else if((n > 0 && n % 3 == 1) || (n < 0 && -n % 3 == 2)){
			ret = "1" + ret;
			--n;
		}else{
			ret = "-" + ret;
			++n;
		}
		n /= 3;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		cout << balanced_ternary(n) << "\n";
	}
	return 0;
}
