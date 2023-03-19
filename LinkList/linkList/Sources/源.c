#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:C4703)
#include<stdio.h>
#include<malloc.h>
#include "Դ.h"
/* define struct of linked list
typedef struct LNode {
	ElemType data;
	struct LNode* next;
} LNode, * LinkedList;*/
typedef struct LNode {
	int score;
	struct LNode* next;
} LinkList;

LinkList* creat(int n) {
	LinkList* head, * node, * end;
	head = (LinkList*)malloc(sizeof(LinkList));
	if (head == NULL) {
		printf("����ʧ��!");
		return NULL;
	}
	head->next = NULL;
	end = head;     
	puts("��������������");
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
		scanf_s("%d", &node->score);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}
void change(LinkList* list, int n) {
	LinkList* t = list;
	int i = 0;
	while (i < n && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
		puts("����Ҫ�޸ĵ�ֵ");
		scanf_s("%d", &t->score);
	}
	else {
		puts("�ڵ㲻����");
	}
}
void delet(LinkList* list, int n) {
	LinkList* t = list, *in=list;
	int i = 0;
	while (i < n && t != NULL) {
		in = t;
		t = t->next;
		i++;
	}
	if (t != NULL) {
		in->next = t->next;
		free(t);
	}
	else {
		puts("�ڵ㲻����");
	}
}
void insert(LinkList* list, int n) {
	LinkList* t = list, * in;
	int i = 0;
	while (i < n && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
		in = (LinkList*)malloc(sizeof(LinkList));
		puts("����Ҫ�����ֵ");
		scanf_s("%d", &in->score);
		in->next = t->next;
		t->next = in;
	}
	else {
		puts("�ڵ㲻����");
	}
}
void destroyed(LinkList* list) {
	LinkList* h = list,*d;
	while (h->next != NULL) {
		d = h;
		h = h->next;
		free(d);
	}
}
void getnode(LinkList* list, int n) {
	int i=0;
	LinkList* p = list;
	while (p->next && i < n) {
		p = p->next;
		i++;
	}
	if (n == i) {
		puts("�ڵ�Ϊ ");
		return p;
	}
	else puts("�ڵ�Ϊ��");
}
void searchnode(LinkList* list, int key) {
	LinkList* p = list->next; int t = 1;
	while (p && p->score != key) {
		p = p->next; t++;
	}
	if (p) {
		printf_s("�ڵ�Ϊ��%d�� ",t);
		return p;
	}
	else puts("����ʧ�ܣ�");
}
void printlist(LinkList *list) {
		LinkList* p = list;
		for (p = list->next; p != NULL; p = p->next) {
			printf("%d ", p->score);
		}
	
}

int LLL = 1;
void Mainmenu(void)
{
	printf("\t   ************************************************************\n");
	if (LLL) {
		printf("\t   *                  ��ӭ����������ADT                       *\n");
		LLL = 0;
	}
	else {
		printf("\t   *                                                          *\n");
		printf("\t   *      �����Խ������²���:                                 *\n");
	}
	printf("\t   *                                                          *\n");
	printf("\t   *      �������� �밴 1                                     *\n\n");
	printf("\t   *          ���¹��ܽ�������������                        *\n\n");
	printf("\t   *      ���ڵ���Ų��� �밴 2                               *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      ���ڵ����ݲ��� �밴 3                               *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      �޸Ľڵ����� �밴 4                                 *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      ɾ���ڵ� �밴 5                                     *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      ����ڵ� �밴 6                                     *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      �������� �밴 7                                     *\n");
	printf("\t   *			                                                *\n");
	printf("\t   *      ��ӡ���� �밴 8                                     *\n");
	printf("\t   ************************************************************\n\n");
}

void main() {
	LinkList* head=NULL;
	LLL = 1;
	int op,selt,n = 0;
	while (1) {
		Mainmenu();
		op = scanf_s("%d", &selt);
		if (!op) {
			puts("���������룡");
			continue;
		}
		switch (selt) {
		case 1:
			puts("���Ժ�");
			puts("������ڵ����");
			scanf_s("%d", &n);
			head = creat(n);
			puts("�Ѵ�������"); break;
		case 2:
			puts("���Ժ�");
			puts("����������ڵ����");
			scanf_s("%d", &n);
			getnode(head, n);
			puts("���ҵ�Ŀ������"); break;
		case 3:
			puts("���Ժ�");
			puts("������ڵ�����");
			scanf_s("%d", &n);
			searchnode(head, n);
			puts("���ҵ�Ŀ������"); break;
		case 4:
			puts("���Ժ�");
			puts("����������ڵ����");
			scanf_s("%d", &n);
			change(head, n);
			puts("���޸�����"); break;
		case 5:
			puts("���Ժ�");
			puts("����������ڵ����");
			scanf_s("%d", &n);
			delet(head, n);
			puts("��ɾ���ڵ�"); break;
		case 6:
			puts("���Ժ�");
			puts("����������ڵ����");
			scanf_s("%d", &n);
			insert(head, n);
			puts("�Ѳ���ڵ�"); break;
		case 7:
			puts("���Ժ�");
			destroyed(head);
			puts("����������"); break;
		case 8:
			puts("���Ժ�");
		
			printlist(head);
			puts("�Ѵ�ӡ����");
			break;
		}
		
	}

	return 0;
}	
