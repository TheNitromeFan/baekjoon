#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

unsigned find_index(vector<int> &vec, int val){
	unsigned low = 0, high = vec.size() - 1;
	while(low < high){
		unsigned mid = (low + high) / 2;
		if(vec[mid] >= val){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	return low;
}

int rand_num(){
	return rand() % 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(NULL));
	for(int i = 0; i < 10; ++i){
		cout << rand_num() << ' ';
	}
	return 0;
}
