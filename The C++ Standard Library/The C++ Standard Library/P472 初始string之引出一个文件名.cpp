// C:\Users\daxiong\Desktop\�½��ļ���\1.exe prog.dat mydir hello. oops.tmp end.dat
#include <iostream>
#include <string>	// string ������ַ���β��û��һ�������ַ� '\0'
using namespace std;

int main(/*int argc, char ** argv*/)
{
	int argc = 6;
	char *argv[6] = {
		"C:\\Users\\daxiong\\Desktop\\�½��ļ���\\1.exe",
		"prog.dat", "mydir", "hello.", "oops.tmp", "end.dat"
	};
	string filename, basename, extname, tmpname;
	const string suffix("tmp");	// suffix ���׺, ��׺, �±�

	// for each command-line argument
	// (which is an ordinary C-string)
	for (int i = 0; i < argc; ++i)
	{
		// process argument as file name
		filename = argv[i];
		// search period in file name	// period ����, ���
		string::size_type idx = filename.find('.');	// ��Ѱʧ�ܷ��� string::npos
		if (idx == string::npos)	// ����ַ�������û��'.'����
			// file name does not contain any period
			tmpname = filename + '.' + suffix;
		else
		{
			// split(�ֿ�, ����, �ָ�) file name into base name and extension(�ӳ�)
			// - base name contains all characters before the period
			// - extension contains all characters after  the period
			basename = filename.substr(0, idx);	// arg1 ������� arg2 �ַ�����
				// arg2 �ַ���������Ϊ����ֵ, �������ʣ���ַ���, ��ʣ���ַ����ᱻ����	

			extname  = filename.substr(idx + 1);// �� arg1 ��ʼ, ��ʣ���ַ�������
			if (extname.empty())	// ���� "hello."
			{
				// caontains period but no extension: append tmp
				tmpname = filename;
				tmpname += suffix;
			}
			else if (extname == suffix)	// ���� "oops.tmp"
			{
				// replace extension tmp with xxx
				tmpname = filename;
				tmpname.replace(idx + 1, extname.size(), "xxx");	// arg1 ������� arg2 �ַ�����  arg2����Ϊ����ֵ, �������ʵ��ʣ���ַ���, ������ʣ���ַ����ᱻ�õ�
					// string::size()�����ַ������ַ����� string::length()���Ի����ͬ���
					// ��������������ͬ�����ԭ��ִ������ͬ�Ķ���, length()�����ַ����ĳ���, �ͺ���C-strings��strlen()���ý��һ��, size()���Ǹ���STLϰ�߶����õĳ�Ա����, ��������Ԫ������
			}
			else	// ���� "end.dat"
			{
				// replace any extension with tmp
				tmpname = filename;
				tmpname.replace(idx + 1, string::npos, suffix);
					// ���ʹ��string::npos�൱��ָ��"ʹ�������ַ�"
			}	
		}
		// print file name and temporary name
		cout << filename << " => " << tmpname << endl;
	}
	string a;
	cin >> a;
}
// ����"��һ��������һ���ַ�������Ϊ����"�ĵط�, �ַ�����Ϊ��ѭ������������:
//		1. ����ֵ����Ϸ�, ��ֵ����С���ַ������ַ�����(��һ���ַ���������0), ���һ���ַ�����һ��λ��(������)��������������λ��  �󲿷������, ���ָ��������������ʵ���ַ���, �ͻ�����out_of_range�쳣, ����, ������Ѱ��һ�ַ�����ĳ��λ�õ�������Ѱ����, ���ɽ�����������, �������������ʵ���ַ���, ��Щ�����ͻ᷵��string::npos(��ʾû���ҵ�)

//		2. �ַ�����(����)����Ϊ����ֵ, �����ֵ����ʵ��ʣ����ַ���, ����Щʣ���ַ����ᱻ�õ�, ���ʹ��string::npos, �൱��"ʣ�������ַ�"
//		eg: ����Ҳ���'.', ���±��ʽ���׳��쳣, filename.substr(filename.find('.')), �������±��ʽ�����׳��쳣, ���Ƿ��������ļ���filename.substr(0, filename.find('.'))