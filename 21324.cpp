#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 2){
		double angle1, angle2;
		cin >> angle1 >> angle2;
		int val = 16 * (int)(angle1 / 22.5) + (int)(angle2 / 22.5);
		cout << (char)val;
	}
	return 0;
}
