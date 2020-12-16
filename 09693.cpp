#include <iostream>

using namespace std;

int sifar(int n){
	int ret = 0;
	while(n > 0){
		ret += n / 5;
		n /= 5;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		++t;
		cout << "Case #" << t << ": " << sifar(n) << "\n";
	}
	return 0;
}
