#pragma once
#include <iostream>
#include <algorithm>
template <class T>
struct TNode
{
	T value;
	TNode<T>* pNext;
	TNode() { pNext = nullptr; }
};
template <class T>
class TList
{
protected:
	TNode<T>* pFirst, * pLast, * pStop, * pCurr, * pPr;
	int pos, len;
public:
	TList()
	{
		pFirst = nullptr; pLast = nullptr; pStop = nullptr; pCurr = nullptr; pPr = nullptr;
		pos = -1;
		len = 0;
	}; //����������� �� ���������
	inline void Reset()//������������ pCurr �� ������
	{
		pCurr = pFirst;
		pPr = pStop;
		pos = 0;

	}
	inline void GoNext()// ����������� pCurr �� ��������� �������
	{
		if (pCurr != pStop)
		{
			pPr = pCurr;
			pCurr = pCurr->pNext;
			pos++;

		}
		else
		{
			throw "This List is empty or current is not detected!";
		}
	}
	inline bool IsEnd()//�������� �� ��� ������ �� �� ����� ����������
	{
		return (pStop == pCurr);
	}
	inline void DelList()//����� ��� �������� ������
	{
		TNode<T>* tmp;
		while (pFirst != pStop)
		{
			tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		len = 0;
		pos = -1;
	}
	~TList() { DelList(); }; //����������
	TList(const TList<T>& list_object)//����������� �����������
	{
		TNode<T>* tmp = list_object.pFirst, * curr;

		while (tmp != list_object.pStop)
		{
			curr = new TNode<T>;
			curr->value = tmp->value;
			if (pFirst == pStop)
			{
				pFirst = curr;
				pLast = curr;
			}
			else
			{
				pLast->pNext = curr;
				pLast = curr;
			}

			tmp = tmp->pNext;
		}
		len = list_object.len;
		Reset();
	}
	inline void InsCurr(T _val)
	{
		if (len == 0)
		{
			InsFirst(_val);
		}
		if (pCurr == pFirst)
		{
			InsFirst(_val);
		}
		if (pCurr == pStop && pPr == pLast)
		{
			InsLast(_val);

		}
		else
		{

			TNode<T>* tmp = new TNode<T>;
			tmp->value = _val;
			pPr->pNext = tmp;
			tmp->pNext = pCurr;
			pPr = tmp;
			len++;
			pos++;
		}
	}

	inline void InsFirst(const T& _val)
	{
		if (pFirst == pStop)
		{
			TNode<T>* tmp = new TNode<T>;
			tmp->value = _val;
			tmp->pNext = pFirst;//////
			pFirst = tmp;
			pLast = tmp;
			len++;
		}
		else
		{
			TNode<T>* tmp = new TNode<T>;
			tmp->value = _val;
			tmp->pNext = pFirst;//////
			pFirst = tmp;
			len++;
		}
	
	}
	void InsLast(const T& _val)
	{
		if (pFirst == pStop)
		{
			InsFirst(_val);
		}
		else
		{
			TNode<T>* tmp = new TNode<T>;
			tmp->value = _val;
			pLast->pNext = tmp;
			pLast = tmp;
			tmp->pNext = pStop;
			len++;
		}
	}
	T Get_First()
	{
		return pFirst->value;
	}
	T Get_Last()
	{
		return pLast->value;
	}
	T Get_pos()
	{
		return pos;
	}
	T Get_length()
	{
		return len;
	}
	bool Is_Empty()
	{
		return (pFirst == pStop);
	}
	inline void DelCurr()
	{
		if (pCurr == pFirst)
		{
			DelFirst();
		}
		if (pCurr == pLast)
		{
			TNode<T>* tmp = pCurr;
			pCurr = pCurr->pNext;
			pPr->pNext = pCurr;
			pLast = pPr;
			delete tmp;
			len--;

		}
		if (pCurr != pStop)
		{
			
			TNode<T>* tmp = pCurr;
			pCurr = pCurr->pNext;
			pPr->pNext = pCurr;
			delete tmp;
			len--;

		}
		else
		{
			throw "This List is empty!";
		}

	}
	 inline void DelFirst()
	{
		if (pFirst != pStop)
		{
			TNode<T>* tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
			len--;
		}
		else
		{
			throw "This List is empty!";

		}
	}
	inline TList<T>& operator=(const TList<T>& list_object)
	{
		if (list_object.pFirst == nullptr)
		{
			DelList();
		}
		else
		{
			DelList();
			TNode<T>* tmp = list_object.pFirst, * curr;
			while (tmp != nullptr)
			{
				curr = new TNode<T>;
				curr->value = tmp->value;
				if (pFirst == nullptr)
				{
					pFirst = curr;
					pLast = curr;
				}
				else
				{
					pLast->pNext = curr;
					pLast = curr;
				}
				tmp = tmp->pNext;
			}
			len = list_object.len;
			pos = 0;
			Reset();
		}
		return *this;
	}
	inline void setPos(int _pos)
	{
		if (_pos < 0 || _pos >= len)
		{
			throw "� ������ ��� ����� �������!";
		}
        Reset();
		for (int i = 0; i < _pos; ++i)
		{
			GoNext();
		}
	}

};


