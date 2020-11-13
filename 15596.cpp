#include <iostream>
#include <vector>

long long sum(std::vector<int> &a){
	long long ret = 0;
	for(int x : a){
		ret += x;
	}
	return ret;
}

int main(){
	std::vector<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	q.push_back(4);
	std::cout << sum(q) << std::endl;
	return 0;
}
