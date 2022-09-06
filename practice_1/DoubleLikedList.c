#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// ���, ����Ʈ ����

typedef struct _node {

	char e;
	struct _node* prev;
	struct _node* next;

} Node;

typedef struct _DoubleLinkedList {

	Node* H, * T;
	int size;

} DoubleLinkedList;

// �޼ҵ� ����

void initList(DoubleLinkedList* list);
Node* newNode(char e);
void add(DoubleLinkedList* list, int r, char e);
void delete(DoubleLinkedList* list, int r);
void get(DoubleLinkedList* list, int r);
void print(DoubleLinkedList* list);

int main() {

	DoubleLinkedList* list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	int num, r;
	char oper, e;

	initList(list);

	scanf("%d", &num); getchar();
	for (int i = 0; i < num; i++) {

		scanf("%c", &oper); getchar();

		switch (oper) {

		case 'A':
			scanf("%d %c", &r, &e); getchar();
			add(list, r, e);
			break;

		case 'D':
			scanf("%d", &r); getchar();
			delete(list, r);
			break;
		case 'G':
			scanf("%d", &r); getchar();
			get(list, r);
			break;
		case 'P':
			print(list);
			break;

		}
	}

	return 0;

}

void initList(DoubleLinkedList* list) {

	Node* H, * T;

	H = (Node*)malloc(sizeof(Node));
	T = (Node*)malloc(sizeof(Node));

	list->H = H; H->next = T; H->prev = NULL;
	list->T = T; T->prev = H; T->next = NULL;

	list->size = 0;

}

Node* newNode(char e) {

	Node* new = (Node*)malloc(sizeof(Node));

	new->prev = new->next = NULL;
	new->e = e;

	return new;

}

void add(DoubleLinkedList* list, int r, char e) {

	Node* new;
	Node* pos = list->H;

	// ���� ���� ����
	// 4���� �Է� �� 6���� �Է� �Ұ�. �ݵ�� 1, 2, 3, 4, 5 , ... ���� ����.
	if (list->size + 1 < r) {
		printf("invalid position\n");
		return;
	}

	new = newNode(e);

	// ��� �̵�
	for (int i = 0; i < r; i++) pos = pos->next;

	// ��� ����
	pos->prev->next = new;
	new->prev = pos->prev;

	pos->prev = new;
	new->next = pos;

	pos = new;
	list->size++;

}

void delete(DoubleLinkedList* list, int r) {

	Node* pos = list->H;

	if (list->size < r) {
		printf("invalid position\n");
		return;
	}

	// ��� �̵�
	for (int i = 0; i < r; i++) pos = pos->next;

	// ���� ����� ��, �� ��� ����
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	// ��� ����
	free(pos);
	list->size--;
}

void get(DoubleLinkedList* list, int r) {

	Node* pos = list->H;

	if (list->size < r) {
		printf("invalid position\n");
		return;
	}

	// ��� �̵�
	for (int i = 0; i < r; i++) pos = pos->next;
	printf("%c\n", pos->e);

}

void print(DoubleLinkedList* list) {

	Node* node = list->H;
	int size = list->size;

	for (int i = 0; i < size; i++) {
		node = node->next;
		printf("%c", node->e);
	} printf("\n");

}