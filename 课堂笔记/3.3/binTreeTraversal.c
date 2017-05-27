void InorderTraversal(BinTree BT){
	if (BT)
	{
		InorderTraversal(BT->Left);
		printf("%d ", BT->Data);
		InorderTraversal(BT->Right);
	}
}

void PreorderTraversal(BinTree BT){
	if (BT) {
		printf("%d ", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

void PostorderTraversal(BinTree BT){
	if (BT) {
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf("%d ", BT->Data);
	}
}

void LevelorderTraversal(BinTree BT){
	Queue Q;
	BinTree T;

	if (!BT)
	{
		return;
	}

	Q = CreateQueue();
	AddQ(Q, BT);
	while (!IsEmpty(Q)) {
		T = DeleteQ(Q);
		printf("%d ", T->Data);
		if (T->Left)
		{
			AddQ(Q, T->Left);
		}
		if (T->Right)
		{
			AddQ(Q, T->Right);
		}
	}
}