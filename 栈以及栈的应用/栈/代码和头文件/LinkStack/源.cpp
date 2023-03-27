#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define ElemType int
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;

} StackNode,*LinkStack;
void InitStack(LinkStack* s) {
	*s = NULL;
}//��ʼ��
void Push(LinkStack* s, ElemType x) {
	StackNode* p = new StackNode;//=(StackNode*)malloc(sizeof(StackNode))
	p->data = x;
	if (*s == NULL) {
		*s = p;
		p->next = NULL;
	}
	else {
		p->next = *s;
		*s = p;
	}
}//��ջ
void Show(LinkStack* s) {
	StackNode* p = *s;
	while (p != NULL) {
		printf_s("%d\n", p->data);
		p = p->next;

	}
	printf_s("\n");
}//������ӡ
void Pop(LinkStack* s) {
	StackNode* p = *s;
	*s = p->next;
	free(p);
	p = NULL;
}//��ջ

int isEmpty(LinkStack* s) {
	if (*s == NULL)return 1;
	else return 0;
}//�жϿ�ջ

int GetTop(LinkStack* s, ElemType* x) {
	if (isEmpty(s)) {
		printf_s("��ջ��error\n");
		return 0;
	}
	*x = (*s)->data;
	return 1;
}

int GetLen(LinkStack* s) {
	int len = 0;
	StackNode* p = *s;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}//��ȡ����
void Clear(LinkStack* s) {
	while (*s != NULL) {
		Pop(s);
	}
}//���ջ
void main(){
	LinkStack st;
	int n = 0;
	InitStack(&st);
	printf_s("�������ʼջ�ڵ���");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int j=0;
		printf_s("����push�����ݣ����ͣ�");
		scanf_s("%d", &j);
		Push(&st,j );
	}
	puts("������ջչʾ");
	Show(&st);
	printf("ջ���ȣ�%d\n", GetLen(&st));
	ElemType v;
	if (GetTop(&st, &v))
		printf_s("ջ��Ԫ�أ�%d\n\n", v);

	do {
		printf_s("��1ִ����ջ����2ִ�г�ջ����3չʾջԪ�أ���4���ջ���˳�\n");
		int j = 0;
		scanf_s("%d",&j);
		if (j == 1) {
			printf_s("����push�����ݣ����ͣ�");
			int i = 0;
			scanf_s("%d", &i);
			Push(&st, i);
			Show(&st);
		}
		if (j == 2) {
			Pop(&st);
			Show(&st);
		}if (j == 3) {
			Show(&st);
		}if (j == 4) {
			Clear(&st);
		}

		
	} while (!isEmpty(&st));
	Clear(&st);

	if (isEmpty(&st))
		printf_s("ture\n");
	else
		printf_s("false\n");

}