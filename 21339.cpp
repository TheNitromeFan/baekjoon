#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, d, s;
	cin >> n >> k >> d >> s;
	double avg = (n * d - k * s) / (double)(n - k);
	if(avg >= 0 && avg <= 100){
		cout << fixed << setprecision(12) << avg;
	}else{
		cout << "impossible";
	}
	return 0;
}
