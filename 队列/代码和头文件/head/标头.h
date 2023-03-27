#pragma once
#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

#include<stdio.h>
#include<malloc.h>
#include<assert.h>

//数据类型
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
void EnQueue(LinkQueue* Q, ElemType x);
void ShowQueue(LinkQueue* Q);
void DeQueue(LinkQueue* Q);
void GetHead(LinkQueue* Q, ElemType* v);
int Length(LinkQueue* Q);
void ClearQueue(LinkQueue* Q);
void DestroyQueue(LinkQueue* Q);

#endif //__LINKQUEUE_H__
