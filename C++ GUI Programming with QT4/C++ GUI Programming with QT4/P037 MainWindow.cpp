#include "P010 FindDialog.h"
#include "P020 GoToCell.h"
#include "P036 MainWindow.h"
#include "P027 sortdialog.h"
#include "P060 Spreadsheet.h"

MainWindow::MainWindow()
{
	spreadsheet = new Spreadsheet;	// ����һ��Spreadsheet���ڲ���
	setCentralWidget(spreadsheet);	// ��������Ϊ��������ڵ����봰��, ���봰�ڲ�����ռ�������ڵ��������򲿷�

	//// ���������ڵ����ಿ��
	createActions();	// ����"����", "����"�ǲ˵����߹������е�һ��ѡ��
	createMenus();
	createContextMenu();
	createToolBars();
	createStatusBar();

	//// ��ȡ���Ӧ�ó���洢��һЩ����
	readSettngs();

	findDialog = nullptr;	// �����ָ���ʼ��Ϊ��, �ڵ�һ�ε���MainWindow::find()������ʱ��, ��������FindDialog����

	setWindowIcon(QIcon("images/panda.png"));	// ������ʾ�ڴ������Ͻǵ�ͼ��(Qt����Դ���Ʒ�)
			// Ϊ�����ṩͼƬ�����ַ���:
			//		1. ��ͼƬ���浽�ļ���, ���������е�ʱ����������;
			//		2. ��XPM�ļ�������Դ������(��һ����֮���Կ���, ����ΪXPM�ļ�Ҳ����Ч��C++�ļ�);
			//		3. ʹ��Qt����Դ����(resource mechanism);

	setCurrentFile("");
}

void MainWindow::createActions()
{
	createFileActions();
	createEditActions();
	createToolsActions();
	createOptionsActions();
	createHelpActions();
}

#include <QMenuBar>
void MainWindow::createMenus()
{
	createFileMenu();
	createEditMenu();
	createToolsMenu();
	createOptionsMenu();
	createHelpMenu();
}

void MainWindow::createContextMenu()
{
	spreadsheet->addAction(cutAction);
	spreadsheet->addAction(copyAction);
	spreadsheet->addAction(pasteAction);
	spreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
}

#include <QStatusBar>
void MainWindow::createStatusBar()
{
	locationLabel = new QLabel(" W999 ");
	locationLabel->setAlignment(Qt::AlignHCenter);
	locationLabel->setMinimumSize(locationLabel->sizeHint());

	formulaLabel = new QLabel;
	formulaLabel->setIndent(3);	// indent ����	����һ��������ʽ, �Ա�����Щ����������ʾ���ı��ܹ������������һ��С��ƫ����

	statusBar()->addWidget(locationLabel);		// ��һ�ε���statusBar()��ʱ��ᴴ��״̬��// QLabel������ӵ�״̬����, ���ǵĸ�����ᱻ�Զ��ض���
	statusBar()->addWidget(formulaLabel, 1);	// ��չ���� 1 ʵ���˶�λָʾ���Ķ���ռ�������ʽָʾ��
												// ��չ���� 0 ��ζ������ϲ������չ
	
	connect(spreadsheet, SIGNAL(currentCellChanged(int, int, int, int)), this, SLOT(updateStatusBar()));
	connect(spreadsheet, SIGNAL(modified()), this, SLOT(spreadsheetModified()));
	updateStatusBar();
}

void MainWindow::spreadsheetModified()
{
	setWindowModified(true);	// ��windowModified�������ó�true, ���Ը��±�����
	updateStatusBar();			// ����λ�ú͹�ʽָʾ��
}

#include <QToolBar>
void MainWindow::createToolBars()
{
	fileToolBar = addToolBar(tr("&File"));
	fileToolBar->addAction(newAction);
	fileToolBar->addAction(openAction);
	fileToolBar->addAction(saveAction);

	editToolBar = addToolBar(tr("&Edit"));
	editToolBar->addAction(cutAction);
	editToolBar->addAction(copyAction);
	editToolBar->addAction(pasteAction);
	editToolBar->addSeparator();
	editToolBar->addAction(findAction);
	editToolBar->addAction(goToCellAction);
}

