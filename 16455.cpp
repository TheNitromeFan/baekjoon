#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int>::size_type partition(std::vector<int> &a, std::vector<int>::size_type left, std::vector<int>::size_type right, std::vector<int>::size_type pivotIndex){
	int pivotValue = a[pivotIndex];
	std::swap(a[pivotIndex], a[right]);
	auto storeIndex = left;
	for(auto i = left; i < right; ++i){
		if(a[i] < pivotValue){
			std::swap(a[storeIndex], a[i]);
			++storeIndex;
		}
	}
	std::swap(a[right], a[storeIndex]);
	return storeIndex;
}

/*
int select(std::vector<int> &a, std::vector<int>::size_type left, std::vector<int>::size_type right, int k){
	if(left == right){
		return a[left];
	}
	auto pivotIndex = (left + right) / 2;
	pivotIndex = partition(a, left, right, pivotIndex);
	if(k == pivotIndex){
		return a[k];
	}else if(k < pivotIndex){
		return select(a, left, pivotIndex - 1, k);
	}else{
		return select(a, pivotIndex + 1, right, k);
	}
}
*/

int kth(std::vector<int> &a, int k){
	--k;
	int left = 0, right = a.size() - 1;
	while(true){
		if(left == right){
			return a[left];
		}
		auto pivotIndex = (left + right) / 2;
		pivotIndex = partition(a, left, right, pivotIndex);
		if(k == pivotIndex){
			return a[k];
		}else if(k < pivotIndex){
			right = pivotIndex - 1;
		}else{
			left = pivotIndex + 1;
		}
	}
}

int main(){
	return 0;
}

