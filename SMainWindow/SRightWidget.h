﻿#ifndef SRIGHTWIDGET_H_
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
	void initChatView(QListWidget* w, const QString& text);
private:
	SRightTopBar* m_rightTopBar;

	QPushButton* m_emojiBtn;
	QPushButton * m_sendFileBtn;
	QPushButton * m_screenshotBtn;
	QPushButton * m_chatHistoryBtn;
	QPushButton * m_voiceChatBtn;
	QPushButton * m_videoChatBtn;

	QListWidget* m_msgShowWidget;
	QTextEdit* m_msgEdit;
	QPushButton* m_sendMsgBtn;
};

#endif // !SRIGHTWIDGET_H_
