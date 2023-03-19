#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:C4703)
#include<stdio.h>
#include<malloc.h>
#include "源.h"
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
		printf("创建失败!");
		return NULL;
	}
	head->next = NULL;
	end = head;     
	puts("请依次输入数据");
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
		puts("输入要修改的值");
		scanf_s("%d", &t->score);
	}
	else {
		puts("节点不存在");
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
		puts("节点不存在");
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
		puts("输入要插入的值");
		scanf_s("%d", &in->score);
		in->next = t->next;
		t->next = in;
	}
	else {
		puts("节点不存在");
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
		puts("节点为 ");
		return p;
	}
	else puts("节点为空");
}
void searchnode(LinkList* list, int key) {
	LinkList* p = list->next; int t = 1;
	while (p && p->score != key) {
		p = p->next; t++;
	}
	if (p) {
		printf_s("节点为第%d个 ",t);
		return p;
	}
	else puts("查找失败！");
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
		printf("\t   *                  欢迎来到单链表ADT                       *\n");
		LLL = 0;
	}
	else {
		printf("\t   *                                                          *\n");
		printf("\t   *      您可以进行以下操作:                                 *\n");
	}
	printf("\t   *                                                          *\n");
	printf("\t   *      创建链表 请按 1                                     *\n\n");
	printf("\t   *          以下功能仅创建链表后可用                        *\n\n");
	printf("\t   *      按节点序号查找 请按 2                               *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      按节点数据查找 请按 3                               *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      修改节点数据 请按 4                                 *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      删除节点 请按 5                                     *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      插入节点 请按 6                                     *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      销毁链表 请按 7                                     *\n");
	printf("\t   *			                                                *\n");
	printf("\t   *      打印链表 请按 8                                     *\n");
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
			puts("请重新输入！");
			continue;
		}
		switch (selt) {
		case 1:
			puts("请稍后");
			puts("请输入节点个数");
			scanf_s("%d", &n);
			head = creat(n);
			puts("已创建链表"); break;
		case 2:
			puts("请稍后");
			puts("请输入链表节点序号");
			scanf_s("%d", &n);
			getnode(head, n);
			puts("已找到目标数据"); break;
		case 3:
			puts("请稍后");
			puts("请输入节点数据");
			scanf_s("%d", &n);
			searchnode(head, n);
			puts("已找到目标数据"); break;
		case 4:
			puts("请稍后");
			puts("请输入链表节点序号");
			scanf_s("%d", &n);
			change(head, n);
			puts("已修改数据"); break;
		case 5:
			puts("请稍后");
			puts("请输入链表节点序号");
			scanf_s("%d", &n);
			delet(head, n);
			puts("已删除节点"); break;
		case 6:
			puts("请稍后");
			puts("请输入链表节点序号");
			scanf_s("%d", &n);
			insert(head, n);
			puts("已插入节点"); break;
		case 7:
			puts("请稍后");
			destroyed(head);
			puts("已销毁链表"); break;
		case 8:
			puts("请稍后");
		
			printlist(head);
			puts("已打印链表");
			break;
		}
		
	}

	return 0;
}	
