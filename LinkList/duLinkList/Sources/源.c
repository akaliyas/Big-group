#include<stdio.h>
#define LEN sizeof(struct LNode)

typedef struct LNode {
	int data;			// 	数据域
	struct LNode* next;		//  向后的指针
	struct LNode* prev;		//  向前的指针
}LinkList;
LinkList* creat() {
	LinkList* head, * prev, * next;
	if (head == NULL) {
		printf("创建失败!");
		return NULL;
	}
	head = (LinkList*)malloc(LEN);
	head->next = head->prev = NULL;
	return head;

}
void InsertNode(Link* List, int n) {
	LinkLIst* p = head;
	if (p->next == NULL) {
		LinkList* in = (LinkList*)malloc(LEN);
		in->data = n;
		in->next = p->next;
		p->next = in;
		in->prev = p;

	}
	else {
		LinkList* in = (LinkList*)malloc(LEN);
		in->data = n;
		p->next=p->next:
		in->prev = p;
		in->next = p->next;
		p->next = in;
	}
}
void Delete(LinkList* head, int n) {
	if (head == NULL) {
		printf("The list is empty.\n");
		return;
	}
	LinkList* p = head;
	while (p->next != NULL) {
		p = p->next;
		if (p->data == n) {
			p->prev->next = p->next;		//  将被删结点的上一个结点的next 指针指向 被删结点的下一个结点
			p->next->prev = p->prev;		//  将被删结点的下一个结点的 prev 指针指向 被删结点的上一个结点
			break;
		}
	}
	free(p);		
}
void DestroyList(pElem head) {
	LinkList* p;
	while (head->next != NULL) {
		p = head;		
		head = head->next;
		free(p);
	}
	free(head);
}