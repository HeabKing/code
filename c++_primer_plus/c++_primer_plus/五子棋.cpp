//--------------------------------------------------------------------------//
//                 �������壨����̨�棩����[Ver2.1]
//     �޸���AIԽ������⣬�����ֺ������޸���Ӯ�жϺ�����BUG��
//     AI���ֺ��������в��ָı䣬����Ҳ���Ӽ�����
//     �������幦�ܣ�����AI��սʱ���ã��������¿�ʼ���ܡ�
//     �޸������һ��СBUG���޸�AI������Ӳ��ֵĶ������
//                 ���ߣ���Ҷ����     QQ��775904764
//--------------------------------------------------------------------------//
#include "������.h"
#include <time.h>                                                  
#include <iostream>
using namespace std;                                                   
static const char ch[11][4]={"��","��","��","��","��","��","��","��","��","��","��"};  //�ɹ�ѡ�õ��ַ���������̻���������
static int Record[15][15]={0};             //��¼����
static int Score[15][15]={0};              //����
static int Sum=0,Renum=0;                 
int main()                                
{
    int Default[15][15]={ 0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,  //������
						  3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                          3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
						  3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
						  3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                          3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                          3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                          3,4,4,4,4,4,4,4,4,4,4,4,4,4,5, 
                          3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                          3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                          3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                          3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                          3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                          3,4,4,4,4,4,4,4,4,4,4,4,4,4,5,
                          6,7,7,7,7,7,7,7,7,7,7,7,7,7,8 };
	int value[15][15]={0};      
	FiveChess Start;
	do
	{
	    Start.StartGame(value,Default);   //��ʼ��Ϸ
	}
	while (Start.Continue);        //����Ҫ�˳����޸����ֵ
	return 0;                       
}
//------------------------------��ʼ��Ϸ------------------------------------------//
void FiveChess::StartGame(int value[][15],int Default[][15])
{
	Empty(value,Default);         //��ʼ������ad
	ExWhile=true;
	while(ExWhile)
	{
		Choice=MainMenu();        //�������˵��������û�ѡ���ֵ������Choice��                 
		switch(Choice)                       
	    {
	        case 1:flag=1;ExWhile=false;break;    //�ѱ�־����Ϊ1����AI��ս
	    	case 2:flag=2;ExWhile=false;break;    //�ѱ�־����Ϊ2��˫�˶�ս
			case 3:Select=Introduce();ExWhile=Select;Continue=false;break;     //��Ϸ˵������
	    	case 4:Select=Coder();ExWhile=Select;Continue=false;break;         //���߽��ܺ���
	    	case 5:Exit();ExWhile=false;Continue=false;break;                  //�˳���Ϸ����
	    	default:cin.fail();cin.clear();cin.sync();cout<<"����������������룡\n";system("pause>nul 2>nul");ExWhile=true;break;  //����
	    }
   	}
	if (flag==1)             //�����־����1��˵��Ϊ������Ϸ
	{
		Single(value);        
	}
   	else if (flag==2)		  //�����־����2��˵��Ϊ˫����Ϸ
	{
		Double(value);
	}
	flag=0;
}
//------------------------������̻��ʼ������-----------------------------------//
void FiveChess::Empty(int value[][15],int Default[][15])       //�������
{
	for (int i=0;i<15;i++)             
	{
		for (int j=0;j<15;j++)
		{
		     value[i][j]=Default[i][j];
		}
	}
}
void FiveChess::Exit()             //�˳���Ϸ
{
	system("cls");
	cout<<"������������������������������������������������������\n";
	cout<<"��          ��л��ʹ�ã��������� Ver2.1           ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[��Ϸ����]����Ҷ����                              ��\n";
	cout<<"��[��ϵQ Q ]: 775904764                             ��\n";
	cout<<"��[��ϵ����]��lxhdjwg@126.com                       ��\n";
	cout<<"��[��˵��]����Ϸ�������棬лл����ʹ�ã�          ��\n";
	cout<<"������������������������������������������������������\n";
	cout<<"��л����ʹ�ã�лл����������˳���Ϸ...\n";
	system("pause>nul 2>nul");          
}
bool FiveChess::Introduce()              //��Ϸ����
{
	system("cls");
	cout<<"������������������������������������������������������\n";
	cout<<"��          �������� Ver2.1[��Ϸ���ܽ���]         ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[������Ϸ]����Һ�AI���˹����ܣ���ս��AI���̲��ߡ���\n";
	cout<<"��                                                  ��\n";
	cout<<"��[˫����Ϸ]: �����������һ���ս�����ܲ��Ǻܷ��㡣��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[��Ϸ����]������X Y�������ӣ�����˫-1���塣       ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[�ر���ʾ]������Ϸ����ͻȻ�˳�����Ctrl+C�����жϡ���\n";
	cout<<"��                                                  ��\n";
	cout<<"������������������������������������������������������\n";
	cout<<"�Ƿ񷵻أ�[Y-���� N-�˳�]��";
	char choice;
	cin>>choice;
	if (choice=='N'||choice=='n')
	{
		cout<<"��л����ʹ�ã�лл����������˳���Ϸ...\n";
	    system("pause>nul 2>nul");      
		return false;
	}
	else
	{
		return true;
	}
}
bool FiveChess::Coder()                     //���߽���              
{
	system("cls");
	cout<<"������������������������������������������������������\n";
	cout<<"��          �������� Ver2.1[���߽��ܽ���]         ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[��Ϸ����]����Ҷ����                              ��\n";
	cout<<"��[��ϵQ Q ]: 775904764                             ��\n";
	cout<<"��[��ϵ����]��lxhdjwg@126.com                       ��\n";
	cout<<"��[�򵥽���]����Ϸ������ª���������^_^��           ��\n";
    cout<<"��[����˵��]����������Ŭ��ѧϰC++�У��ٺ�~          ��\n";
  	cout<<"������������������������������������������������������\n";
	cout<<"�Ƿ񷵻أ�[Y-���� N-�˳�]��";
	char choice;
	cin>>choice;
	if (choice=='N'||choice=='n')
	{
		cout<<"��л����ʹ�ã�лл����������˳���Ϸ...\n";
	    system("pause>nul 2>nul");             
		return false;                       
	}
	else
	{
		return true;
	}
}