void MainWindow::createFileActions()
{
	newAction = new QAction(tr("&New"), this);	// ���ټ�New ������Ϊ������
	newAction->setIcon(QIcon("images/newFile.png"));
	newAction->setShortcut(QKeySequence::New);	// ʹ���ʵ���QKeySequence::StandardKeyö��ֵ, ����ȷ��Qt�ܹ�ΪӦ�ó����������е�ƽ̨���ṩ��ȷ�Ŀ�ݼ�
												// ����ı������ڲ˵���ѡ���߶���һ�� Ctrl + N, �����N����ΪQKeySequence::New������"&New"
												// Sequence ����, ˳��
	newAction->setStatusTip(tr("Create a new spreadsheet file"));	// ״̬��ʾ
	connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));	// triggered ����

	openAction = new QAction(tr("&Open"), this);
	openAction->setIcon(QIcon("images/openFile"));
	openAction->setShortcut(QKeySequence::Open);
	openAction->setStatusTip(tr("Open a file"));
	connect(openAction, SIGNAL(triggered()), this, SLOT(open()));

	saveAction = new QAction(tr("&Save"), this);
	saveAction->setIcon(QIcon("images/save.png"));
	saveAction->setShortcut(QKeySequence::Save);
	openAction->setStatusTip(tr("Save the file"));
	connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
	
	saveAsAction = new QAction(tr("Save As"), this);
	saveAsAction->setIcon(QIcon("images/saveAs.png"));
	saveAsAction->setShortcut(QKeySequence::SaveAs);
	connect(saveAsAction, SIGNAL(triggered()), this, SLOT(save()));

	exitAction = new QAction(tr("E&xit"), this);
	exitAction->setIcon(QIcon("images/exit.png"));
	exitAction->setShortcut(tr("Ctrl + Q"));	// ����û�б�׼��������, ������Ҫ��������ȷָ��������
	exitAction->setStatusTip(tr("Exit the application"));
	connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

	// ����򿪵��ļ�
	for (int i = 0; i < MaxRecentFiles; i++)
	{
		recentFileActions[i] = new QAction(this);
		recentFileActions[i]->setVisible(false);	// ��ӵ���Щ����������ʽ��
		connect(recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
	}
}

void MainWindow::createEditActions()
{
	cutAction = new QAction(tr("&Cut"), this);
	cutAction->setIcon(QIcon("images/cut.png"));
	cutAction->setShortcut(QKeySequence::Cut);
	connect(cutAction, SIGNAL(triggered()), this, SLOT(cut()));

	copyAction = new QAction(tr("&Copy"), this);
	copyAction->setIcon(QIcon("images/copy.png"));
	copyAction->setShortcut(QKeySequence::Copy);
	connect(copyAction, SIGNAL(triggered()), this, SLOT(copy()));

	pasteAction = new QAction(tr("&Paste"), this);
	pasteAction->setIcon(QIcon("images/paste.png"));
	pasteAction->setShortcut(QKeySequence::Paste);
	connect(pasteAction, SIGNAL(triggered()), this, SLOT(paste()));

	deleteAction = new QAction(tr("Delete"), this);
	deleteAction->setIcon(QIcon("images/delete.png"));
	deleteAction->setShortcut(QKeySequence::Delete);
	connect(deleteAction, SIGNAL(triggered()), this, SLOT(del()));

	selectAllAction = new QAction(tr("&All"), this);
	selectAllAction->setShortcut(QKeySequence::SelectAll);
	selectAllAction->setStatusTip(tr("Select all the cells in the spreadsheet"));
	connect(selectAllAction, SIGNAL(triggered()), spreadsheet, SLOT(selectAll()));	// QTableWidget�ĸ���֮һQAbstractItemView�ṩ

	findAction = new QAction(tr("&Find"), this);
	findAction->setIcon(QIcon("images/find.png"));
	findAction->setShortcut(QKeySequence::Find);
	connect(findAction, SIGNAL(triggered()), this, SLOT(find()));

	goToCellAction = new QAction(tr("Go To Cell"), this);
	goToCellAction->setIcon(QIcon("images/goNext.png"));
	goToCellAction->setShortcut(tr("Ctrl + G"));
	connect(goToCellAction, SIGNAL(triggered()), this, SLOT(goToCell()));
}

