#include <cstdio>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int ans_i = 1, ans_s, ans_c, ans_l;
	scanf("%d %d %d", &ans_s, &ans_c, &ans_l);
	for(int i = 2; i <= n; ++i){
		int s, c, l;
		scanf("%d %d %d", &s, &c, &l);
		if(s > ans_s || (s == ans_s && (c < ans_c || (c == ans_c && l < ans_l)))){
			ans_i = i;
			ans_s = s;
			ans_c = c;
			ans_l = l;
		}
	}
	printf("%d", ans_i);
	return 0;
}
