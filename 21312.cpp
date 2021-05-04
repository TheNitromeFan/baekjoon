#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	int cocktail = 1;
	if(!(a % 2 == 0 && b % 2 == 0 && c % 2 == 0)){
		if(a % 2 == 1){
			cocktail *= a;
		}
		if(b % 2 == 1){
			cocktail *= b;
		}
		if(c % 2 == 1){
			cocktail *= c;
		}
	}else{
		cocktail = a * b * c;
	}
	cout << cocktail;
	return 0;
}
