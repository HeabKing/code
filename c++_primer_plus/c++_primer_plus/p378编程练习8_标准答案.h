// �����ϰ 10.10 (8) ��׼��
#ifndef SIMPLEST_
#define SIMPLEST_

// program-special declarations
const int TSIZE = 45;  // size of array to hold(����) title
struct film
{
	char title[TSIZE];
	int rating;
};

// general(һ��, ����) type definitiongs ( �������Ͷ��� )
typedef struct film Item;

const int MAXLIST = 10;
class Simplist
{
private:
	Item items[MAXLIST];
	int count;
public:
	Simplist(void);
	bool isempty(void);
	bool isfull(void);
	int itemcount();
	bool additem(Item item);
	void transverse(void (pfun)(Item item));
};

#endif