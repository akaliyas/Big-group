#include<stdio.h>
#include<malloc.h>
#include<assert.h>

#define ElemType int

//���н������
typedef struct QueueNode
{
	ElemType data;          //������
	struct QueueNode* next; //ָ����
}QueueNode;

//��ʽ���й���ṹ
typedef struct LinkQueue
{
	QueueNode* front;  //��ͷָ��
	QueueNode* tail;   //��βָ��
}LinkQueue;

void InitQueue(LinkQueue* Q);
void DestroyQueue(LinkQueue* Q);

void EnQueue(LinkQueue* Q, ElemType x);
void DeQueue(LinkQueue* Q);
void ClearQueue(LinkQueue* Q);

void GetHead(LinkQueue* Q, ElemType* v);
void ShowQueue(LinkQueue* Q);



int LengthQueue(LinkQueue* Q);



//��ʼ������
void InitQueue(LinkQueue* Q)
{
	//����ͷ����ڴ�ռ�
	QueueNode* s = (QueueNode*)malloc(sizeof(QueueNode));
	assert(s != NULL);
	//��ʼ��ʱ����ͷָ���βָ�붼ָ��ͷ���
	Q->front = Q->tail = s;
	//��ͷ������һ��㸳��
	Q->tail->next = NULL;
}

//��Ӳ������ڶ�βִ�в������
void EnQueue(LinkQueue* Q, ElemType x)
{
	//������н��
	QueueNode* s = (QueueNode*)malloc(sizeof(QueueNode));
	assert(s != NULL);
	//Ϊ����Ķ��н�㸳ֵ
	s->data = x;
	s->next = NULL;
	//������Ķ��н����뵽��β
	Q->tail->next = s;
	//���Ķ��й�������βָ���ָ��
	Q->tail = s;
}

//��ӡ�����ڵ�����
void ShowQueue(LinkQueue* Q)
{
	//��ȡ�����е�һ����Ч���
	QueueNode* p = Q->front->next;
	printf("Front:>");
	//��������ÿ����Ч����е����ݴ�ӡ
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("<:Tail.\n");
}

//���Ӳ�����ɾ����ͷ�ĵ�һ����Ч���
void DeQueue(LinkQueue* Q)
{
	//�����������Ч��㣬������в���
	if (Q->front == Q->tail)
		return;

	//��ȡ��ͷ�ĵ�һ����Ч���
	QueueNode* p = Q->front->next;
	//����ͷ�ĵ�һ����Ч���Ӷ����жϿ�
	Q->front->next = p->next;
	//�ͷŸý��
	free(p);
	//���ɾ���Ľ�������һ����Ч��㣬��Ҫ����βָ���ָ��
	if (p == Q->tail)
		Q->tail = Q->front;
}
//��ȡ��ͷԪ��
void GetHead(LinkQueue* Q)
{
	//�����������Ч��㣬������в���
	if (Q->front == Q->tail)
		return;
	//��ȡ��ͷ�ĵ�һ����Ч���
	QueueNode* p = Q->front->next;
	//���ض�ͷ��һ����Ч�������
	printf_s("ͷ�ڵ�����Ϊ%d", p->data);
}

//����еĳ���
int LengthQueue(LinkQueue* Q)
{
	int len = 0;//��ʼ����Ϊ0
	//��ȡ��ͷ�ĵ�һ����Ч���
	QueueNode* p = Q->front->next;
	//�������У���ȡһ����㣬�����г��ȼ�һ
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	//���س���ֵ
	return len;
}

//��ն��У��ͷ����е���Ч���
void ClearQueue(LinkQueue* Q)
{
	//�����������Ч��㣬������в���
	if (Q->front == Q->tail)
		return;
	//��ȡ��ͷ�ĵ�һ����Ч���
	QueueNode* p = Q->front->next;
	//���������е���Ч���
	while (p != NULL)
	{
		//�Ƴ����
		Q->front->next = p->next;
		//�ͷŽ��
		free(p);
		//ָ����һ�����
		p = Q->front->next;
	}
	Q->tail = Q->front;
}

bool IsEmpty(LinkQueue* Q) {//�жϿ� 
	if (Q->front == Q->tail) {	//Q.front->next==NULL   Ӧ��Ҳ���԰� 
		puts("Empty");
		return true;
	}
	else {
		puts("Not Empty");
		return false;
	}
	
}



//���ٶ���
void DestroyQueue(LinkQueue* Q)
{
	//��ն���
	ClearQueue(Q);
	//�ͷ�ͷ���
	free(Q->front);
	//���������е�ͷָ���βָ�붼ָ���
	Q->front = Q->tail = NULL;
}

void main()
{
	LinkQueue Q;
	InitQueue(&Q);//��ʼ������

	for (int i = 1; i <= 10; ++i)
	{
		EnQueue(&Q, i);//��Ӳ���
	}
	int flag = 0;
	ShowQueue(&Q);
	do {
		printf_s("\n��1ִ����ӣ�\n��2ִ�г��ӣ�\n��3���ջ��\n��4�鿴��ͷ��\n");
		printf_s("��5�ж϶ӿգ�\n��6�鿴���г��ȣ�\n��7�����鿴���в��˳�.\n");
		int j = 0; 
		scanf_s("%d", &j);
		if (j == 1) {
			printf_s("\n����Enqueue�����ݣ����ͣ�");
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
