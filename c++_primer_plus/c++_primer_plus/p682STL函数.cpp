#include <iostream>
#include <string>
#include <vector>
#include <algorithm>  // sort(), find()

struct Review
{
	std::string title;
	int rating;
};

bool operator<(const Review & r1, const Review & r2);
bool worseThan(const Review & r1, const Review & r2);
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main(void)
{
	using namespace std;

	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "Thank you. You entered the following "
			<< books.size() << " ratings:\n"
			<< "Rating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);

		sort(books.begin(), books.end());  // Ĭ��ʹ�õ���<, ����С�����˳������
		cout << "Sorted by title: \nRating\tBook\n";
		for (Review x: books)  // ���ڷ�Χ��forѭ����Ϊ����STL����Ƶ�
			ShowReview(x);
		// ��ͬ��for_each(), ���ڷ�Χ��forѭ�������޸�����������, �������ƶ�һ�����ò���
		//for (Review & x: books) 
		//{
			//x.rating = 0; 
			//ShowReview(x);
		//}
		// ������������÷��Ž����for�е���ʱ����x���и�ֵ


		sort(books.begin(), books.end(), worseThan);
		cout << "Sorted by rating:\nRating\tBook\n";
		for (auto x: books) ShowReview(x);  // ��Ȼ, ʹ��auto������

		random_shuffle(books.begin(), books.end());
		cout << "After shuffling:\nRating\tBook\n";
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
		cout << "No entries.";
	cout << "Bye.\n";

	return 0;
}

// �������Ԫ�����û�����Ķ���, ��Ҫʹ��sort(), ���붨���ܹ������������operator<()����
// ����Review��һ���ṹ, ������Ա�ǹ��е�, �����ķǳ�Ա������Ϊ:
bool operator<(const Review & r1, const Review & r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool worseThan(const Review & r1, const Review & r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}

bool FillReview(Review & rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;
	while (std::cin.get() != '\n');
	return true;
}

void ShowReview(const Review & rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}