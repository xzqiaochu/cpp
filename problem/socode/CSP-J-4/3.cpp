// CSP-J-C 周一杀
// author: xzqiaochu
// status: AC
// time: 2019/10/26
#include <cstdio>

const int m_31[] = {1, 3, 5, 7, 8, 10, 12};

struct Date
{
	int y, m, d, w; // y年，m月，d日，w星期 
};

Date p, e, ori;
int ans;

bool isSp(Date &D) // 判断闰年 
{
	if ((D.y % 4 == 0 && D.y % 100 != 0) || D.y % 400 == 0)
		return true;
	else
		return false;
}

bool is31(Date &D) // 判断当前月是否是31天 
{
	for (int i = 0; i < 7; i++)
		if (D.m == m_31[i])
			return true;
	return false;
}

void addY(Date &D)
{
	D.y++;
}

void addM(Date &D)
{
	if (D.m == 12) // 当前是12月 
		D.m = 1, addY(D);
	else
		D.m++; 
}

void addD(Date &D)
{
	bool f = true;
	if (D.m == 2) // 当前是二月
		if (isSp(D) && D.d == 29) // 闰年29天 
			D.d = 1, addM(D), f = false; 
		else if (!isSp(D) && D.d == 28) // 非闰年28天 
			D.d = 1, addM(D), f = false;
	if (D.m != 2) // 不是二月
		if (is31(D) && D.d == 31)
			D.d = 1, addM(D), f = false;
		if (!is31(D) && D.d == 30)
			D.d = 1, addM(D), f = false;
	if (f)
		D.d++; 
	// 以下是星期处理
	if (D.w == 7)
		D.w = 1;
	else
		D.w++; 
}

bool isEnd()
{
	if (p.y == e.y && p.m == e.m && p.d == e.d)
		return true;
	else
		return false;
}

bool initOK()
{
	if (p.y == ori.y && p.m == ori.m && p.d == ori.d)
		return true;
	else
		return false;
}

void init()
{
	ori.y = 1900, ori.m = 1, ori.d = 1, ori.w = 1;
	while (true)
	{
		if (initOK())
		{
			p.w = ori.w;
			return;
		}
		addD(ori);
	}
}

bool check()
{
	if (p.d == 1 && p.w == 1)
		return true;
	else
		return false; 
}

void calc()
{
	while (true)
	{
		if (isEnd())
		{
			if (check())
				ans++;
			return;
		}
		if (check())
			ans++;
		addD(p);
	} 
}

int main()
{
	scanf("%d-%d-%d", &p.y, &p.m, &p.d);
//	init();
//	printf("%d-%d-%d-%d", p.y, p.m, p.d, p.w);
	scanf("%d-%d-%d", &e.y, &e.m, &e.d);
	init();
	calc();
	printf("%d\n", ans);
	return 0;
}
