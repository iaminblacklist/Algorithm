//	Recursion
void preOrder1(BinTree *root)
{
	if(root != NULL)
	{
		cout << root->data << " ";
		preOrder(root->lchild);
		preOrder(root->rchild);
	}
}

//	Non-Recursion
void preOrder2(BinTree *root)
{
	stack<BinTree*> s;
	BinTree *p = root;
	//	对任一节点P，其可看做为根节点
	while(p != NULL || !s.empty())
	{
		while(p != NULL)
		{
			cout << p->data << " ";
			//	访问结点P，并将结点P入栈
			s.push(p);
			//	判断结点P的左孩子是否为空，若不为空，
			//	则将P的左孩子置为当前结点P
			p = p->lchild;
		}
		//	若结点P的左孩子为空，取栈顶结点并进行出栈操作
		//	并将栈顶结点的右孩子置为当前结点P
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}