#ifndef PLOTTER_H
#define PLOTTER_H

#include <QMap>
#include <QPixmap>
#include <QVector>
#include <QWidget>

class QToolButton;
class PlotSettings;

class Plotter : public QWidget
{
	Q_OBJECT;
public:
	inline Plotter(QWidget * parent = nullptr);

	inline void setPlotSettings(const PlotSettings & settings);	// plot ͼ settings ����
	inline void setCurveData(int id, const QVector<QPointF> & data);	// curve ����
	inline void clearCurve(int id);
	inline QSize minimumSizeHint() const;	// ��д�麯��
	inline QSize sizeHint() const;			// ��д�麯��

public slots:
	inline void zoomIn();
	inline void zoomOut();

protected:	// ����������Ҫ����ʵ�ֵ�QWidget�¼�������
	inline void paintEvent(QPaintEvent * e);
	inline void resizeEvent(QResizeEvent * e);
	inline void mousePressEvent(QMouseEvent * e);
	inline void mouseMoveEvent(QMouseEvent * e);
	inline void mouseReleaseEvent(QMouseEvent * e);
	inline void keyPressEvent(QKeyEvent * e);
	inline void wheelEvent(QWheelEvent * e);

private:	// һЩ���ڻ���������ڲ����ĺ���, һ�������ͼ�����Ա����
	inline void updateRubberBandRegion();	// rubber band �𽺻�
	inline void refreshPixmap();	// refresh ����
	inline void drawGrid(QPainter * painter);
	inline void drawCurves(QPainter * painter);

	enum{ Margin = 50 };	// margin ��Ե	Ϊͼ���������Χ�ṩһЩ�ռ�

	QToolButton * zoomInButton;
	QToolButton * zoomOutButton;
	QMap<int, QVector<QPointF>> curveMap;
	QVector<PlotSettings> zoomStack;
	int curZoom;
	bool ruberBandIsShown;
	QRect rubberBandRect;
	QPixmap pixmap;	// ����������������ڲ����ö�������ݽ����˸��Ʊ���, �����Ļ����ʾ��ͼ������ͬ��. ��ͼ������������������ӳ���ϻ���ͼ��, Ȼ��Ű���һ����ӳ�临�Ƶ����ڲ�����
};

class PlotSettings	// ����x��y��ķ�Χ�Լ�����Щ���Ͽ̶ȱ�Ƿ�������
{
public:
	inline PlotSettings();

	inline void	scroll(int dx, int dy);
	inline void	adjust();
	double	spanX() const { return maxX - minX; }
	double	spanY() const { return maxY - minY; }

	double	minX;
	double	maxX;
	int		numXTicks;
	double	minY;
	double	maxY;
	int		numYTicks;

private:
	inline static void adjustAxis(double & min, double & max, int & numTicks);
};

#include <QToolButton>

Plotter::Plotter(QWidget * parent) : QWidget(parent)
{
	setBackgroundRole(QPalette::Dark);	// role ��ɫ ����	ʹ�õ�ɫ���е�"��"������Ϊ�ػ洰�ڲ�������ɫ, ������ʹ��"����ɫ"����
	setAutoFillBackground(true);	// �����ϱߵĻ���
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);	// Ĭ����QtSizePolicy::Preferred: ���ڲ�����С������ʾ��С, ����б�Ҫ, �������޷Ŵ�, Ҳ����һֱ��С����ʾ��������С��С
	setFocusPolicy(Qt::StrongFocus);	// ���û�ͨ���������߰���Tab�������뽹��
	ruberBandIsShown = false;
	zoomInButton = new QToolButton(this);
	zoomInButton->setIcon(QIcon("images/zoomIn.png"));
	zoomInButton->adjustSize();	// ���óɴ�С��ʾ�Ĵ�С
	connect(zoomInButton, SIGNAL(clicked()), this, SLOT(zoomIn()));

	zoomOutButton = new QToolButton(this);
	zoomOutButton->setIcon(QIcon("images/zoomOut.png"));
	zoomOutButton->adjustSize();
	connect(zoomOutButton, SIGNAL(clicked()), this, SLOT(zoomOut()));

	setPlotSettings(PlotSettings());
}

