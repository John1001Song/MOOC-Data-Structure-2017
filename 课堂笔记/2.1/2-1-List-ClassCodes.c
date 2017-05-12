typedef int Position;
typedef struct LNode *List;
struct LNode
{
	ElementType Data[MAXSIZE];
	Position Last;
};

List MakeEmpty(){
	List L;

	L = (List)malloc(sizeof(LNode));
	L->Last = -1;
	return L;
}

#define ERROR -1

Position Find(List L, ElementType X){
	Position i = 0;

	while(i < L->Last && L->Data[i]!=X){
		i++;
	}

	if (i > L->Last)
	{
		return ERROR;
	}else return i;
}

bool Insert(List L, ElementType X, Position P){
	Position i;

	if (L->Last == MAXSIZE-1)	
	{
		printf("FULL List\n");
		return false;
	}
	if (P < 0 || P > L->Last+1)
	{
		printf("illegal Position\n");
		return false;
	}
}for (i = L->Last; i >= P; i--)
{
	L->Data[i+1] = L->Data[i];]
L->Data[p] = x;
L->last++;
return true;

bool Delete(List L, Position P){
	Position i;
	if (p<0 || P>L->Position)
	{
		printf("Position or element does not exist\n");
		return false;
	}	
	for (i = p+1; i < L->Last; i++)
	{
		L->Data[i-1] = l=>Data[i]	}
	return true;
}


