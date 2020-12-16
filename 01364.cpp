#include <iostream>
#define MAX 200001

using namespace std;

long long hexagons(int n){
	long long s[6][MAX]; // s[n % 6][n / 6]
	s[1][0] = 1;
	for(int i = 0; 6 * i <= n; ++i){
		s[2][i] = s[1][i] + i + 1;
		s[3][i] = s[2][i] + i + 1;
		s[4][i] = s[3][i] + i + 1;
		s[5][i] = s[4][i] + i + 1;
		s[0][i + 1] = s[5][i] + i + 2;
		s[1][i + 1] = s[0][i + 1] + i + 1;
	}
	return s[n % 6][n / 6];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	cout << hexagons(n);
	return 0;
}
