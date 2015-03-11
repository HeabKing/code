// �����ϰ 10.10 (8) �ͻ��ļ�
#include <iostream>
#include <cstdlib>  // for exit()
#include "p378�����ϰ8_��׼��.h"

void showmovies(Item item);  // to be used by transverse()

int main(void)
{
	using namespace std;
	Simplist movies;  // create an empty list
	Item temp;

	if (movies.isfull())  // invokes(����) isfull() member function
	{
		cout << "No more room in list!Bye!\n";
		exit(1);
	}

	cout << "Enter first movie title:\n";
	while (cin.getline(temp.title, TSIZE) && temp.title[0] != '\0')  // ??? ���������TSIZE�ı������ô�� ???
	{
		cout << "Enter your rating <0-10>: ";
		cin >> temp.rating;
		while (cin.get() != '\n')
			continue;
		if (movies.additem(temp) == false)
		{
			cout << "List already is full!\n";
			break;
		}
		if (movies.isfull())
		{
			cout << "You have filled the list.\n";
			break;
		}
		cout << "Enter next movie title (empty line to stop):\n";
	}
	if (movies.isempty())
		cout << "No data entered. \n";
	else
	{
		cout << "Here is the movie list:\n";
		movies.transverse(showmovies);
	}
	cout << "Bye!\n";
}

void showmovies(Item item)
{
	std::cout << "Movie: " << item.title << "  Rating: "
		<< item.rating << std::endl;
}