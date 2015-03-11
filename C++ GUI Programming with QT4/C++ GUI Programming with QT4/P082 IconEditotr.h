// ͼ��༭��
#ifndef ICONEDITOR_H
#define ICONEDITOR_H

#include <QColor>
#include <QImage>
#include <QWidget>

class IconEdit : public QWidget
{
	Q_OBJECT;
	Q_PROPERTY(QColor penColor READ penColor WRITE setPenColor)
	Q_PROPERTY(QImage iconImage READ iconImage WRITE setIconImage)
	Q_PROPERTY(int zoomFactor READ zoomFactor WRITE setZoomFactor)
		// ʹ��Q_PROPERTY(property ���� ����)()�������������Զ�������: penColor, iconImage��zoomFactor
		// ÿ�����Զ���һ����������, һ��"��"������һ����Ϊ��ѡ���"д"����(penColor ��������: QColor ����ʹ��penColor()��setPenColor()�������ж�д)
		// ��Qt���ʦ��ʹ��������ڲ�����ʱ��, Qt���ʦ�����Ա༭����, ��Щ�̳���QWidget����������, ������ʾ��Щ�Զ�������, ��Щ���Կ�������QVariant��֧�ֵ��κ�����
public:
	IconEdit(QWidget * parent = nullptr);

	inline void		setPenColor(const QColor & newColor);
	inline QColor	penColor() const { return curColor; }
	inline void		setZoomFactor(int newZoom);
	inline int		zoomFactor() const { return zoom; }
	inline void		setIconImage(const QImage & newImage);
	inline QImage	iconImage() const { return image; }
	inline QSize	sizeHint() const;

protected:	// ����ʵ��QWidget�е�������������
	inline void		mousePressEvent(QMouseEvent * event);
	inline void		mouseMoveEvent(QMouseEvent * event);
	inline void		paintEvent(QPaintEvent * event);

private:	// ӵ�����Լ���˽�к�����˽�б���
	inline void		setImagePixel(const QPoint & pos, bool opaque);
	inline QRect	pixelRect(int i, int j) const;

	QColor	curColor;
	QImage	image;
	int		zoom;
};

IconEdit::IconEdit(QWidget * parent) : QWidget(parent)
{
	setAttribute(Qt::WA_StaticContents);	// ����Qt, �����¸ı䴰�ڲ����Ĵ�Сʱ, ���ڲ���������û�з����仯, �������������Ծɱ��ִӴ��ڲ������Ͻǿ�ʼ������, �������������¶��崰�ڲ�����С��ʱ��Qt���Ѿ���ʾ������������»���
		// ͨ��, ���¶���һ�����ڲ����Ĵ�Сʱ, Qt��Ϊ���ڲ����������ɼ�������һ�������¼�, ����ڴ��ڲ���������ʱ��ʹ����Qt::WA_StaticContents����, ��ô�����¼�������ᱻ�ϸ��޶���֮ǰû�б���ʾ�����ز�����

	setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);	// ���߲���ϵͳ�Ƿ���Զ����������������
		// ������߲��ֹ�����, ���ڲ����Ĵ�С��ʾ(sizeHint())����������С�ߴ��С
		// ����, ���ֹ���ϵͳ��������������ڲ���, ���Ǿ�������������̵������Ĵ�С��ʾ��ҪС�ĳߴ�

	curColor = Qt::black;	// ������ɫ����Ϊ��ɫ
	zoom = 8;				// ������������Ϊ8 (ͼ���е�ÿһ�����ض�����ʾ��һ��8 x 8��������)
	image = QImage(16, 16, QImage::Format_ARGB32);	// ����: QImage ��ʼ��: 16 x 16�����ش�С��32λ��ARGB��ɫ��ʽ, ���ָ�ʽ֧�ְ�͸��Ч�� ͨ�����һ��͸������ɫ�Ϳ������Images�е�����
		// QImage��ʹ��һ����Ӳ���޹صķ�ʽ���洢ͼ��, ���԰������ó�1λ, 8λ����32λɫ��, 32λ: �ֱ��ð�λ�洢����������, ʣ���λ�洢������ص�alpha����(����͸����, Խ��Խ��͸��) ����ɫ: QRgb red = 0xFFFF0000; ֻ���ڴ���QImageʱ��ʹ��QRgb, ���������ʾ��ɫ�Ķ���QColor
		// ͼ�����ݻᱣ����image��Ա������, ���ҿ���ͨ��setIconImage()��iconImage()���������ǽ��з���  ���û���һ��ͼ���ļ�ʱ, ͼ��༭������ͨ���õ���setIconImage()����; ���û��������ͼ��ʱ, �����iconImage()�����µõ����ͼ��
	image.fill(qRgba(0, 0, 0, 0));
}

QSize IconEdit::sizeHint() const
{
	QSize size = zoom * image.size();
	if (zoom >= 3)	// �������������3���߸���, ��ô��ÿ����������Ҫ��������һ������, �Ա��������һ��������, �������������2����1, �Ͳ�������ʾ������, ��Ϊ��Щ�����߼��������ٸ�ͼ������������κοռ�
		size += QSize(1, 1);
	return size;
}

void IconEdit::setPenColor(const QColor & newColor)
{
	curColor = newColor;
}

