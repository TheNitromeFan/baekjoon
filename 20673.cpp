#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p, q;
	cin >> p >> q;
	if(p <= 50 && q <= 10){
		cout << "White";
	}else if(q >= 30){
		cout << "Red";
	}else{
		cout << "Yellow";
	}
	return 0;
}