//-------------------------------ѡ�����˵�-----------------------------//
int FiveChess::MainMenu()                         
{
	system("cls");                                 //����
	system("title ��������Ϸ   By--��Ҷ����   QQ:775904764");     //�޸Ĵ��ڱ���
	system("color 3f");                            //���崰����ɫ
	system ("mode con cols=56 lines=20");          //���ô��ڴ�С
	cout<<"������������������������������������������������������\n";
	cout<<"��                  �������� Ver2.1               ��\n";
	cout<<"��[1]��������Ϸ                                     ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[2]��˫����Ϸ                                     ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[3]����Ϸ����                                     ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[4]����������                                     ��\n";
	cout<<"��                                                  ��\n";
	cout<<"��[5]���˳�                                         ��\n";
	cout<<"������������������������������������������������������\n";
	cout<<"��ѡ��";
	int select;
	cin>>select;
    return select;      //�����û�ѡ���ֵ
}

//--------------------------------ʤ������--------------------------------//
void FiveChess::Victory(int Num)
{
	system ("mode con cols=56 lines=20");          //���ô��ڴ�С
	system("cls");
	if (Num==1)
	{
		system("color 1f");
	    cout<<"������������������������������������������������������\n";
	    cout<<"��          ��ϲ���1[����]���ʤ����               ��\n";
		cout<<"��                                                  ��\n";
		cout<<"��[ʤ�����]�����1                                 ��\n";
		cout<<"��[��������]: ��ɫ                                  ��\n";
		cout<<"��[ף������]������Ŷ^_^����ϲ�������ʤ����         ��\n";
		cout<<"��                                                  ��\n";
		cout<<"������������������������������������������������������\n";
	}
	else if (Num==2)
	{
		system("color 2f");
		cout<<"������������������������������������������������������\n";
		cout<<"��          ��ϲ���2[����]���ʤ����               ��\n";
		cout<<"��                                                  ��\n";
		cout<<"��[ʤ�����]�����2                                 ��\n";
		cout<<"��[��������]: ��ɫ                                  ��\n";
		cout<<"��[ף������]����ϲ�������ʤ�����ٽ�������^_^��     ��\n";
		cout<<"��                                                  ��\n";
		cout<<"������������������������������������������������������\n";
	}
	else if(Num==3)
	{
		system("color 3f");
		cout<<"������������������������������������������������������\n";
		cout<<"��                  ��ϲ���������ʤ��              ��\n";
		cout<<"��                                                  ��\n";
		cout<<"��[ʤ�����]���Լ�                                  ��\n";
		cout<<"��[��������]: ��ɫ                                  ��\n";
		cout<<"��[ף������]������Ŷ�������AI����ϲ��              ��\n";
		cout<<"��                                                  ��\n";
		cout<<"������������������������������������������������������\n";
	}
	else if(Num==4)
	{
		system("color 5f");
		cout<<"������������������������������������������������������\n";
		cout<<"��                  �ǳ��ź���������!               ��\n";
		cout<<"��                                                  ��\n";
		cout<<"��[ʤ�����]��AI�����ԣ�                            ��\n";
		cout<<"��[��������]: ��ɫ                                  ��\n";
		cout<<"��[ף������]�����Ͱɣ��´�һ��Ҫ��AI���Ŷ!         ��\n";
		cout<<"��                                                  ��\n";
		cout<<"������������������������������������������������������\n";
	}
	else
	{
		system("color 5f");
		cout<<"������������������������������������������������������\n";
		cout<<"��                  �ƾ����С���ƽ��                ��\n";
		cout<<"��                                                  ��\n";
		cout<<"��[ʤ�����]����[ƽ��]                              ��\n";
		cout<<"��[��������]: ��ɫ���ɫ                            ��\n";
		cout<<"��[ף������]�����̾�Ȼ�������ˣ�������~��         ��\n";
		cout<<"��                                                  ��\n";
		cout<<"������������������������������������������������������\n";
	}
	cout<<"�Ƿ񷵻������棿[Y-���� N-�˳�]��";
	char choice;
	cin>>choice;
	if (choice=='N'||choice=='n')
	{
		cout<<"��л����ʹ�ã�лл����������˳���Ϸ...\n";
	    system("pause>nul 2>nul");              
		Continue=false;
	}
	else
	{
		Continue=true;
	}
}

