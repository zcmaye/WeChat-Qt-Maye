#ifndef SRIGHTTOPBAR_H_
#define SRIGHTTOPBAR_H_

#include<QWidget>
class QPushButton;
class SRightTopButton;
class SRightTopBar :public QWidget
{
public:
	explicit SRightTopBar(QWidget* parent = nullptr);
	void init();
signals:
	void requestClose();
	void requestShowMax();
	void requestShowMin();
	void requestOnTop();
private:
	QPushButton* m_conactsNameBtn;
	SRightTopButton* m_rightTopBtn;
};

#endif // !SRIGHTTOPBAR_H_
