/*****************************************************************//**
 * \file   SMainWindow.h
 * \brief
 *
 * \author Maye - 顽石老师
 * \date   February 2023
 * \other  微信公众号<C语言Plus> 欢迎关注
 *********************************************************************/

#ifndef SMAINWINDOW_H_
#define SMAINWINDOW_H_

#include <QWidget>
#include "SLeftToolBar.h"
#include "SCenterStackedWidget.h"
#include "SRightWidget.h"
class SMainWindow : public QWidget
{
	Q_OBJECT
public:
	explicit SMainWindow(QWidget* parent = nullptr);
	void init();
private:
	SLeftToolBar* m_leftToolBar = nullptr;
	SCenterStackedWidget* m_centerStacked;
	SRightWidget* m_rightWidget = nullptr;
};

#endif // !SMAINWINDOW_H_