//----------------------------����-------------------------------//
void FiveChess::Retract(int &x1,int &y1,int &x2,int &y2,int value[][15])
{
	if (Sum>=1)
	{
	    Sum--;
	}
	if ((x1==-1)&&(y1==-1)&&(x2==-1)&&(y2==-1))
	{
		cout<<"��ǰ�޷����壬������û������!";
		system("pause>nul");
	}
	else if (Renum>=6)
	{
		cout<<"���峬��6�Σ�Ϊ�˹�ƽ���������ٴλ���!";
		system("pause>nul");
	}
	else
    {
		Renum++;
		if (x1==0&&y1==0){value[x1][y1]=0;Record[x1][y1]=0;}
		else if (x1==0&&y1==14){value[x1][y1]=2;Record[x1][y1]=0;}
		else if (x1==14&&y1==0){value[x1][y1]=6;Record[x1][y1]=0;}
		else if (x1==14&&y1==14){value[x1][y1]=8;Record[x1][y1]=0;}
		else if (x1==14&&(y1>0&&y1<14)){value[x1][y1]=7;Record[x1][y1]=0;}
		else if (y1==14&&(x1>0&&x1<14)){value[x1][y1]=5;Record[x1][y1]=0;}
		else if (x1==0&&(y1>0&&y1<14)){value[x1][y1]=1;Record[x1][y1]=0;}
		else if (y1==0&&(x1>0&&x1<14)){value[x1][y1]=3;Record[x1][y1]=0;}
		else {value[x1][y1]=4;Record[x1][y1]=0;}

		if (x2==0&&y2==0){value[x2][y2]=0;Record[x2][y2]=0;}
		else if (x2==0&&y2==14){value[x2][y2]=2;Record[x2][y2]=0;}
		else if (x2==14&&y2==0){value[x2][y2]=6;Record[x2][y2]=0;}
		else if (x2==14&&y2==14){value[x2][y2]=8;Record[x2][y2]=0;}
		else if (x2==14&&(y2>0&&y2<14)){value[x2][y2]=7;Record[x2][y2]=0;}
		else if (y2==14&&(x2>0&&x2<14)){value[x1][y2]=5;Record[x2][y2]=0;}
		else if (x2==0&&(y2>0&&y2<14)){value[x2][y2]=1;Record[x2][y2]=0;}
		else if (y2==0&&(x2>0&&x2<14)){value[x2][y2]=3;Record[x2][y2]=0;}
		else {value[x2][y2]=4;Record[x2][y2]=0;}
		cout<<"ÿ������������6��,�����ֻ�ܻص���һ��!";
		system("pause>nul");
	}
}
//-----------------------------�ж��û����������Ϸ���-------------------------//
int FiveChess::Position(int *x,int *y,int value[][15])            
{              
	if (cin.fail()||*x<0||*x>=15||*y<0||*y>=15)  
	{
		cin.clear();   
                cin.sync();   
		return 1;      //����1��ʾ���ڷ�Χ�ڻ�������Ĳ�������
	}
    	else if (value[*x][*y]==9||value[*x][*y]==10)
	{
		return 2;           //��������
	}
	else
	{
	    return 0;           //���� 0 ��ʾ ��������
    }
}

