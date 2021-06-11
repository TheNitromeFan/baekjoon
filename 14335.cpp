#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
ll MOD = 1000000007ll;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)

vector <int> Vu;
void vpush(int x) {
	for (auto it : Vu) if (it == x) return;
	Vu.push_back(x);
}
int myfind(int x) {
	for (int i = 0; i < Vu.size(); i++) if (Vu[i] == x) return i;
	assert(false);
}

int nxt[30][3];

db dp[30];
db tdp[30];
int main() {
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++) {
		int A, B, C, N, X, K;
		scanf("%d %d %d %d %d %d", &N, &X, &K, &A, &B, &C);

		Vu.push_back(X);
		for (int i = 0; i < Vu.size(); i++) {
			vpush(Vu[i] ^ K);
			vpush(Vu[i] & K);
			vpush(Vu[i] | K);
		}

		int M = Vu.size();
		for (int i = 0; i < M; i++) {
			nxt[i][0] = myfind(Vu[i] & K);
			nxt[i][1] = myfind(Vu[i] | K);
			nxt[i][2] = myfind(Vu[i] ^ K);
		}

		memset(dp, 0, sizeof(dp));
		dp[myfind(X)] = 1;
		for (int i = 0; i < N; i++) {
			memset(tdp, 0, sizeof(tdp));
			for (int j = 0; j < M; j++) {
				tdp[nxt[j][0]] += 1.0 * A / 100 * dp[j];
				tdp[nxt[j][1]] += 1.0 * B / 100 * dp[j];
				tdp[nxt[j][2]] += 1.0 * C / 100 * dp[j];
			}
			for (int j = 0; j < M; j++) dp[j] = tdp[j];
		}

		db ans = 0;
		for (int i = 0; i < M; i++) ans += dp[i] * Vu[i];
		printf("Case #%d: %.20lf\n", tc, ans);

		Vu.clear();
	}
	return 0;
}
