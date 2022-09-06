#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

// ��� �� Ʈ�� ����

typedef struct _node {
    int data;
    struct _node* left;
    struct _node* right;
} Node;

typedef struct _Btree
{
    Node * root;
    int size;
} BTree;

// �޼ҵ� ����

void initBTree(BTree* bt);
Node * newNode(int data);
void makeBTree(BTree* bt, int data, int left, int right);
Node* searchroot(Node* root, int data);
void searchTree(Node* node, char* str);

int main(void)
{
    int num;
    int data, left, right;
    char str[101];

    BTree * bt; 
    bt = (BTree*)malloc(sizeof(BTree));
    initBTree(bt);

    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d %d", &data, &left, &right);
        makeBTree(bt, data, left, right);
    }

    scanf("%d", &num); getchar();
    for (int i = 0; i < num; i++)
    {
        scanf("%[^\n]", str); getchar();
        searchTree(bt->root, str);
    }

    return 0;
}


void initBTree(BTree* bt) {

    bt->root = NULL;
    bt->size = 0;

} // Ʈ�� �ʱ�ȭ

Node * newNode(int data) {
    
    Node* new = (Node*)malloc(sizeof(Node));

    new->data = data;
    new->left = new->right = NULL;

    return new;

} // ��� ����


void makeBTree(BTree* bt, int data, int left, int right) {

    Node* node = NULL;
   
    if (!bt->root) { // ��Ʈ ��尡 ������ �ٷ� ����
        node = newNode(data);
        bt->root = node;
        bt->size++;
    } else {    // ��Ʈ ��� ����� �ش� data�� ������ ��� �˻�
        node = searchroot(bt->root, data);
    }
    
    if (left) { // �˻� �� ��Ʈ ����� ���� ��� ����
        node->left = newNode(left);
        bt->size++;
    } 

    if (right) { // �˻� �� ��Ʈ ����� ���� ��� ����
        node->right = newNode(right);
        bt->size++;
    }

} // Ʈ�� ����

Node* searchroot(Node* root, int data) {

    Node* node = NULL;

    // ��Ʈ ����̸� ��ȯ
    if (root->data == data) {
        return root;
    }

    // ���� ��� Ž��
    if (root->left && !node) {
            node = searchroot(root->left, data);
        }

     // ������ ��� Ž�� (��, ���� ��� Ž�� �� ��Ʈ ��带 �߰��ϸ� �̽���)
     if (root->right && !node) {
            node = searchroot(root->right, data);
      }
  
    return node;

} // ��Ʈ ��� ã��

void searchTree(Node* node, char* str) {
\
    int len = strlen(str);

    for (int i = 0; i <= len; i++) {
        printf(" %d", node->data);
        switch (*(str + i)) {
        case 'L':
            node = node->left;
            break;
        case 'R':
            node = node->right;
        }
    } printf("\n");
}