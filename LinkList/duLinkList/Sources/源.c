#include<stdio.h>
#include<assert.h>
#define LEN sizeof(struct LNode)

typedef struct LNode {
	int data;			// 	数据域
	struct LNode* next;		//  向后的指针
	struct LNode* prev;		//  向前的指针
}LinkList;
LinkList* creat() {
	
	LinkList* node = (LinkList*)malloc(LEN);

	
	node->prev = NULL;
	node->next = NULL;
	return node;

}//生成链表
void InsertNode(LinkList* head, int n) {
	LinkList* p = head;
	if (head == NULL) {
		printf("The list is empty.\n");		//  头结点为空，则无法插入
		return;
	}
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
		p->next = p->next;
		in->prev = p;
		in->next = p->next;
		p->next = in;
	}
}//插入链表
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
}                    //删除节点      
void DestroyList(LinkList* head) {
	LinkList* p;

	while (head->next != NULL) {
		p = head;
		head = head->next;
		free(p);
	}
	free(head);
}//销毁链表
void printlist(LinkList* head) {
	LinkList* p = head;
	if (head == NULL) {
		printf_s("The list is empty.\n");
		return;
	}
	for (p = head->next; p != NULL; p = p->next) {
		printf("%d ", p->data);
	}
}
int LLL = 1;
void Mainmenu(void)
{
	printf("\t   ************************************************************\n");
	if (LLL) {
		printf("\t   *                  欢迎来到双链表ADT                       *\n");
		LLL = 0;
	}
	else {
		printf("\t   *                                                          *\n");
		printf("\t   *      您可以进行以下操作:                                 *\n");
	}
	printf("\t   *                                                          *\n");
	printf("\t   *      创建链表 请按 1                                     *\n\n");
	printf("\t   *          以下功能仅创建链表后可用                        *\n\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      插入节点 请按 2                                    *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      删除节点 请按 3                                     *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      销毁链表 请按 4                                     *\n");
	printf("\t   *			                                                *\n");
	printf("\t   *      打印当前链表 请按 5                                 *\n");
	printf("\t   ************************************************************\n\n");
}
void main() {
	LinkList* head = NULL;
	LLL = 1;
	int op, selt, n = 0;
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
			scanf_s("请输入头节点int数据 %d", &n);
			head = creat(n);
			puts("已创建链表"); break;
		case 2:
			puts("请稍后");
			puts("请输入链表节点数据");
			scanf_s("%d", &n);
			InsertNode(head, n);
			puts("已插入节点"); break;
		case 3:
			puts("请稍后");
			puts("请输入链表节点序号");
			scanf_s("%d", &n);
			Delete(head, n);
			puts("已删除节点"); break;
		case 4:
			puts("请稍后");
			DestroyList(head);
			puts("已销毁链表"); break;
		case 5:
			puts("请稍后");

			printlist(head);
			puts("已打印链表");
			break;
		}

	}

	return 0;
}
