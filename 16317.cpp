#include <cstdio>
#include <vector>

using namespace std;

int main(){
	unsigned n;
	scanf("%u", &n);
	vector<int> jobs(n);
	for(unsigned i = 0; i < n; ++i){
		scanf("%d", &jobs[i]);
	}
	vector<int> dirty;
	unsigned index = 0;
	int day = 0;
	int cleanups = 0;
	do{
		++day;
		int dirtiness = 0;
		for(int x : dirty){
			dirtiness += day - x;
		}
		if(dirtiness >= 20){
			++cleanups;
			dirty.clear();
		}
		if(index < n && jobs[index] == day){
			dirty.push_back(day);
			++index;
		}
	}while(day <= 365);
	if(!dirty.empty()){
		++cleanups;
		dirty.clear();
	}
	printf("%d", cleanups);
	return 0;
}
