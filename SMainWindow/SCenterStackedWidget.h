/*****************************************************************//**
 * \file   SCtenterStackedWidget.h
 * \brief
 *
 * \author Maye - 顽石老师
 * \date   February 2023
 * \other  微信公众号<C语言Plus> 欢迎关注
 *********************************************************************/

#ifndef SCTENTERSTACKEDWIDGET_H_
#define SCTENTERSTACKEDWIDGET_H_

#include <QStackedWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
class SSearchWidget;
class SCenterStackedWidget : public QStackedWidget
{
	Q_OBJECT
public:
	explicit SCenterStackedWidget(QWidget* parent = nullptr);
	void init();

private:
	SSearchWidget* m_searchWidget;
};

#endif // !SCTENTERSTACKEDWIDGET_H_
