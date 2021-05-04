#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n, k;
	cin >> m >> n >> k;
	vector<double> p(k);
	for(int i = 0; i < k; ++i){
		cin >> p[i];
	}
	vector<double> pm(k + 1), pn(k + 1);
	double rolling_sum = 0;
	for(int i = 0; i < m; ++i){
		rolling_sum += p[i];
	}
	for(int i = m; i < k; ++i){
		pm[i] = rolling_sum / m;
		rolling_sum += p[i] - p[i - m];
	}
	pm[k] = rolling_sum / m;
	rolling_sum = 0;
	for(int i = 0; i < n; ++i){
		rolling_sum += p[i];
	}
	for(int i = n; i < k; ++i){
		pn[i] = rolling_sum / n;
		rolling_sum += p[i] - p[i - n];
	}
	pn[k] = rolling_sum / n;
	if(pm[n] > pn[n]){
		cout << "BUY ON DAY " << n << "\n";
	}else if(pm[n] < pn[n]){
		cout << "SELL ON DAY " << n << "\n";
	}
	for(int i = n + 1; i <= k; ++i){
		if(pm[i - 1] < pn[i - 1] && pm[i] > pn[i]){
			cout << "BUY ON DAY " << i << "\n";
		}else if(pm[i - 1] > pn[i - 1] && pm[i] < pn[i]){
			cout << "SELL ON DAY " << i << "\n";
		}
	}
	return 0;
}
