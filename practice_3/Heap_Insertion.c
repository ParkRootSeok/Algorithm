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
void insertItem(int key);
int removeMax();
void upHeap(int i);
void downHeap(int i);
void printHeap();

int main() {

	int key;
	char oper;

	while (1) {

		scanf("%c", &oper); getchar();

		switch (oper) {
		case 'i':
			scanf("%d", &key); getchar();
			insertItem(key);
			break;
		case 'd':
			printf("%d\n", removeMax());
			break;
		case 'p':
			printHeap();
			break;
		case 'q':
			return;
			break;
		}
	}

	return;

}

void insertItem(int key) { // �� ����

	H[++n] = key;
	upHeap(n);	// �� ���� ����

	printf("0\n");

}

int removeMax() {

	int key = H[1];
	H[1] = H[n--];
	downHeap(1);// �� ���� ����

	return key;
}

void upHeap(int i) {

	int tmp;

	// �ֻ��� ����� ��� ����
	if (i == 1) return;

	// �θ� ��尡 �� Ŭ ��� ����
	if (H[i / 2] >= H[i]) return;

	// �� ��� ��찡 �ƴ� ��� ����
	tmp = H[i / 2];
	H[i / 2] = H[i];
	H[i] = tmp;

	upHeap(i / 2);
}

void downHeap(int i) {

	int tmp, bigger;

	// �ڽ� ��� ���� Ȯ��
	if ((n < i * 2) & (n < i * 2 + 1)) return;

	bigger = i * 2;

	// ���� ��� �� ���� ū �� ã��
	// �ִ����̹Ƿ� ū ���� ã�´�. ���� �ּ����̶�� ���� ���� ã�� ����. 
	if ((n >= i * 2 + 1)) {
		if (H[i * 2 + 1] > H[bigger]) {
			bigger = i * 2 + 1;
		}
	}

	// �θ� ��庸�� �۰ų� ���� ��� ���� �ʿ� X
	if (H[i] >= H[bigger]) return;

	tmp = H[i];
	H[i] = H[bigger];
	H[bigger] =tmp;
	
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