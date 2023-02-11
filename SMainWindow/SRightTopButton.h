#ifndef SRIGHTTOPBUTTON_H_
#define SRIGHTTOPBUTTON_H_

#include<QWidget>
class QPushButton;
class SRightTopButton :public QWidget
{
public:
	explicit SRightTopButton(QWidget* parent = nullptr);
	void init();
signals:
	void requestClose();
	void requestShowMax();
	void requestShowMin();
	void requestOnTop();
private:
	QPushButton* m_closeBtn;
	QPushButton* m_maxBtn;
	QPushButton* m_minBtn;
	QPushButton* m_topBtn;

};

#endif // !SRIGHTTOPBUTTON_H_
