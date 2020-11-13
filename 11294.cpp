#include <iostream>
#include <string>

using namespace std;

string change_base(int n, int base){
	string ret;
	while(n){
		if(n % base <= 9){
			ret = to_string(n % base) + ret;
		}else{
			ret = "A" + ret;
			ret[0] += n % base - 10;
		}
		n /= base;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string animal;
		getline(cin, animal);
		if(animal == "#"){
			break;
		}
		int base, n;
		cin >> base >> n;
		cout << animal << ", " << n << ", " << change_base(n, base) << '\n';
		getline(cin, animal);
	}
	return 0;
}
