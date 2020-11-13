#include <iostream>

using namespace std;

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if(b >= c){
		cout << -1;
		return 0;
	}
	int n = a / (c - b);
	cout << n+1;
	return 0;
}
