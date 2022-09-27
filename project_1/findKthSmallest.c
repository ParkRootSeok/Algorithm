#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma waring(disable:4996)


/* �޼ҵ� ���� */
void rBuildHeap(int * L, int i, int n);
void downHeap(int * L, int i, int n);
void inPlaceHeapSort(int * L, int n);
int findKthSmallest(int* L, int n, int k);
int * buildList(int n, int min, int max);

int main() {

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	int e, output[4], karray[] = {1, 100, 99900, 99999};
	int* L;

	L = buildList(10, 1, 100);

	for (int i = 1; i <= 10; i++) {	// ����Ʈ ���	
		printf(" %d", L[i]);
	} printf("\n");

	for (int k = 1; k < 4; k++) {	// �ּڰ� Ž��
		output[k - 1] = findKthSmallest(L, 10, k);
	} printf(" %d %d %d\n", output[0], output[1], output[2]);

	L = buildList(100000, 1, 1000000);

	for (int k = 0; k < 4; k++) {	// �ּڰ� Ž��

		// �ð� ���� 
		QueryPerformanceFrequency(&ticksPerSec);		
		QueryPerformanceCounter(&start);
		e = findKthSmallest(L, 100000, karray[k]);		// karray[k]��° �ּڰ� Ž��
		QueryPerformanceCounter(&end);					

		diff.QuadPart = end.QuadPart - start.QuadPart;	// CPUtime()

		// ��� ���
		printf("%6dth min : %7d, time: %4.12fms\n", karray[k], e, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
	}

}

void rBuildHeap(int * L, int i, int n) {

	if (i > n) return;

	rBuildHeap(L, i * 2, n);
	rBuildHeap(L, i * 2 + 1, n);

	downHeap(L, i, n);

}

void downHeap(int* L, int i, int n) {

	int tmp, bigger;

	// ũ�� �ʰ��� ����
	if (n < i * 2 && n < i * 2 + 1) return;

	bigger = i * 2;

	// ������ �ڽ� ���� �� ũ�� ��
	if (n >= i * 2 + 1) {
		if (L[i * 2 + 1] > L[bigger]) bigger = i * 2 + 1;
	}

	if (L[i] >= L[bigger]) return;

	// Swap
	tmp = L[i];
	L[i] = L[bigger];
	L[bigger] = tmp;

	downHeap(L, bigger, n);
}
void inPlaceHeapSort(int* L, int n) {

	int tmp;

	// ����� �� ����
	rBuildHeap(L, 1, n);

	// Swap
	for (int i = n; i >= 2; i--) {
		tmp = L[1];
		L[1] = L[i];
		L[i] = tmp;

		downHeap(L, 1, i - 1);
	}

	return;

}

int findKthSmallest(int* L, int n, int k) {

	int result;

	// ����
	inPlaceHeapSort(L, n);

	return result = L[k];

}

int * buildList(int n, int min, int max) {

	int* L;

	L = (int*)malloc(sizeof(int) * (n + 1));

	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		L[i] = rand() % (max - min + 1) + min;
	}

	return L;

}