#ifndef CONTACTSINFO_H_
#define CONTACTSINFO_H_

#include <QString>
#include <QPixmap>

class ContactsInfo
{
public:
	ContactsInfo() {};
	ContactsInfo(const QString& username,const QString& signature ="这个人非常的懒，啥都没有写~", const QPixmap& profile = QPixmap(":/ContactsAssets/images/default_profile.jpg"));
	friend QDebug operator<<(QDebug out, const ContactsInfo& info);
	
	enum VIPType {NoVIP,VIP,SVIP};
	enum InfoRole 
	{
		ProfileRole = Qt::UserRole + 2,
		UsernameRole,
		VipRole,
		SignatureRole
	};
public:
	QPixmap profile_;
	QString username_;
	QString signature_;
	VIPType vipType_;
};
Q_DECLARE_METATYPE(ContactsInfo)
#endif // !CONTACTSINFO_H_
