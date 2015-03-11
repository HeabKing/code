// ����: 2014-08-21 16:43:16

#include <iostream>

// PRINT_ELEMENTS()
// - prints optional(��ѡ��, �����) C-stirng optcstr(opt, ѡ��) followed by
// - all elements of the collection coll
// - separated by spaces
template<class T>
inline void PRINT_ELEMENTS(const T & coll, const char * optcstr = "", const char * s = "\n")
{
	typename T::const_iterator pos;	// typename T::const_iterator ָ����ߵ���һ�����Ͷ�����һ��ֵ
	std::cout << optcstr;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		std::cout << *pos << " ";
	std::cout << s;
}