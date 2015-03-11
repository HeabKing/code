//---------------------------------------------------------------------
//�ļ��޸�ʱ�䣺2013��1��10��   ϵͳ��Win7 32λ�콢�� IDE��VS2010
//   ���ߣ���Ҷ����                     QQ��775904764
//   ͷ�ļ�������������.h
//   ��Ҫ���ܣ��������������õ���һЩ����������������ʼ����
//   ����˵�����������һ�㴢����ͷ�ļ��У�����һ��ϰ�ߡ�
//---------------------------------------------------------------------
class FiveChess
{
public:
	FiveChess():x(0),y(0),flag(0),Choice(0),Check(0),Check1(0),Select(true),ExWhile(true),ExWhile1(true),Continue(true){}  //���캯����ʼ����Ա������ֵ
	~FiveChess(){}                         
	void StartGame(int [][15],int [][15]);			//��Ϸ��ʼ
	void PrintBord(int *,int *,int [][15],int);     //���Ӻ�������������
	void Empty(int [][15],int [][15]);				//�������
	void Retract(int &,int &,int &,int &,int [][15]); //����
	int Position(int *,int *,int [][15]);			//�ж�����Ϸ���
	int Win(int *,int *,int,int [][15]);			//�ж�ʤ�����ߺ���
	int NextPlayer(int [][15]);						//�жϸ��ĸ��������
	void Single(int [][15]);						//��AI��ս
	void Double(int [][15]);						//˫�˶�ս
	void Robot(int *,int *,int *,int [][15]);		//AI����������
	void Findscore(int &,int &);                    //Ѱ���������
	void ChessScore();                              //AI���ֺ���
	void ChessOne(int &,int &,int [][15]);          //���Ե�һ���������
	void Victory(int);					            //ʤ������
	int  MainMenu();								//ѡ�����
	bool Introduce();								//��Ϸ����
	bool Coder();								    //��������
	void Exit();								    //�˳�����
	bool Continue;                                  //�Ƿ������Ϸ
private:
	int x;                             //����
	int y;
	int flag;                          //��־
	int Sumchess;                      //������ͳ��
	bool Select;
	bool ExWhile;                      //�˳�ѭ������
	bool ExWhile1;
	int Choice;
	int Check;                         //��ⷵ��ֵ�õ�
	int Check1;
};