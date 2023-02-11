#include"SRightWidget.h"
#include<QVBoxLayout>
SRightWidget::SRightWidget(QWidget* parent)
	: QWidget(parent)
	, m_rightTopBar(new SRightTopBar)
{
	this->init();
}

void SRightWidget::init()
{
	auto vlayout = new QVBoxLayout(this);
	vlayout->setContentsMargins(0, 0, 0, 0);
	vlayout->addWidget(m_rightTopBar);
	vlayout->addStretch(0);
	
	setStyleSheet("background-color:rgb(245,245,245)");
}
