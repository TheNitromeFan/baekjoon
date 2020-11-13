#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string words[7] = {"", "Yakk", "Doh", "Seh", "Ghar", "Bang", "Sheesh"};
	string doubles[7] = {"", "Habb Yakk", "Dobara", "Dousa", "Dorgy", "Dabash", "Dosh"};
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a < b){
			swap(a, b);
		}
		printf("Case %d: ", i);
		if(a == 6 && b == 5){
			printf("Sheesh Beesh\n");
		}else if(a == b){
			printf("%s\n", doubles[a].c_str());
		}else{
			printf("%s %s\n", words[a].c_str(), words[b].c_str());
		}
	}
	return 0;
}
