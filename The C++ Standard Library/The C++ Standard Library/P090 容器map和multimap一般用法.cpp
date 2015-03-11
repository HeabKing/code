// ����: 2014-08-20 14:17:19
// map��Ԫ���ǳɶԵļ�ֵ/ʵֵ(key/value)

#include <iostream>
#include <map>
#include <string>

// multimap����������ʹ��subscript(�±�)������, ��Ϊmultimap����һ������Ӧ�����ͬ��Ԫ��, ���±������ȴֻ�ܴ���һʵֵ
// ����map�����м�ֵ���Ƕ�һ�޶���, ���ǿ��԰�����Ϊһ������ʽ����
// ����ʽ����: �Լ�ֵΪ����, ��ֵ����ʹ�����ͱ�.

#define MAP
//#define MULTIMAP

int main()
{
#ifdef MAP
	
	typedef std::map<std::string, float> StringFloatMap;
	StringFloatMap coll;

	// insert some elements into the collection
	coll["VAT"] = 0.15f;
	coll["Pi"] = 3.1415f;
	coll["an arbitrary number"] = 4983.223f;
	coll["Null"] = 0;
	// coll.insert("kkkkkk", 1.23f);	// ERROR # 1

	// print all elements
	// - iterator over all elements
	// - element member first is the key
	for (StringFloatMap::iterator pos = coll.begin(); pos != coll.end(); ++pos)
		std::cout	<< "key: \"" << pos->first << "\" "
					<< "value: " << (*pos).second << std::endl;

	using namespace std;
	cout << endl << endl;
	cout << "coll[\"Pi\"] = " << coll["Pi"] << endl;	// !!!!!!!!!!!!!! �ⲻ����php�е�..........

#elif defined MULTIMAP
	
	// type of the collection
	typedef std::multimap<int, std::string> IntStringMMap;

	IntStringMMap coll;

	// insert some elements in arbitrary order
	// - a value with key 1 gets inserted twice
	coll.insert(std::make_pair(5, "tagged"));
	coll.insert(std::make_pair(2, "a"));
	coll.insert(std::make_pair(1, "this"));
	coll.insert(std::make_pair(4, "of"));
	coll.insert(std::make_pair(6, "strings"));
	coll.insert(std::make_pair(1, "is"));
	coll.insert(std::make_pair(3, "multimap"));
	//coll.insert(7, std::string("777777"));	// ERROR # 2

	// print all element values
	// - iterate over all elements
	// - element member second is the value
	IntStringMMap::iterator pos;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		std::cout << pos->second /*(*pos).second*/ << ' ';	// pos->second ȡ��pair�ĵڶ�����Ա
	std::cout << std::endl;

	//std::cout << std::endl << std::endl;
	//std::cout << coll[3] << std::endl;	// multimap �޷���������������..........
#endif

	std::map<std::string, std::string> temp;
	//temp.insert(std::string("124"), string("1212"));	// EORROR # 3
	//cout << endl << endl << temp.begin()->first << temp.begin()->second << endl;

	temp["he"] = "shixiong";
	temp.insert(make_pair("da", "xiong"));
	std::map<std::string, std::string> & temp2 = temp;
	cout << endl << endl << temp2["da"] << endl;
}