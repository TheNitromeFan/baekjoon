#include <iostream>

using namespace std;

int main(){
	int l, r;
	cin >> l >> r;
	long long powers_of_ten[15];
	long long power = 1LL;
	int i;
	for(i = 0; power <= l || power <= r; ++i){
		powers_of_ten[i] = power;
		power *= 10;
	}
	int eights = 0;
	--i;
	for(; i >= 0; --i){
		if(l / powers_of_ten[i] != r / powers_of_ten[i]){
	 		break;
		}else if((l / powers_of_ten[i]) % 10 == 8){
			++eights;
		}
	}
	cout << eights << endl;
	return 0;
}
