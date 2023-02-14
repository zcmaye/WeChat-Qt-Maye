#include"SChatBubble.h"
#include"SChatMessage.h"
#include"ContactsInfo.h"

#include<QPainter>
#include<QResizeEvent>
#include<QPainterPath>
#define SpaceWidth() (_xOffset + m_profileRect.width() + 5 * m_textMargin)
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
	setFont(QFont("楷体", 18));

	//头像矩形
	m_profileRect.setSize(QSize(42,42));
}

void SChatBubble::setMessage(const ContactsInfo* info, const SChatMessage* msg, SChatBubble::BubbleType type)
{
	m_contacts = info;
	m_msg = msg;
	m_type = type;

	setText(m_msg->msgText());
}
int  SChatBubble::textHeight()const
{
	return this->fontMetrics().boundingRect(QRect(), Qt::AlignLeft, m_msg->msgText()).height();
}

void SChatBubble::paintEvent(QPaintEvent* ev)
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::RenderHint::Antialiasing);

	if (m_type == BubbleType::BubbleTime)
	{

	}
	else
	{
		painter.setPen(Qt::PenStyle::NoPen);
		painter.setBrush(QColor(60, 172, 213));

		//绘制头像	
		painter.drawPixmap(m_profileRect, m_contacts->profile_);

		//绘制气泡
		painter.drawRoundedRect(m_bubbleRect, 10, 10);

		//绘制三角形
		painter.drawPolygon(m_points);

		painter.setPen(Qt::GlobalColor::red);
		painter.setBrush(Qt::BrushStyle::NoBrush);
		painter.drawRect(m_textRect);
	}

	QLabel::paintEvent(ev);
}

void SChatBubble::resizeEvent(QResizeEvent* ev)
{
	updateTextRect();
	updateBubbleSize();
}

void SChatBubble::updateBubbleSize()
{
	if (m_type == SChatBubble::BubbleLeft)
	{
		m_profileRect.moveTopLeft(QPoint(_xOffset, _yOffset));

		m_bubbleRect = m_textRect.adjusted(-m_textMargin, -m_textMargin, m_textMargin, m_textMargin);
		
		m_points.clear();
		m_points.append(QPointF(m_bubbleRect.x(), m_bubbleRect.y() + 21 - 6));
		m_points.append(QPointF(m_bubbleRect.x(), m_bubbleRect.y() + 21 + 12 - 6));
		m_points.append(QPointF(m_bubbleRect.x() - 6, m_bubbleRect.y() + 21));

	}
	else if (m_type == SChatBubble::BubbleRight)
	{
		m_profileRect.moveTopRight(QPoint(width() - _xOffset, _yOffset));
		
		m_bubbleRect = m_textRect.adjusted(-m_textMargin, -m_textMargin, m_textMargin, m_textMargin);
		
		m_points.clear();
		m_points.append(QPointF(m_bubbleRect.right(), m_bubbleRect.y() + 21 - 6));
		m_points.append(QPointF(m_bubbleRect.right(), m_bubbleRect.y() + 21 + 12 - 6));
		m_points.append(QPointF(m_bubbleRect.right() + 6, m_bubbleRect.y() + 21));
		
	}

	setFixedHeight(m_bubbleRect.height() + 1 * m_textMargin);

	setContentsMargins(
		m_textRect.x(),
		m_textRect.y(),
		width() - (m_textRect.right() + 1),
		height() - (m_textRect.bottom() + 1)
	);
}

void SChatBubble::updateTextRect()
{
	auto fm = this->fontMetrics();
	auto bRect = fm.boundingRect(QRect(), Qt::AlignLeft, m_msg->msgText());

	//m_textRect = rect();
	if (m_type == SChatBubble::BubbleLeft)
	{
		m_textRect.moveTopLeft(QPoint(
				_xOffset + m_profileRect.width() + 3 * m_textMargin,
				_yOffset + m_textMargin
			));

		if (bRect.width() <= width() - SpaceWidth())
		{
			m_textRect.setSize(bRect.size());
		}
		else
		{
			m_textRect.setWidth(width() - SpaceWidth());
			m_textRect.setHeight(realLineNumber() * fm.lineSpacing() + fm.lineSpacing() / 2);
		}
	}
	else if (m_type == SChatBubble::BubbleRight)
	{
		if (bRect.width() <= width() - SpaceWidth())
		{
			m_textRect.setX(width() - bRect.width() - m_profileRect.width() - 3 * m_textMargin);
			m_textRect.setY(_yOffset + m_textMargin);;
			m_textRect.setSize(bRect.size());
		}
		else
		{
			m_textRect.setX(_xOffset + 2 * m_textMargin);
			m_textRect.setY(m_textMargin);

			m_textRect.setWidth(width() - SpaceWidth());
			m_textRect.setHeight(realLineNumber() * fm.lineSpacing() + fm.lineSpacing() / 2);
		}
	}
}

QList<int> SChatBubble::textWidthList()const
{
	QList<int> list;
	auto fm = this->fontMetrics();

	qsizetype lineFeedpos = 0;		////\n的位置
	QString tstr = m_msg->msgText();
	for (int i = 0; i < tstr.length(); i = lineFeedpos + 1)
	{
		lineFeedpos = tstr.indexOf("\n", i);
		//最后不是\n，需要补加一行
		if (lineFeedpos == -1)
		{
			int curLineW = fm.boundingRect(QRect(), Qt::AlignLeft, tstr.mid(i)).width();
			list.append(curLineW);
			break;
		}
		else
		{
			int curLineW = fm.boundingRect(QRect(), Qt::AlignLeft, tstr.mid(i, lineFeedpos - i)).width();
			list.append(curLineW);
		}


	}
	return list;
}

int SChatBubble::lineNumber() const
{
	return 	textWidthList().size();
}

int SChatBubble::realLineNumber() const
{
	auto list = textWidthList();
	int nLine = list.size();

	for (auto w : list)
	{
		auto num = w / m_textRect.width();
		//只有一行
		if (num == 0)
		{

		}
		//多出一行(一行太长，容纳不下了，就换行了，就多了一行)
		else
		{
			nLine += num;
		}
	}
	return nLine;
}
