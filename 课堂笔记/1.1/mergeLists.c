#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode List;

List Read();
void Print(List L);
List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

List Read(){
	int listSize;
	int dataValue;
	PtrToNode head = NULL;
	PtrToNode tail = NULL;

	scanf("%d", &listSize);
	if (listSize == 0)
	{
		return NULL;
	}
	
	head = (PtrToNode) malloc(sizeof(struct Node));
	head->Next = NULL;
	tail = head; 

	while(listSize){
		scanf("%d", &dataValue);
		PtrToNode node = (PtrToNode) malloc(sizeof(struct Node));
		node->Data = dataValue;
		node->Next = NULL;
		tail->Next = node;
		tail = node;
		listSize--;
	}
	return head;
}

void Print(List L){
	if (L->Next == NULL){
		printf("NULL\n");
		return;
	}
	L = L->Next;
	while(L!=NULL){
		printf("%d ", L->Data);
		L = L->Next;
	}
	putchar('\n');
}

List Merge(List L1, List L2){
	List result;
	PtrToNode L = (PtrToNode) malloc(sizeof(struct Node));
	List p = L1->Next;
	List q = L2->Next;
	result = L;
	L->Next = NULL;
	while(p != NULL && q != NULL){
		if (p->Data < q->Data)
		{
			result->Next = p;
			p = p->Next;
			result = result->Next;
		}
		else{
			result->Next = q;
			q = q->Next;
			result = result->Next;
		}
	}
	result->Next = NULL;
	if(p!=NULL)
		result->Next = p;
	if(q!=NULL)
		result->Next = q;
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}