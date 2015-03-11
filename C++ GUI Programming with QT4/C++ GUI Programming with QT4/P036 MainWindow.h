#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

class MainWindow : public QMainWindow
{
	Q_OBJECT;
public:
	MainWindow();
protected:
	void closeEvent(QCloseEvent * event);	// closeEvent()��QWidget���е�һ���麯��, ���û��رմ��ڵ�ʱ��, ����������ᱻ�Զ�����		event �¼�
											// ��������ʵ����, �Ե������û�ѯ���Ƿ񱣴������, ����ִ��һЩ�����û���ǰʹ��״̬�ȵȵĶ���
private slots:	// �� File->New�����Ĳ˵�, ��MainWindow�лᱻʵ��Ϊ˽�в�
	// File�˵�
	void newFile();
	void openRecentFile(); 
	void open();
	bool save();	// ������Ϊһ���źŵ���Ӧ��������ִ��ʱ, ����Է���ֵ, ���ǵ��Ѳ���Ϊ���������õ�ʱ��, ����ֵ�ͺ���ͨC++����һ����
	bool saveAs();
	// Edit�˵�
	void cut(){}
	void copy(){}
	void paste(){}
	void del(){} 
	void find(){};
	void goToCell(){}
	// Tools�˵�
	void recalculate(){}
	void sort(){};
	// Options�˵�
	void autoRecalculate(){}
	// Help�˵�
	void about(){};
	// ״̬��
	void updateStatusBar(){};	// ���ڸ��µ�Ԫ��λָʾ���͵�Ԫ��ʽָʾ��
	void spreadsheetModified();	// modefied �޸�, �Ľ�
private:
	// ��������
	void createActions();
	void createFileActions();
	void createEditActions();
	void createToolsActions();
	void createHelpActions();
	void createOptionsActions();	

	// �����˵�
	void createContextMenu();	// �����Ĳ˵�, ���û��Ҽ������ʱ����ֵĲ˵�
	void createMenus();		// �������������Ĳ˵�ϵͳ
	void createFileMenu();
	void createEditMenu();
	void createToolsMenu();
	void createOptionsMenu();
	void createHelpMenu();

	
	void createToolBars();	// ����������
	void createStatusBar();	// ����״̬��
	
	// ��������
	bool okToContinue();	// �ж����Ƿ����δ������ļ�
	bool loadFile(const QString & fileName);
	bool saveFile(const QString & fileName);
	void setCurrentFile(const QString & fileName);	// ���õ�ǰ�򿪵��ļ��ı���, ���������ļ���ʾ(����������ļ�)
														// 1. curFile = fileName Ϊ��	���ñ���ΪUntitled ������������ļ��б�
														// 2. curFile = fileName �ǿ�	���ñ���(��ȥ·��) ����������ļ��б�
	void updateRecentFileActions();	// ����File�˵��е���Ŀ
	void writeSettings();
	void readSettngs();
	QString strippedName(const QString & fullFileName);	// �����Ƴ��ļ����е�·������
	
	// �õ��Ĵ��ڲ���
	Spreadsheet	* spreadsheet;
	FindDialog	* findDialog;
	
	QStringList	  recentFiles;
	QString		  curFile;

	// �����
	QAction * separatorAction;

	// File�˵�
	enum{ MaxRecentFiles = 5 };
	QMenu	* fileMenu;
	QAction * newAction;	// �½�����
	QAction * openAction;	// �򿪶���
	QAction * saveAction;	// ���涯��
	QAction * saveAsAction;	// ���Ϊ����
	QAction * recentFileActions[MaxRecentFiles];
	QAction * exitAction;	// �˳�����
	
	// Edit�˵�
	QMenu	* editMenu;
	QToolBar* fileToolBar;
	QToolBar* editToolBar;
	QAction * cutAction;	// ����
	QAction * copyAction;	// ����
	QAction * pasteAction;// ճ��
	QAction * deleteAction;
	QAction * selectAction;
	QAction * selectAllAction;	// ȫѡ
	QAction * findAction;
	QAction * goToCellAction;
	
	// Tools�˵�
	QMenu	* toolsMenu;
	QAction * recalculateAction;
	QAction * sortAction;

	// Options�˵�
	QMenu	* optionsMenu;
	QAction * showGridAction;	// ����һ����ѡ����, ���õ�ʱ��, Spreadsheet����ͻ���ʾһ������
	QAction * autoRecalculateAction;

	// Help�˵�
	QMenu	* helpMenu;
	QAction * aboutAction;
	QAction * aboutQtAction;

	// ״̬��
	QLabel	* locationLabel;
	QLabel	* formulaLabel;
};

#endif