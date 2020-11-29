#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<lint, lint>;
const int MAXN = 10005;

int mask[MAXN][27];

struct kek{
	int a[27], idx;
	bool operator<(const kek &k)const{
		for(int i=0; i<27; i++) if(a[i] != k.a[i]) return a[i] < k.a[i];
		return idx < k.idx;
	}
}v[MAXN];

pi dfs(int s, int e, int dep = 0){
	if(s == e){
		return pi(0, -v[s].idx);
	}
	bool chk = 0;
	for(int i=s; i<=e; i++){
		if(v[i].a[dep]) chk = 1;
	}
	pi ret(-1, -1);
	for(int i=s; i<=e; ){
		int j = i;
		while(j <= e && v[i].a[dep] == v[j].a[dep]) j++;
		j--;
		auto foo = dfs(i, j, dep + 1);
		if(chk && v[i].a[dep] == 0) foo.first++;
		ret = max(ret, foo);
		i = j+1;
	}
	return ret;
}

int main(){
	int tc; scanf("%d",&tc);
	for(int i=1; i<=tc; i++){
		int n, m;
		cin >> n >> m;
		vector<string> D(n), L(m);
		for(auto &i : D) cin >> i;
		for(auto &i : L) cin >> i;
		memset(mask, 0 ,sizeof(mask));
		for(int i=0; i<n; i++){
			for(int j=0; j<sz(D[i]); j++){
				mask[i][D[i][j] - 'a'] |= (1<<j);
			}
		}
		printf("Case #%d:", i);
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				v[j].a[0]= sz(D[j]);
				for(int k=0; k<26; k++){
					v[j].a[k+1] = mask[j][L[i][k] - 'a'];
				}
				v[j].idx = j;
			}
			sort(v, v + n);
			pi ret = dfs(0, n - 1);
			printf(" %s", D[-ret.second].c_str());
		}
		puts("");
	}
}

