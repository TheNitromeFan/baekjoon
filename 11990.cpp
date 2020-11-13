#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN (1 << 17)

int S1[2 * MAXN];
int S2[2 * MAXN];

int quad(pair<int, int> A, pair<int, int> B) {
  return (A.first < B.first) + 2 * (A.second < B.second);
}

void update(int* S, int x, int v) {
  x += MAXN;
  S[x] += v;
  for (x = x >> 1; x; x = x >> 1) {
    S[x] = S[2 * x + 0] + S[2 * x + 1];
  }
}

int query(int x, int l1, int r1, int l2, int r2) {
  if (x > MAXN) {
    (l1 < r1 ? l1 : r1) += S1[x];
    (l2 < r2 ? l2 : r2) += S2[x];
    return max(max(l1, r1), max(l2, r2));
  }

  int c1 = x * 2 + 0;
  int c2 = x * 2 + 1;
  if (max(l1 + S1[c1], l2 + S2[c1]) < max(r1 + S1[c2], r2 + S2[c2])) {
    return query(c2, l1 + S1[c1], r1, l2 + S2[c1], r2);
  } else {
    return query(c1, l1, r1 + S1[c2], l2, r2 + S2[c2]);
  }
}

int main() {
  int N; cin >> N;

  vector<pair<int, int> > A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  sort(A.begin(), A.end());
  if(N <= 100){
  	int ans = 1e9;
	for(int i = 0; i < N; i++){
		for(int k = 0; k < N; k++){
	    int cnt[4] = {0, 0, 0, 0};
	    int res = 0;
	    for(int j = 0; j < N; j++){
		  cnt[quad(make_pair(A[i].first + 1, A[k].second + 1), A[j])]++;
		}
		for(int j = 0; j < 4; j++){
		  if(res < cnt[j]){
		  	res = cnt[j];
		  }
		}
		if(ans > res){
		  ans = res;
		}
	  }
	}
	printf("%d", ans);
	return 0;
  }

  int xp = 0, lx = A[0].first;
  for (int i = 0; i < N; i++) {
    if (A[i].first != lx) {
      lx = A[i].first;
      xp++;
    }
    A[i].first = xp;
  }

  sort(A.begin(), A.end(), [](pair<int, int> a, pair<int, int> b) {
    return make_pair(a.second, a.first) < make_pair(b.second, b.first);
  });

  for (int i = 0; i < N; i++) {
    update(S1, A[i].first, 1);
  }

  int result = N;
  for (int i = 0; i < N; ) {
    int sz = 0;
    while (i + sz < N && A[i].second == A[i + sz].second) {
      update(S1, A[i + sz].first, -1);
      update(S2, A[i + sz].first, 1);
      sz++;
    }
    result = min(result, query(1, 0, 0, 0, 0));
    i += sz;
  }
  cout << result << endl;
  return 0;
}
