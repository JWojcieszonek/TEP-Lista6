#pragma once
#include "CNodeDynamic.h"
#include <string>

class CTreeDynamicString
{
public:
	CTreeDynamicString();
	~CTreeDynamicString();

	CNodeDynamic <string> *pcGetRoot() { return(pc_root); };
	void vPrintTree();
	bool bMoveSubtree(CNodeDynamic<string> *pcParentNode, CNodeDynamic<string> *PcNewChildNode);

private:
	CNodeDynamic<string> *pc_root;
};

