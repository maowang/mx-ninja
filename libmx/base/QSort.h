#ifndef _QSORT_H
#define _QSORT_H

#include "base/Base.h"

BEG_MX_NAMESPACE

template<typename T>
void _sort(std::vector<T>& array,int u,int v,bool asc)
{
	if (u<v)
	{
		int m = u;

		std::swap(array[u], array[(u+v)/2]);

		for (int i = u + 1; i <= v; i++)
			if ((array[i]<array[u]) == asc)
				std::swap(array[++m], array[i]);

		std::swap(array[u], array[m]);

		_sort<T>(array,u, m - 1,asc);
		_sort<T>(array,m + 1, v,asc);
	}
}

template<class T>
class QSort
{
public:
	static void sort(std::vector<T>& array,bool asc = true)
	{
		_sort<T>(array,0,array.size()-1,asc);
	}
};

END_MX_NAMESPACE

#endif
