#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#pragma warning(disable:4996)

/* ���� ���� ���� */
int n = 100000;
int Limits[] = { 1, 100, 500, 1000 };

/* �޼ҵ� ���� */
int * createArray();
void swap(int* a, int* b);
void show(int* L);

int findPivot(int* L, int l, int r, int mode);
void insertionSort(int* L);
void inPlaceQuickSort(int* L, int l, int r, int limit, int mode);
int inPlacePartirion(int* L, int l, int r, int k);

int main() {

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	int *arr, *L;

	// �迭 ����
	arr = createArray();
	
	for (int i = 0; i < 4; i++) {
		
		printf("Limit : %d\t", Limits[i]);
	
		
		for (int mode = 0; mode < 4; mode++) {

			L = (int*)malloc(sizeof(int) * n);
			memcpy(L, arr, sizeof(int) * n); // �迭 ����
			
			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start); // ���� �ð� ����
			inPlaceQuickSort(L, 0, n - 1, Limits[i], mode);
			QueryPerformanceCounter(&end); // �� �ð� ����
			diff.QuadPart = end.QuadPart - start.QuadPart; // �� ���� �ð� ���
			printf("time: %.12f\t", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000); // CPUtime ���
			
			free(L);
		}printf("\n");

	} free(arr);
	return;
}

int * createArray() {

	int* L;
	int randNum;

	L = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		randNum = (rand() % n) + 1;
		L[i] = randNum;
	}

	return L;
}

void swap(int* a, int* b) {

	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}


void show(int * L) {

	for (int i = 0; i < n; i++) {
		printf(" %d", L[i]);
	} printf("\n");
}

/*
������ 1 : ÷�� r ��ȯ
������ 3 : �ι迭�� ũ�Ⱑ 3 �̸��� ��� �� ��ġ ��ȯ, �׷��� ���� ��� �� ��, �߰�, �� �� ���� �� 3-�߾Ӱ� ��ȯ
������ 1 : l�� r ������ ������ ��ġ ��ȯ
������ 3 : �ι迭�� ũ�Ⱑ 3 �̸��� ��� �� ��ġ ��ȯ, �׷��� ���� ��� ������ ���� �� 3-�߾Ӱ� ��ȯ
*/

int findPivot(int* L, int l, int r, int mode) {

	//printf("----�Ǻ� ã�� ����----\n");

	int result, ll, mm, rr;
	
	srand(time(NULL));
	switch (mode) { // 0 : ������ 1, 1 : ������ 3, 2 : ������ 1, 3: ������ 3 
	
	case 0:	// ������ 1 - ÷�� r�� ��ȯ
		//printf("----�Ǻ� ã�� : ������ 1----\n");
		result = r; 
		break;
	
	case 1: // ������ 3 - �� ��, �߰�, �� �� ���� �� 3-�߾Ӱ� ��ȯ 
		//printf("----�Ǻ� ã�� : ������ 3----\n");
		ll = l; mm = (int)(r / 2 + 0.5);  rr = r;

		if (L[ll] <= L[mm] && L[mm] <= L[rr] || L[ll] >= L[mm] && L[mm] >= L[rr]) // �߰����� mm �� ��
			result = mm;
		else if (L[mm] <= L[ll] && L[ll] <= L[rr] || L[mm] >= L[ll] && L[ll] >= L[rr]) // �߰����� ll �� ��
			result = ll;
		else // �߰����� rr �� ��
			result = rr;
		break;
	
	case 2: // ������ 1 - l ~ r ������ ���� ��ȯ
		//printf("----�Ǻ� ã�� : ������ 1----\n");
		result = rand() % (r - l + 1) + l;
		break;
	
	case 3:// ������ 3 - ������ ���� �� 3-�߾Ӱ� ��ȯ
		//printf("----�Ǻ� ã�� : ������ 3----\n");
		ll = rand() % (r - l + 1) + l; mm = rand() % (r - l + 1) + l; rr = rand() % (r - l + 1) + l;

		if (L[ll] <= L[mm] && L[mm] <= L[rr] || L[ll] >= L[mm] && L[mm] >= L[rr]) // �߰����� mm �� ��
			result = mm;
 		else if (L[mm] <= L[ll] && L[ll] <= L[rr] || L[mm] >= L[ll] && L[ll] >= L[rr]) // �߰��� ll �� ��
			result = ll;
		else // �߰����� rr �� ��
			result = rr;
		break;
	}

	return result; // �Ǻ� ��ȯ
}

void insertionSort(int* L) {
	
	int j, pass, save;

	for (pass = 1; pass < n; pass++) {
		
		save = L[pass];
		j = pass - 1;
		
		while (j >= 0 && L[j] > save) {
			L[j + 1] = L[j];
			j -= 1;
		}
		L[j + 1] = save;
	}

	return;
}

void inPlaceQuickSort(int* L, int l, int r, int limit, int mode) {
	
	
	int k, b, size = r - l + 1;

	if (l >= r) return;

	if (limit >= size) { // Limit >= �ι迭 ũ���϶� ���� �� ���� ���� ���� 
		insertionSort(L); 
	}
	else { // �� �ܿ� ��� �� ���� ����

		k = findPivot(L, l, r, mode);
		b = inPlacePartirion(L, l, r, k);


		inPlaceQuickSort(L, l, b - 1, limit, mode);
		inPlaceQuickSort(L, b + 1, r, limit, mode);
	}

}

int inPlacePartirion(int* L, int l, int r, int k) {
	
	int pivot, i, j;
	
	pivot = L[k];
	i = l;
	j = r - 1;

	swap(L + r, L + k); // �Ǻ��� ������ �ʿ䰡 �����Ƿ� �迭 �� ������ �̵�
	
	while (i <= j) {
		
		while (i <= j && L[i] < pivot) i++; // pivot���� ū ���� ��ġ �˻�
		
		while (i <= j && L[j] >= pivot) j--; // pivot���� ū �˻� ��ġ �˻�

		if (i < j) swap(L + i, L + j);	// �������� ������ �����ؾ��� ���Ұ� ���� �ϴٴ� �ǹ��̹Ƿ�  swap
	
	}

	swap(L + i, L + r);

	return i;

}