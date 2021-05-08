#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int max_start = 0, max_end = 0;
	int start = 0;
	for(int i = 1; i < n; ++i){
		if(v[i - 1] <= v[i] && max_end - max_start < i - start){
			max_start = start;
			max_end = i;
		}else if(v[i - 1] > v[i]){
			start = i;
		}
	}
	long long sum = 0;
	for(int i = max_start; i <= max_end; ++i){
		sum += v[i];
	}
	cout << max_end - max_start + 1 << ' ' << sum;
	return 0;
}
