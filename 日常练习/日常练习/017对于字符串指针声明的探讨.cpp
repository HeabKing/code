#include <iostream>
using namespace std;
int main(void)
{
	char strAr[] = "daxiong";  // ���ﲻ��һ��ָ������ָ��, ���ǽ�����ֵ"daxiong"������strAr����, �������ܶ���ʹ��cin>>��;
	char * pStr = "heshixiong";  // ����������const, ���Ҽ����˵Ļ����ڱ���ǰ��cin>>���б���;

	cout << strAr << endl
		<< pStr << endl;
	cin >> strAr;
	cout << strAr << endl;
	cin >> pStr;  // ����ᵼ�³������, ��Ϊ"heshixiong"��һ������ֵ, ���ڴ����в��ܳ��ֶ��ٴζ���Ψһһ���ڴ汣���, ����pStr���ܸı���, �����Ὣ������Ҳ������, ����������ʱ��������const;
	cout << pStr << endl;

	return 0;
}
