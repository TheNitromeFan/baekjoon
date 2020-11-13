#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main(){
	unsigned n;
	scanf("%u", &n);
	vector<pair<unsigned, unsigned >> v(n);
	for(unsigned i = 0; i < n; ++i){
		unsigned x;
		scanf("%u", &x);
		v[i] = make_pair(i + 1, x);
	}
	unsigned pos = 0;
	while(v.size() > 1){
		pos += v[pos].second - 1;
		pos %= v.size();
		v.erase(v.begin() + pos);
		pos %= v.size();
		/*
		for(pair<unsigned, unsigned> p : v){
			printf("(%u %u), ", p.first, p.second);
		}
		*/
	}
	printf("%u", v[0].first);
	return 0;
}
