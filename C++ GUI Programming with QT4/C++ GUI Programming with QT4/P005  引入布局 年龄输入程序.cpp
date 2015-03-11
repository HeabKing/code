#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
int main(int argc, char * argv[])
{
	QApplication App(argc, argv);
	
	// QWidget������
	QWidget * window = new QWidget;
	window->setWindowTitle("Enter Your Age");

	// ���鲿��
	QSlider * slider = new QSlider(Qt::Horizontal);	// ����ϵͳ����ȷ�Ľ�����������Ϊ�丸����
	slider->setRange(0, 130);

	// ΢����
	QSpinBox * spinBox = new QSpinBox;
	spinBox->setRange(0, 130);

	// ��������
	QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
	QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
	spinBox->setValue(35);

	// ���ֿ���
	QHBoxLayout * layout = new QHBoxLayout;
	layout->addWidget(spinBox);
	layout->addWidget(slider);

	window->setLayout(layout);	// �������ڰ��ϲ��ֹ�����, ���ֹ������еĲ����Զ���������Ϊ������
	window->show();

	return App.exec();
}