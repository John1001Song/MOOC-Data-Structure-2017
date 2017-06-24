BinTree Insert(BinTree BST, ElementType X){
	if (!BST)
	{
		BST = (BinTree) malloc (sizeof(struct TNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	}
	else {
		if (X < BST->Data)
		{
			BST->Left = Insert(BST->Left, X);
		}
		else if (X > BST->Data)
			BST->Right = Insert(BST->Right, X);
	}
	return BST;
}

BinTree Delete(BinTree BST, ElementType X){
	Position Tmp;

	if (!BST) 
		printf("Can not find the wanted element\n");
	else {
		if (X < BST->Data)
			BST->Left = Delete(BST->Left, X);
		else if (X > BST->Data)
			BST->Right = Delete(BST->Right, X);
		else {
			if (BST->Left && BST->Right) {
				Tmp = FindMin(BST->Right);
				BST->Data = Tmp->Data;
				BST->Right = Delete(BST->Right, BST->Data);
			}
			else {
				Tmp = BST;
				if (!BST->Left)
					BST = BST->Right;
				else
					BST = BST->Left;
				free(Tmp);
			}
		}
	}
	return BST;
}