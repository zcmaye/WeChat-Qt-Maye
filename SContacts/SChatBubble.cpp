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
	setFont(QFont("楷体", 18));
}

void SChatBubble::setMessage(const ContactsInfo* info, const SChatMessage* msg, SChatBubble::BubbleType type)
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
		painter.drawPixmap(m_profileRect, m_contacts->profile_);

		//绘制气泡
		painter.drawRoundedRect(m_bubbleRect, 10, 10);

		//绘制三角形
		painter.drawPolygon(m_points);

		painter.setPen(Qt::GlobalColor::red);
		painter.setBrush(Qt::BrushStyle::NoBrush);
		painter.drawRect(m_textRect);

		painter.setPen(Qt::GlobalColor::green);
		painter.drawRect(m_textRect1);
		

	}

	QLabel::paintEvent(ev);
}

void SChatBubble::resizeEvent(QResizeEvent* ev)
{
	updateSize();
	updateTextRect();
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
		qInfo() << tstr.mid(i, lineFeedpos - i) << curLineW;
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
		m_profileRect = { 0,0,42,42 };

		//如果能完全展示
		if (m_bubbleRect.width() + 2 * m_textMargin + m_profileRect.width() <= width())
		{
			m_bubbleRect =
			{
					m_profileRect.right() + 2 * m_textMargin,
					0,
					m_textSize.width() + 2 * m_textMargin,
					m_textSize.height() + 2 * m_textMargin
			};
		}
		else
		{

			m_textRect =
			{
				m_bubbleRect.x() + m_textMargin,
				m_textMargin,
				m_bubbleRect.width() - 2 * m_textMargin,
				m_bubbleRect.height() - 2 * m_textMargin
			};

			{
				auto fm = this->fontMetrics();
				int textH = fm.height() + fm.leading();
				int textW = fm.boundingRect(QRect(), Qt::AlignLeft, m_msg->msgText()).width();

				if (textW <= m_textRect.width())
				{
					//m_textRect.setHeight(textH);
				}
				else
				{

					auto list = textWidthList();
					int nLine = list.size();
					qInfo() << "nLine1" << nLine;
					for (auto w : list)
					{
						auto num = w / m_textRect.width() + 0;
						//只有一行
						if (num == 0)
						{

						}
						//多出一行(一行太长，容纳不下了，就换行了，就多了一行)
						else
						{
							nLine += num;
						}
						qInfo() << "num" << num << "   " << w << m_textRect.width();
					}
					qInfo() << "nLine2" << nLine << "height" << m_textRect.height() << fm.height() + fm.leading();
					qInfo() << "totalh" << nLine * textH;
					m_textRect.setHeight(nLine * fm.lineSpacing() + fm.lineSpacing() / 2);

					m_bubbleRect.setWidth(m_textRect.width() + 2 * m_textMargin);
					m_bubbleRect.setHeight(m_textRect.height() + 2 * m_textMargin);
					setFixedHeight(m_bubbleRect.height() + 2 * m_textMargin);
				}

				qInfo() << "else";

			}
		}
		setContentsMargins(
			m_textRect.x(),
			m_textMargin,
			m_textMargin * 2,
			m_textMargin * 2);

		m_points.clear();
		m_points.append(QPointF(m_bubbleRect.x(), m_bubbleRect.y() + 21 - 6));
		m_points.append(QPointF(m_bubbleRect.x(), m_bubbleRect.y() + 21 + 12 - 6));
		m_points.append(QPointF(m_bubbleRect.x() - 6, m_bubbleRect.y() + 21));


	}
	else if (m_type == SChatBubble::BubbleRight)
	{
		m_profileRect = { width() - 42,0,42,42 };

		m_bubbleRect = {
			m_profileRect.left() - m_textSize.width() - 3 * m_textMargin,
			0,
			m_textSize.width() + 2 * m_textMargin ,
			m_textSize.height() + 2 * m_textMargin };

		int left = 0;
		//如果能完全展示
		if (m_bubbleRect.width() + 2 * m_textMargin + m_profileRect.width() <= width())
		{
			//left = m_bubbleRect.x() + m_textMargin;
			m_textRect =
			{
				m_bubbleRect.x() + m_textMargin,
				m_textMargin,
				m_bubbleRect.width() - 2 * m_textMargin,
				m_bubbleRect.height() - 2 * m_textMargin
			};
		}
		else
		{
			m_bubbleRect.setX(m_textMargin);
			m_bubbleRect.setWidth(width() - 2 * m_textMargin - m_profileRect.width());

			m_textRect =
			{
				2 * m_textMargin ,
				m_textMargin,
				m_bubbleRect.width() - 2 * m_textMargin,
				m_bubbleRect.height() - 2 * m_textMargin
			};

			{
				auto fm = this->fontMetrics();
				int textH = fm.height() + fm.leading();
				int textW = fm.boundingRect(QRect(), Qt::AlignLeft, m_msg->msgText()).width();

				if (textW <= m_textRect.width())
				{
					//m_textRect.setHeight(textH);
				}
				else
				{

					auto list = textWidthList();
					int nLine = list.size();
					qInfo() << "nLine1" << nLine;
					for (auto w : list)
					{
						auto num = w / m_textRect.width() + 0;
						//只有一行
						if (num == 0)
						{

						}
						//多出一行(一行太长，容纳不下了，就换行了，就多了一行)
						else
						{
							nLine += num;
						}
						qInfo() << "num" << num << "   " << w << m_textRect.width();
					}
					qInfo() << "nLine2" << nLine << "height" << m_textRect.height() << fm.height() + fm.leading();
					qInfo() << "totalh" << nLine * textH;
					m_textRect.setHeight(nLine * fm.lineSpacing() + fm.lineSpacing() / 2);
				}

				m_bubbleRect.setHeight(m_textRect.height() + 2 * m_textMargin);
				setFixedHeight(m_bubbleRect.height() + 2 * m_textMargin);
			}
		}
		setContentsMargins(
			m_textRect.x(),
			m_textMargin,
			m_profileRect.width() + m_textMargin * 2,
			m_textMargin * 2);

		m_points.clear();
		m_points.append(QPointF(m_bubbleRect.right(), m_bubbleRect.y() + 21 - 6));
		m_points.append(QPointF(m_bubbleRect.right(), m_bubbleRect.y() + 21 + 12 - 6));
		m_points.append(QPointF(m_bubbleRect.right() + 6, m_bubbleRect.y() + 21));

	}

}

