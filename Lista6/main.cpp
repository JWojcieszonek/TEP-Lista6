#include "CTreeDynamic.h"
#include "CTreeDynamicString.h"

int main()
{
	
	CTreeDynamic c_dynamic_tree_1 = CTreeDynamic();
	c_dynamic_tree_1.pcGetRoot()->vAddNewChild(); 
	c_dynamic_tree_1.pcGetRoot()->vAddNewChild();
	c_dynamic_tree_1.pcGetRoot()->vAddNewChild();
	c_dynamic_tree_1.pcGetRoot()->pcGetChild(0)->vSetValue(1.5);
	c_dynamic_tree_1.pcGetRoot()->pcGetChild(1)->vSetValue(2.0);
	c_dynamic_tree_1.pcGetRoot()->pcGetChild(2)->vSetValue(3.0);
	c_dynamic_tree_1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	c_dynamic_tree_1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4.0);
	c_dynamic_tree_1.vPrintTree();
	
	CTreeDynamic c_dynamic_tree_2 = CTreeDynamic();
	c_dynamic_tree_2.pcGetRoot()->vSetValue(50);
	c_dynamic_tree_2.pcGetRoot()->vAddNewChild();
	c_dynamic_tree_2.pcGetRoot()->vAddNewChild();
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(1)->vSetValue(55);
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57.75);
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	c_dynamic_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);
	c_dynamic_tree_2.vPrintTree();
	//delete c_dynamic_tree_2.pcGetRoot()->pcGetChild(0);
	c_dynamic_tree_1.bMoveSubtree(c_dynamic_tree_1.pcGetRoot()->pcGetChild(2), c_dynamic_tree_2.pcGetRoot()->pcGetChild(0));
	c_dynamic_tree_1.vPrintTree();
	c_dynamic_tree_2.vPrintTree();

	CTreeDynamicString c_dynamic_string_tree_1 = CTreeDynamicString();
	c_dynamic_string_tree_1.pcGetRoot()->vAddNewChild();
	c_dynamic_string_tree_1.pcGetRoot()->vAddNewChild();
	c_dynamic_string_tree_1.pcGetRoot()->vAddNewChild();
	c_dynamic_string_tree_1.pcGetRoot()->pcGetChild(0)->vSetValue("Ala");
	c_dynamic_string_tree_1.pcGetRoot()->pcGetChild(1)->vSetValue("Ma");
	c_dynamic_string_tree_1.pcGetRoot()->pcGetChild(2)->vSetValue("Kota");
	c_dynamic_string_tree_1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	c_dynamic_string_tree_1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue("Psa");
	c_dynamic_string_tree_1.vPrintTree();

	CTreeDynamicString c_dynamic_string_tree_2 = CTreeDynamicString();
	c_dynamic_string_tree_2.pcGetRoot()->vSetValue("a");
	c_dynamic_string_tree_2.pcGetRoot()->vAddNewChild();
	c_dynamic_string_tree_2.pcGetRoot()->vAddNewChild();
	c_dynamic_string_tree_2.pcGetRoot()->pcGetChild(0)->vSetValue("b");
	c_dynamic_string_tree_2.pcGetRoot()->pcGetChild(1)->vSetValue("c");
	c_dynamic_string_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_dynamic_string_tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_dynamic_string_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("d");
	c_dynamic_string_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue("e");
	c_dynamic_string_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	c_dynamic_string_tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue("f");
	c_dynamic_string_tree_2.vPrintTree();

	c_dynamic_string_tree_1.bMoveSubtree(c_dynamic_string_tree_1.pcGetRoot()->pcGetChild(2), c_dynamic_string_tree_2.pcGetRoot()->pcGetChild(0));
	c_dynamic_string_tree_1.vPrintTree();
	c_dynamic_string_tree_2.vPrintTree();
	
	return 0;
}