void IconEdit::setIconImage(const QImage & newImage)	// ������Ҫ�༭��ͼ��
{
	if (newImage != image)	// ������ͼ�����������ڱ༭��ͼ��, ���� # 1
	{
		image = newImage.convertToFormat(QImage::Format_ARGB32);	// # 1 ��������������һ����alpha�����32λͼ��, �����������н������ͼ������ʱ�洢��32λ��ARGBֵ�е�
		update();	// ʹ���ĵ�ͼ��ǿ���ػ�������ڲ���
		updateGeometry();	// ���߰���������ڲ����Ĳ��ֹ�����, ������ڲ����Ĵ�С��ʾ�Ѿ������˸ı�, ����, �ò��ֽ����Զ���Ӧ����µĴ�С��ʾ
	}
}

void IconEdit::setZoomFactor(int newZoom)
{
	if (newZoom < 1)	// �����������ط���0��, Ӧ�����κ�С��1��ֵ
		newZoom = 1;
	if (newZoom != zoom)
	{
		zoom = newZoom;
		update();
		updateGeometry();
	}
}
#include <QPainter>
#include <QtGui>
void IconEdit::paintEvent(QPaintEvent * e)
{
	QPainter painter(this);
	if (zoom >= 3)	// �������������3���߱�3��Ҫ��, ʹ��QPainter::drawLine()�������ƹ��������ˮƽ�߶κʹ�ֱ�߶�
	{
		painter.setPen(palette().foreground().color());	// fore ǰ�� foreground ǰ�� ��������λ��
			// ʹ�õ�ɫ��(palette)ָ�����ʵ���ɫ
			// ÿ�����ڲ������䱸һ����ɫ��, ������ȷ����ʲô��Ӧ��ʹ��ʲô��ɫ, Ĭ�������, һ�����ڲ����ĵ�ɫ����ô���ϵͳ����ɫ����
			// һ�����ڲ����ĵ�ɫ����������ɫ���: ������(Active), �Ǽ�����(Inactive), ��������(Disabled)

		for (int i = 0; i <= image.width(); ++i)
			painter.drawLine(zoom * i, 0, zoom * i, zoom * image.height());	// drawLine(x1, y1, x2, y2)	// (x1, y1)���߶�һ���˵�λ��, (x2, y2)���߶���һ���˵�λ��
		for (int j = 0; j <= image.height(); ++j)
			painter.drawLine(0, zoom * j, zoom * image.width(), zoom * j);
	}
	for (int i = 0; i < image.width(); i++)
	{
		for (int j = 0; j < image.height(); j++)
		{
			QRect rect = pixelRect(i, j);
			if (!e->region().intersected(rect).isEmpty())
			{
				QColor color = QColor::fromRgba(image.pixel(i, j));	// IconEdit::pixelRect()����һ��QRect, ��������Ҫ���»��Ƶ�����
				if (color.alpha() < 255)
					painter.fillRect(rect, Qt::white);
				painter.fillRect(rect, color);	// �������ź������
			}
		}
	}
}

QRect IconEdit::pixelRect(int i, int j) const	// ����һ��������QPainter::fillRect()��QRect, �����i��j��QImage��������������Ǵ��ڲ����е�����, �������������1, ��ô����������ϵ��ǡ��һ����
{
	if (zoom >= 3)
		return QRect(zoom * i, zoom * j + 1, zoom - 1, zoom - 1);
	else
		return QRect(zoom * i, zoom * j, zoom, zoom);
}

void IconEdit::mousePressEvent(QMouseEvent * e)	// �û�������갴ťʱ, ϵͳ�ͻ����һ��"��갴��"�¼�, ����ʵ��QWidget::mousePressEvent()�Ϳ�����Ӧ����¼�
{
	if (e->button() == Qt::LeftButton)	// ��������µ����ؽ�������
		setImagePixel(e->pos(), true);	// ������������óɵ�ǰ���ʵ���ɫ
	else if (e->button() == Qt::RightButton)	// ��������µ����ؽ������
		setImagePixel(e->pos(), false);			// ����false������������
}

void IconEdit::mouseMoveEvent(QMouseEvent * e)	// ����"����ƶ�"�¼�(Ĭ�����û���סһ�������ŵ�ʱ����ܲ���, ͨ��QWidget::setMouseTracking()���Ըı���һ��Ϊ)
{
	if (e->buttons() & Qt::LeftButton)	// ���ͬʱ��������������ֻ���������
		setImagePixel(e->pos(), true);
	else if (e->buttons() & Qt::RightButton)
		setImagePixel(e->pos(), false);
}

void IconEdit::setImagePixel(const QPoint & pos, bool opaque)	// opaque ��͸����	���������mousePressEvent()��mouseMoveEvent()�еõ�����, pos������ڴ��ڲ����е�λ��
{
	int i = pos.x() / zoom;
	int j = pos.y() / zoom;
		// ������λ�ôӴ��ڲ���������ת����ͼ�������

	if (image.rect().contains(i, j))	// ���õ��Ƿ�λ����ȷ��Χ֮��
	{
		if (opaque)
			image.setPixel(i, j, penColor().rgba());
		else
			image.setPixel(i, j, qRgba(0, 0, 0, 0));	// ���һ��������ʵ�Ͼ��ǰ������͸����
		update(pixelRect(i, j));	// ���»��Ʋ�������
	}
}

#endif