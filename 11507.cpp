#include <cstdio>
#include <set>

using namespace std;

int main(){
	char suit;
	int num;
	set<int> p, k, h, t;
	while(scanf("%c%d", &suit, &num) == 2){
		switch(suit){
			case 'P':
				if(p.find(num) != p.end()){
					printf("GRESKA");
					return 0;
				}
				p.insert(num);
				break;
			case 'K':
				if(k.find(num) != k.end()){
					printf("GRESKA");
					return 0;
				}
				k.insert(num);
				break;
			case 'H':
				if(h.find(num) != h.end()){
					printf("GRESKA");
					return 0;
				}
				h.insert(num);
				break;
			case 'T':
				if(t.find(num) != t.end()){
					printf("GRESKA");
					return 0;
				}
				t.insert(num);
				break;
		}
	}
	printf("%llu %llu %llu %llu", 13 - p.size(), 13 - k.size(), 13 - h.size(), 13 - t.size());
	return 0;
}
