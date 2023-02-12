#include"SChatMessage.h"

SChatMessage::SChatMessage()
{

}

SChatMessage::SChatMessage(const QString& msgText, const QString& dateTime)
	: msgText_(msgText)
	, msgDateTime_(QDateTime::fromString(dateTime,Qt::DateFormat::ISODate))
{

}

QString SChatMessage::msgText() const
{
	return msgText_;
}

void SChatMessage::setMsgText(const QString& text)
{
	msgText_ = text;
}

QString SChatMessage::msgDateTime() const
{
	return msgDateTime_.toString("yyyy/MM/dd hh:mm:ss");
}

void SChatMessage::setMsgDateTime(const QString& datetime)
{
	msgDateTime_ = QDateTime::fromString(datetime,Qt::DateFormat::ISODate);
}
