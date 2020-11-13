#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string x;
	cin >> x;
	if(next_permutation(x.begin(), x.end())){
		cout << x;
	}else{
		cout << 0;
	}
	return 0;
}
