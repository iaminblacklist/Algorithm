// Recursion
void inOrder1(BinTree *root)
{
	if(root!=NULL)
	{
		inOrder1(root->lchild);
		cout<<root->data<<" ";
		inOrder1(root->rchild);
	}
}

// Non-Recursion
void inOrder2(BinTree *root)
{
	stack<BinTree*> s;
	BinTree *p=root;
	while(p!=NULL||!s.empty())
	{
		while(p!=NULL)
		{
			s.push(p);
			p=p->lchild;
		}
		if(!s.empty())
		{
			p=s.top();
			cout<<p->data<<" ";
			s.pop();
			p=p->rchild;
		}
	}
}