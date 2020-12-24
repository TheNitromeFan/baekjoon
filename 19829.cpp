#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int ans = 0;
	int j = 0;
	while(j < n){
		int start = j;
		do{
			++j;
		}while(j < n && v[j] != v[j - 1]);
		if(ans < j - start){
			ans = j - start;
		}
	}
	cout << ans;
	return 0;
}
