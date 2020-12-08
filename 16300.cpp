#include <iostream>
#include <string>
#include <map>

using namespace std;

void parseAtoms(map<char, long long> &m, string &mol){
	unsigned idx = 0;
	while(idx < mol.length()){
		char atom = mol[idx];
		++idx;
		long long cnt = 0;
		while(idx < mol.length() && mol[idx] >= '0' && mol[idx] <= '9'){
			cnt = cnt * 10 + mol[idx] - '0';
			++idx;
		}
		if(cnt != 0){
			m[atom] += cnt;
		}else{
			++m[atom];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	int k;
	cin >> a >> k >> b;
	map<char, long long> atomCnt1, atomCnt2;
	for(char c = 'A'; c <= 'Z'; ++c){
		atomCnt1[c] = 0;
		atomCnt2[c] = 0;
	}
	parseAtoms(atomCnt1, a);
	parseAtoms(atomCnt2, b);
	for(char c = 'A'; c <= 'Z'; ++c){
		atomCnt1[c] *= k;
	}
	long long ans = 1000000000000000000LL;
	for(char c = 'A'; c <= 'Z'; ++c){
		if(atomCnt2[c] != 0 && ans > atomCnt1[c] / atomCnt2[c]){
			ans = atomCnt1[c] / atomCnt2[c];
		}
	}
	cout << ans;
	return 0;
}
