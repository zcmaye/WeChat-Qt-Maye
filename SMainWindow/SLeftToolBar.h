/*****************************************************************//**
 * \file   SMainWindow.h
 * \brief
 *
 * \author Maye - 顽石老师
 * \date   February 2023
 * \other  微信公众号<C语言Plus> 欢迎关注
 *********************************************************************/

#ifndef SLEFTTOOLBAR_H
#define SLEFTTOOLBAR_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
class SLeftToolBar : public QWidget
{
	Q_OBJECT
public:
	enum ToolBarAction
	{
		Chat,
		Contacts,
		More,
		More2
	};
public:
	explicit SLeftToolBar(QWidget* parent = nullptr);
	void init();
protected:
	void paintEvent(QPaintEvent* ev)override;
signals:
	void toolClicked(SLeftToolBar::ToolBarAction act);
private:
	QVBoxLayout* m_vlayout;
	QLabel* m_profileLab;
	QPushButton* m_chatBtn;
	QPushButton* m_contactsBtn;
	QPushButton* m_moreBtn;
	QPushButton* m_more2Btn;
};

#endif // !SLEFTTOOLBAR_H
