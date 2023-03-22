#include<stdio.h>
#include<assert.h>
#define LEN sizeof(struct LNode)

typedef struct LNode {
	int data;			// 	������
	struct LNode* next;		//  ����ָ��
	struct LNode* prev;		//  ��ǰ��ָ��
}LinkList;
LinkList* creat() {
	
	LinkList* node = (LinkList*)malloc(LEN);

	
	node->prev = NULL;
	node->next = NULL;
	return node;

}//��������
void InsertNode(LinkList* head, int n) {
	LinkList* p = head;
	if (head == NULL) {
		printf("The list is empty.\n");		//  ͷ���Ϊ�գ����޷�����
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
}//��������
void Delete(LinkList* head, int n) {
	if (head == NULL) {
		printf("The list is empty.\n");
		return;
	}
	LinkList* p = head;
	while (p->next != NULL) {
		p = p->next;
		if (p->data == n) {
			p->prev->next = p->next;		//  ����ɾ������һ������next ָ��ָ�� ��ɾ������һ�����
			p->next->prev = p->prev;		//  ����ɾ������һ������ prev ָ��ָ�� ��ɾ������һ�����
			break;
		}
	}
	free(p);
}                    //ɾ���ڵ�      
void DestroyList(LinkList* head) {
	LinkList* p;

	while (head->next != NULL) {
		p = head;
		head = head->next;
		free(p);
	}
	free(head);
}//��������
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
		printf("\t   *                  ��ӭ����˫����ADT                       *\n");
		LLL = 0;
	}
	else {
		printf("\t   *                                                          *\n");
		printf("\t   *      �����Խ������²���:                                 *\n");
	}
	printf("\t   *                                                          *\n");
	printf("\t   *      �������� �밴 1                                     *\n\n");
	printf("\t   *          ���¹��ܽ�������������                        *\n\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      ����ڵ� �밴 2                                    *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      ɾ���ڵ� �밴 3                                     *\n");
	printf("\t   *                                                          *\n");
	printf("\t   *      �������� �밴 4                                     *\n");
	printf("\t   *			                                                *\n");
	printf("\t   *      ��ӡ��ǰ���� �밴 5                                 *\n");
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
			puts("���������룡");
			continue;
		}
		switch (selt) {
		case 1:
			puts("���Ժ�");
			scanf_s("������ͷ�ڵ�int���� %d", &n);
			head = creat(n);
			puts("�Ѵ�������"); break;
		case 2:
			puts("���Ժ�");
			puts("����������ڵ�����");
			scanf_s("%d", &n);
			InsertNode(head, n);
			puts("�Ѳ���ڵ�"); break;
		case 3:
			puts("���Ժ�");
			puts("����������ڵ����");
			scanf_s("%d", &n);
			Delete(head, n);
			puts("��ɾ���ڵ�"); break;
		case 4:
			puts("���Ժ�");
			DestroyList(head);
			puts("����������"); break;
		case 5:
			puts("���Ժ�");

			printlist(head);
			puts("�Ѵ�ӡ����");
			break;
		}

	}

	return 0;
}
