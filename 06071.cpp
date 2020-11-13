#include <cstdio>
#include <set>

using std::set;

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int m, n;
		scanf("%d %d", &m, &n);
		if(m == 0 && n == 0){
			break;
		}
		set<int> cards;
		for(int i = 0; i < n; ++i){
			int card;
			scanf("%d", &card);
			cards.insert(card);
		}
		int ans = 0, card_cnt = 0;
		for(int card = m * n; card > 0; --card){
			if(cards.find(card) != cards.end()){
				if(card_cnt == 0){
					++ans;
				}else{
					--card_cnt;
				}
			}else{
				++card_cnt;
			}
		}
		printf("Case %d: %d\n", cnt, ans);
	}
	return 0;
}
