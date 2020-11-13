#include <iostream>
#include <string>
#include <vector>
#define MAX (1000000 + 2)

using namespace std;

void build_table(int kmp_table[MAX], string p, int m){
	kmp_table[0] = -1;
	int pos = 1, cnd = 0;
	while(pos < m){
		if(p[pos] == p[cnd]){
			kmp_table[pos] = kmp_table[cnd];
		}else{
			kmp_table[pos] = cnd;
			cnd = kmp_table[cnd];
			while(cnd >= 0 && p[pos] != p[cnd]){
				cnd = kmp_table[cnd];
			}
		}
		++pos;
		++cnd;
	}
	kmp_table[pos] = cnd;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string t, p;
	getline(cin, t);
	int n = t.length();
	getline(cin, p);
	int m = p.length();
	static int kmp_table[MAX];
	build_table(kmp_table, p, m);
	vector<int> v;
	int j = 0, k = 0;
	while(j < n){
		if(p[k] == t[j]){
			++j;
			++k;
			if(k == m){
				v.push_back(j - k);
				k = kmp_table[k];
			}
		}else{
			k = kmp_table[k];
			if(k < 0){
				++j;
				++k;
			}
		}
	}
	cout << !v.empty();
	return 0;
}
