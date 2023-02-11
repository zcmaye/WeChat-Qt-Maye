#include"SCenterStackedWidget.h"
#include"SSearchWidget.h"
#include"SCenterStackedPage.h"
SCenterStackedWidget::SCenterStackedWidget(QWidget* parent)
	:QStackedWidget(parent)
	, m_searchWidget(new SSearchWidget)
{
	this->init();
}

void SCenterStackedWidget::init()
{
	setFixedWidth(250);
	layout()->setContentsMargins(0, 0, 0, 0);
	addWidget(new SCenterStackedPage);

	//setStyleSheet("background-color:green;");
	
}
