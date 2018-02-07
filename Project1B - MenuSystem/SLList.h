#pragma once

template <typename Type> class SLLIter;

template <typename Type> class SLList
{
private:
	friend class SLLIter<Type>;
	struct Node
	{
		Node * next;
		Type data;
	};

	Node * Head;
	unsigned int Size;

public:
	SLList()
	{
		Head = nullptr;
		Size = 0;
	}

	~SLList()
	{
		clear();
	}
	void RecursiveCopy(Node * n)
	{
		if (n != nullptr)
		{
			RecursiveCopy(n->next);
			addHead(n->data);
		}
	}
	SLList<Type>& operator=(const SLList<Type>& that)
	{
		if (this != &that)
		{
			clear();
			RecursiveCopy(that.Head);
		}
		return *this;
	}
	SLList(const SLList<Type>& that)
	{
		clear();
		*this = that;
	}
	void addHead(const Type& v)
	{
		Node * temp = new Node;
		temp->data = v;
		temp->next = Head;
		Head = temp;
		++Size;
	}
	void clear()
	{
		while (Head != nullptr)
		{
			Node * temp = Head;
			Head = Head->next;
			delete temp;
		}
		Head = nullptr;
		Size = 0;
	}
	void insert(SLLIter<Type>& index, const Type& v)
	{
		Node * temp = new Node;
		temp->data = v;
		temp->next = index.c;
		if (index.end() == false)
		{
			if (index.c == Head)
			{
				Head = temp;
			}
			else
			{
				index.prev->next = temp;
			}
			index.c = temp;
			++Size;
		}

	}
	void remove(SLLIter<Type>& index)
	{
		if (index.c != nullptr)
		{
			if (index.c == Head)
			{
				Head = Head->next;
				delete index.c;
				index.c = Head;
			}
			else
			{
				index.prev->next = index.c->next;
				delete index.c;
				index.c = index.prev->next;
			}

			--Size;
		}
	}

	inline unsigned int size() const { return Size; }
};

template <typename Type> class SLLIter
{
private:
	friend class SLList<Type>;
	typename SLList<Type>::Node * c;
	typename SLList<Type>::Node * prev;
	SLList<Type> * list;

public:
	SLLIter(SLList<Type>& listToIterate)
	{
		list = &listToIterate;
		c = list->Head;
		prev = nullptr;
	}
	void begin()
	{
		c = list->Head;
		prev = nullptr;
	}
	bool end() const
	{
		if (c == nullptr)
		{
			return true;
		}
		else return false;
	}
	SLLIter<Type>& operator++()
	{
		if (end() == false)
		{
			prev = c;
			c = c->next;
			return *this;
		}
		return *this;
	}
	Type& current() const
	{
		return c->data;
	}
};