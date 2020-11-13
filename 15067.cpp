#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool prime(int n){
	if(n == 0 || n == 1){
		return false;
	}
	for(int p = 2; p * p <= n; ++p){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string letters;
		int num;
		cin >> letters >> num;
		if(letters == "END" && num == 0){
			break;
		}
		while(!prime(num)){
			++num;
			if(num == 10000){
				num = 0;
				if(letters[2] == 'Z' && letters[1] == 'Z'){
					++letters[0];
					letters[1] = 'A';
					letters[2] = 'A';
				}else if(letters[2] == 'Z'){
					++letters[1];
					letters[2] = 'A';
				}else{
					++letters[2];
				}
			}
		}
		cout << letters << ' ' << setfill('0') << setw(4) << num << '\n';
	}
	return 0;
}