//---------------------------�жϸ��ĸ��������----------------------------//
int FiveChess::NextPlayer(int value[][15])    
{
	int i,j;
	int player1=0,player2=0;           
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			if (value[i][j]==10)
			{
				player1++;               //ͳ������������ӵĸ���
			}
			else if (value[i][j]==9)
			{
				player2++;               //ͳ�������ϰ��ӵĸ���
			}
		}
	}
	if (player1>player2||player1<player2) 
	{
		return 2;                          //�����2����(����)
	}
	else                                   
	{
		return 1;                          //�����1���ˣ����ӣ�
	}
}

//---------------------------�ж�����������㣬�Ƿ�ʤ������ƽ��-----------------------------------------//
int FiveChess::Win(int *x,int *y,int ChessNum,int value[][15])   
{                                       
	int i,j,k;             //����-1��ƽ��     ����0��û��˭ʤ��     ����1�����ݹ���ChessNum�ŵ���һ��ʤ��
    int number=0;
	Sumchess=0;            
	for (i=-1;i<=1;i++)
	{
		for (j=-1;j<=1;j++)      //ѭ��8�Σ��ֱ����������8�������Ƿ񹹳�5��
		{
			if (i!=0 || j!=0)    //i����j����0�����ʹ������ChessNum��ֵ��
			{
				for (k=1;k<5;k++)  //ѭ��4��
				{                              //���ǲ�Խ���ж�                                     //����������Ŀ+1
				    if(*x+k*i>=0 &&*x+k*i<=14 && *y+k*j>=0 &&*y+k*j<=14 && value[*x+k*i][*y+k*j]==ChessNum){number++;}   //��������������
                    else {break;}      //û�����Ӿ�����
				}
				for (k=-1;k>-5;k--)  //��������Եķ�����ж�
				{                         
					if(*x+k*i>=0 &&*x+k*i<=14 && *y+k*j>=0 &&*y+k*j<=14 && value[*x+k*i][*y+k*j]==ChessNum){number++;}   
                    else {break;}      //û�����Ӿ�����
				}
				if(number>=4)          //���>=4��˵��5���ˣ�����ChessNum��ʾ���ݹ����������ҵ����ӵ��ܹ���5����ʤ���� 
                {
                     return 1;  
                }
                else
                {
                     number=0;          //���ͳ�� 
                }

			}
		}
	}
	for (i=0;i<15;i++)                   //�����Ƿ�����
	{
		for(j=0;j<15;j++)
		{
			if (value[i][j]==9||value[i][j]==10)
			{
				Sumchess++;   //ͳ�ƺ��ӺͰ��ӵ��ܸ���
			}
		}
	}
	if (Sumchess>=225)
	{
	   return -1;                 //��������
	}
	else
	{
        return  0;               //ûʤ��Ҳû����
	}
}

