#include "sorting.h"
#include <algorithm>

struct Cmp{
	bool operator()(int x, int y){
		return compare_difficulty(x, y);
	}
};


void sort_questions(int N, int Q, int A[]) {
	for (int i = 0; i < N; i++) {
		A[i] = i + 1;
	}
	std::stable_sort(A, A + N, Cmp());
	return;
}

