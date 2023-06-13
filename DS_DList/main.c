#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996) 
typedef char element[10];


typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;



void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;

}


DListNode* now;


void print_list(DListNode* phead,DListNode*now ) {//�Ϲ� ����Ʈ�ƴ� 
	DListNode* p;

	for (p = phead->rlink; phead != p; p = p->rlink){

		//printf("%s,%s\n", p->data, now->data);
		if (strcmp(p->data, now->data) == 0) {
			printf("%s[0]\n", p->data);
			
		}
		else {
		
			printf("%s\n", p->data);
		}
	
	}
	
	printf("\n");

}

void dinsert(DListNode* before,element data) {

	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);// ����
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete( DListNode* removed) {
	if (removed->llink==removed) {
		printf("head�� ����� �����ϴ�.\n");
		return;
	}

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);

}

void select(DListNode* head) {
	//������ select�� ��ӹݺ��Ǵµ� ����ٰ� now=head���� ����, �ݺ������� �ʱ�ȭ�Ҷ� ����

	char sel;
	char fruit[10];
	char sample = 'n';
	DListNode *temp=(DListNode*)malloc(sizeof(DListNode));
	printf("n) next Fruit\n");
	printf("p) previous Fruit\n");
	printf("d) delete the current fruit\n");
	printf("i) insert fruit after current fruit\n");
	printf("o) output the fruit list(Output [0] at the end of the currently selected fruit)\n");
	printf("e) exit the program\n");
	printf("select a menu:");  //�ƹ��͵� ��ġ�� �Ѿ (�ذ�)
	scanf_s(" %c", &sel);

	if (sel != 'n' && sel != 'p' && sel != 'd' && sel != 'i' && sel != 'o' && sel != 'e') {
		printf("�ùٸ��� ���� �Է��Դϴ�.\n");
		return;
	}

	switch (sel) {
	case 'n':
		if (head->llink == head) {//now�� head �̸� �̷��� �ž��ϴµ�
			printf("is empty\n");//delete�� head�� ������ ���� print����
			return;
		}
		now=now->rlink;
		//("%s\n",now->data);
		
		break;

	case 'p':
		if (head->llink == head) {
			printf("is empty\n");
			return;
		}
		now = now->llink;
		printf("%s\n", now->data);
		
		break;
		
	case 'd'://������� ���� �����ϸ� �������� ��������� ��
		if (head->llink == head) {
			printf("is empty\n");
			return;
		}
		temp = now->rlink;
		ddelete(now);
		now = temp;
	
		break;

	case 'i':

		printf("Enter the name of the fruit to add:");
		scanf_s("%s", fruit,sizeof(char)*10);
		

		if (head->rlink == head) {//ó�������� �߰��Ǹ� �װ� ����(head->rlink==head->llink �ߴµ� �ȵ���)

			dinsert(now, fruit);
			now = now->rlink;
			//printf("%s\n", now->data);
		}
		else {
			dinsert(now, fruit);
		}
		
		
		break;

	case 'o':
		//printf("%s sel \n", now->data);
		print_list(head,now);
		break;

	case 'e':
		exit(1);
		break;

	}

}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	now = (DListNode*)malloc(sizeof(DListNode));//���� �߾ȵɶ� �߿�!!!!!!!!!!!!!!
	now= head;

	while (1)
	{
		
		select(head);
	}





}