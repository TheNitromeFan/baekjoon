#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r;
	double s;
	while(cin >> r >> s){
		cout << (int)round(sqrt((r * (s + 0.16)) / 0.067)) << '\n';
	}
	return 0;
}