//---------------------------------�������̡����Ӻ���-----------------------------------------//
void FiveChess::PrintBord(int *x,int *y,int value[][15],int player)    
{
	system("cls");  
	int i,j;
	if (player==1)                   
	{
	    value[*x][*y]=9;              //����
	}
	else if (player==2)              
	{
	    value[*x][*y]=10;           //����
	}
	cout<<"     0 1 2 3 4 5 6 7 8 9 10 1 2 3 4\n";     //����ο�����
	for (i=0;i<15;i++)              
	{
		if(i!=0)
		{
        		cout<<"    "<<i%10;         
		}
		else
		{
			cout<<"    0";
		}
		for (j=0;j<15;j++)           
		{
           		cout<<ch[value[i][j]];    
		}
		cout<<"\n";                  
	 }
}

//------------------------------------˫�˶�ս-----------------------------//
void FiveChess::Double(int value[][15])   
{
	cout<<"��ѡ����˫�˶�սģʽ���밴�����������";
	system("pause>nul 2>nul");        
	system("cls");
	system ("mode con cols=43 lines=20");   
	system("color 3f");
	system("title ������-˫�˶�սģʽ");
	PrintBord(&x,&y,value,-1);  //�Ȼ��Ƹ�������
	ExWhile=true;        //�˳�ѭ���õ�
	memset(Record,0,sizeof(Record));   //�ȰѼ�¼���ӵ�������0
	while(ExWhile)
	{
		int play=NextPlayer(value); //�ȵõ����ĸ����������
		cout<<"��(���"<<play<<")��������[�ÿո����]��";
		cin>>x>>y;
		Check=Position(&x,&y,value);   //�������Ϸ���
		if (Check==0)                  //����û����
		{ 
		    PrintBord(&x,&y,value,play); //�ٻ�����������
			Record[x][y]=play;           //��¼����㣬1��ʾ����,2��ʾ����
			cout<<"���["<<play<<"]�����������ˣ�[X:"<<x<<"]  [Y:"<<y<<"]\n";
			Check1=Win(&x,&y,play,Record);  //����Ƿ���һ��ʤ�����ߺ���
            if (Check1==-1)          //����
		    {
				cout<<"��Ϸ������������û�ֳ�ʤ��������������!\n";
				cout<<"������Ϸ�����������������...";
			    system("pause>nul 2>nul");  
				Victory(5);                //��תʤ������
				ExWhile=false;             
			}
			else if(Check1==1)       //��ǰ���palyʤ��
			{
				cout<<"��ϲ[���"<<play<<"]���ʤ����\n";
				cout<<"������Ϸ�����������������...";
			    system("pause>nul 2>nul");
				Victory(play);           //��תʤ������
				ExWhile=false;       
			}
			else                     //û˭ʤ��
			{
				ExWhile=true;            //���˳�ѭ��
			}
		}
		else if(Check==1)
		{
			cout<<"���뷶Χ�������������룡\n";
			ExWhile=true;
		}
		else
		{
			cout<<"������������Ѿ��������ӣ����������룡\n";
			ExWhile=true;
		}
	}
}

