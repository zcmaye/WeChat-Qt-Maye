/*****************************************************************//**
 * \file   SChatMessage.h
 * \brief
 *
 * \author Maye - 顽石老师
 * \date   February 2023
 * \other  微信公众号<C语言Plus> 欢迎关注
 *********************************************************************/

#ifndef SCHATMESSAGE_H_
#define SCHATMESSAGE_H_

#include <QString>
#include <QDateTime>

class SChatMessage
{
public:
	SChatMessage();
	SChatMessage(const QString& msgText, const QString& dateTime);
	QString msgText() const;
	void setMsgText(const QString& text);
	QString msgDateTime()const;
	void setMsgDateTime(const QString&datetime);
private:
	QString		msgText_;		//消息文本
	QDateTime	msgDateTime_;	//消息日期时间
};

#endif // !SCHATMESSAGE_H_
