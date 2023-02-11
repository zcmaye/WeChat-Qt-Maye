#include"SSearchWidget.h"

SSearchWidget::SSearchWidget(QWidget* parent)
	:QWidget(parent)
	, m_searchEdit(new QLineEdit)
	, m_searchBtn(new QPushButton)
{ 
	this->init();
}

void SSearchWidget::init()
{
	setAttribute(Qt::WA_StyledBackground, true);
	setFixedSize(250,64);

	auto hlayout = new QHBoxLayout(this);
	hlayout->addWidget(m_searchEdit);
	hlayout->addWidget(m_searchBtn);
	hlayout->setSpacing(9);
	hlayout->setContentsMargins(12, 25, 12, 12);

	m_searchEdit->setObjectName("searchEdit");
	m_searchEdit->setFixedHeight(25);
	m_searchEdit->setPlaceholderText("搜索");
	m_searchEdit->addAction(QIcon(":/assets/images/searchIcon.png"), QLineEdit::ActionPosition::LeadingPosition);
	m_searchEdit->setClearButtonEnabled(true);

	m_searchBtn->setObjectName("searchBtn");
	m_searchBtn->setFixedSize(25,25);
}
