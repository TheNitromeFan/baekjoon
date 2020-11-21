#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int m, nmin, nmax;
		cin >> m >> nmin >> nmax;
		if(m == 0 && nmin == 0 && nmax == 0){
			break;
		}
		vector<int> p(m);
		for(int i = 0; i < m; ++i){
			cin >> p[i];
		}
		sort(p.begin(), p.end(), greater<int>());
		int gap = 0, n;
		for(int i = nmin; i <= nmax; ++i){
			if(gap <= p[i - 1] - p[i]){
				gap = p[i - 1] - p[i];
				n = i;
			}
		}
		cout << n << '\n';
	}
	return 0;
}
