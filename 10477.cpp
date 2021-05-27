#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		long long a, b;
		cin >> a >> b;
		long long sum = 1, t = 1;
		long long j = 1;
		while(j <= a + b){
			if(j <= a && j <= b){
				sum += 2 * t;
			}else if(j <= b){
				sum += 2 * t - (j - a);
			}else if(j <= a){
				sum += 2 * t - (j - b);
			}else{
				sum += 2 * t - (j - a) - (j - b);
			}
			t *= 2;
			j += t;
		}
		cout << sum << '\n';
	}
	return 0;
}
