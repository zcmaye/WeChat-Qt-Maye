/*****************************************************************//**
 * \file   SMainWindow.h
 * \brief
 *
 * \author Maye - 顽石老师
 * \date   February 2023
 * \other  微信公众号<C语言Plus> 欢迎关注
 *********************************************************************/

#ifndef SCHATBUBBLE_H_
#define SCHATBUBBLE_H_

#include <QLabel>
class ContactsInfo;
class SChatMessage;
class SChatBubble : public QLabel
{
	Q_OBJECT
public:
	enum BubbleType
	{
		BubbleLeft,
		BubbleRight,
		BubbleTime
	};
	explicit SChatBubble(QWidget* parent = nullptr);
	void init();
	void setMessage(const ContactsInfo* info, const  SChatMessage* msg, SChatBubble::BubbleType type = SChatBubble::BubbleLeft);
	int textHeight()const ;
protected:
	void paintEvent(QPaintEvent* ev)override;
	void resizeEvent(QResizeEvent* ev)override;
	//void mousePressEvent(QMouseEvent* ev) { adjustSize(); };
	void updateBubbleSize();

	void updateTextRect();			//文本输出实际矩形区域
	QList<int> textWidthList()const;
	int lineNumber()const;			//消息文本总行数
	int realLineNumber()const;		//消息文本实际行数(不能完全显示，换行之后的)
private:
	const ContactsInfo* m_contacts = nullptr;
	const SChatMessage* m_msg = nullptr;

	BubbleType	m_type = BubbleRight;
	QRect		m_profileRect;		//头像矩形
	QRect		m_bubbleRect;		//气泡矩形
	QList<QPointF> m_points;		//小三角形
	int			m_textMargin = 12;	//文本距离气泡左边的距离
	QRect		m_textRect;			//文本矩形

	int _xOffset = 0;
	int _yOffset = 0;
};

#endif // !SCHATBUBBLE_H_
