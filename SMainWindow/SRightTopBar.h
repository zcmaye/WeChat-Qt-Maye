#ifndef SRIGHTTOPBAR_H_
#define SRIGHTTOPBAR_H_

#include<QWidget>
class QPushButton;
class SRightTopButton;
class QHBoxLayout;
class SRightTopBar :public QWidget
{
public:
	explicit SRightTopBar(QWidget* parent = nullptr);
	void init();
	QHBoxLayout* CreateButtonLayout();
signals:
	void requestClose();
	void requestShowMax();
	void requestShowMin();
	void requestOnTop();
private:
	QPushButton* m_conactsNameBtn;
	//SRightTopButton* m_rightTopBtn;

	QPushButton* m_closeBtn;
	QPushButton* m_maxBtn;
	QPushButton* m_minBtn;
	QPushButton* m_topBtn;
};

#endif // !SRIGHTTOPBAR_H_
