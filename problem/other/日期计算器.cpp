#include<iostream>
using namespace std;
 
class Date
{
public:
	//构造函数
	Date(int year=2018, int month=8, int day=16)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//析构函数
	~Date()
	{
 
	}
	//拷贝构造函数
	Date(const Date& d)//必须传引用，传值会引发无穷递归调用
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值重载
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}
	//打印输出
	void showDate()
	{
		cout << "原来的日期：" << _year << "-" << _month << "-" << _day << endl;
	}
 
	void showDate1()
	{
		cout << "加上指定天数：" << _year << "-" << _month << "-" << _day<<endl;
	}
	void showDate2()
	{
		cout << "减去指定天数：" << _year << "-" << _month << "-" << _day << endl;
	}
 
	void showDate3()
	{
		cout << "加等指定天数：" << _year << "-" << _month << "-" << _day << endl;
	}
 
	void showDate4()
	{
		cout << "减等指定天数：" << _year << "-" << _month << "-" << _day << endl;
	}
	void showDate5()
	{
		cout << "前置++：" << _year << "-" << _month << "-" << _day << endl;
	}
	void showDate6()
	{
		cout << "后置++：" << _year << "-" << _month << "-" << _day << endl;
	}
	void showDate7()
	{
		cout << "前置--：" << _year << "-" << _month << "-" << _day << endl;
	}
	void showDate8()
	{
		cout << "后置--：" << _year << "-" << _month << "-" << _day << endl;
	}
	void showDate9()
	{
		cout << "要比较的日期：" << _year << "-" << _month << "-" << _day << endl;
	}
 
	bool operator ==(const Date& d)//判断两个日期相等
	{
		return _year == d._year
			&&_month == d._month
			&&_day == d._day;
	}
	bool operator !=(const Date& d)//判断两个日期不相等
	{
		return !(*this == d);
	}
	bool operator>(const Date& d) // > 
	{
		if ((_year > d._year) || (_year ==d._year&&_month > d._month) || (_year ==d._year&&_month == d._month&&_day > d._day))
		{
			return true;
		}
		return false;
	}
	bool operator>=(const Date& d)// >= 
	{
		return ((*this == d) || *this > d);
	}
	bool operator<(const Date& d) // <
	{
		if ((_year <d._year) || (_year ==d._year&&_month <d._month) || (_year == d._year&&_month ==d._month&&_day < d._day))
		{
			return true;
		}
		return false;
	}
	bool operator<=(const Date& d) //<=
	{
		return ((*this == d) || *this > d);
	}
 
	//是否是润年
	bool IsLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
 
	int GetDayByYearAndMonth(int year, int month)//判断返回的月份的天数
	{
		int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (IsLeapYear(year) && month == 2)
		{
			return 29;
		}
		else{
			return MonthDay[month];
		}
	}
 
 
	//日期加上天数，并不会改变原来的日期值
	Date operator+(int dayNum)
	{
		if (_day<0)
		{
			return *this -(-_day);
		}
		Date tmpDate(*this);//拷贝this指针
		tmpDate._day += dayNum;
		while (tmpDate._day > GetDayByYearAndMonth(_year, _month))
		{
			tmpDate._day = tmpDate._day -GetDayByYearAndMonth(tmpDate._year,tmpDate._month);
			tmpDate._month += 1;
			if (tmpDate._month > 12)
			{
				++tmpDate._year;
				tmpDate._month = 1;
			}
		}
		return tmpDate;
 
	}
	Date& operator+=(int days)// +=,会改变原来的值，进而在原来的值上面继续加指定的天数
	{
		_day += days;
		while (_day > GetDayByYearAndMonth(_year, _month))
		{
			_day =_day - GetDayByYearAndMonth(_year,_month);
			_month += 1;
			if (_month > 12)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}
	Date& operator++() //前置++
	{
		*this += 1;
		return *this;
	}
	Date operator++(int)//后置++ 
	{
		Date tmpDate(*this);
		*this += 1;
		return *this;
	}
	//日期减去天数，并不会改变原来的日期值
		Date operator-(int dayNum)
	{
			Date tmpDate(*this);
			tmpDate._day -= dayNum;
			while (tmpDate._day <0)
			{
				tmpDate._month -= 1;
				if (tmpDate._month <= 0)
				{
					--tmpDate._year;
					tmpDate._month = 12;
				}
				tmpDate._day += GetDayByYearAndMonth(tmpDate._year,tmpDate._month) ;
			}
			return tmpDate;
	}
		Date& operator-=(int dayNum)//-=,会改变原来的值，进而在原来的值上面继续减指定的天数
		{
			_day -= dayNum;
			while (_day <0)
			{
				_month -= 1;
				if (_month <= 0)
				{
					--_year;
					_month = 12;
				}
				_day += GetDayByYearAndMonth(_year,_month);
			}
			return *this;
		}
		Date& operator--()//前置– 
		{
			*this -= 1;
			return *this;
		}
		Date operator--(int)//后置 –
		{
			Date tmpDate(*this);//先对*this进行拷贝
			*this -= 1;
			return *this;
		}
		int operator-( const Date& d) // 两个日期相隔天数 
		{
			Date big(*this);
			Date small(d);
			int day = 0;
			int flags = 1;
			if (big <small)
			{
				small = *this;
				big = d;
				flags *= -1;
			}
			
			while (small != big)
			{
				small =small+1;
				++day;
			}
			
			return day*flags;
		}
	
		
		
	
 
private://私有成员变量
	int _year;
	int _month;
	int _day;
};
 
 
int main()
{
	Date d1(2018,1,1);
	d1.showDate();
	Date d2;
	d2 = d1 + 66;
	d2.showDate1();
	d2 = d1 + 1;
	d2.showDate1();
	Date d3;
	d3 = d1 - 20;
	d3.showDate2();
	Date d4;
	d4+=10;
	d4.showDate3();
	d4 += 10;
	d4.showDate3();
	Date d5;
	d5 -= 10;
	d5.showDate4();
	d5-= 10;
	d5.showDate4();
 
	Date d6;
	++d6;
	d6.showDate5();
	Date d7;
	d7++;
	d7.showDate6();
 
	Date d8;
	d8--;
	d8.showDate7();
	Date d9;
	d9--;
	d9.showDate8();
 
	Date d10(2018, 8, 18);
	d10.showDate9();
	cout << "(d1 < d10):是否小于(1:表示小于 0表示：大于等于):"<<(d1 < d10) << endl;
	
	Date d11(2018,1,1);
	d11.showDate9();
	cout <<"(d1 > d10):是否大于(1:表示大于 0表示小于等于)"<< (d1 > d10) << endl;
	Date d12(2018,8,18);
	d12.showDate9();
	cout <<"(d1 >= d10):是否大于等于(0:表示小于 1表示：大于等于)"<< (d1 >= d10) << endl;
	Date d13(2018,10,1);
	d13.showDate9();
	cout <<"(d1 <= d10):是否小于等于(1:表示小于等于 0表示：大于)"<< (d1 <= d10) << endl;
	Date d14(2018,1,2);
	d14.showDate();
	cout << "两个日期相距天数：" <<(d1-d14) << endl;
	system("pause");
	return 0;
}

