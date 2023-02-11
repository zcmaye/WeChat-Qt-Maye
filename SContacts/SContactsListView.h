#ifndef SCONTACTSLISTVIEW_H_
#define SCONTACTSLISTVIEW_H_

#include "SCustomWidgets/SListView.h"

class ContactsInfo;
class QStandardItemModel;
class SContactsListView :public SListView
{
	Q_OBJECT
public:
	explicit SContactsListView(QWidget* parent = nullptr);
	void init();
protected:
	void enterEvent(QEnterEvent* ev)override;
	void leaveEvent(QEvent* ev)override;
private:
	QStandardItemModel* m_model;
	QList<ContactsInfo*> m_infos;
};
#endif // !SCONTACTSLISTVIEW_H_
