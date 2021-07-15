#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i){
		int h1, m1, s1, h2, m2, s2;
		scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
		a[i] = 60 * 60 * h1 + 60 * m1 + s1;
		b[i] = 60 * 60 * h2 + 60 * m2 + s2;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int max_cnt = 0;
	int i = 0, j = 0;
	int cnt = 0;
	for(int time = 0; time < 60 * 60 * 24; ++time){
		while(i < n && a[i] == time){
			++cnt;
			++i;
		}
		max_cnt = max(max_cnt, cnt);
		while(j < n && b[j] == time){
			--cnt;
			++j;
		}
	}
	printf("%d\n", max_cnt);
	return 0;
}
