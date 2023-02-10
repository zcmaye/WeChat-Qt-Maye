#include"SLeftToolBar.h"
#include<QLabel>
#include<QPushButton>
#include<QPainter>
SLeftToolBar::SLeftToolBar(QWidget* parent)
	:QWidget(parent)
	, m_vlayout(new QVBoxLayout(this))
	, m_profileLab(new QLabel)
	, m_chatBtn(new QPushButton)
	,m_contactsBtn(new QPushButton)
	,m_moreBtn(new QPushButton)
	,m_more2Btn(new QPushButton)
{
	this->init();
}
void SLeftToolBar::init()
{
	setFixedWidth(55);

	m_profileLab->setPixmap(QPixmap(":/assets/images/default_profile.jpg"));
	m_profileLab->setScaledContents(true);
	m_profileLab->setFixedSize(37, 37);

	m_chatBtn->setObjectName("chatBtn");
	m_chatBtn->setCheckable(true);
	m_chatBtn->setChecked(true);
	m_chatBtn->setAutoExclusive(true);

	m_contactsBtn->setObjectName("contactsBtn");
	m_contactsBtn->setCheckable(true);
	m_contactsBtn->setAutoExclusive(true);

	m_moreBtn->setObjectName("moreBtn");
	m_moreBtn->setCheckable(true);

	m_more2Btn->setObjectName("more2Btn");
	m_more2Btn->setCheckable(true);

	//m_vlayout->setContentsMargins(0, 0, 0, 0);
	m_vlayout->addWidget(m_profileLab);
	m_vlayout->addWidget(m_chatBtn);
	m_vlayout->addWidget(m_contactsBtn);
	m_vlayout->addWidget(m_moreBtn);
	m_vlayout->addStretch();
	m_vlayout->addWidget(m_more2Btn);


	this->setStyleSheet(
		R"(
QPushButton{border:none;min-width:37px;min-height:37px;max-width:37px;max-height:37px;icon-size:20px;}
QPushButton#chatBtn{icon:url(':/assets/images/bubble.png');}
QPushButton#chatBtn:checked{icon:url(':/assets/images/bubble-chk.png');}
QPushButton#contactsBtn{icon:url(':/assets/images/contacts.png');}
QPushButton#contactsBtn:checked{icon:url(':/assets/images/contacts-chk.png');}
QPushButton#moreBtn{icon:url(':/assets/images/more.png');}
QPushButton#moreBtn:hover{icon:url(':/assets/images/more-hover.png');}
QPushButton#more2Btn{icon:url(':/assets/images/more2.png');}
QPushButton#more2Btn:hover{icon:url(':/assets/images/more2-hover.png');}
)");

}

void SLeftToolBar::paintEvent(QPaintEvent* ev)
{
	QWidget::paintEvent(ev);

	QPainter painter(this);
	painter.fillRect(rect(), QColor(46, 46, 46));
}