QList<int> SChatBubble::textWidthList()
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

void SChatBubble::updateTextRect()
{
	auto fm = this->fontMetrics();
	auto bRect = fm.boundingRect(QRect(), Qt::AlignLeft, m_msg->msgText());
	int textH = fm.lineSpacing();

	m_textRect1 = rect();
	if (m_type == SChatBubble::BubbleLeft)
	{
		if (bRect.width() <= width() - m_profileRect.width() + 2 * m_textMargin)
		{
			m_textRect1 =
			{
				m_profileRect.right() + 3 * m_textMargin,
				m_profileRect.y() + m_textMargin,
				bRect.width(),
				bRect.height()
			};
		}
		else
		{
			auto list = textWidthList();

			int nLine = list.size();

			qInfo() << "nLine1" << nLine;
			for (auto w : list)
			{
				auto num = w / m_textRect1.width() + 0;
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

			m_textRect1 =
			{
				m_profileRect.right() + 3 * m_textMargin,
				m_profileRect.y() + m_textMargin,
				width() - m_profileRect.width() + 3 * m_textMargin,
				nLine * textH + textH / 2
			};
		}
	}
	else if (m_type == SChatBubble::BubbleRight)
	{
		if (bRect.width() <= width() - m_profileRect.width() + 3 * m_textMargin)
		{
			m_textRect1 =
			{
				m_profileRect.left() - bRect.width() - 2 * m_textMargin,
				m_profileRect.y() + m_textMargin,
				bRect.width(),
				bRect.height()
			};
		}
		else
		{
			auto list = textWidthList();

			int nLine = list.size();

			for (auto w : list)
			{
				auto num = w / m_textRect1.width() + 0;
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
			int realW = width() - m_profileRect.width() - 4 * m_textMargin;
			int realH = nLine* fm.lineSpacing() + fm.lineSpacing() / 2;
			m_textRect1 =
			{
				m_profileRect.left() - realW,
				m_profileRect.y() + m_textMargin,
				realW,//width() - m_profileRect.width() + 3 * m_textMargin,
				realH
			};
		}
	}
}
