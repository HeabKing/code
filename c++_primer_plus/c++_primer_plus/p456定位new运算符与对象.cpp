// �����嵥 12.8
#include <iostream>
#include <string>
#include <new>  // ��λnew
using namespace std;
const int BUF = 512;
class JustTesting
{
private:
	string words;
	int number;
public:
	JustTesting(const string & s = "Just Testing", int n = 0)
	{words = s; number = n; cout << words << " constructed\n";}
	~JustTesting(){cout << words << " ------------ destroyed\n";}
	void Show() const {cout << words << ", " << number << endl;}
};

int main(void)
{
{
	char * buffer = new char[BUF];  // ����һ����λ�洢��
	JustTesting * pc1, * pc2;

	pc1 = new(buffer) JustTesting;  // place object in buffer �ڶ�λ�洢������һ���ڴ�
	pc2 = new JustTesting("Heap1", 20);  // place object on heap �ڶ��������һ���ڴ�

	cout << "Memory block addressed:\n" << "buffer: "
		<< (void *)buffer << "    heap: " << pc2 << endl;
	cout << "Memory contents:\n";
	cout << pc1 << ": ";
	pc1->Show();
	cout << pc2 << ": ";
	pc2->Show();

	JustTesting * pc3, * pc4;
	pc3 = new (buffer) JustTesting("Bad Idea", 6);  // ����ĵ�ַ��pc1һ��!!!!!!!
	pc4 = new JustTesting("Heap2", 10);

	cout << "Memory contents:\n";
	cout << pc3 << ": ";
	pc3->Show();
	cout << pc4 << ": ";
	pc4->Show();

	delete pc4;  // ������û��дdelete pc2Ȼ����ʾ����û��------------ destroyed\n��Ϊ��λ�ڶ�̬������ڴ���, ���Բ�����return�ϱߵ�}���Զ�������������!!!
	//delete pc1; // �����ǲ��Ե�, ��Ϊdeleteֻ���볣��new���ʹ��!!! ����ʹ�û������е�ʱ����
	delete [] buffer;
	cout << "Done!";
}
	return 0;
}