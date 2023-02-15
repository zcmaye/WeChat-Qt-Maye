#include <QApplication>
#include "SMainWindow/SMainWindow.h"
#include "SContacts/SChatBubble.h"
#include "SContacts/ContactsInfo.h"
#include "SContacts/SChatMessage.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SMainWindow w;
    w.show();

	QString str1 = R"(@全体成员 还在担心学习编程没有方向吗？来长风老师的课堂，揭秘核心技术
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

	//	str = R"(1
	//2
	//3
	//4
	//5)";

	//auto contacts = new ContactsInfo("十一期 江涛", "面包会有的，一切都会有的");
	//auto msg = new SChatMessage(str, QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss"));
	//
	//
	//SChatBubble cb;
	//cb.QLabel::setFont(QFont("楷体", 18));
	////cb.setMessage(contacts,msg,SChatBubble::BubbleRight);
	//cb.setMessage(contacts, msg);
	//cb.show();


    return a.exec();
}
