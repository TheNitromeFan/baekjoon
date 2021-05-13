#include <iostream>
#include <string>
#define MAX 5000001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q, m;
	cin >> q >> m;
	int a[MAX] = {};
	a[0] = 1;
	a[1] = 1;
	string seq;
	for(int i = 2; i < m * m; ++i){
		a[i] = (a[i - 1] + a[i - 2]) % m;
		if(a[i] == 1 && a[i - 1] == 1){
			for(int j = 0; j < i - 1; ++j){
				seq += to_string(a[j]);
			}
			break;
		}
	}
	if(m == 2){
		seq = "110";
	}else if(m == 3){
		seq = "11202210";
	}
	int t = (int)seq.length();
	for(int a0 = 0; a0 < q; ++a0){
		long long n;
		cin >> n;
		cout << seq[(n + t - 1) % t] << '\n';
	}
	return 0;
}
