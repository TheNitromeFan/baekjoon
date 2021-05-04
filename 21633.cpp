#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	double fee = 0.01 * k + 25;
	if(fee < 100){
		fee = 100;
	}
	if(fee > 2000){
		fee = 2000;
	}
	cout << fixed << setprecision(2) << fee;
	return 0;
}
