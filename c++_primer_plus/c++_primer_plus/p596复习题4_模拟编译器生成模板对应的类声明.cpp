// ģ�����������Stack<Worker *>sw��������
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

class Stack<Worker *>
{
private:
	enum{MAX = 10};
	Worker * items[MAX];
	int top;
public:
	Stack();
	bool isempty() {return top == 0;}
	bool isfull();
	bool push(const Worker & item);
	bool pop(Worker & item);
};