//-------------------------------��AI��ս------------------------------//
void FiveChess::Single(int value[][15])                        
{
	cout<<"��ѡ������AI��ս��ģʽ���밴�����������";
	system("pause>nul 2>nul");       
	system("cls");
	system ("mode con cols=43 lines=20");   
	system("color 3f");
	system("title ������-��AI�Ķ�սģʽ");
	PrintBord(&x,&y,value,-1);                     //�Ȼ��Ƹ�������
	ExWhile=true;                                  //�˳�ѭ���õ�
	Sum=0,Renum=0;                                    
	memset(Record,0,sizeof(Record));               //�ȰѼ�¼���ӵ�������0
	int x1=-1,y1=-1,x2=-1,y2=-1;
	while(ExWhile)
	{
		    ExWhile1=true;
			cout<<"��[���]��������[˫(-1)Ϊ����]��";
		    cin>>x>>y;
			Check=Position(&x,&y,value);
			if ((x==-1)&&(y==-1))
			{
				Retract(x1,y1,x2,y2,value);
				PrintBord(&x,&y,value,-1);   //������������
				ExWhile=true;
			}
		    else if (Check==0)          //����û����
		    {
				value[x][y]=9;
				Record[x][y]=1;                 //��¼����㣬1��ʾ����,2��ʾ����
				x1=x;y1=y;                      //��¼��ǰ���������
				Sum++;
				if (Win(&x,&y,1,Record)==0)
			    { 
					Robot(&x,&y,&Sum,value);    //����AI����
					PrintBord(&x,&y,value,2);   //������������
					x2=x;y2=y;                  //��¼��ǰ���������
					cout<<"���������:"<<Sum<<" ���Ե�����������[X:"<<x<<"] [Y:"<<y<<"]\n";
					//cout<<"������꣺"<<x1<<" "<<y1<<"��������:"<<x2<<"  "<<y2<<endl;
					if (Win(&x,&y,2,Record)==1)
					{
						cout<<"�ǳ��ź��������ˣ�AI�����ʤ����\n";
						cout<<"������Ϸ�����������������...";
						system("pause>nul 2>nul");
						Victory(4);                   //��תʤ������
						ExWhile=false;
					}
					else if(Win(&x,&y,2,Record)==-1)
					{
						cout<<"��Ϸ������������û�ֳ�ʤ��������������!\n";
						cout<<"������Ϸ�����������������...";
						system("pause>nul 2>nul");
						Victory(5);                    //��תƽ�ֽ���
						ExWhile=false;
					}
					else {ExWhile=true;}
				}
				else if(Win(&x,&y,1,Record)==1)
				{
					PrintBord(&x,&y,value,-1);       //��������
					cout<<"��ϲ[���]���ʤ����\n";
				    cout<<"������Ϸ�����������������...";
			        system("pause>nul 2>nul");
				    Victory(3);              //��תʤ������
					ExWhile=false;
				}
				else if(Win(&x,&y,1,Record)==-1)
				{
					PrintBord(&x,&y,value,-1);       //��������
					cout<<"��Ϸ������������û�ֳ�ʤ��������������!\n";
				    cout<<"������Ϸ�����������������...";
			        system("pause>nul 2>nul");
				    Victory(5);                    //��תƽ�ֽ���
					ExWhile=false;
				}
		    }
		    else if(Check==1)
		    {
			    cout<<"���뷶Χ�������������룡\n";
		    }
		    else
		    {
			    cout<<"������������Ѿ��������ӣ����������룡\n";
		    }
	}
}

//-----------------------------�������Ӻ���-------------------------------//
void FiveChess::Robot(int *x,int *y,int *Sum,int value[][15])  
{
	ExWhile1=true;
	if (*Sum==1)                
	{
		while(ExWhile1)
		{
		   ChessOne(*x,*y,value);
		   if (Position(x,y,value)==0){ExWhile1=false;}
		}
		Record[*x][*y]=2;          //��¼�����
	}
	else                             //�ӵ�2����ʼ��ʹ������ϵͳ
	{
	    Findscore(*x,*y);             
	}
}

