#include <ctime>
#define CLOCKSTART	clock_t start =	clock()
#define CLOCKINI	start = 0
#define SHOWTIME	std::cout << "����ʱ��: " << clock() - start << " ����" << endl