void Plotter::setPlotSettings(const PlotSettings & settings)	// ָ����ʾ��ͼ��ʱ�õ���PlotSettings
{
	zoomStack.clear();
	zoomStack.append(settings);	// append ���� ���� ���������ļ�������·��
	curZoom = 0;
	zoomInButton->hide();
	zoomOutButton->hide();
	refreshPixmap();	// ���ﲻʹ��update(), ��Ϊ��������QPixmap������ʱ�̶���������״̬, ��������������ӳ��֮��, refreshPixmap()�����update(), �������ӳ�临�Ƶ����ڲ�����
}
	// ��ʼʱʹ��Ĭ�����ż�, �û�ÿ�Ŵ�һ��, ���ᴴ��һ���µ�PlotSettingsʵ��, ���һὫ��������Ŷ�ջ��

void Plotter::zoomOut()	// zoom out ��С
{
	if (curZoom > 0)
	{
		--curZoom;
		zoomOutButton->setEnabled(curZoom > 0);
		zoomInButton->setEnabled(true);
		zoomInButton->show();
		refreshPixmap();
	}
}

void Plotter::zoomIn()
{
	if (curZoom < zoomStack.count() - 1)
	{
		++curZoom;
		zoomInButton->setEnabled(curZoom < zoomStack.count() - 1);
		zoomOutButton->setEnabled(true);
		zoomOutButton->show();
		refreshPixmap();
	}
}

void Plotter::setCurveData(int id, const QVector<QPointF> & data)
{
	curveMap[id] = data;
	refreshPixmap();
}

void Plotter::clearCurve(int id)	// �Ƴ�һ������������
{
	curveMap.remove(id);
	refreshPixmap();
}

QSize Plotter::minimumSizeHint() const	// ָ��������С��С ���ǲ��ֹ�������С��������ļ���
{
	return QSize(6 * Margin, 4 * Margin);
}

QSize Plotter::sizeHint() const
{
	return QSize(12 * Margin, 8 * Margin);
}

// Protected �е��¼�������
#include <QStylePainter>
#include <QStyleOptionFocusRect>
void Plotter::paintEvent(QPaintEvent * /*e*/)	// ͨ��paintEvent()ִ�����л�������, ��������ͼ�����Ļ���������֮ǰ��refreshPixmap()�������, ����ֻ��򵥵�ͨ���Ѹ�����ӳ�临�Ƶ����ڲ�����(0, 0)λ�ô������������ͼ�λ��ƹ���
{
	QStylePainter painter(this);
	painter.drawPixmap(0, 0, pixmap);

	if (ruberBandIsShown)
	{
		painter.setPen(palette().light().color());	// ѡ��ǰ��ɫ���е�"��"������Ϊ���ʵ���ɫ, �����û��Ƴ�����Ƥ��ѡ�����"��"���������γɺܺõķ���
		painter.drawRect(rubberBandRect.normalized());	// QRect::normalized()ȷ�����������Ƥ��ѡ���Ŀ�Ⱥ͸߶ȶ�����ֵ, ����adjusted()���԰Ѿ��εĴ�С��ȥһ������, ������������һ�����ؿ������
		if (hasFocus())	// ���Plotterӵ�н���
		{
			QStyleOptionFocusRect option;
			option.initFrom(this);	// ����ѡ����������ѡ��ĳ�ʼ�������Plotter���ڲ���[ͨ������initFrom()]
			option.backgroundColor = palette().dark().color();	// ��ȷ����������ɫ
			painter.drawPrimitive(QStyle::PE_FrameFocusRect, option);	// ���ƽ���ѡ���	// QStyle ���ڷ�� xp, mac, win7...
		}
	}
}