void MainWindow::createToolsActions()
{
	recalculateAction = new QAction(tr("Recalrulate"), this);
	recalculateAction->setShortcut(tr("F9"));
	connect(recalculateAction, SIGNAL(triggered()), this, SLOT(recalculate()));

	sortAction = new QAction(tr("Sort..."), this);
	connect(sortAction, SIGNAL(triggered()), this, SLOT(sort()));
}

void MainWindow::createOptionsActions()
{
	showGridAction = new QAction(tr("&Show Grid"), this);
	showGridAction->setCheckable(true);	// ����һ����ѡ����
	showGridAction->setChecked(spreadsheet->showGrid());	// ���õ�ʱ��, Spreadsheet����ͻ���ʾһ������
	showGridAction->setStatusTip(tr("Show or hide the spreadsheet's grid"));
	connect(showGridAction, SIGNAL(toggled(bool)), spreadsheet, SLOT(setShowGrid(bool)));	// ����ۼ̳���QTableWidget

	autoRecalculateAction = new QAction(tr("Auto Recalculate"), this);
	autoRecalculateAction->setCheckable(true);
	autoRecalculateAction->setChecked(true);
	connect(autoRecalculateAction, SIGNAL(toggled(bool)), this, SLOT(autoRecalculate()));
}

void MainWindow::createHelpActions()
{ 
	aboutAction = new QAction(tr("About"), this);
	connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

	aboutQtAction = new QAction(tr("About &Qt"), this);
	aboutQtAction->setIcon(QIcon("images/qtLogo.png"));
	aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
	connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));	// ͨ������qAppȫ�ֱ���, ���ǿ���ʹ��QApplication��aboutQt()��
}

void MainWindow::createFileMenu()
{
	
	fileMenu = menuBar()->addMenu(tr("&File"));	// addMenu()����ָ�����ı�����һ��QMenu���ڲ���, ���һ������ӵ��˵���
												// menuBar()��������һ��ָ��QMenuBar��ָ��
												// �˵������ڵ�һ�ε���menuBar()������ʱ�򴴽�����
	fileMenu->addAction(newAction);	// ΪFile�˵���Ӷ���
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addAction(saveAsAction);
	
	separatorAction = fileMenu->addSeparator();	// separaotr ����� ������������Ӿ��ϰѹ�ϵ���е���Щ��Ŀ����һ��
												// ���ﱣ����һ�������, �����Ϳ�����������(���û������ļ�)������ʾ�Ǹ������, ��Ϊ���������֮��ʲô��û���е㶺��
	for (int i = 0; i < MaxRecentFiles; i++)
		fileMenu->addAction(recentFileActions[i]);	// ʹ��ѭ�����recentFileActions�����е�����(��������ص�)
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);
}

void MainWindow::createEditMenu()
{
	editMenu = menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction(cutAction);
	editMenu->addAction(copyAction);
	editMenu->addAction(pasteAction);
	editMenu->addAction(deleteAction);
	editMenu->addSeparator();
	editMenu->addAction(findAction);
	editMenu->addAction(goToCellAction);
}

void MainWindow::createToolsMenu()
{
	toolsMenu = menuBar()->addMenu(tr("&Tools"));
	toolsMenu->addAction(recalculateAction);
	toolsMenu->addAction(sortAction);
}

void MainWindow::createOptionsMenu()
{
	optionsMenu = menuBar()->addMenu(tr("Options"));
	optionsMenu->addAction(showGridAction);
	optionsMenu->addAction(autoRecalculateAction);
}

void MainWindow::createHelpMenu()
{
	helpMenu = menuBar()->addMenu(tr("Help"));
	helpMenu->addAction(aboutAction);
	helpMenu->addAction(aboutQtAction);
}

void MainWindow::newFile()
{
	if (okToContinue())	// �����жϴ�ʱ�������Ƿ����δ������ļ�
	{
		spreadsheet->clear();	// ��յ����Ʊ�����е�ȫ����Ԫ��͹�ʽ
		setCurrentFile("");		// ���´��ڵı���, ��˵�����ڱ༭����һ��û�б�����ĵ�, ����������curFile�ļ����Ҹ�������򿪵Ķ��ļ����б�
	}
}

