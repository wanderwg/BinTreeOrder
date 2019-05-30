#include "BinTree.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Queue.h"


void PreOrder(BTNode* pRoot) {
	if (pRoot) {
		printf("%c",pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

void InOrder(BTNode* pRoot) {
	if (pRoot) {
		InOrder(pRoot->_pLeft);
		printf("%c",pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

void PostOrder(BTNode* pRoot) {
	if (pRoot) {
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c", pRoot->_data);
	}
}

void LevelOrder(BTNode* pRoot) {
	if (pRoot == NULL)
		return;
	Queue q;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q)) {
		BTNode* pCur = QueueFront(&q);//ȡ��ͷԪ��
		printf("%c ", pCur->_data);
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);//�����Ӵ��ڣ��������
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);//���Һ��Ӵ��ڣ��������
		QueuePop(&q);
	}
	QueueDestory(&q);
	printf("\n");
}
