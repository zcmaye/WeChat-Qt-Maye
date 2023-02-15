#include"SRightTopBar.h"
#include"SRightTopButton.h"
#include<QGridLayout>
#include<QPushButton>
SRightTopBar::SRightTopBar(QWidget* parent)
	: QWidget(parent)
	, m_conactsNameBtn(new QPushButton("Maye"))
	//, m_rightTopBtn(new SRightTopButton)
{
	this->init();
}

void SRightTopBar::init()
{
	//setAttribute(Qt::WA_sty)
	//setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setFixedHeight(64);

	auto rightTopBar = new  QWidget;
	rightTopBar->setFixedHeight(64);

	auto glayout = new QGridLayout(this);
	glayout->setSpacing(0);
	glayout->setContentsMargins(0, 0, 0, 0);
	
	glayout->addWidget(m_conactsNameBtn,0,0,2,1);
	//glayout->setColumnStretch(1, 0);
	glayout->addLayout(CreateButtonLayout(),0,1);

	
	setStyleSheet(R"(
QPushButton{border:none;text-align:left;}
QPushButton#closeBtn{image:url(':/assets/images/close.png');}
QPushButton#maxBtn{image:url(':/assets/images/maxshow.png');}
QPushButton#minBtn{image:url(':/assets/images/minshow.png');}
QPushButton#topBtn{image:url(':/assets/images/pushpin.png');}
QPushButton#closeBtn:hover{image:url(':/assets/images/close-hover.png');background-color:rgb(251,115,115);}
QPushButton#maxBtn:hover{background-color:rgb(226,226,226);}
QPushButton#minBtn:hover{background-color:rgb(226,226,226);}
QPushButton#topBtn:checked{image:url(':/assets/images/pushpin-chk.png');background-color:rgb(226,226,226);}
QPushButton#closeBtn,QPushButton#maxBtn,QPushButton#minBtn,QPushButton#topBtn{min-width:32px;min-height:25px;max-width:32px;max-height:25px;}
)");
}

QHBoxLayout* SRightTopBar::CreateButtonLayout()
{
	m_closeBtn=new QPushButton;
    m_maxBtn=new QPushButton;
    m_minBtn=new QPushButton;
    m_topBtn=new QPushButton;

	auto hlayout = new QHBoxLayout;
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

	return hlayout;
}
