#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int scenario = 0;
	while(true){
		++scenario;
		int n, d;
		cin >> n >> d;
		if(n == 0 && d == 0){
			break;
		}
		int rb, rc;
		cin >> rb >> rc;
		cout << "Scenario " << scenario << '\n';
		for(int day = 1; day <= d; ++day){
			int b, c;
			cin >> b >> c;
			if(rb != 0 && b >= rb){
				++b;
			}
			if(rc != 0 && c >= rc){
				++c;
			}
			cout << "Day " << day << ' ' << (b + c == n + 1 ? "ALERT" : "OK") << '\n';
		}
	}
	return 0;
}
