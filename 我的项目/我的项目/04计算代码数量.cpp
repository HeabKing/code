#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

const char * FILENAME = "04���������������.cpp";

int main(void)
{
		// ���ļ�, ������

	ifstream fin;	// �ļ��������
	fin.open(FILENAME);
	if (!fin.is_open())
	{
		cout << "���ܴ��ļ� " << FILENAME << " !\n";
		exit(EXIT_FAILURE);
	}
	cout << "���ļ� " << FILENAME << " �ɹ�...\n";
	cout << "��ȡ�ļ� " << FILENAME << " ��ʼͳ��...\n\n";

		// ��ȡ�ļ�, ����ͳ��
	char	ch;				// ��ʱ����ÿ����ȡ���ַ�
	struct
	{
		int		iCntChar;	// �ַ���(����ʾ�Ļس�����, ע�ͳ���, �հ׷�(�ո�, tap)����)
		int		iCntLetter;	// ��ĸ��((����ʾ�Ļس�����, ע�ͳ���))
		int     iCntFuHao;	// ������(, ; / * () {} & ...)
		int		iCntRow;	// ����
		int		iDigit;		// ���������ָ���
		int		iCnHalf;	// ��ע�����ĸ���(�ַ���, �����ּ�����ĺ�(#define ����), ����...)
		int		iCnHalfAnt;	// ע�����ĸ���
		int		iCntCharAnt;// ע���ַ�����(�س�������, �����հ׷�(�ո�, tap��һ���ַ�)
	} Data = {0};
	enum annotation{ifAnt, isAnt, notAnt, isAnt2};
	annotation	Ant = notAnt;	// ע���ж�
		// ��ʼͳ��

	ch = fin.get();	
	int chNum = 0;
	while (fin.good())
	{
		if (chNum++ >= 100000)
		{
			std::cout << "�ļ�" << FILENAME << "���Ǳ�׼c/c++/h���ļ�, �����˳�";
			exit(EXIT_FAILURE);
		}
			// ���Ĵ���

		if ((ch > 255 || ch < 0) 
			&& isAnt != Ant && isAnt2 != Ant)	// �ų�����ע��
		{
			ch = fin.get();
			Data.iCnHalf++;
			continue;
		}

			// ͳ������
		if (ch == '\n')
			Data.iCntRow++;

			// ����ע�� "//"
		if ('/' == ch && notAnt == Ant)	// "//" ? "/" ? "/*" ? "*/"
			Ant = ifAnt;
		else if ('/' == ch && ifAnt == Ant)
			Ant = isAnt;
		else if (isAnt == Ant)
		{
			int flag = 0;
			do{	// ʹ��do-whileʹ�� "//"��ߵĵ�һ���ַ�Ҳ�ܽ����ж�
				if (ch == EOF)
				{
					flag = 1;
					break;
				}
				if (ch < 0 || ch > 255)
					Data.iCnHalfAnt++;
				else
					Data.iCntCharAnt++;
			}while('\n' != (ch = fin.get()));	// �Ե�ע��
			Data.iCntCharAnt += 2;	// "//"����Ҳ������ע���ַ�

			if (flag)
				break;
			Data.iCntRow++;	// �������е�ע��, �����������ǵü���
			Ant = notAnt;
			
		}

			// ����ע�� "/* */"
		else if ('*' == ch && ifAnt == Ant)
			Ant = isAnt2;
		else if (isAnt2 == Ant)
		{
			Ant = notAnt;
			int flag = 0;	// Ѱ�� "*/" �ı��
				
				// һֱɾ��ע��, ֱ��ע�ͽ���
			
			do{	// ��ֹ/*��ߵĵ�һ���ַ�������, ���Ҳ���do-while�Ļ�, /**/�����
				if (ch < 0 || ch > 255)
					Data.iCnHalfAnt++;
				else if ('*' == ch)
				{
					flag = 1;
					Data.iCntCharAnt++;
				}
				else if (flag && '/' == ch)
					break;
				else
				{
					if ('\n' == ch)	// ע�͵�����Ҳ������, ���ǲ���ע���ַ�
						Data.iCntRow++;
					else
						Data.iCntCharAnt++;
					flag = 0;
				}
			} while (ch = fin.get());
			Data.iCntCharAnt += 3;	// "/*", '/'
		}

			// ͳ���ַ�, ��ĸ����
		else if (isgraph(ch))	// �ַ�
		{
			Ant = notAnt;
			Data.iCntChar++;
			if (isalpha(ch))	// ��ĸ����
				Data.iCntLetter++;
			else if (ispunct(ch))	// ��������
				Data.iCntFuHao++;
			else if (isdigit(ch))	// ���ָ���
				Data.iDigit++;	
		}
		ch = fin.get();
	}

		// ���������ʾ

	cout << "\nͳ���ļ� "		<< FILENAME						<< " ���...\n";
	cout << " ���� : "			<< ++Data.iCntRow					<< endl;
	cout << "���ַ�: "			<< Data.iCntChar + Data.iCnHalf / 2 + Data.iCntCharAnt + Data.iCnHalfAnt / 2 << endl;
	cout << "\t��ע���ַ���: "	<< Data.iCntChar + Data.iCnHalf / 2		<< endl;
	cout << "\t\t��ĸ��: "		<< Data.iCntLetter					<< endl;
	cout << "\t\t������: "		<< Data.iCntFuHao					<< endl;
	cout << "\t\t������: "		<< Data.iDigit						<< endl;
	cout << "\t\t������: "		<< Data.iCnHalf / 2					<< endl;
	cout << "\tע���ַ���: "	<< Data.iCntCharAnt + Data.iCnHalfAnt / 2	<< endl;
	cout << "\t\t������: "		<< Data.iCnHalfAnt / 2				<< endl;
	cout << "\t\t�ַ���: "		<< Data.iCntCharAnt					<< endl;

	cout << "\nDone!\n";
	return 0;
}