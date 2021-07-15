#include <iostream>

using namespace std;

int rbm(double r, double b, double m){
	double payment = b;
	int month = 1;
	for(; payment > 0 && month <= 1200; ++month){
		payment *= 1 + r / 100;
		payment = (int)(payment * 100 + 0.5 + 1e-8) / 100.0;
		payment -= m;
	}
	if(payment > 0){
		return -1;
	}
	return month;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		double r, b, m;
		cin >> r >> b >> m;
		int ans = rbm(r, b, m);
		if(ans != -1){
			cout << ans << '\n';
		}else{
			cout << "impossible\n";
		}
	}
	return 0;
}
