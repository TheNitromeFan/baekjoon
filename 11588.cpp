#include <iostream>
#include <vector>

using namespace std;

bool pizza(vector<int> &v, int x){
	for(int y : v){
		if((x & y) == y){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> v(m);
	for(int i = 0; i < m; ++i){
		int a, b;
		cin >> a >> b;
		v[i] = (1 << (a - 1)) | (1 << (b - 1));
	}
	int cnt = 0;
	for(int x = 0; x < (1 << n); ++x){
		if(pizza(v, x)){
			++cnt;
		}
	}
	cout << cnt << '\n';
	return 0;
}
