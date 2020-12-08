#include <iostream>
#include <vector>

using namespace std;

int truthtellers(vector<int> &a, vector<int> &b, int n){
	int ret = n;
	for(; ret >= 0; --ret){
		int correct = 0;
		for(int i = 1; i <= n; ++i){
			if(ret >= a[i] && ret <= b[i]){
				++correct;
			}
		}
		if(ret == correct){
			break;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> a[i] >> b[i];
	}
	cout << truthtellers(a, b, n);
	return 0;
}