#include <QMessageBox>
bool MainWindow::okToContinue()
{
	if (isWindowModified())
	{
		int r = QMessageBox::warning(this, tr("SpreadsheetWarning"), 
			tr("The doucument has been modified.\n"
			"Do you want to save your changes?"), 
			QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		if (r == QMessageBox::Yes)
			return save();
		else if (r == QMessageBox::Cancel)
			return false;
	}
	return true;
}

#include <QFileDialog>
void MainWindow::open()
{
	if (okToContinue())	// ����δ����ı仯
	{
		QString fileName = QFileDialog::getOpenFileName(this, tr("Open Spreadsheet"), ".", tr("Spread files (*.sp)"));
										// ʹ�þ�̬�������û�������һ���µ��ļ���, ��������ᵯ��һ���ļ��Ի���, ���û�ѡ���ļ�, ������ѡ���ļ����ļ���
										// ����û������Cancel��ť, �򷵻�һ�����ַ���
										// ��һ�����������ĸ����ڲ���, ���ڶԻ�����������ڲ���, �����ͬ�ڶԻ�����������ڲ����ĸ��ӹ�ϵ, �Ի���ͨ��ӵ������Ȩ, ����������и�����, Ĭ�������������з��ڸ�������, һ���ӶԻ���Ҳ�ṫ�ø������������
										// �ڶ��������ǶԻ������
										// ������������Ӧ�ô���һ��Ŀ¼��ʼ, ������������ǵ�ǰĿ¼
										// ���ĸ�ָ�����ļ�������, filter��һ�������ı���һ��ͨ������
		if (!fileName.isEmpty())		
			loadFile(fileName);
	}
}

bool MainWindow::loadFile(const QString & fileName)
{
	if (!spreadsheet->readFile(fileName))	// readFile()��ȡ�����е��ļ�
											// �����ȡ���ɹ��Ļ�, readFile()����ͨ��һ����Ϣ�������������֪ͨ���û�, ͨ�������, �õײ���������������Ϣ��һ�������ϰ��, ��Ϊ���ǿ����ṩ׼ȷ�Ĵ���ϸ��
	{
		statusBar()->showMessage(tr("Loading canceled"), 2000);	// ״̬������ʾһ����Ϣ2000����
		return false;
	}

	setCurrentFile(fileName);
	statusBar()->showMessage(tr("File loaded"), 2000);
	return true;
}

bool MainWindow::save()// �������ļ���֮ǰ���ļ�������һ���Ѿ���������ļ�, �����Ѿ�����һ������, ��ôsave()�����ͻ���������ֵ���saveFile()����, ����, ��ֻ�Ǽ򵥵ĵ���saveAs()����
{
	if (curFile.isEmpty())
		return saveAs();
	else
		return saveFile(curFile);
}

bool MainWindow::saveFile(const QString & fileName)	
{
	if (!spreadsheet->writeFile(fileName))
	{
		statusBar()->showMessage(tr("Saving canceled"), 2000);
		return false;
	}

	setCurrentFile(fileName);
	statusBar()->showMessage(tr("File Saved"), 2000);
	return true;
}

bool MainWindow::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this, // ͨ���˺������û�����õ�һ���ļ���, ����û�������Cancel, �򷵻�false, �⽫��ʹ���������ϴ��ݸ����ĵ�����save()����okToContinue()			����������ļ��Ѿ�����, getSaveFileName()��������Ҫ���û�ȷ���Ƿ񸲸Ǹ��ļ�, ����ͨ����getSaveFileName()��������һ��QFIleDialog::DontConfirmOverwrite���Ӳ���, ���Ըı���һ��Ϊ
		tr("Save Spreadsheet"), ".", tr("Spreadsheet files (*.sp)"));
	if (fileName.isEmpty())
		return false;

	return saveFile(fileName);
}

#include <QCloseEvent>
void MainWindow::closeEvent(QCloseEvent * e)	// ����ͨ������ʵ��QWidget::closeEvent()����, �Ϳ�����;��ȡ����������ڵĹرղ���, ����ȷ���ǲ�����Ĺر��������	 �����������¼��Ļ�, Qt�����ظô���, �����һ�����ڹرպ�, Ӧ�ó���ͽ�����	�����QApplication��quitOnLastWindowClosed��������Ϊfalse, ���Խ�ֹ������Ϊ, ����, �ó�������е�����QApplication::quit()�����Ż����
{
	if (okToContinue())
	{
		writeSettings();	// �������Ӧ�ó���ĵ�ǰ����
		e->accept();
	}
	else
		e->ignore();
}

