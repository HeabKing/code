// �����嵥 4.20
#include <iostream>
#include <cstring>
int main()
{
	using namespace std;
	char animal[20] = "bear";
	const char * bird = "wren"; // "wren" ʵ�ʱ�ʾ�����ַ����ĵ�ַ
	char ch = 'c';
	char * Ptr;
	char * ps;

	Ptr = &ch;
	// ֱ��д*Ptr = 'c';�ǲ��Ե�, ��ΪPtrû�г�ʼ��, �������Ǹ�Ұָ��
	cout << animal << " and " << bird << " and " << Ptr << endl;
	// cout����ַ�����ʱ��ʹ��һ���ַ��ĵ�ַΪ������,
	// ֻҪ���ַ���ַ, ���ͻ���ͼȥһֱ���¶�֪������'\0'
	// ���Ե�����Ptr���������

	// cout << ps << endl; ʹ��Ұָ��ᵼ�³�����ֹ 

	cout << "Enter a kind of animal: " << endl;
	cin >> animal;

	// cin >> ps; ����ʹ��Ұָ��Ҳ�ᵼ�³������ֹ
	// *ps = 'b'; ͬ���� ����ʹ��Ұָ��Ҳ�ᵼ�³������ֹ
	
	ps = animal;
	cout << ps << endl;

	cout << "Before using strcpy():\n";
	cout << animal << " at " << (int *)animal << endl;
	cout << ps << " at " << (int *)ps << endl;
	// ��������ͽ�����ǿ�Ƶ�����ת�� ��Ϊchar���͵�ָ��ᱻ��������ַ���, ����ǿ��ת������ָ��int��ָ��

	ps = new char[strlen(animal) + 1]; // ��"��"���涯̬����һ�����û�����Ķ�����һ����С�Ŀռ�
	strcpy(ps, animal);
	cout << "After using strcpy():\n";
	cout << animal << " at " << (int *)animal << endl;
	cout << ps << " at " << (int *)ps << endl;

	cout << "*bird =" << bird << endl;
	// strcpy(bird, animal); �ᱨ��, ��Ϊconst char * bird = "wrten";��˼��bird�����ݿ��Ըı䵫�ǲ�����ͨ�����ı���ָ���ڴ��ֵ
	// animal = bird; ͬ��������, ˵��Ҳ������ͨ��������ָ���޸�"wrten", ��һ��˵��const char * bird = "wrten";ָ��"wrten"�ǲ����޸ĵĳ���
	// const char * bird = "wrten"; ����������:  >>�����ַ�<<ָ�� char const * bi = "ceshi"; δ�����д�� char * const bi = "ceshi"; ����: �ַ�>>ָ�볣��<<
	//char * const bi = "ceshi";
	//bi = animal;�ǲ������
	//bi = animal;
	//cout << "bi = " << bi << endl;
	//strcpy(animal, bird);//ȷʵ���Ե�
	cout << "*bird =" << bird << endl;

	delete [] ps;

	return 0;
}