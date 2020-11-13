#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

unsigned factorial(unsigned x){
	if(x == 0){
		return 1;
	}else{
		return x * factorial(x - 1);
	}
}

int main(){
	string str;
	unsigned n;
	while(cin >> str >> n){
		cout << str << ' ' << n << " = ";
		if(n > factorial(str.length())){
			cout << "No permutation\n";
			continue;
		}
		unsigned i = 1;
		while(i < n){
			next_permutation(str.begin(), str.end());
			++i;
		}
		cout << str << '\n';
	}
	return 0;
}
