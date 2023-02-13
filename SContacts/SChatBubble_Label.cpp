#include"SChatBubble.h"
#include"SChatMessage.h"
#include"ContactsInfo.h"

#include<QPainter>
#include<QResizeEvent>
#include<QPainterPath>

SChatBubble::SChatBubble(QWidget* parent)
	:QLabel(parent)
{
	this->init();
}
void SChatBubble::init()
{
	//resize(640, 480);
	setAlignment(Qt::AlignTop);
	setWordWrap(true);
	setTextInteractionFlags(Qt::TextInteractionFlag::TextSelectableByMouse);
}

void SChatBubble::setMessage(const ContactsInfo* info, const SChatMessage* msg,SChatBubble::BubbleType type)
{
	m_contacts = info;
	m_msg = msg;
	m_type = type;

	setText(m_msg->msgText());
	m_textSize = textSize();
}

void SChatBubble::paintEvent(QPaintEvent* ev)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::RenderHint::Antialiasing);
	//painter.fillRect(rect(), Qt::GlobalColor::white);

	if (m_type == BubbleType::BubbleTime)
	{

	}
	else
	{
		painter.setPen(Qt::PenStyle::NoPen);
		painter.setBrush(QColor(60, 172, 213));



		//绘制头像	
		painter.drawPixmap(profileRect, m_contacts->profile_);

		//绘制气泡
		painter.drawRoundedRect(bubbleRect, 10, 10);
		
		//绘制三角形
		painter.drawPolygon(polygon);

	}

	QLabel::paintEvent(ev);
}

void SChatBubble::resizeEvent(QResizeEvent* ev)
{
	updateSize();
}

QSize SChatBubble::textSize() const
{
	if (!m_msg)
		return QSize();
	QFontMetrics fm = fontMetrics();
#if 0
	//计算文本Size
	QString tstr = m_msg->msgText();
	int maxWidth = 0;		//1,最长的一行文本宽度
	int totalHeight = 0;	//2,所有文本总高度

	int lineCnt = 0;				//文本行数
	qsizetype lineFeedpos = 0;		////\n的位置

	for (int i = 0; i < tstr.length(); i = lineFeedpos + 1)
	{
		lineFeedpos = tstr.indexOf("\n", i);
		//最后不是\n，需要补加一行
		if (lineFeedpos == -1)
		{
			++lineCnt;
			break;
		}
		else
		{
			++lineCnt;
		}

		int curLineW = fm.horizontalAdvance(tstr.mid(i, lineFeedpos));
		if (curLineW > maxWidth)
		{
			maxWidth = curLineW;
		}
		qInfo() << tstr.mid(i, lineFeedpos - i) <<curLineW;
	}
	totalHeight = lineCnt * fm.height();
	return QSize(maxWidth, totalHeight);
#else
	QRect rect = fm.boundingRect(QRect(0, 0, 0, 0), Qt::AlignLeft, m_msg->msgText());
	return rect.size();
#endif

}

void SChatBubble::updateSize()
{
	if (m_type == SChatBubble::BubbleLeft)
	{
		profileRect = { 0,0,42,42 };


		bubbleRect = { 
			profileRect.right() + 2 * m_textMargin,
			0,
			m_textSize.width() + 2 * m_textMargin,
			m_textSize.height() + 2 * m_textMargin };

		//如果能完全展示
		if (bubbleRect.width() + 2 * m_textMargin + profileRect.width() <= width())
		{
		}
		else
		{
			qInfo() << "else";
			bubbleRect.setWidth(width() - 3 * m_textMargin - profileRect.width());
		}
		
		setContentsMargins(
			bubbleRect.x() + m_textMargin,
			m_textMargin,
			m_textMargin * 2,
			m_textMargin * 2);

		polygon << QPoint{ bubbleRect.x(),bubbleRect.y() + 21 - 6 }
			<< QPoint{ bubbleRect.x(),bubbleRect.y() + 21 + 12 - 6 }
		<< QPoint{ bubbleRect.x() - 6,bubbleRect.y() + 21 };


	}
	else if (m_type == SChatBubble::BubbleRight)
	{
		profileRect = { width()-42,0,42,42};

		bubbleRect = { 
			profileRect.left() - m_textSize.width() - 3 * m_textMargin,
			0,
			m_textSize.width() + 2 * m_textMargin ,
			m_textSize.height() + 2 * m_textMargin };

		int left = 0;
		//如果能完全展示
		if (bubbleRect.width() + 2 * m_textMargin + profileRect.width() <= width())
		{
			left = bubbleRect.x() +  m_textMargin;
		}
		else
		{
			left = 2 * m_textMargin;
			bubbleRect.setX(m_textMargin);
			bubbleRect.setWidth(width() - 2 * m_textMargin - profileRect.width());
		}
		setContentsMargins(
			left,
			m_textMargin,
			profileRect.width() + m_textMargin * 2,
			m_textMargin * 2);

		polygon << QPoint{ bubbleRect.right(),bubbleRect.y() + 21 - 6 }
			    << QPoint{ bubbleRect.right(),bubbleRect.y() + 21 + 12 - 6 }
		        << QPoint{ bubbleRect.right() + 6,bubbleRect.y() + 21 };
	}

}
