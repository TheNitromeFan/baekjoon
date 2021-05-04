#include <iostream>
#include <vector>

using namespace std;

bool covered(vector<bool> &ad, int m){
	for(int i = 1; i <= m; ++i){
		if(!ad[i]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;
	vector<bool> ad(m + 1);
	for(int i = 0; i < n; ++i){
		int li, ri;
		cin >> li >> ri;
		for(int j = li; j <= ri; ++j){
			ad[j] = true;
		}
	}
	cout << (covered(ad, m) ? "YES" : "NO");
	return 0;
}
