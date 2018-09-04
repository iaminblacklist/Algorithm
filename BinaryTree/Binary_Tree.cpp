#include <stdio.h>
#include <stdlib.h>

typedef struct treenode      //���Ľڵ�
{
    char data ;
    treenode * leftchild, * rightchild ;
}TreeNode;

typedef TreeNode * StackElemType ;   //����ջ��������������

typedef struct stacknode    //ջ�Ľڵ�
{
    StackElemType data ;
    stacknode * next ;
}StackNode;

typedef TreeNode * QueueElemType ;     //������а�������������

typedef struct queuenode     //������нڵ�
{
    QueueElemType  data ;
    struct queuenode * next ;
}QueueNode;

typedef struct queuehead    //������е�ͷ�ڵ�
{
    QueueNode * front, * rear ;
}QueueHead;

//stack���й�����
StackNode * InitStack(StackNode * S) ;
void StackPush(StackNode * S, StackElemType data) ;
void StackPop(StackNode * S, StackElemType & data) ;
int StackEmpty(StackNode * S) ;
int StackGetTop(StackNode * S, StackElemType & data) ;

//queue���й�����
QueueHead * InitQueue(QueueHead * Q) ;
void QueuePush(QueueHead * Q, QueueElemType data) ;
void QueuePop(QueueHead * Q, QueueElemType & data) ;
int QueueEmpty(QueueHead * Q) ;

//TreeTraverse���й�����
TreeNode * InitTree(TreeNode * T) ;
void PreTraverseTree1(TreeNode * T) ;
void PreTraverseTree2(TreeNode * T) ;
void InOrderTraverseTree1(TreeNode * T) ;
void InOrderTraverseTree2(TreeNode * T) ;
void LastTraverseTree1(TreeNode * T) ;
void LastTraverseTree2(TreeNode * T) ;
void LevelTraverseTree(TreeNode * T) ;

//ջ�ĺ�������
StackNode * InitStack(StackNode * S)
{
    S = (StackNode *)malloc(sizeof(StackNode)) ;
    if(NULL == S)
    {
        printf("�ڴ治�㣬���ܷ���ջ��\n") ;
        exit(0) ;
    }

    S->next = NULL ;
    return(S) ;
}

void StackPush(StackNode * S, StackElemType data)
{
    StackNode * q ;
    q = (StackNode *)malloc(sizeof(StackNode)) ;
    if(NULL == q)
    {
        printf("�ڴ治�㣬���ܷ���ջ��\n") ;
        exit(0) ;
    }
    q->data = data ;
    q->next = S->next ;
    S->next = q ;
}

void StackPop(StackNode * S, StackElemType & data)
{
    StackNode * q ;
    if(NULL == S->next)
    {
        printf("ջΪ�գ��޷���ֵ��\n") ;
    }

    q = S->next ;
    data = q->data ;
    S->next = q->next ;
    free(q) ;
}

int StackEmpty(StackNode * S)
{
    if(NULL == S->next)
    {
        return(1) ;
    }

    return(0) ;
}

int StackGetTop(StackNode * S, StackElemType & data)
{
    if(NULL != S->next)
    {
        data = S->next->data ;
        return(1) ;
    }
    else
    {
        //data = NULL ;
        return(0) ;
    }
}


//���к����Ķ���
QueueHead * InitQueue(QueueHead * Q)
{
    QueueNode * q ;
    Q = (QueueHead *)malloc(sizeof(QueueHead)) ;
    if(NULL == Q)
    {
        printf("�ڴ治�㣡\n") ;
        exit(0) ;
    }
    q = (QueueNode *)malloc(sizeof(QueueNode)) ;
    if(NULL == q)
    {
        printf("�ڴ治�㣡\n") ;
        exit(0) ;
    }

    q->next = NULL ;
    Q->front = q ;
    Q->rear = q ;

    return(Q) ;
}

void QueuePush(QueueHead * Q, QueueElemType data)
{
    QueueNode * q ;
    q = (QueueNode *)malloc(sizeof(QueueNode)) ;
    if(NULL == q)
    {
        printf("�ڴ治�㣡\n") ;
        exit(0) ;
    }

    q->data = data ;
    q->next = Q->rear->next ;
    Q->rear->next = q ;
    Q->rear = q ;
}

void QueuePop(QueueHead * Q, QueueElemType & data)
{
    QueueNode * q ;
    if(Q->front == Q->rear)
    {
        printf("����Ϊ�գ�\n") ;
        return ;
    }

    q = Q->front->next ;
    data = q->data ;
    Q->front->next = q->next ;
    if(Q->rear == q)
        Q->rear = Q->front ;

    free(q) ;
}

int QueueEmpty(QueueHead * Q)
{
    if(Q->front == Q->rear)
        return(1) ;
    else
        return(0) ;
}


//���ĸ��ֱ�����������

/*����һ�ö�����*/
TreeNode * InitTree(TreeNode * T)
{
    char data ;
    scanf("%c", &data) ;

    if('#' == data)
    {
        T = NULL ;
    }
    else
    {
        T = (TreeNode *)malloc(sizeof(TreeNode)) ;
        T->data = data ;
        T->leftchild = InitTree(T->leftchild) ;
        T->rightchild = InitTree(T->rightchild) ;
    }

    return(T) ;
}

