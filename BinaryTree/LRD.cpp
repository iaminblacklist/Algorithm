//	Recursion
void postOrder1(BinTree *root)
{
	if(root!=NULL)
	{
		postOrder1(root->lchild);
		postOrder1(root->rchild);
		cout<<root->data<<" ";
	}
}



//	Non-Recursion
void postOrder2(BinTree *root)
{
	stack<BinTree*> s;
	BinTree *cur;				//	当前节点
	BinTree *pre=NULL;			//	前一次访问的节点
	s.push(root);
	while(!s.empty())
	{
		cur=s.top();
		//	如果当前结点没有孩子结点或者孩子节点都已被访问过
		if((cur->lchild==NULL&&cur->rchild==NULL)||
			(pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
		{
			cout<<cur->data<<" ";
			s.pop();
			pre=cur;
		}
		else
		{
			if(cur->rchild!=NULL)
				s.push(cur->rchild);
			if(cur->lchild!=NULL)
				s.push(cur->lchild);
		}
	}
}

//	要保证根结点在左孩子和右孩子访问之后才能访问，因此对于任一结点P，先将其入栈。
//	如果P不存在左孩子和右孩子，则可以直接访问它；
//	或者P存在左孩子或者右孩子，但是其左孩子和右孩子都已被访问过了，则同样可以直接访问该结点。
//	若非上述两种情况，则将P的右孩子和左孩子依次入栈，这样就保证了 
//	每次取栈顶元素的时候，左孩子在右孩子前面被访问，
//	左孩子和右孩子都在根结点前面被访问。