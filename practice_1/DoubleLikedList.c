#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// ��� �� ����Ʈ ����

typedef struct DoubleLinkedListNode {
	
	int r;			// ����
	char elem;			// ����
	struct DoubleLinkedListNode* prev;	// ���� ���
	struct DoubleLinkedListNode* next;	// ���� ���

} node; // ���߿��Ḯ��Ʈ ��� 


typedef struct DoubleLinkedList{

	int size;	// ����Ʈ ũ��
	node* H;	// ���
	node* T;	// Ʈ���Ϸ�

} list; // ���߿��Ḯ��Ʈ(���, Ʈ���Ϸ� ����)

// �޼ҵ� ����

void init(list* list);
node* newNode(int r, char elem);
void ADD(list* list, int r, char e);
void DELETE(list* list, int r);
void GET(list* list, int r);
void print(list* list);

int main() {

	list list; init(&list);
	int opernum, r;
	char oper, elem;

	scanf("%d", &opernum);
	getchar();

	for (int i = 0; i < opernum; i++) {
		scanf("%c", &oper);
		getchar();

		switch (oper) {
		case 'A' :
			scanf("%d %c", &r, &elem);
			getchar();
			ADD(&list, r, elem);
			break;
		case 'D':
			scanf("%d", &r);
			getchar();
			DELETE(&list, r);
			break;
		case 'G':
			scanf("%d", &r);
			getchar();
			GET(&list, r);
			break;
		case 'P':
			print(&list);
			break;
		default:
			break;
		}
	}

	return;
}


// �޼ҵ� ����

void init(list* list) {

	node* header = (node *)malloc(sizeof(node));
	node* trailer = (node*)malloc(sizeof(node));

	list->H = header; header->next = trailer; header->prev = NULL;
	list->T = trailer; trailer->prev = header; trailer->next = NULL;
	list->size = 0;

} // DoublelinkedList ����

node* newNode(int r, char elem) {

	node* newnode = (node*)malloc(sizeof(node));

	newnode->next = NULL; newnode->prev = NULL;
	
	newnode->r = r;
	newnode->elem = elem;

	return newnode;

} // Node ����

void ADD(list* list, int r, char e) {

	node* newnode = newNode(r, e);
	node* node = list->H;

	// ��� ��ġ �̵� �� ��� �߰�
	for (int i = 0; i < r; i++) {
		node = node->next;
	} 
	
	// node.prev <- new -> node 
	newnode->next = node;
	newnode->prev = node->prev;

	// node -> new
	node->prev = newnode;

	// newnode <- node
	node = newnode->prev;
	node->next = newnode;

	list->size++;

}

void DELETE(list* list, int r) {

	node* node, *p, *q;
	node = list->H;

	if (r > list->size) {
		printf("invalid position\n");
		return;
	}

	// ��� �̵�
	for (int i = 0; i < r; i++) node = node->next;
	
	// node.prev -> node.next, node.prev <- node.next
	p = node->prev;
	q = node->next;
	p->next = q;
	q->prev = p;

	free(node);
	list->size--;

}
void GET(list* list, int r) {

	node* node = list->H;

	if (r > list->size) {
		printf("invalid position\n");
		return;
	}

	for (int i = 0; i < r; i++) {
		node = node->next;
	}

	printf("%c\n", node->elem);

}

void print(list* list) {

	node* node = list->H;

	for (int i = 0; i < list->size; i++) {
		node = node->next;
		printf("%c", node->elem);
	} printf("\n");

}