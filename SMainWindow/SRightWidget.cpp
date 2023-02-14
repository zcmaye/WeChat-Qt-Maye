#include"SRightWidget.h"
#include<QVBoxLayout>
#include<QSplitter>
#include<QTextEdit>
#include<QListWidget>
#include<QPushButton>

#include"SContacts/SChatBubble.h"	
#include"SContacts/ContactsInfo.h"
#include"SContacts/SChatMessage.h"

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
	vlayout->addWidget(CreateRightBottomWidget());
	
	setStyleSheet("background-color:rgb(245,245,245)");

	connect(m_sendMsgBtn, &QPushButton::clicked, this, [=]()
		{
			initChatView(m_msgShowWidget, m_msgEdit->toPlainText());
			m_msgEdit->clear();
			m_msgShowWidget->scrollToBottom();

		});

}

QWidget* SRightWidget::CreateRightBottomWidget()
{
	m_msgShowWidget = new QListWidget;
	m_msgShowWidget->setMinimumHeight(20);
	m_msgShowWidget->setSelectionMode(QListWidget::SelectionMode::NoSelection);
	m_msgShowWidget->setFocusPolicy(Qt::FocusPolicy::NoFocus);
	m_msgShowWidget->setVerticalScrollMode(QListWidget::ScrollMode::ScrollPerPixel);

	initChatView(m_msgShowWidget, "hello wrold");
	initChatView(m_msgShowWidget, "我是顽石老师");
	initChatView(m_msgShowWidget, "大手大脚付款了");
	for (int i = 0; i < 200; i++)
	{
		initChatView(m_msgShowWidget, "你是谁，我不知道🤭");
	}


	QString str = R"(@全体成员 还在担心学习编程没有方向吗？来长风老师的课堂，揭秘核心技术
今晚课题：C / C++ 互联网核心技术大揭秘
1、Windows服务器开发
2、Linux服务器开发
3、Web网页服务器
4、HTTP服务器
必学指数 : ★★★★★★★★★★（十颗星）
---- - 【课程相当精彩】
主讲老师：顿开教育 【C / C++高级工程师】 - 长风老师
上课时间：今晚20点整
课堂直达链接：http ://q.occloud.net/oTXzMw
看到快去课堂！别错过精彩部分)";
	initChatView(m_msgShowWidget, str);

	//表情栏
	m_emojiBtn = new QPushButton;
	m_sendFileBtn = new QPushButton;
	m_screenshotBtn = new QPushButton;
	m_chatHistoryBtn = new QPushButton;
	m_voiceChatBtn = new QPushButton;
	m_videoChatBtn = new QPushButton;

	m_emojiBtn->setObjectName("emojiBtn");
	m_sendFileBtn->setObjectName("sendFileBtn");
	m_screenshotBtn->setObjectName("screenshotBtn");
	m_chatHistoryBtn->setObjectName("chatHistoryBtn");
	m_voiceChatBtn->setObjectName("voiceChatBtn");
	m_videoChatBtn->setObjectName("videoChatBtn");

	auto hlayout = new QHBoxLayout;
	hlayout->addWidget(m_emojiBtn);
	hlayout->addWidget(m_sendFileBtn);
	hlayout->addWidget(m_screenshotBtn);
	hlayout->addWidget(m_chatHistoryBtn);
	hlayout->addStretch(0);
	hlayout->addWidget(m_voiceChatBtn);
	hlayout->addWidget(m_videoChatBtn);

	//消息输入框
	m_msgEdit = new QTextEdit;

	//发送消息
	m_sendMsgBtn = new QPushButton("发送(&S)");
	m_sendMsgBtn->setObjectName("sendMsgBtn");
	//m_sendMsgBtn->setFixedSize(100, 32);

	auto hlayout1 = new QHBoxLayout;
	hlayout1->addStretch(0);
	hlayout1->addWidget(m_sendMsgBtn);

	QWidget* bottomWidget = new QWidget;
	bottomWidget->setMinimumHeight(130);

	auto vlayout = new QVBoxLayout(bottomWidget);
	vlayout->addLayout(hlayout);
	vlayout->addWidget(m_msgEdit);
	vlayout->addLayout(hlayout1);


	QSplitter* splitter = new QSplitter(Qt::Orientation::Vertical);
	splitter->addWidget(m_msgShowWidget);
	splitter->addWidget(bottomWidget);
	//splitter->setStretchFactor(1, 2);
	//splitter->setStretchFactor(0, 0);
	splitter->setCollapsible(0, false);
	splitter->setCollapsible(1, false);

	splitter->setStyleSheet(R"(
QPushButton{border:none;min-width:20px;min-height:20px;max-width:20px;max-height:20px;}
QPushButton#emojiBtn{image:url(':/assets/images/chat/emoji.png');}
QPushButton#emojiBtn:hover{image:url(':/assets/images/chat/emoji-hover.png');}
QPushButton#sendFileBtn{image:url(':/assets/images/chat/file.png');}
QPushButton#sendFileBtn:hover{image:url(':/assets/images/chat/file-hover.png');}
QPushButton#screenshotBtn{image:url(':/assets/images/chat/screenshot.png');}
QPushButton#screenshotBtn:hover{image:url(':/assets/images/chat/screenshot-hover.png');}
QPushButton#chatHistoryBtn{image:url(':/assets/images/chat/chatHistory.png');}
QPushButton#chatHistoryBtn:hover{image:url(':/assets/images/chat/chatHistory-hover.png');}
QPushButton#voiceChatBtn{image:url(':/assets/images/chat/voiceChat.png');}
QPushButton#voiceChatBtn:hover{image:url(':/assets/images/chat/voiceChat-hover.png');}
QPushButton#videoChatBtn{image:url(':/assets/images/chat/videoChat.png');}
QPushButton#videoChatBtn:hover{image:url(':/assets/images/chat/videoChat-hover.png');}
QPushButton#sendMsgBtn{background-color:rgb(233,233,233);border-radius:5px;font:normal 13pt '楷体';color:rgb(7,193,96);min-width:100px;min-height:32px;max-width:100px;max-height:32px;}
QPushButton#sendMsgBtn:hover{background-color:rgb(210,210,210);}
)");

	return splitter;
}

void SRightWidget::initChatView(QListWidget* w, const QString& text)
{
	auto contacts = new ContactsInfo("十一期 江涛", "面包会有的，一切都会有的");
	auto msg = new SChatMessage(text, QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));

	auto bubble = new SChatBubble();
	bubble->setMessage(contacts, msg, SChatBubble::BubbleType(rand()%2));

	w->addItem(bubble);
	w->setItemWidget(bubble, bubble);

	//auto item = new QListWidgetItem(w);
	//w->setItemWidget(item, bubble);

	//item->setSizeHint(QSize(0, bubble->textHeight() + 3 * 12));
	w->scrollToBottom();
}
