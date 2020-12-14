#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long t;
	cin >> n >> t;
	vector<long long> initial(n), final(n);
	for(int i = 0; i < n; ++i){
		long long vi;
		cin >> initial[i] >> vi;
		final[i] = initial[i] + vi * t;
	}
	long long red = initial.front();
	sort(initial.begin(), initial.end());
	sort(final.begin(), final.end());
	vector<long long>::iterator it = find(initial.begin(), initial.end(), red);
	cout << final[it - initial.begin()];
	return 0;
}
