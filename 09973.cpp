#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string s;
		cin >> s;
		if(s == "ENDOFINPUT"){
			break;
		}
		int x, y, z;
		cin >> x >> y >> z >> s;
		z = min(z, 360 - z);
		if(5 * y >= 2 * PI * x * z / 360 * 2){
			cout << "YES " << (int)(y - 2 * PI * x * z / 360 * 2 / 5);
		}else{
			cout << "NO " << 5 * y;
		}
		cout << "\n";
	}
	return 0;
}
