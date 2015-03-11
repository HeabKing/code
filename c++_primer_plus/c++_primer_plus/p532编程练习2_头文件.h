class Cd  // represents a CD disk
{
private:
	char * performers;
	char * label;  // ��ǩ
	int selections;
	double playtime;
public:
	Cd(char * s1, char * s2, int n, double x);
	Cd(const Cd & d); 
	Cd();  // Ĭ�Ϲ��캯��
	virtual ~Cd();  // ��������
	virtual void Report() const;  // reports all CD data
	virtual Cd & operator= (const Cd & d);  // ��ֵ����  
};

class Classic : public Cd
{
private:
	char * best;
public:
	Classic(char * bes, char * s1, char * s2, int n, double x);
	Classic();
	virtual ~Classic();
	virtual void Report() const;
	virtual Classic & operator=(const Classic & d);
};