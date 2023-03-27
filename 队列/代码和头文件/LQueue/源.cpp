#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define ElemType int

//队列结点类型
typedef struct QueueNode
{
	ElemType data;          //数据域
	struct QueueNode* next; //指针域
}QueueNode;

//链式队列管理结构
typedef struct LinkQueue
{
	QueueNode* front;  //队头指针
	QueueNode* tail;   //队尾指针
}LinkQueue;

void InitQueue(LinkQueue* Q);
void DestroyQueue(LinkQueue* Q);

void EnQueue(LinkQueue* Q, ElemType x);
void DeQueue(LinkQueue* Q);
void ClearQueue(LinkQueue* Q);

void GetHead(LinkQueue* Q, ElemType* v);
void ShowQueue(LinkQueue* Q);



int LengthQueue(LinkQueue* Q);



//初始化队列
void InitQueue(LinkQueue* Q)
{
	//申请头结点内存空间
	QueueNode* s = (QueueNode*)malloc(sizeof(QueueNode));
	assert(s != NULL);
	//初始化时，将头指针和尾指针都指向头结点
	Q->front = Q->tail = s;
	//将头结点的下一结点赋空
	Q->tail->next = NULL;
}

//入队操作：在队尾执行插入操作
void EnQueue(LinkQueue* Q, ElemType x)
{
	//申请队列结点
	QueueNode* s = (QueueNode*)malloc(sizeof(QueueNode));
	assert(s != NULL);
	//为申请的队列结点赋值
	s->data = x;
	s->next = NULL;
	//将申请的队列结点插入到队尾
	Q->tail->next = s;
	//更改队列管理结点中尾指针的指向
	Q->tail = s;
}

//打印队列内的数据
void ShowQueue(LinkQueue* Q)
{
	//获取队列中第一个有效结点
	QueueNode* p = Q->front->next;
	printf("Front:>");
	//将队列中每个有效结点中的数据打印
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("<:Tail.\n");
}

//出队操作：删除队头的第一个有效结点
void DeQueue(LinkQueue* Q)
{
	//如果队中无有效结点，无需进行操作
	if (Q->front == Q->tail)
		return;

	//获取队头的第一个有效结点
	QueueNode* p = Q->front->next;
	//将队头的第一个有效结点从队列中断开
	Q->front->next = p->next;
	//释放该结点
	free(p);
	//如果删除的结点是最后一个有效结点，需要更改尾指针的指向
	if (p == Q->tail)
		Q->tail = Q->front;
}
//获取队头元素
void GetHead(LinkQueue* Q)
{
	//如果队中无有效结点，无需进行操作
	if (Q->front == Q->tail)
		return;
	//获取队头的第一个有效结点
	QueueNode* p = Q->front->next;
	//返回队头第一个有效结点数据
	printf_s("头节点数据为%d", p->data);
}

//求队列的长度
int LengthQueue(LinkQueue* Q)
{
	int len = 0;//初始长度为0
	//获取队头的第一个有效结点
	QueueNode* p = Q->front->next;
	//遍历队列，获取一个结点，将队列长度加一
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	//返回长度值
	return len;
}

//清空队列：释放所有的有效结点
void ClearQueue(LinkQueue* Q)
{
	//如果队中无有效结点，无需进行操作
	if (Q->front == Q->tail)
		return;
	//获取队头的第一个有效结点
	QueueNode* p = Q->front->next;
	//遍历队列中的有效结点
	while (p != NULL)
	{
		//移除结点
		Q->front->next = p->next;
		//释放结点
		free(p);
		//指向下一个结点
		p = Q->front->next;
	}
	Q->tail = Q->front;
}

bool IsEmpty(LinkQueue* Q) {//判断空 
	if (Q->front == Q->tail) {	//Q.front->next==NULL   应该也可以吧 
		puts("Empty");
		return true;
	}
	else {
		puts("Not Empty");
		return false;
	}
	
}



//销毁队列
void DestroyQueue(LinkQueue* Q)
{
	//清空队列
	ClearQueue(Q);
	//释放头结点
	free(Q->front);
	//将管理结点中的头指针和尾指针都指向空
	Q->front = Q->tail = NULL;
}

void main()
{
	LinkQueue Q;
	InitQueue(&Q);//初始化队列

	for (int i = 1; i <= 10; ++i)
	{
		EnQueue(&Q, i);//入队操作
	}
	int flag = 0;
	ShowQueue(&Q);
	do {
		printf_s("\n扣1执行入队，\n扣2执行出队，\n扣3清空栈，\n扣4查看队头，\n");
		printf_s("扣5判断队空，\n扣6查看队列长度，\n扣7遍历查看队列并退出.\n");
		int j = 0; 
		scanf_s("%d", &j);
		if (j == 1) {
			printf_s("\n输入Enqueue的数据（整型）");
			int i = 0;
			scanf_s("%d", &i);
			EnQueue(&Q, i);
			ShowQueue(&Q);
		}
		if (j == 2) {
			DeQueue(&Q);
			ShowQueue(&Q);
		}
		if (j == 3) {
			ClearQueue(&Q);
			;
		}
		if (j == 4) {
			GetHead(&Q);
			;
		}
		if (j == 5) {
			IsEmpty(&Q);
		}
		if (j == 6) {
			printf_s("Length=%d\n",LengthQueue(&Q));
		}
		if (j == 7) {

			ShowQueue(&Q);
			flag = 1;
		}


	} while (!flag);
	printf("Len = %d\n", LengthQueue(&Q));
}
