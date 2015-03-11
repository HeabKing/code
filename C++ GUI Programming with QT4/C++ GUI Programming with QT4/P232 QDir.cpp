// ����һ���ض�Ŀ¼�Լ����Ŀ¼�µ�������ȵ���Ŀ¼������ͼƬ��ռ�õĿռ�
#include <QApplication>
#include <QtGui>
#include <QWidget>
#include <QMessageBox>

// �����ض�Ŀ¼�Լ����Ŀ¼��������ȵ���Ŀ¼������ͼƬ��ռ�õĿռ�
qlonglong imageSpace(const QString &path)
{
    QDir dir(path);	// ʹ�ø�����·������һ��QDir����
    qlonglong size = 0;
	 
    QStringList filters;
    foreach (QByteArray format, QImageReader::supportedImageFormats())
        filters += "*." + format;

    foreach (QString file, dir.entryList(filters, QDir::Files))	// entryList() entry ��Ŀ, ��� ��һ���������ļ�����������һ���б�, ���ǿ��԰���"*"��"?"�����ͨ���  �ڶ�������ָ����Ҫ����Ŀ����(��ͨ�ļ�, Ŀ¼, ������)
        size += QFileInfo(dir, file).size();	// QFileInfo����Է����ļ�������(��С, Ȩ��, ������ʱ���...)

    foreach (QString subDir, 
		dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))	// ������Ŀ¼�µ�������Ŀ¼
        size += imageSpace(path + QDir::separator() + subDir);	// Ϊ�˴���ÿһ����Ŀ¼��·��, �ѵ�ǰĿ¼��·������Ŀ¼�����������, Ȼ����б�߰����Ƿָ���, ������Windows����ϵͳ���Ͽ�"\"֮��, QDir������ƽ̨�϶���"\"������Ŀ¼�ָ���

    return size;
}

int main(int argc, char *argv[])
{
	QApplication App(argc, argv);
    QStringList args = QApplication::arguments();

    QString path = QDir::currentPath();	// ��·��ת��Ϊ��ǰĿ¼	// QDir::homePath()����ת��Ϊ�û�����Ŀ¼, ����û�����������ָ����һ��·��, ������������ǰ���Ŀ¼
    if (args.count() > 1)
        path = args[1];

	QWidget		W;

	QString str = QString("Space used by images in ") + qPrintable(path)
              + " and its subdirectories is "		// qPrintable() �� QString ת���� const char *
			  + QString::number(imageSpace(path) / 1024) + " KB";
	W.show();
	QMessageBox::warning(nullptr, nullptr, str);
	return App.exec();    
}
