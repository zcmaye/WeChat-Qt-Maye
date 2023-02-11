#include"SMainWindow.h"
#include<QHBoxLayout>

SMainWindow::SMainWindow(QWidget* parent)
	: QWidget(parent)
	, m_leftToolBar(new SLeftToolBar)
	, m_centerStacked(new SCenterStackedWidget)
	, m_rightWidget(new SRightWidget)
{
	this->init();
}
void SMainWindow::init()
{
	setMinimumSize(718, 518);
	auto hlayout = new QHBoxLayout(this);
	hlayout->addWidget(m_leftToolBar);
	hlayout->addWidget(m_centerStacked);
	hlayout->addWidget(m_rightWidget);
	hlayout->setSpacing(0);

	
}
