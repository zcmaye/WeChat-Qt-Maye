#include"SMainWindow.h"
#include<QHBoxLayout>
#include"SUtil/SEventFilterObject.h"
SMainWindow::SMainWindow(QWidget* parent)
	: QWidget(parent)
	, m_leftToolBar(new SLeftToolBar)
	, m_centerStacked(new SCenterStackedWidget)
	, m_rightWidget(new SRightWidget(this))
{
	this->init();
}
void SMainWindow::init()
{
	setMinimumSize(718, 518);
	setWindowFlag(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);

	auto filter = new SEventFilterObject(this);
	filter->setDropShadowEffect(true);
	installEventFilter(filter);

	auto hlayout = new QHBoxLayout(this);
	hlayout->addWidget(m_leftToolBar);
	hlayout->addWidget(m_centerStacked);
	hlayout->addWidget(m_rightWidget);
	hlayout->setSpacing(0);

	
}
