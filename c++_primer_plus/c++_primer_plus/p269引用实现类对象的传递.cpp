// �����嵥 8.7
#include <iostream>
#include <string>
using namespace std;
string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);
const string & version3(string & s1, const string & s2);

int main()
{
	string input;
	string copy;
	string result;

	cout << "Enter a string: ";
	getline(cin, input);
	copy = input;
	cout << "Your string as entered: " << input << endl;
	result = version1(input, "����"); // ���ﶨ�����ʹ��const string &��������ʵ�ʴ���������c�����ַ���, ԭ��: 1. string�ඨ����һ�ִ�char * ��string���ת������. 2. const�����β���һ������: ����ʵ�ε����������ò������Ͳ�ƥ��, ���ǿ��Ա�ת������������, ���򽫻ᴴ��һ����ȷ���͵���ʱ����, ʹ��ת�����ʵ��ֵ����ʼ����, Ȼ�� ����(??�ǲ���˵���������ڴ���ǰ���������Բ���ר�����������ľֲ��Զ�����???) һ��ָ�����ʱ����������.
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;

	result = version2(input, "###");   // ���ص��Ƕ�s1������, Ȼ��result������������, �������൱��ֱ�ӽ�result = input��
									  // ��һ����, �������Ƿ��ص�input������, �����ڶ�result���и�ֵ��ʱ��inputҲ����ű�, ���п��ܲ���������Ҫ��
	cout << "Your string enhanced: " << result << endl;
	cout << "Your orginal string: "  << input << endl;

	cout << "Resultting orginal string:\n";
	input = copy;
	result = version3(input, "@@@");  // ���ص��ǶԾֲ��Զ�����temp������, Ȼ��temp��ִ����version3�󽫻ᱻ����, ���Խ��ᵼ��abort()�����, ��ȷ��ʽ����ѡ��̬�����ڴ淽ʽ
	// �������û��"result ="�Ͳ��ᱨ����!!!   ��������ó��������������Ѿ��ͷŵ��ڴ�
	cout << "Your string enhanced: " << result << endl;
	cout << "Your original string: " << input << endl;

	return 0;
}

string version1(const string & s1, const string & s2) // ��version1��: ���ܽ����� 2 �ӡ�const char [7]��ת��Ϊ��std::string &�� �����������const�Ļ������������ת����
 {                                                   // ��return��: �޷��ӡ�const std::string(���ﲻ˵����const string &�ǲ�����Ϊ����˵�Ĳ��ǲ��ܰ�s2����������˵�Ĳ��ܰ�"����"������???)��ת��Ϊ��std::string &�� �ڷ��� ֵ���͵�����ϲ�����string & ����, ����const string &�ǿ��Ե�
	string temp;

	temp = s2 + s1 + s2;
	return s2;
}

const string & version2(string & s1, const string & s2)
{
	s1 = s2 + s1 + s2;
	return s1;
}

const string & version3(string & s1, const string & s2)
{
	string temp;
	temp = s2 + s1 + s2;
	return temp;  // warning C4172: ���ؾֲ���������ʱ�����ĵ�ַ
	/*string * temp = new string;
	*temp = s2 + s1 + s2;
	return *temp;*/
}