void Plotter::resizeEvent(QResizeEvent * /*e*/)	// ���캯����û��ָ����ť��λ��, ������Ϊ��һ�����ڲ�����һ����ʾ֮ǰ, Qt���ǻ��Զ�����һ��"�ض����С�¼�"
{
	int x = width() - (zoomInButton->width() + zoomOutButton->width() + 10);
	zoomInButton->move(x, 5);
	zoomOutButton->move(x + zoomInButton->width() + 5, 5);
	refreshPixmap();
}
#include <QMouseEvent>
void Plotter::mousePressEvent(QMouseEvent * e)
{
	QRect rect(Margin, Margin, width() - 2 * Margin, height() - 2 * Margin);
	if (e->button() == Qt::LeftButton)
	{
		if (rect.contains(e->pos()))	// �����굥��λ��λ��ͼ����
		{
			ruberBandIsShown = true;	// ����������, ����һ����Ƥ��ѡ���
			rubberBandRect.setTopLeft(e->pos());
			rubberBandRect.setBottomRight(e->pos());
				// QRect��С�Ķ��巽ʽ:
					// 1. (x, y, width, height)
					// 2. �������������������λ�� setTopLeft(), setBottomRight()

			updateRubberBandRegion();	// ����Ƥ��ѡ��������ǵ�(��С)�������ǿ���ػ�
			setCursor(Qt::CrossCursor);	// Cross ʮ��	// �������ĳ�ʮ���ι��
				// �����������״�Ŀ���:
					// 1. �����ͣ��ĳ�����ڲ�����, QWidget::setCursor()����������״, ���û������, ����游����, �������ڲ���Ĭ���Ǽ�ͷ
					// 2. ��������Ӧ�ó�������ʹ�õĹ����״, ����ͨ��QApplication::setOverrideCursor()��������, ����Ѳ�ͬ���ڲ����еĹ����״ȫ�����ǵ�ֱ������restoreOverrideCursor()
		}
	}
}

void Plotter::mouseMoveEvent(QMouseEvent * e)
{
	if (ruberBandIsShown)
	{
		updateRubberBandRegion();	// ԤԼһ�������¼�
		rubberBandRect.setBottomRight(e->pos());	// ���¼���rubberBandRect��˵������ƶ��ľ���
		updateRubberBandRegion();	// ��һ�ζԻ���������Ƥ��ѡ����Ѿ��ƶ���������������¼���
			// ������������Ч������Ƥ��ѡ���, ���ҿ������µ�����ϵ�����»�����
			// ����û����ϻ��������ƶ����, ���������½��ܵ������Ͻǵ��ϱ߻������, ����, QRect�ͻ����һ�����Ŀ�Ȼ��߸߶�, paintEvent()�е�QRect::normalized()�Ϳ��Զ����Ľǽ��е���, ��ȷ���ܹ���÷Ǹ��Ŀ��ֵ���߸߶�ֵ
	}
}

void Plotter::mouseReleaseEvent(QMouseEvent * e)
{
	if (e->button() == Qt::LeftButton && ruberBandIsShown)
	{
		ruberBandIsShown = false;
		updateRubberBandRegion();
		unsetCursor();

		QRect rect = rubberBandRect.normalized();
		if (rect.width() < 4 || rect.height() < 4)	// �����Ƥ��ѡ���С��4 x 4��ִ�����Ų���, ���С��, ����Ӧ�����û�����ĵ���˴��ڲ���, ���߽�����Ϊ���ô��ڲ�����ý���
			return;
		rect.translate(-Margin, -Margin);

		PlotSettings prevSettings = zoomStack[curZoom];
		PlotSettings settings;
		double dx = prevSettings.spanX() / (width() - 2 * Margin);
		double dy = prevSettings.spanY() / (height() - 2 * Margin);
		settings.minX = prevSettings.minX + dx * rect.left();
		settings.maxX = prevSettings.minX + dx * rect.right();
		settings.minY = prevSettings.maxY - dy * rect.bottom();
		settings.maxY = prevSettings.maxY - dy * rect.top();
		settings.adjust();
			// ����Ƥ��ѡ��������Ӵ��ڲ�������ϵת���ɻ�ͼ������ϵ


		zoomStack.resize(curZoom + 1);
		zoomStack.append(settings);
		zoomIn();
			// ������ͼ������ϵ���ҷŴ���Ƥ��ѡ���
	}
}

