#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> villages(n);
	for(int i = 0; i < n; ++i){
		cin >> villages[i];
	}
	sort(villages.begin(), villages.end());
	double minNeighborhood = 2000000000;
	for(int i = 1; i + 1 < n; ++i){
		double low = (villages[i] + villages[i - 1]) / 2.0;
		double high = (villages[i + 1] + villages[i]) / 2.0;
		double len = high - low;
		if(len < minNeighborhood){
			minNeighborhood = len;
		}
	}
	cout << fixed << setprecision(1) << minNeighborhood;
	return 0;
}
