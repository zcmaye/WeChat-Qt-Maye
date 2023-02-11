/*****************************************************************//**
 * \file   SSearchWidget.h
 * \brief
 *
 * \author Maye - 顽石老师
 * \date   February 2023
 * \other  微信公众号<C语言Plus> 欢迎关注
 *********************************************************************/

#ifndef SSEARCHWIDGET_H_
#define SSEARCHWIDGET_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
class SSearchWidget : public QWidget
{
	Q_OBJECT
public:
	explicit SSearchWidget(QWidget* parent = nullptr);
	void init();

private:
	QLineEdit*		m_searchEdit;
	QPushButton*	m_searchBtn;
};

#endif // !SSEARCHWIDGET_H_
