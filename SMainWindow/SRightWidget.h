#ifndef SRIGHTWIDGET_H_
#define SRIGHTWIDGET_H_

#include<QWidget>
#include"SRightTopBar.h"
class QPushButton;
class QListWidget;
class QTextEdit;
class SRightWidget :public QWidget
{
public:
	explicit SRightWidget(QWidget* parent = nullptr);
	void init();
	QWidget* CreateRightBottomWidget();
	QWidget* CreateRightTopWidget();
	void initChatView(QListWidget* w, const QString& text);
private:
	SRightTopBar* m_rightTopBar;
	//Tool
	QPushButton* m_emojiBtn;
	QPushButton * m_sendFileBtn;
	QPushButton * m_screenshotBtn;
	QPushButton * m_chatHistoryBtn;
	QPushButton * m_voiceChatBtn;
	QPushButton * m_videoChatBtn;
	//Right
	QListWidget* m_msgShowWidget;
	QTextEdit* m_msgEdit;
	QPushButton* m_sendMsgBtn;

	//rightTopBar
	QPushButton* m_conactsNameBtn;

	QPushButton* m_closeBtn;
	QPushButton* m_maxBtn;
	QPushButton* m_minBtn;
	QPushButton* m_topBtn;
};

#endif // !SRIGHTWIDGET_H_
