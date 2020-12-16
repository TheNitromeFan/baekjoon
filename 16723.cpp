#include <iostream>

using namespace std;

long long souvenirs(int n){
	if(n == 0){
		return 0;
	}
	return 2 * ((n + 1) / 2) + 2 * souvenirs(n / 2);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << souvenirs(n);
	return 0;
}
