#ifndef SRIGHTWIDGET_H_
#define SRIGHTWIDGET_H_

#include<QWidget>
#include"SRightTopBar.h"
class QPushButton;
class SRightWidget :public QWidget
{
public:
	explicit SRightWidget(QWidget* parent = nullptr);
	void init();
private:
	SRightTopBar* m_rightTopBar;
};

#endif // !SRIGHTWIDGET_H_
