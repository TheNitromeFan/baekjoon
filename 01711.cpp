#include <iostream>
#define MAX 1500

using namespace std;

bool is_right(long long a[2], long long b[2], long long c[2]){
	long long d1 = (b[0] - a[0]) * (b[0] - a[0]) + (b[1] - a[1]) * (b[1] - a[1]);
	long long d2 = (c[0] - a[0]) * (c[0] - a[0]) + (c[1] - a[1]) * (c[1] - a[1]);
	long long d3 = (c[0] - b[0]) * (c[0] - b[0]) + (c[1] - b[1]) * (c[1] - b[1]);
	return d1 == d2 + d3 || d2 == d3 + d1 || d3 == d1 + d2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long p[MAX][2];
	for(int i = 0; i < n; ++i){
		cin >> p[i][0] >> p[i][1];
	}
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			for(int k = 0; k < j; ++k){
				if(is_right(p[i], p[j], p[k])){
					++cnt;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
