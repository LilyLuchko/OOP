#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <direct.h>
#include <string.h>

template <typename T> class Container
{
private:
	struct element
	{
		T data;
		element *pNext;
	};
	element *pHead;
	Container(const Container&x){};
	Container&operator=(const Container&x){};

public:
	bool Empty() const
	{
		return (pHead==NULL);
	}
	class Iterator
	{
		element *d;
	public:
		Iterator()
		{
         d=NULL;
		}
		void operator=(element* x)
		{
			this->d=x;
		}
		void operator++()
		{
			if(d!=NULL)
				d=d->pNext;
		}
		bool operator == (Iterator const & other) const
		{
			return d==other.d;
		}
		bool operator !=(Iterator const & other) const
		{
			return false;
			else 
				return true;
		}
		T operator*()
		{
			if (d!=NULL)
				return d->data;
		}
		element * operator->()
		{
			if(d!=NULL)
				return d;
		}
	};
	Iterator begin()
	{
		Iterator k;
		k=pHead;
		return k;
	}
	Iterator end()
	{
		return NULL;
	}
	Container()
	{
		pHead=NULL;
	}
	~Container()
	{
		element *tmp;
		while (pHead!=NULL)
			tmp=pHead->pNext;
		delete pHead;
		pHead=tmp;

	}
	void AddBegin(T x)
	{
		element *b=new element;
		b->data=x;
		b->pNext=pHead;
		pHead=b;
	}
	void AddEnd(T& x)
	{
		element *end = new element;
		element *q=pHead;
		end->data = x;
		end->pNext = NULL;
		if (pHead == NULL) 
		{
			pHead = end;
			return;
		}

		while (q->pNext != NULL)
		{
			q = q->pNext;
		}
		q->pNext = end;
	}
	void DeleteBegin(T x)
	{
		element *newHead = pHead->pNext;
		delete pHead;
		pHead = newHead;
	}
	void DeleteEnd(T x)
	{
		if (pHead == NULL)
		{
			return;
		}
		element *t;
		element *q;
		t = pHead;
		while (t->pNext != NULL)
			q = t;
		t = t->pNext;
		delete t;
		q->pNext = NULL;
	}
	T getHead() const
	{
		if (pHead != NULL)
			return pHead->data;
	}
	T getEnd() const
	{
		if (pHead != NULL)
		{
			element* k;
			for (k = pHead; k->pNext != NULL; k = k->pNext);
			return k->data;
		}
	}
	int CountContainer() const
	{
		if (pHead != NULL)
		{
			element* k; 
			int i = 0;
			for (k = pHead;k != NULL; k = k->pNext) 
				i++;
			return i;
		}
		else
			return 0;
	}
	void print()
	{
		element *q = pHead;
		if (q == NULL)
		{
			std::cout << q->data << '\n';
		}
		while (q != NULL)
		{
			std::cout << q->data << '\n';
			q = q->pNext;
		}
		
	}

};