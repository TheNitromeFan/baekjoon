#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> baseB(int b, int x){
	vector<int> ret;
	while(x > 0){
		ret.push_back(x % b);
		x /= b;
	}
	return ret;
}

int NimSum(int b, int x, int y){
	vector<int> vx = baseB(b, x), vy = baseB(b, y);
	if(vx.size() < vy.size()){
		vx.resize(vy.size());
	}else{
		vy.resize(vx.size());
	}
	vector<int> nim(vx.size());
	for(unsigned i = 0; i < vx.size(); ++i){
		nim[i] = (vx[i] + vy[i]) % b;
	}
	reverse(nim.begin(), nim.end());
	int ret = 0;
	for(int z : nim){
		ret *= b;
		ret += z;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p;
	cin >> p;
	for(int i = 0; i < p; ++i){
		int b, x, y;
		cin >> b >> x >> y;
		cout << NimSum(b, x, y) << '\n';
	}
	return 0;
}