//-----------------------------����������ߵ�����-------------------------//
void FiveChess::Findscore(int &x,int &y)           
{
	srand( (unsigned)time( NULL ) );         
	int i,j,x1,x2,y1,y2,lx;
	int Max=0;
	ChessScore();                   //�������ֺ���
	for (i=0;i<15;i++)
	{
		for (j=0;j<15;j++)
		{
			if(Score[i][j]>Max)
			{
				Max=Score[i][j];          //��ȡ���е��У�������ߵ�
				x1=i;
				y1=j;
			}
		}
	}
	x2=x1;y2=y1;
	for (i=0;i<15;i++)                   //���ܵĻ�����������ͬ�Ķ����
	{
		for (j=0;j<15;j++)
		{
	        if(Score[i][j]==Max&&i!=x2&&j!=y2)    //����ô�����ͬ�����ĵ��У������һ��
			{
				lx=rand()%10;
				if (lx<5)
				{
			        x2=i,y2=j;
					break;
				}
			}
		}
	}
	if (x2!=x1 || y2!=y1)    //��������2����߷�
	{
		lx=rand()%10;            //���һ��^_^
		if (lx>6)
		{
			x=x1,y=y1;
		}
		else
		{
			x=x2,y=y2;
		}
	}
	else                  //������ֻ��һ����߷�
	{
	   x=x1,y=y1;
	}
	Max=0;                 //������ֵ
	Record[x][y]=2;          //��¼�����
}

