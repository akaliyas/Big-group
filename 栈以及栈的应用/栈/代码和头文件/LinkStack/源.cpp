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
}//初始化
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
}//入栈
void Show(LinkStack* s) {
	StackNode* p = *s;
	while (p != NULL) {
		printf_s("%d\n", p->data);
		p = p->next;

	}
	printf_s("\n");
}//遍历打印
void Pop(LinkStack* s) {
	StackNode* p = *s;
	*s = p->next;
	free(p);
	p = NULL;
}//出栈

int isEmpty(LinkStack* s) {
	if (*s == NULL)return 1;
	else return 0;
}//判断空栈

int GetTop(LinkStack* s, ElemType* x) {
	if (isEmpty(s)) {
		printf_s("空栈，error\n");
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
}//获取长度
void Clear(LinkStack* s) {
	while (*s != NULL) {
		Pop(s);
	}
}//清空栈
void main(){
	LinkStack st;
	int n = 0;
	InitStack(&st);
	printf_s("请输入初始栈节点数");
	scanf_s("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int j=0;
		printf_s("输入push的数据（整型）");
		scanf_s("%d", &j);
		Push(&st,j );
	}
	puts("以下是栈展示");
	Show(&st);
	printf("栈长度：%d\n", GetLen(&st));
	ElemType v;
	if (GetTop(&st, &v))
		printf_s("栈顶元素：%d\n\n", v);

	do {
		printf_s("扣1执行入栈，扣2执行出栈，扣3展示栈元素，扣4清空栈并退出\n");
		int j = 0;
		scanf_s("%d",&j);
		if (j == 1) {
			printf_s("输入push的数据（整型）");
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