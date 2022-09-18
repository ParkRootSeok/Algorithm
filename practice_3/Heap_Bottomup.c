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
void rBuildHeap(int i);
void BuildHeap();
void downHeap(int i);
void printHeap();

int main() {

	int num, e;

	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		
		scanf("%d", &e);
		H[i] = e;
		n++;
	}

	//rBuildHeap(1);
	BuildHeap();
	printHeap();

	return;

}

void rBuildHeap(int i) { // ����� ���

	if (i > n) return;

	rBuildHeap(i * 2);
	rBuildHeap(i * 2 + 1);
	downHeap(i);
	
	return;
}

void BuildHeap() { // ������� ���
	
	for (int i = n / 2; i > 0; i--) {
		downHeap(i);
	}

	return;
}

void downHeap(int i) {

	int tmp, bigger;

	// ���� ��� ���� Ȯ��
	if (n < (i * 2) && n < (i * 2 + 1)) return;

	// ���� �� ���� ��� �� ���� ū ��� ã��
	bigger = i * 2;

	if (n >= i * 2 + 1) {

		if (H[i * 2 + 1] > H[bigger]) {

			bigger = i * 2 + 1;

		}

	}

	// ���� ��尡 ���� ���� ũ�ų� ������ ��ȯ �ʿ� X
	if (H[i] >= H[bigger]) return;

	// ����
	tmp = H[i];
	H[i] = H[bigger];
	H[bigger] = tmp;

	downHeap(bigger);
}

void printHeap() {

	if (n < 1) {
		return;
	}

	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	} printf("\n");

}