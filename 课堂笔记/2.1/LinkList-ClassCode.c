typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

#define ERROR NULL

Position Find(List L, ElementType X){
    Position p = L;
    
    while (p && p->Data!=X) {
        p = p->Next;
    }
    
    if (P) {
        return p;
    }else
        return ERROR;
}

bool Insert(List L, ElementType X, Position P){
    Position tmp, pre;
    
    for (pre=L; pre&&pre->Next!=P; pre=pre->Next);
    if (pre==NULL) {
        printf("Wrong parameter");
        return false;
    }else{
        tmp = (Position)malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}

bool Delete(List L, Position P){
    Position tmp, pre;
    
    for (pre=L; pre&&pre->Next!=P; pre=pre->Next);
    if (pre==NULL || P==NULL) {
        printf("Delete wrong parameter\n");
        return false;
    }
    else{
        pre->Next = P->Next;
        free(P);
        return true;
    }
}
