#include <cstdio>
#include <set>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int g;
		scanf("%d", &g);
		set<int> guests;
		for(int j = 0; j < g; ++j){
			int c;
			scanf("%d", &c);
			if(guests.find(c) == guests.end()){
				guests.insert(c);
			}else{
				guests.erase(c);
			}
		}
		printf("Case #%d: ", i);
		for(int guest : guests){
			printf("%d\n", guest);
		}
	}
	return 0;
}
