// �����嵥 13.3  �����嵥 13.6
#include <iostream>
#include "p481��ļ̳�_ͷ�ļ�.h"

int main(void)
{
	// =============== 13.3 ================
	//using std::cout;  // �����cout������Name()��������һ����ɫ, �ѵ������cout������һ����̬�ĳ�Ա����? ���� ��һ��ȫ�ֱ���, Ϊʲô?????  ��Ϊ����һ������!
	//using std::output_iterator_tag;
	//TableTennisPlayer player1("Chuck", "Blizzard", true);
	//TableTennisPlayer player2("Tara", "Boomdea", false);
	//
	//player1.Name();
	//if (player1.HasTable())
	//	cout << ": has a table.\n";
	//else
	//	cout << ": hasn't a table.\n";

	//player2.Name();
	//if (player2.HasTable())
	//	cout << ": has a table.\n";
	//else
	//	cout << ": hasn't a table.\n";
	// ==========================================
	// ============== 13.4 ======================
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	
	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";

	player1.Name();
	if (player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";

	cout << "Name: ";
	rplayer1.Name();
	cout << "; " << rplayer1.Rating() << endl;
	
	RatedPlayer rplayer2(1212, player1);
	cout << "Name: ";
	rplayer2.Name();
	cout << "; " << rplayer2.Rating() << endl;
	// ==========================================
	return 0;
}