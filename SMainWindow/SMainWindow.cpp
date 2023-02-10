#include"SMainWindow.h"
#include<QHBoxLayout>

SMainWindow::SMainWindow(QWidget* parent)
	:QWidget(parent)
	, m_leftToolBar(new SLeftToolBar)
{
	this->init();
}
void SMainWindow::init()
{
	setMinimumSize(718, 518);
	auto hlayout = new QHBoxLayout(this);
	hlayout->addWidget(m_leftToolBar);
	hlayout->addStretch(1);

	
}
