typedef int Position;
struct QNode
{
	ElementType *Data;
	Position Front, Rear;
	int MaxSize;
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize){
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

bool IsFull(Queue Q){
	return((Q->Rear+1)%Q->MaxSize == Q->Front);
}

bool AddQ(Queue Q, ElementType X){
	if (IsFull(Q))	
	{
		printf("FULL Queue\n");
		return false;
	}
	else{
		Q->Rear = (Q->Rear+1)%Q->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}

bool isEmpty(Queue Q){
	return(Q->Rear == Q->Front);
}

ElementType DeleteQ(Queue Q){
	if (isEmpty(Q))
	{
		printf("Queue is Empty\n");
		return ERROR;
	}
	else{
		Q->Front = (Q->Front+1)%Q->MaxSize;
		return Q->Data[Q->Front];
	}
}