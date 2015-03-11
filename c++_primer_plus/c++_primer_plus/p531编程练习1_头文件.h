class Cd  // represents a CD disk
{
private:
	char performers[50];
	char label[20];  // ��ǩ
	int selections;
	double playtime;
public:
	Cd(char * s1, char * s2, int n, double x);
	//Cd(const Cd & d);  // ���ƹ��캯��  ע��: ����û�ж�̬�����ڴ�֮��Ķ���, ����Ĭ�ϵĸ��ƹ��캯���Ϳ���ʵ����
	Cd();  // Ĭ�Ϲ��캯��
	virtual ~Cd();  // ��������
	virtual void Report() const;  // reports all CD data
	//virtual Cd & operator= (const Cd & d);  // ��ֵ����  ע��: Ĭ�ϵľ�ͦ��
};

class Classic : public Cd
{
private:
	char best[100];
public:
	Classic(char * bes, char * s1, char * s2, int n, double x);
	Classic();
	//virtual ~Classic(); �������������������ʡ��, ���ڻ����Ѿ�����������������, �����������������������
	virtual void Report() const;
	//virtual Cd & operator=(const Cd & d);  // ���������Ϊ��������Ƶ�ҲҪʹ�û����������????
};