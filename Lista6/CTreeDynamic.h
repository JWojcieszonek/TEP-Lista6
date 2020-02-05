#pragma once
#include "CNodeDynamic.h"

class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();

	CNodeDynamic <double> *pcGetRoot() { return(pc_root); };
	void vPrintTree();
	bool bMoveSubtree(CNodeDynamic<double> *pcParentNode, CNodeDynamic<double> *PcNewChildNode);
	
private:
	CNodeDynamic<double> *pc_root;
};

