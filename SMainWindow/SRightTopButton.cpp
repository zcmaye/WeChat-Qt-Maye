#include"SRightTopButton.h"
#include<QHBoxLayout>
#include<QPushButton>
SRightTopButton::SRightTopButton(QWidget* parent)
	:QWidget(parent)
	,m_closeBtn(new QPushButton)
    ,m_maxBtn(new QPushButton)
    ,m_minBtn(new QPushButton)
    ,m_topBtn(new QPushButton)
{
	this->init();
}

void SRightTopButton::init()
{
	setFixedWidth(32 * 4);

	auto hlayout = new QHBoxLayout(this);
	hlayout->setSpacing(0);
	hlayout->setContentsMargins(0, 0, 2, 0);
	hlayout->addWidget(m_topBtn);
	hlayout->addWidget(m_minBtn);
	hlayout->addWidget(m_maxBtn);
	hlayout->addWidget(m_closeBtn);

	m_topBtn->setObjectName("topBtn");
	m_topBtn->setCheckable(true);

	m_minBtn->setObjectName("minBtn");
	m_maxBtn->setObjectName("maxBtn");
	m_closeBtn->setObjectName("closeBtn");

	setStyleSheet("QPushButton{min-width:32px;min-height:25px;max-width:32px;max-height:25px;}");
}