void MainWindow::setCurrentFile(const QString & fileName)	// �Ա������ڱ༭���ļ�����curFile˽�б�����������, �ٰ�����ļ�����ʾ�ڱ�������֮ǰ, ��Ҫʹ��strippedName()�����Ƴ��ļ����е�·���ַ�
{
	curFile = fileName;
	setWindowModified(false);	// ÿ��QWidget����һ��windowModified����, ����ô��ڵ��ĵ�����û�б���ı仯, ��Ӧ����������Ϊtrue, ����Ӧ����������Ϊfalse

	QString shownName = tr("Untitled");
	if (!curFile.isEmpty())
	{
		shownName = strippedName(curFile);
		recentFiles.removeAll(curFile);
		recentFiles.prepend(curFile);	// prepend Ԥı Ԥ��
		updateRecentFileActions();
	}
	setWindowTitle(tr("%1[*] - %2").arg(shownName)	// QString::arg()��������ʹ���Լ��Ĳ����滻��С���ֵ�"%n"����, ���һ������Ĳ������ؽ��"%n"�ַ������յĽ���ַ���
								   .arg(tr("Spreadsheet")));
	// ֱ��дsetWindowTitle(shownName + tr("[*] - Spreadsheet"));Ҳ��, ����ʹ��arg()��������Ϊ������Ա�ṩ����������
}

QString MainWindow::strippedName(const QString & fullFileName)	// �Ƴ��ļ����е�·���ַ�, ��������ʹ�ļ����������Ѻ�һЩ
{
	return QFileInfo(fullFileName).fileName();
}

void MainWindow::updateRecentFileActions()
{
	QMutableStringListIterator i(recentFiles);
	while (i.hasNext())
		if (!QFile::exists(i.next()))
			i.remove();
	for (int j = 0; j < MaxRecentFiles; ++j)
	{
		if (j < recentFiles.count())
		{
			QString text = tr("&%1 %2")
							.arg(j + 1)
							.arg(strippedName(recentFiles[j]));
			recentFileActions[j]->setText(text);
			recentFileActions[j]->setData(recentFiles[j]);
			recentFileActions[j]->setVisible(true);
		}
		else
			recentFileActions[j]->setVisible(false);
	}
	separatorAction->setVisible(!recentFiles.isEmpty());
}

void MainWindow::openRecentFile()	// �û�ѡ��һ������򿪵��ļ�
{
	if (okToContinue())
	{
		QAction * action = qobject_cast<QAction *>	// qobject_cast<T>()��������Qt��moc(meta-object compiler, Ԫ���������)�����ɵ�Ԫ��Ϣ������ִ�ж�̬����ǿ������ת��, ������һ��ָ������QObject�����ָ��, �������ڸö����ܱ� ת����������������ʱ����0
			(sender());	// ʹ��sender()������ĸ��ض��Ķ��������������
		if (action)
			loadFile(action->data().toString());
	}
}

#include <QSettings>

void MainWindow::writeSettings()	// ���������ڵļ�����״(λ�úͳߴ��С), ������ļ��б��Լ�ShowGrid��Auto-Recalculateѡ�������ֵ
{
	QSettings settings("Software Inc.", "Spreadsheet");	// Ĭ�������, QSettings��洢Ӧ�ó��������ض�ƽ̨��ص�һЩ������Ϣ
					// "��֯������", "Ӧ�ó��������"

	settings.setValue("geometry", saveGeometry());
	settings.setValue("recentFiles", recentFiles);
	settings.setValue("showGrid", showGridAction->isCheckable());
	settings.setValue("autoRecalc", autoRecalculateAction->isChecked());

	settings.beginGroup("findDialog");
	//settings.setValue("matchCase", caseCheckBox->isChecked());
	//settings.setValue("searchBackward", backwardCheckBox->isChecked());
	settings.endGroup();
}

void MainWindow::readSettngs()
{
	QSettings settings("Software Inc.", "Spreadsheet");

	restoreGeometry(settings.value("geometry").toByteArray());

	recentFiles = settings.value("recentFiles").toStringList();
	updateRecentFileActions();

	bool showGrid = settings.value("showGrid", true).toBool();
	showGridAction->setChecked(showGrid);

	bool autoRecalc = settings.value("autoRecalc", true).toBool();
	autoRecalculateAction->setChecked(autoRecalc);
}
