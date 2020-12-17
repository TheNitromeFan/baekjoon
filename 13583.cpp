#include <iostream>

using namespace std;

int n(int a, int b, int c, int d){
	if(a % b == 0 || d % c == 0){
		return -1;
	}
	for(int i = a; i <= c; i += a){
		if(i % b != 0 && c % i == 0 && d % i != 0){
			return i;
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << n(a, b, c, d);
	return 0;
}
