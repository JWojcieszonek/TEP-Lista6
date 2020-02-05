#include "CTreeDynamic.h"



CTreeDynamic::CTreeDynamic()
{
	pc_root = new CNodeDynamic<double>();
}

CTreeDynamic::~CTreeDynamic()
{
	delete pc_root;
	pc_root = NULL;
}

void CTreeDynamic::vPrintTree()
{
	pc_root->vPrintAllBelow();
	cout << endl;
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic<double> * pcParentNode, CNodeDynamic<double> * pcNewChildNode)
{
	if (pcParentNode != NULL && pcNewChildNode != NULL)
	{
		pcParentNode->vAddNewChild(new CNodeDynamic<double>(*pcNewChildNode));
		int new_child_index = pcParentNode->iGetChildrenNumber() - 1; // indeks gdzie zosta³ dodany wêze³
		pcParentNode->pcGetChild(new_child_index)->vSetParent(pcParentNode);
		pcNewChildNode->pcGetParent()->bDeleteChild(pcNewChildNode->iGetIndex());

		return true;
	}
	else
		return false;
}


