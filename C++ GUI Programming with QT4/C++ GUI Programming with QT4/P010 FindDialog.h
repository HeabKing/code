// ���������ͷ�ļ��м򵥵����һ��<QtGui>����������, ������ʡȥ�˰���<QDialog>��ʹ��ǰ���������鷳, ����, ��һ��ͷ�ļ����ٰ���һ����ô���ͷ�ļ���ʵ����һ�ֺõı�̷��, ������ڱȽϴ�Ĺ�����Ŀ�������
#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>	// ������QDialog������

// ǰ������һЩ��������Ի���ʵ���е�Qt��(ǰ�����������C++���������Ĵ���, �������ṩ�������ľ���ϸ��(ͨ���������Լ���ͷ�ļ���))
class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

// ����FindDialog, ��������ΪQDialog������
class FindDialog : public QDialog
{
	Q_OBJECT;	// �������ж������źźͲ۵���, ����Ŀ�ʼ����Q_OBJECT�궼�Ǳ����;
				// �����������������Q_OBJECT��, �����qmake���ɵ�makefile���Զ�����һЩ����moc�Ĺ���, moc��Qt��Ԫ���������
				// Ϊ��ʹmoc�ܹ���������, �������������ʵ���ļ��з������, ���ŵ�ͷ�ļ���, ��moc���ɵĴ����������ͷ�ļ�, ���һ����һЩ�����C++����
public:
	FindDialog(QWidget * parent = nullptr);	// һ�����͵�Qt���ڲ������๹�캯������, Ĭ�ϸöԻ���û�и�����
signals:	// �����������˵��û�����Find��ťʱ�Ի���������������ź�;
			// singnalsʵ������һ����, C++Ԥ���������ڱ�������ҵ���֮ǰ����ת���ɱ�׼C++����
	void findNext	 (const QString & str, Qt::CaseSensitivity cs);	// Qt::CaseSensitivity��һ��ö������, ����Qt::CaseSensitive��Qt::CaseInsensitive����ȡֵ
	void findPrevious(const QString & str, Qt::CaseSensitivity cs);
private slots:	// ����������
				// slots��һ����, Ҳ������չ��C++���������Դ����һ�ֽṹ��ʽ
	void findClicked();
	void enableFindButton(const QString & text);	// ���ﴫ��text��Ϊ���жϴ�ʱLineEdit�е��ı��ǿյĻ��Ƿǿյ�����������Find��ť�Ƿ����
private:	// ����ʹ��ǰ�����������ǿ��е�, ��Ϊ���Ƕ���ָ��, ����û�б�Ҫ��ͷ�ļ��о�ȥ��������, �����������������Щ�����������, ����Ҳ���ð����⼸��������ͷ�ļ�(��<QCheckBox>, <QLabel>�ȵ�), ����ʹ����һЩǰ������, �����ʹ�ñ�����̸���Щ
	QLabel		* label;
	QLineEdit	* lineEdit;
	QCheckBox	* caseCheckBox;
	QCheckBox	* backwardCheckBox;
	QPushButton	* findButton;
	QPushButton * closeButton;
};

#endif