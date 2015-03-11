#ifndef WORKER_H_
#define WORKER_H_
#include <string>

class Worker  // an abstract base class
{
private:
	std::string fullname;
	long id;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Worker() : fullname("no one"), id(0L) {}
	Worker(const std::string & s, long n) : fullname(s), id(n) {}
	virtual ~Worker() = 0;  // ���麯��, ��������಻��ʵ��������
	virtual void Set();
	virtual void Show() const = 0;
};
     // ȥ��virtual error C2385: �ԡ�Worker���ķ��ʲ���ȷ  ��ΪSinger��ʾ����virtual, ��������û�б�ʾ
class Waiter : virtual public Worker  // ����WorkerΪ�����, �����ʹ�ôӶ����(���ǵĻ�����ͬ)�������Ķ���ֻ�̳�һ���������
{
private:
	int panache;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Waiter() : Worker(), panache(0) {}        
	Waiter(const std::string & s, long n, int p = 0) : Worker(s, n), panache(p) {}  
	Waiter(const Worker & wk, int p = 0) : Worker(wk), panache(p) {}
	void Set();
	void Show() const;
};

class Singer : virtual public Worker
{
protected:
	enum {other, alto, contralto, soprano, bass, baritone, tenor};
	enum {Vtypes = 7};
	virtual void Data() const;
	virtual void Get();
private:
	static char * pv[Vtypes];
	int voice;
public:
	Singer() : Worker(), voice(other) {}
	Singer(const std::string & s, long n, int v = other) : Worker(s, n), voice(v) {}
	Singer(const Worker & wk, int v = other) : Worker(wk), voice(v) {}
	void Set();
	void Show() const;
};

class SingingWaiter : public Singer, public Waiter
{
protected:
	void Data() const;
	void Get();
public:
	SingingWaiter(){}
	SingingWaiter(const std::string & s, long n, int p = 0, int v = other ) : Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {} 
	SingingWaiter(const Worker & wk, int p = 0, int v = other) : Worker(wk), Waiter(wk, p), Singer(wk, v) {}
	SingingWaiter(const Waiter & wt, int v = other) : Worker(wt), Waiter(wt), Singer(wt, v) {}
	SingingWaiter(const Worker & wt, int p = 0) : Worker(wt), Waiter(wt, p), Singer() {}  // ��Singer(wk)д����Singer()��ȫû����
	// c++�ڻ��������ʱ, ��ֹ��Ϣͨ���м����Զ����ݸ�����, ����Waiter(wk, p)�е�wkֻ��������ȷʹ��Waiter�ĸ����캯��������, ����wk�ǲ��ܴ���ȥ��
	// ��������˻���Ļ���Ĺ��캯��, �ڷ�������ǷǷ���, �������ǺϷ���, �����дWorker(wk)�������Ĭ�ϵ�
	void Set();
	void Show() const;
};

#endif