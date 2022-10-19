#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// Define Method
int* InitArray(int n);
void SelectionSort(int n, int* arr);
void swap(int* a, int* b);

int main() {

	int* arr;
	int n;
	scanf("%d", &n);

	arr = InitArray(n);

	// Run Selection Sort
	SelectionSort(n, arr);

	// Run Print Array
	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}

	return;

}

int* InitArray(int n) {

	int* arr = (int*)malloc(sizeof(int) * n);

	if (arr == NULL) {
		printf("Error");
		return;
	}

	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	return arr;
}

// �ð� ���⵵ : O(n^2)
// Data�� ��
void SelectionSort(int n, int* arr) { 

	int pass, minLoc;

	for(pass = 0;pass < n - 2;pass++) { 
		
		minLoc = pass;

		for (int j = pass + 1; j < n - 1; j++) { 

			// ����Ʈ���� ���� ���� Data �˻�
			if (arr[j] < arr[minLoc]) {
				minLoc = j;
			}
		}

		// ���� ���� Data�� ������ �̵�
		swap(arr[pass], arr[minLoc]);
	}

}

void swap(int* a, int* b) {

	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}