#pragma once
#include <vector>
#include <iostream>
using namespace std;
template <typename T> class CNodeDynamic
{
public:
	CNodeDynamic() { pc_parent_node = NULL; i_index = 0; };
	CNodeDynamic(CNodeDynamic &other);
	~CNodeDynamic();
	void vSetValue(T iNewVal) { i_val = iNewVal; };

	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic *pcNewChild);
	CNodeDynamic *pcGetChild(int iChildOffset);
	void vSetParent(CNodeDynamic *newParent);
	CNodeDynamic *pcGetParent();
	int iGetIndex();
	
	bool bDeleteChild(int iIndex);

	void vPrint() { cout << " " << i_val; };
	void vPrintAllBelow();
private:
	vector<CNodeDynamic *> v_children;
	CNodeDynamic *pc_parent_node;
	T i_val;
	int i_index;

	void vSetIndex(int iIndex);
};


template <typename T>
void CNodeDynamic<T>::vAddNewChild()
{
	CNodeDynamic *pc_child = new CNodeDynamic();
	pc_child->pc_parent_node = this;
	pc_child->i_index = v_children.size();
	v_children.push_back(pc_child);
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic * pcNewChild) 
{
	pcNewChild->i_index = v_children.size();
	v_children.push_back(pcNewChild);
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>:: pcGetChild( int iChildOffset)
{
	if (iChildOffset >= 0 && iChildOffset < v_children.size())
		return v_children[iChildOffset];
	else
		return nullptr;
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetParent()
{
	return pc_parent_node;
}

template <typename T>
void CNodeDynamic<T>:: vSetParent(CNodeDynamic *newParent)
{
	pc_parent_node = newParent;
}

template <typename T>
int CNodeDynamic<T>::iGetIndex()
{
	return i_index;
}

template <typename T>
bool CNodeDynamic<T>::bDeleteChild(int iIndex)
{
	if (iIndex >= 0 && iIndex < v_children.size())
	{
		v_children.erase(v_children.begin() + iIndex);
		for (typename vector<CNodeDynamic*>::iterator it = v_children.begin(); it != v_children.end(); it++)
		{
			(*it)->vSetIndex(std::distance(v_children.begin(), it));
		}
		return true;
	}
	else
		return false;
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow()
{
	vPrint();
	for (typename vector<CNodeDynamic *>::iterator it = (v_children.begin()); it != v_children.end(); it++)
	{
		if (*it != NULL)
			(*it)->vPrintAllBelow();
	}
}

template <typename T>
void CNodeDynamic<T>::vSetIndex(int iIndex)
{
	i_index = iIndex;
}

template <typename T>
CNodeDynamic<T>::CNodeDynamic(CNodeDynamic &other)
{
	i_val = other.i_val;
	pc_parent_node = new CNodeDynamic();
	*pc_parent_node = *(other.pc_parent_node);
	for (std::size_t i = 0; i < other.v_children.size(); i++)
	{
		v_children.push_back(new CNodeDynamic(*other.v_children[i]));
		v_children.back()->vSetParent(this);
	}
}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic()
{
	for (typename vector<CNodeDynamic *>::iterator it = (v_children.begin()); it != v_children.end(); it++)
	{
		delete (*it);
	}
}


