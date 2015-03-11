#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>	// ���鲿��
#include <QSpinBox>	// ΢���򲿼�
int main(int argc, char * argv[])
{
	QApplication app(argc, argv);

	// ����QWidget����, ��������ΪӦ�ó����������
	QWidget		* window	= new QWidget;
	window	->setWindowTitle("Enter Your Age");	// ������ʾ�ڴ��ڱ������ϵ�����
	
	// ����QSpinBox(����)��QSlider(΢����)���������ǵ���Ч��Χ
	QSpinBox	* spinBox	= new QSpinBox;	// ����Ӧ�ý������ڴ��ݸ����ǵĹ��캯��, ��˵�����������ڲ����ĸ��������������, ��������û�б�Ҫ, ��Ϊ����ϵͳ�������еó���һ������Զ��Ѹô�������Ϊ΢����ͻ���ĸ�����;
	QSlider		* slider	= new QSlider(Qt::Horizontal);
	spinBox	->setRange(0, 130);
	slider	->setRange(0, 130);

	// ȷ��΢����ͻ���ͬ��, �Ա���������������ʾ��ͬ����ֵ
	QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));	// һ��һ�����ڲ�����ֵ�����˸ı�, ��ô�ͻᷢ������valueChanged(int)�ź�, ��һ�����ڲ������������ֵ��������setValue(int)��
	QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
	spinBox	->setValue(35);	// ��΢�����ֵ����Ϊ35, �������������ʱ, QSpinBox�ͻᷢ��valueChanged(int)�ź�, ����, int������ֵ��35, ��������ᱻ���ݸ�QSlider��setValue(int)��, Ȼ����valueChanged(int)�ź�, �����ʹ�����΢�����setValue(int)��, ��������΢�����ֵ�Ѿ���35, ���ԾͲ������ź���, ��������������ѭ������� 

	// ���ֿ���
	QHBoxLayout * layout = new QHBoxLayout;	// �������ֹ�����(layout manager)	QHBoxLayout: ��ˮƽ���������д��ڲ���, ������
											//									QVBoxLayout: �ڴ�ֱ���������д��ڲ���, ���ϵ���
											//									QGridLayout: �Ѹ������ڲ���������һ��������
	layout	->addWidget(spinBox);	// QHboxLayout�ɸ�����������Ӷ������ҪΪ���Ƿ��������λ�úʹ�С
	layout	->addWidget(slider);

	window	->setLayout(layout);	// �ڴ����ϰ�װ���ֹ�����	������ĵײ�ʵ��������, QSpinBox��QSlider���Զ�"�ض��常����", ���ǻ��Զ���Ϊ�����װ�˲��ֵĴ��ڲ������Ӷ���, ���ǻ�������ԭ��, ������һ����Ҫ�Ž�ĳ�������еĴ��ڲ���ʱ, ��û�б�ҪΪ����ʾָ����������
	window	->show();

	return app.exec();
}