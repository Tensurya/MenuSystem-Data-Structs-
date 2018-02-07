#pragma once

template <typename Type> class DynArray
{
private:
	Type * array;
	unsigned int Size, Capacity;
public:

	DynArray()
	{
		array = nullptr;
		Size = 0;
		Capacity = 0;
	}
	~DynArray() 
	{ 
		delete[] array;
	}

	DynArray(const DynArray<Type>& that)
	{
		array = nullptr;
		*this = that;
	}

	DynArray<Type>& operator=(const DynArray<Type>& that)
	{
		if (this != &that)
		{
			delete[]array;
			Size = that.Size;
			Capacity = that.Capacity;
			array = new Type[Capacity];

			for (unsigned int i = 0; i < Size; ++i)
				array[i] = that.array[i];
		}
		return *this;
	}


	Type& operator[](const unsigned int index)
	{
		return array[index];
	}

	const Type& operator[](const unsigned int index) const
	{
		return array[index];
	}

	unsigned int size() const
	{
		return Size;
	}

	unsigned int capacity() const
	{
		return Capacity;
	}

	void clear()
	{
		delete[] array;
		array = nullptr; 
		
		Size = 0;
		Capacity = 0;
	}

	void append(const Type& item)
	{
		if (Size == Capacity)
		{
			reserve();
		}

		array[Size++] = item;
	}

	void reserve(const unsigned int & newCap = 0)
	{
		if (newCap <= Capacity && newCap > 0)
			return;
		else if (0 == newCap)
		{
			if (0 == Capacity)
			{
				Capacity = 1;
			}
			else
			{
				Capacity *= 2;
			}
		}
		else
			Capacity = newCap;

		Type * temp = new Type[Capacity];
		for (unsigned int i = 0; i < Size; i++)
		{
			temp[i] = array[i];
		}
		delete[] array;
		array = temp;
	}
};