void Plotter::keyPressEvent(QKeyEvent * e)
{
	switch (e->key())
	{
	case Qt::Key_Plus:
		zoomIn();
		break;
	case Qt::Key_Minus:
		zoomOut();
		break;
	case Qt::Key_Left:
		zoomStack[curZoom].scroll(-1, 0);
		refreshPixmap();
		break;
	case Qt::Key_Right:
		zoomStack[curZoom].scroll(+1, 0);
		refreshPixmap();
		break;
	case Qt::Key_Down:
		zoomStack[curZoom].scroll(0, -1);
		refreshPixmap();
		break;
	case Qt::Key_Up:
		zoomStack[curZoom].scroll(0, +1);
		refreshPixmap();
		break;
	default:
		QWidget::keyPressEvent(e);
	}
}

void Plotter::wheelEvent(QWheelEvent * e)
{
	int numDegrees = e->delta() / 8;	// dalta()����һ������, �����ڹ�����ת�Ƕȵİ˱�
	int numTicks = numDegrees / 15;		// ���ͨ������15����Ϊ����

	if (e->orientation() == Qt::Horizontal)		// �ټ���ˮƽ����
		zoomStack[curZoom].scroll(numTicks, 0);	// ͨ���޸����Ŷ�ջ����˵�Ԫ�����ı�����ı�Ƿ�����
	else										// �����Ĵ�ֱ����
		zoomStack[curZoom].scroll(0, numTicks);	
	refreshPixmap();
}

// private
void Plotter::updateRubberBandRegion()
{
	QRect rect = rubberBandRect.normalized();
	update(rect.left(), rect.top(), rect.width(), 1);
	update(rect.left(), rect.top(), 1, rect.height());
	update(rect.left(), rect.bottom(), rect.width(), 1);
	update(rect.right(), rect.top(), 1, rect.height());
}

void Plotter::refreshPixmap()	// �ѻ�ͼ�����»��Ƶ���������ӳ������, ���Ҷ���ʾ���Ը���
{
	pixmap = QPixmap(size());	// ����ӳ���С����Ϊ���ڲ�����С
	pixmap.fill(this, 0, 0);	// ʹ�ô��ڲ����Ĳ�����ɫ����������ӳ��, �����ɫ���ǵ�ɫ���е�"��"����, �������ɫ��һ����ʵ�ĵĻ���, QPixmap::fill()����Ҫ֪�����ڲ����е�ƫ����, ����ӳ����Ҫ������ǡ���뻭��ͼ������� (0, 0)����ӳ�����������ڲ������Ӧ

	QPainter painter(&pixmap);	// ����һ��QPainter���������ӳ���Ͻ��л���
	painter.initFrom(this);		// ����painter��ʹ�õĻ���, ����ɫ, ������Plotter���ڲ����е�һ��
	// ִ�л���
	drawGrid(&painter);	
	drawCurves(&painter);
	update();	// ԤԼ�����¼�, painteEvent()������ӳ�临�Ƶ����ڲ�����
}

void Plotter::drawGrid(QPainter * painter)	// �������ߺ��������ߵ�����
{
	QRect rect(Margin, Margin, width() - 2 * Margin, height() - 2 * Margin);
	if (!rect.isValid())	// ���������������ͨ��rect������, ������ڲ���������, �����������ͼ��, ����������
		return;
	PlotSettings settings = zoomStack[curZoom];
	QPen quiteDark = palette().dark().color().light();
	QPen light = palette().light().color();

	for (int i = 0; i <= settings.numXTicks; i++)	// ��������Ĵ�ֱ�ߺ���x�᷽���ϵı�Ƿ�
	{
		int x = rect.left() + (i * (rect.width() - 1) / settings.numXTicks);
		double label = settings.minX + (i * settings.spanX() / settings.numXTicks);
		painter->setPen(quiteDark);
		painter->drawLine(x, rect.top(), x, rect.bottom());
		painter->setPen(light);
		painter->drawLine(x, rect.bottom(), x, rect.bottom() + 5);
		painter->drawText(x - 50, rect.bottom() + 5, 100, 20, Qt::AlignHCenter
			| Qt::AlignTop, QString::number(label));
	}
	for (int j = 0; j <= settings.numYTicks; j++)	// ���������ˮƽ�ߺ���y�᷽���ϵı�Ƿ�
	{
		int y = rect.bottom() - (j * (rect.height() - 1) / settings.numYTicks);
		double label = settings.minY + (j * settings.spanY() / settings.numYTicks);
		painter->setPen(quiteDark);
		painter->drawLine(rect.left(), y, rect.right(), y);
		painter->setPen(light);
		painter->drawLine(rect.left() - 5, y, rect.left(), y);
		painter->drawText(rect.left() - Margin, y - 10, Margin - 5, 20, 
			Qt::AlignRight | Qt::AlignVCenter, QString::number(label));	// ������������������Ǻ����Ӧ����Щ����
			// drawText(x, y, width, height, alignment, text) �ȶ���һ������, Ȼ��ָ���������ı���λ��, text����Ҫ���Ƶ��ı�
	}
	painter->drawRect(rect.adjusted(0, 0, -1, -1));	// �ؿհ��������һ������
}

