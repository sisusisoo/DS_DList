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


void print_list(DListNode* phead,DListNode*now ) {//일반 프린트아님 
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
	strcpy(newnode->data, data);// 주의
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

void ddelete( DListNode* removed) {
	if (removed->llink==removed) {
		printf("head는 지울수 없습니다.\n");
		return;
	}

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);

}

void select(DListNode* head) {
	//문제점 select는 계속반복되는데 여기다가 now=head문을 넣음, 반복문에서 초기화할때 주의

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
	printf("select a menu:");  //아무것도 안치고도 넘어감 (해결)
	scanf_s(" %c", &sel);

	if (sel != 'n' && sel != 'p' && sel != 'd' && sel != 'i' && sel != 'o' && sel != 'e') {
		printf("올바르지 않은 입력입니다.\n");
		return;
	}

	switch (sel) {
	case 'n':
		if (head->llink == head) {//now가 head 이면 이렇게 돼야하는데
			printf("is empty\n");//delete로 head만 남으면 오류 print에서
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
		
	case 'd'://현재과일 삭제 삭제하면 다음것이 현재과일이 됨
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
		

		if (head->rlink == head) {//처음과일이 추가되면 그게 선택(head->rlink==head->llink 했는데 안됐음)

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
	now = (DListNode*)malloc(sizeof(DListNode));//참조 잘안될때 중요!!!!!!!!!!!!!!
	now= head;

	while (1)
	{
		
		select(head);
	}





}