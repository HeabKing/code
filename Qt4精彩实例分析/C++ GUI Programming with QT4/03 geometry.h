// ����: 2014-08-26 14:48:21
// ������λ����صĺ�����������ʹ�ó��� 
/*
	(1)	����������Ϊ����(����������, �߿�...)
		x(), y(), pos(), frameGeometry()
	(2)	�Զ��㲿��Ϊ����
		geometry(), rect(), height(), width(), size()
*/
#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDialog>
#include <QLabel>
#include <QLayout>

class Geometry: public QDialog
{
	Q_OBJECT
public:
	inline Geometry();

	QGridLayout * Layout;
	QLabel * xLabel;
	QLabel * yLabel;
	QLabel * frameGeoLabel;
	QLabel * posLabel;
	QLabel * geoLabel;
	QLabel * widthLabel;
	QLabel * heightLabel;
	QLabel * rectLabel;
	QLabel * sizeLabel;

	inline void updateLabel();

protected:
	void moveEvent(QMoveEvent *)	{updateLabel();}	// �ض���Ի����ƶ��¼�
	void resizeEvent(QResizeEvent *){updateLabel();}	// �ض����С�����¼�
};

Geometry::Geometry()
{
	setWindowTitle("Geometry");
	Layout  = new QGridLayout(this);
	xLabel	= new QLabel("x()");
	yLabel	= new QLabel("y()");
	frameGeoLabel	= new QLabel();
	posLabel		= new QLabel();
	geoLabel		= new QLabel();
	widthLabel		= new QLabel();
	heightLabel		= new QLabel();
	rectLabel		= new QLabel();
	sizeLabel		= new QLabel();

	Layout->addWidget(new QLabel("x(): "), 0, 0);
	Layout->addWidget(xLabel, 0, 1);
	Layout->addWidget(new QLabel("y(): "), 1, 0);
	Layout->addWidget(yLabel, 1, 1);
	Layout->addWidget(new QLabel("frameGeometry(): "), 2, 0);
	Layout->addWidget(frameGeoLabel, 2, 1);
	Layout->addWidget(new QLabel("pos(): "), 3, 0);
	Layout->addWidget(posLabel, 3, 1);
	Layout->addWidget(new QLabel("geometry(): "), 4, 0);
	Layout->addItem(new QSpacerItem(50/*width*/, 50/*height*/, QSizePolicy::Minimum, QSizePolicy::Expanding), 4, 1);				// ��GridLayout�м�����չ��
	Layout->addWidget(geoLabel, 4, 1);
	Layout->addWidget(new QLabel("width(): "), 5, 0);
	Layout->addWidget(widthLabel, 5, 1);
	Layout->addWidget(new QLabel("height(): "), 6, 0);
	Layout->addWidget(heightLabel, 6, 1);
	Layout->addWidget(new QLabel("rect(): "), 7, 0);
	Layout->addWidget(rectLabel, 7, 1);
	Layout->addWidget(new QLabel("size(): "), 8, 0);
	Layout->addWidget(sizeLabel, 8, 1);

	updateLabel();
}

void Geometry::updateLabel()
{	
	// x()
	xLabel->setText(QString::number(x()));

	// y()
	yLabel->setText(QString::number(y()));

	// frameGeometry()
	QString frameGeo;
	QRect r = frameGeometry();
	frameGeo =	QString::number(frameGeometry().x()) + ", " +
				QString::number(frameGeometry().y()) + ", " +
				QString::number(frameGeometry().width()) + ", " +
				QString::number(frameGeometry().height());
	frameGeoLabel->setText(frameGeo);

	// pos()
	QString position;
	position = QString::number(pos().x()) + ", " + QString::number(pos().y());
	posLabel->setText(position);

	// geometry()
	QString geo;
	geo =	QString::number(geometry().x()) + ", " +
			QString::number(geometry().y()) + ", " +
			QString::number(geometry().width()) + ", " +
			QString::number(geometry().height());
	geoLabel->setText(geo);

	// width(), height()
	widthLabel->setText(QString::number(width()));
	heightLabel->setText(QString::number(height()));

	// rect()
	rectLabel->setText(	QString::number(rect().x()) + ", " +
						QString::number(rect().y()) + ", " +
						QString::number(rect().width()) + ", " +
						QString::number(rect().height()));

	// size()
	sizeLabel->setText(QString::number(size().width()) + ", " + QString::number(size().height()));
}

#endif