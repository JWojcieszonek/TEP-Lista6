#include "CTreeDynamicString.h"


CTreeDynamicString::CTreeDynamicString()
{
	pc_root = new CNodeDynamic<string>();
}

CTreeDynamicString::~CTreeDynamicString()
{
	delete pc_root;
	pc_root = NULL;
}

void CTreeDynamicString::vPrintTree()
{
	pc_root->vPrintAllBelow();
	cout << endl;
}

bool CTreeDynamicString::bMoveSubtree(CNodeDynamic<string> * pcParentNode, CNodeDynamic<string> * pcNewChildNode)
{
	if (pcParentNode != NULL && pcNewChildNode != NULL)
	{
		pcParentNode->vAddNewChild(new CNodeDynamic<string>(*pcNewChildNode));
		int new_child_index = pcParentNode->iGetChildrenNumber() - 1; // indeks gdzie zosta³ dodany wêze³
		pcParentNode->pcGetChild(new_child_index)->vSetParent(pcParentNode);
		pcNewChildNode->pcGetParent()->bDeleteChild(pcNewChildNode->iGetIndex());

		return true;
	}
	else
		return false;
}