#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	if(n > 1){
		cout << (n + 1) / 2;
	}else{
		cout << 0;
	}
	return 0;
}
