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
	int textHeight()const { return m_textSize.height(); };
protected:
	void paintEvent(QPaintEvent* ev)override;
	void resizeEvent(QResizeEvent* ev)override;
	//void mousePressEvent(QMouseEvent* ev) { adjustSize(); };
	QSize textSize() const;
	void updateSize();
	bool fullDisplay()
	{
		return (m_textSize.width() < width() - bubbleRect.x() - 2 * m_textMargin);
	}
private:
	const ContactsInfo* m_contacts = nullptr;
	const SChatMessage* m_msg = nullptr;

	BubbleType m_type = BubbleRight;
	QRect profileRect;		//头像矩形
	QRect bubbleRect;		//气泡矩形
	QPolygon polygon;		//小三角形
	int m_textMargin = 12;	//文本距离气泡左边的距离
	QSize m_textSize;		//文本尺寸
};

#endif // !SCHATBUBBLE_H_
