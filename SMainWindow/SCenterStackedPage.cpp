#include"SCenterStackedPage.h"
#include"SSearchWidget.h"
#include"SContacts/SContactsListView.h"
SCenterStackedPage::SCenterStackedPage(QWidget* parent)
	:QWidget(parent)
	, m_searchWidget(new SSearchWidget)
	, m_contactsListView(new SContactsListView)
{
	this->init();
}

void SCenterStackedPage::init()
{
	//使用样式绘制背景(QWidget 需要加上)
	setAttribute(Qt::WA_StyledBackground, true);

	auto vlayout = new QVBoxLayout(this);
	vlayout->addWidget(m_searchWidget);
	vlayout->addWidget(m_contactsListView);
	vlayout->setContentsMargins(0, 0, 0, 0);
	vlayout->setSpacing(0);

	m_searchWidget->setObjectName("searchWidget");
	setStyleSheet(R"(
QWidget#searchWidget{background-color:rgb(247,247,247);}
QLineEdit{background-color:rgb(226,226,226);border:none;border-radius:5px;}
QPushButton#searchBtn{background-color:rgb(226,226,226);border:none;border-radius:5px;image:url(':/assets/images/add.png');}
QLineEdit:focus{background-color:rgb(248,248,248);border:1px solid rgb(220,219,218);}
QPushButton#searchBtn:hover{background-color:rgb(209, 209, 209);}
)");

}
