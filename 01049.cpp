#include <cstdio>
#include <algorithm>

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int six_pack = 1000, single = 1000;
	for(int i = 0; i < m; ++i){
		int p, s;
		scanf("%d %d", &p, &s);
		if(p < six_pack){
			six_pack = p;
		}
		if(s < single){
			single = s;
		}
	}
	if(single * 6 < six_pack){
		six_pack = single * 6;
	}
	printf("%d", std::min(six_pack * (n / 6) + single * (n % 6), six_pack * (n / 6 + 1)));
	return 0;
}