//------------------------------����ߵ�1��ʱ������-------------------------------// 
inline void FiveChess::ChessOne(int &x,int &y,int value[][15])     
{
	int i,j;
	srand( (unsigned)time( NULL ) );            //���������ʱ��ĸı���ı�
	for (i=0;i<15;i++)
	{
		for(j=0;j<15;j++)
		{
			    if (value[i][j]==9)             //����ҵ�����ҵ����ӣ�������8����������һ������
			    {
				        int lx=rand()%7;       
				        if(lx==0)                
				        {
							x=i+1;y=j+1;
							if (Position(&x,&y,value)==0){break;}
				        }
				        else if(lx==1)
				        {
							x=i+1;y=j-1;
							if (Position(&x,&y,value)==0){break;}
				        }
				        else if(lx==2)
				        {
							x=i-1;y=j-1;
							if (Position(&x,&y,value)==0){break;}
				        }
				        else if(lx==3)
				        {
							x=i-1;y=j+1;
							if (Position(&x,&y,value)==0){break;}
				        }
						else if(lx==4)
				        {
							x=i-1;y=j;                             //��
							if (Position(&x,&y,value)==0){break;}
				        }
						else if(lx==5)
				        {
							x=i;y=j-1;                             //��
							if (Position(&x,&y,value)==0){break;}
				        }
						else if(lx==6)
				        {
							x=i;y=j+1;                            //��
							if (Position(&x,&y,value)==0){break;}
				        }
						else
				        {
							x=i+1;y=j;                            //��
							if (Position(&x,&y,value)==0){break;}
				        }
                 }
		   }
	  }
}
//-----------------------------------AI���ֺ���---------------------------------------//
void FiveChess::ChessScore()    
{
      int x,y,i,j,k;				    //ѭ������
	  int number1=0,number2=0;			//number����ͳ����һ�����������ɸ���
	  int empty=0;				        //empty����ͳ�ƿյ����
      memset(Score,0,sizeof(Score));    //����������������
      for(x=0;x<15;x++)
	  {
          for(y=0;y<15;y++)      
		  {
              if(Record[x][y]==0)   //��������Ϊ�� 
			  {
                  for(i=-1;i<=1;i++)
				  {
					  for(j=-1;j<=1;j++)  //�ж�8������ 
					 {
						 if(i!=0 || j!=0)  //���Ƕ�Ϊ0�Ļ����ǲ�����ԭ������
						 {
							 //-------------------------------------������������---------------------------------------//
						      for(k=1;i<=4;k++)          //ѭ��4��
							  {              //���ûԽ��                              //�������ں��ӣ���ң�
                                  if(x+k*i>=0 && x+k*i<=14 && y+k*j>=0 && y+k*j<=14 && Record[x+k*i][y+k*j]==1 ){number1++;}
								  else if(Record[x+k*i][y+k*j]==0){empty++;break;}     //����Ǹ��յ㣬+1���˳�
								  else {break;}         //������ǽ���߶Է��������� 
							  }                    
							  for(k=-1;k>=-4;k--)      //�������෴�����ж� 
							  {            //���ûԽ��                              //�������ں��ӣ���ң�
							      if(x+k*i>=0 && x+k*i<=14 && y+k*j>=0 && y+k*j<=14 && Record[x+k*i][y+k*j]==1 ){number1++;}
								  else if(Record[x+k*i][y+k*j]==0){empty++;break;}    //ͬ����
								  else {break;}           
                              } 
							  if(number2==1)     {Score[x][y]+=1;}  //2������   
                              else if(number1==2)                   //3������ 
                              {
                                    if(empty==1)       {Score[x][y]+=5;}   //��һ���յ�+5��     //��3       
                                    else if(empty==2)  {Score[x][y]+=10;}  //�������յ�+10��    //��3
                              }
                              else if(number1==3)   //4������ 
                              {
                                    if(empty==1)      {Score[x][y]+=20;}    //��һ���յ�+20��   //��4 
                                    else if(empty==2) {Score[x][y]+=100;}   //��2���յ�+100��   //��4
                              }
							  else if(number1>=4)     {Score[x][y]+=1000;}   //�Է���5�����ӣ�����Ҫ�ߵ㣬�ȶ�

                              empty=0;        //ͳ�ƿյ�����ı������� 

                             //---------------------------------------�Ե����������---------------------------------------//
							 for(k=1;i<=4;k++)  //ѭ��4��
							 {         //���ûԽ��                              //�������ڰ��ӣ����ԣ�
                                  if(x+k*i>=0 && x+k*i<=14 && y+k*j>=0 && y+k*j<=14 && Record[x+k*i][y+k*j]==2 ){number2++;}
								  else if(Record[x+k*i][y+k*j]==0){empty++;break;}  //�յ�
								  else {break;}        
							 }                    
							 for(k=-1;k>=-4;k--)      //�������෴�����ж� 
							 {
							      if(x+k*i>=0 && x+k*i<=14 && y+k*j>=0 && y+k*j<=14 && Record[x+k*i][y+k*j]==2 ){number2++;}
								  else if(Record[x+k*i][y+k*j]==0){empty++;break;}  
								  else {break;}           //���ﶥ���ж���ҵĶ��������ˣ����ٽ���
                             }
							 if (number2==0)         {Score[x][y]+=1;}  //1������
							 else if(number2==1)     {Score[x][y]+=2;}  //2������    
							 else if(number2==2)       //3������
							 {
								  if(empty==1)       {Score[x][y]+=8;}   //��3
								  else if(empty==2)  {Score[x][y]+=30;}  //��3 
							 }
							 else if(number2==3)       //4������
							 {
								  if(empty==1)       {Score[x][y]+=50;}    //��4
								  else if(empty==2)  {Score[x][y]+=200;}   //��4
						     }
							 else if(number2>=4)     {Score[x][y]+=10000;}  //�Լ�����������γ�5����Ҳ����ʤ���ˣ��������
							 number1=0;         
						     number2=0;          //���㣬�Ա��´�����ͳ��
                             empty=0;
					     }
				     }
                 }
             }
		 }
     } 
}