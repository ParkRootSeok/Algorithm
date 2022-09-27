	#include <stdio.h>
	#include <stdlib.h>
	#pragma warning(disable:4996)

	#define MAX_SIZE 100

	/* ���� */
	// 1. ������
	// 2. �ִ���(���� �۾� �� �ִ밪 ����)
	// 3. �迭 �ε��� 0 ��� X

	/* ���� ���� ����*/
	int H[MAX_SIZE];		// ��
	int n = 0;				// ���� ũ��

	/* �޼ҵ� ����*/
	void inPlaceHeapSort();
	void insertItem(int key);
	void upHeap(int i);
	void downHeap(int i);
	void rBuildHeap(int i);
	void printHeap();

	int main() {

		int num, key;

		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			scanf("%d", &key);
			insertItem(key);
		}

		inPlaceHeapSort(); 	// ���ڸ� �� ����
		n = num;	// �� ���� �� �� ũ�� ����

		printHeap();

		return;
	}

	void inPlaceHeapSort() {

		int save;

		rBuildHeap(1); // phase 1 ����� �� ����

		for (int i = n; i > 1; i--) {	// phase 2 �� ����

			// ���� �ֻ��� ���� ������ ��� ��ȯ
			save = H[1];
			H[1] = H[i];
			H[i] = save;

			n--;

			downHeap(1); // �� ����(swap �۾����� ���� ������ �ʿ�)

		}

		return;

	}

	void insertItem(int key) {
	
		H[++n] = key;
		upHeap(n);

	}

	void upHeap(int i) {

		int save;

		if (i == 1) return;

		if (H[i] <= H[i / 2]) return;
	
		save = H[i / 2];
		H[i / 2] = H[i];
		H[i] = save;
	
		upHeap(i / 2);

	}

	void downHeap(int i) {

		int save, bigger;
	
		if (n < i * 2 && n < i * 2 + 1) return;

		bigger = i * 2;

		if (n >= i * 2 + 1) {
			if (H[i * 2 + 1] > H[bigger]) bigger = i * 2 + 1;
		}

		if (H[i] >= H[bigger])	return;

		save = H[i];
		H[i] = H[bigger];
		H[bigger] = save;
	
		downHeap(bigger);

	}

	void rBuildHeap(int i) {

		if (i > n) return;

		rBuildHeap(i * 2);
		rBuildHeap(i * 2 + 1);
	
		downHeap(i);

	}

	void printHeap() {

		for (int i = 1; i <= n; i++) {
			printf(" %d", H[i]);
		} printf("\n");

	}