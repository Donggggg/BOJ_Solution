#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int end;
int* arr;

void pop()
{
	int cur, child;

	if (end == 1)
		printf("0\n");
	else {
		printf("%d\n", arr[1]);
		arr[1] = arr[--end];
		arr[end] = 0;
		cur = 1;

		while (1) {
			child = arr[cur * 2] > arr[(cur * 2) + 1] ? cur * 2 : (cur * 2) + 1;

			if (end <= child || arr[child] <= arr[cur])
				break;

			std::swap(arr[child], arr[cur]);
			cur = child;
		}
	}
}

void push(int num)
{
	int cur;

	arr[end] = num;
	cur = end++;

	while (1 < cur && arr[cur / 2] < arr[cur]) {
		std::swap(arr[cur], arr[cur / 2]);
		cur /= 2;
	}
	
}

int main()
{
	int N, num;
	scanf("%d", &N);
	arr = new int[N+1];
	end = 1;

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);

		if (num == 0)
			pop();
		else
			push(num);
	}

	return 0;
}