/*�������ݹ��������*/
void PreTraverseTree1(TreeNode * T)
{
    if(T)
    {
        printf("%c  ", T->data) ;
        PreTraverseTree1(T->leftchild) ;
        PreTraverseTree1(T->rightchild) ;
    }
}

/*�������ķǵݹ��������*/
void PreTraverseTree2(TreeNode * T)
{
    StackNode * S ;
    TreeNode * p ;
    S = NULL ;
    p = T ;
    S = InitStack(S) ;

    if(NULL == p)
    {
        printf("��Ϊ�գ�\n") ;
        return ;
    }

    while(p || !StackEmpty(S))
    {
        if(p)
        {
            StackPush(S, p) ;
            printf("%c  ", p->data) ;
            p = p->leftchild ;
        }
        else
        {
            StackPop(S, p) ;
            p = p->rightchild ;
        }
    }

    free(S) ;
}

/*�������ݹ��������*/
void InOrderTraverseTree1(TreeNode * T)
{
    if(T)
    {
        InOrderTraverseTree1(T->leftchild) ;
        printf("%c  ", T->data) ;
        InOrderTraverseTree1(T->rightchild) ;
    }
}

/*�������ķǵݹ��������*/
void InOrderTraverseTree2(TreeNode * T)
{
    StackNode * S ;
    TreeNode * p ;
    S = NULL ;
    p = T ;
    S = InitStack(S) ;

    if(NULL == p)
    {
        printf("��Ϊ�գ�\n") ;
        return ;
    }

    while(p || !StackEmpty(S))
    {
        if(p)
        {
            StackPush(S, p) ;
            p = p->leftchild ;
        }
        else
        {
            StackPop(S, p) ;
            printf("%c  ", p->data) ;
            p = p->rightchild ;
        }
    }
    free(S) ;
}

/*�������ݹ�������*/
void LastTraverseTree1(TreeNode * T)
{
    if(T)
    {
        LastTraverseTree1(T->leftchild) ;
        LastTraverseTree1(T->rightchild) ;
        printf("%c  ", T->data) ;
    }
}

/*�������ǵݹ�������*/
void LastTraverseTree2(TreeNode * T)
{
    StackNode * S ;
    TreeNode * cur, * pre ;
    S = NULL ;
    S = InitStack(S) ;
    if(NULL == T)
    {
        printf("��Ϊ�գ�\n") ;
        return ;
    }

    pre = NULL ;    cur = NULL ;
    StackPush(S,T) ;
    while(!StackEmpty(S))
    {
        cur = NULL ;
        StackGetTop(S,cur) ;
        if((cur->leftchild == NULL && cur->rightchild == NULL) || (pre != NULL && (pre == cur->leftchild ||pre == cur->rightchild)))
        {
            printf("%c  ", cur->data) ;
            pre = cur ;
            StackPop(S,cur) ;
        }
        else
        {
            if(cur->rightchild != NULL)
            {
                StackPush(S,cur->rightchild) ;
            }
            if(cur->leftchild != NULL)
            {
                StackPush(S,cur->leftchild) ;
            }
        }
    }
    free(S) ;
}

/*��������α���*/
void LevelTraverseTree(TreeNode * T)
{
    QueueHead * Q ;
    TreeNode * p ;
    Q = NULL ;    p = T ;
    Q = InitQueue(Q) ;
    if(NULL == p)
    {
        printf("��Ϊ�գ�\n") ;
        return ;
    }

    QueuePush(Q,p) ;
    while(!QueueEmpty(Q))
    {
        p = NULL ;
        QueuePop(Q,p) ;

        if(NULL != p->leftchild)
            QueuePush(Q,p->leftchild) ;

        if(NULL != p->rightchild)
            QueuePush(Q,p->rightchild) ;

        printf("%c  ", p->data) ;
    }
}


//�������Ķ���
void Tips()
{
    printf("�������ǰ�������������������ģ��������롮#����ʾ����Ϊ�ա�\n") ;
    printf("������Ҫ����������") ;
}

int main()
{
    TreeNode * T ;
    T = NULL ;

    Tips() ;

    T = InitTree(T) ;

    printf("�������ݹ��������\n") ;
    PreTraverseTree1(T) ;
    printf("\n") ;

    printf("�������ǵݹ��������\n") ;
    PreTraverseTree2(T) ;
    printf("\n") ;

    printf("�������ݹ��������\n") ;
    InOrderTraverseTree1(T) ;
    printf("\n") ;

    printf("�������ǵݹ��������\n") ;
    InOrderTraverseTree2(T) ;
    printf("\n") ;

    printf("�������ݹ�������\n") ;
    LastTraverseTree1(T) ;
    printf("\n") ;

    printf("�������ǵݹ�������\n") ;
    LastTraverseTree2(T) ;
    printf("\n") ;

    printf("��������α���\n") ;
    LevelTraverseTree(T) ;
    printf("\n") ;

    return 0 ;
}