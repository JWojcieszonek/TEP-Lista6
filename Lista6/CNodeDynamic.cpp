
/*
CNodeDynamic::CNodeDynamic(CNodeDynamic & other)
{
	i_val = other.i_val;
	pc_parent_node = new CNodeDynamic();
	*pc_parent_node = *(other.pc_parent_node);
	for (std::size_t i=0;i<other.v_children.size();i++)
	{
		v_children.push_back(new CNodeDynamic( *other.v_children[i]));
		v_children.back()->vSetParent(this);
	}
}

CNodeDynamic::~CNodeDynamic()
{
	for (vector<CNodeDynamic *>::iterator it = (v_children.begin()); it != v_children.end(); it++)
	{
		delete (*it);
	}
}

void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic *pc_child = new CNodeDynamic();
	pc_child->pc_parent_node = this;
	pc_child->i_index = v_children.size();
	v_children.push_back(pc_child);

}

void CNodeDynamic::vAddNewChild(CNodeDynamic * pcNewChild)
{
	pcNewChild->i_index = v_children.size();
	v_children.push_back(pcNewChild);
}

CNodeDynamic * CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset >= 0 && iChildOffset < v_children.size())
		return v_children[iChildOffset];
	else
		return nullptr;
}

void CNodeDynamic::vSetParent(CNodeDynamic * newParent)
{
	pc_parent_node=newParent;
}

CNodeDynamic * CNodeDynamic::pcGetParent()
{
	return pc_parent_node;
}

void CNodeDynamic::vSetIndex( int iIndex)
{
	i_index = iIndex;
}

bool CNodeDynamic::bDeleteChild(int iIndex)
{
	if (iIndex >= 0 && iIndex < v_children.size())
	{
		v_children.erase(v_children.begin() + iIndex);
		for (vector<CNodeDynamic*>::iterator it=v_children.begin(); it != v_children.end(); it++)
		{
			(*it)->vSetIndex(std::distance(v_children.begin(), it));
		}
		return true;
	}
	else
		return false;
}

void CNodeDynamic::vPrintAllBelow()
{
	vPrint();
	for (vector<CNodeDynamic *>::iterator it = (v_children.begin()); it != v_children.end(); it++)
	{
		if(*it!=NULL)
			(*it)->vPrintAllBelow();
	}
}
*/

