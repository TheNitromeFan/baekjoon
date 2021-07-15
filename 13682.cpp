#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		v.push_back(v[0]);
		v.push_back(v[1]);
		int peaks = 0;
		for(int i = 1; i <= n; ++i){
			if((v[i] < v[i - 1] && v[i] < v[i + 1]) || (v[i] > v[i - 1] && v[i] > v[i + 1])){
				++peaks;
			}
		}
		cout << peaks << '\n';
	}
	return 0;
}
