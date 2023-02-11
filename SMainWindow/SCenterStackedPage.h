/*****************************************************************//**
 * \file   SCenterStackedPage.h
 * \brief
 *
 * \author Maye - 顽石老师
 * \date   February 2023
 * \other  微信公众号<C语言Plus> 欢迎关注
 *********************************************************************/

#ifndef SCTENTERSTACKEDPAGE_H_
#define SCTENTERSTACKEDPAGE_H_

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
class SContactsListView;
class SSearchWidget;
class SCenterStackedPage : public QWidget
{
	Q_OBJECT
public:
	explicit SCenterStackedPage(QWidget* parent = nullptr);
	void init();

private:
	SSearchWidget* m_searchWidget;
	SContactsListView* m_contactsListView;
};

#endif // !SCTENTERSTACKEDPAGE_H_