void Plotter::drawCurves(QPainter * painter)	// �������ϻ�������
{
	static const QColor colorForIds[6] = {
		Qt::red, Qt::green, Qt::blue, Qt::cyan, Qt::magenta, Qt::yellow
	};
	PlotSettings settings = zoomStack[curZoom];
	QRect rect(Margin, Margin, width() - 2 * Margin, height() - 2 * Margin);
	if (!rect.isValid())
		return;
	painter->setClipRect(rect.adjusted(+1, +1, -1, -1));	// ��Ϊ������Щ����(�߰׺װ�Χ��ͼ���Ŀ�ܳ���)�ľ�������QPainter������, Ȼ��QPainter����������������֮������ػ��Ʋ���
	QMapIterator<int, QVector<QPointF>> i(curveMap);	// ʹ��java��ʽ�ĵ�����������������, ���Ҷ���ÿһ�����߶�Ҫ������������ÿһ��QPointFֵ
	while (i.hasNext())
	{
		i.next();
		int id = i.key();	// ���õ�������key()������ȡ���ߵ�ID
		QVector<QPointF> data = i.value();	// �õ�������value()������ȡ��Ӧ���ߵ�QVector<QPointF>��������
		QPolygonF polyline(data.count());
		for (int j = 0; j < data.count(); j++)	// forѭ����ÿ��QPointF���ӻ�ͼ������ϵת�������ڲ�������ϵ, ���Ұ����Ǳ��浽polyline������
		{
			double dx = data[j].x() - settings.minX;
			double dy = data[j].y() - settings.minY;
			double x  = rect.left() + (dx * (rect.width() - 1) / settings.spanX());
			double y  = rect.bottom() - (dy * (rect.height() - 1) / settings.spanY());
			polyline[j] = QPointF(x, y);
		}
			// ��һ�����ߵ�ȫ���������ת���ɴ��ڲ����е�����

		painter->setPen(colorForIds[uint(id) % 6]);	// Ϊ�����������ߵĻ���������ɫ(ʹ��Ԥ�������ɫ��֮һ)
		painter->drawPolyline(polyline);	// ����drawPolyline()����һ�����������������е��ֱ��
	}
}

PlotSettings::PlotSettings()
{
	minX = 0.0;
	maxX = 10.0;
	numXTicks = 5;

	minY = 0.0;
	maxY = 10.0;
	numYTicks = 5;
}

void PlotSettings::scroll(int dx, int dy)
{
	double stepX = spanX() / numXTicks;
	minX += dx * stepX;
	maxX += dx * stepX;

	double stepY = spanY() / numYTicks;
	minY += dy * stepY;
	maxY += dy * stepY;
}

void PlotSettings::adjust()
{
	adjustAxis(minX, maxX, numXTicks);	// Axis ��
	adjustAxis(minY, maxY, numYTicks);
}

void PlotSettings::adjustAxis(double & min, double & max, int & numTicks)
{
	const int MinTicks = 4;
	double grossStep = (max - min) / MinTicks;
	double step = std::pow(10.0, std::floor(std::log10(grossStep)));

	if (5 * step < grossStep)
		step *= 5;
	else if (2 * step < grossStep)
		step *= 2;
	
	numTicks = int(std::ceil(max / step) - std::floor(min / step));
	if (numTicks < MinTicks)
		numTicks = MinTicks;
	min = std::floor(min / step) * step;
	max = std::ceil(max / step) * step;
}

#endif