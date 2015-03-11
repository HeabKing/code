// �����嵥 11.16 ͷ�ļ�
#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
	enum {LBS_per_stn = 14};  // pounds per stone
	int stone;  // whole stones
	double pds_left;  // fractional(���ֵ�, ������, С����) pounds
	double pounds;
public:
	Stonewt(double lbs);  // constructor for double pounds
	Stonewt(int stn, double lbs);  // constructor for stone, lbs
	Stonewt();  // default constructor
	void show_lbs() const;  // show weight in pounds(��) format
	void show_stn() const;  // show weight in stone(Ӣʯ) format

// conversion functions
	operator int() const;  // ��Ȼû��������������, ����������Ҳ�����������ֵ
		// �����int���Ὣ��ת����ֵ��������Ϊ��ӽ�������, ������ȥ��С������
	operator double() const;

// ��ϰ�� 11.8 (1)
	Stonewt operator * (double) const;
// ��ϰ�� 11.8 (4)
	friend Stonewt operator * (double d, Stonewt & s)
	{
		return Stonewt(d * s.pounds);
	}
};
#endif