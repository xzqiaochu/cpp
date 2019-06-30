#include<iostream>
using namespace std;
 
class Date
{
public:
	//���캯��
	Date(int year=2018, int month=8, int day=16)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//��������
	~Date()
	{
 
	}
	//�������캯��
	Date(const Date& d)//���봫���ã���ֵ����������ݹ����
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//��ֵ����
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
	//��ӡ���
	void showDate()
	{
		cout << "ԭ�������ڣ�" << _year << "-" << _month << "-" << _day << endl;
	}
 
	void showDate1()
	{
		cout << "����ָ��������" << _year << "-" << _month << "-" << _day<<endl;
	}
	void showDate2()
	{
		cout << "��ȥָ��������" << _year << "-" << _month << "-" << _day << endl;
	}
 
	void showDate3()
	{
		cout << "�ӵ�ָ��������" << _year << "-" << _month << "-" << _day << endl;
	}
 
	void showDate4()
	{
		cout << "����ָ��������" << _year << "-" << _month << "-" << _day << endl;
	}
	void showDate5()
	{
		cout << "ǰ��++��" << _year << "-" << _month << "-" << _day << endl;
	}
	void showDate6()
	{
		cout << "����++��" << _year << "-" << _month << "-" << _day << endl;
	}
	void showDate7()
	{
		cout << "ǰ��--��" << _year << "-" << _month << "-" << _day << endl;
	}
	void showDate8()
	{
		cout << "����--��" << _year << "-" << _month << "-" << _day << endl;
	}
	void showDate9()
	{
		cout << "Ҫ�Ƚϵ����ڣ�" << _year << "-" << _month << "-" << _day << endl;
	}
 
	bool operator ==(const Date& d)//�ж������������
	{
		return _year == d._year
			&&_month == d._month
			&&_day == d._day;
	}
	bool operator !=(const Date& d)//�ж��������ڲ����
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
 
	//�Ƿ�������
	bool IsLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
 
	int GetDayByYearAndMonth(int year, int month)//�жϷ��ص��·ݵ�����
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
 
 
	//���ڼ���������������ı�ԭ��������ֵ
	Date operator+(int dayNum)
	{
		if (_day<0)
		{
			return *this -(-_day);
		}
		Date tmpDate(*this);//����thisָ��
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
	Date& operator+=(int days)// +=,��ı�ԭ����ֵ��������ԭ����ֵ���������ָ��������
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
	Date& operator++() //ǰ��++
	{
		*this += 1;
		return *this;
	}
	Date operator++(int)//����++ 
	{
		Date tmpDate(*this);
		*this += 1;
		return *this;
	}
	//���ڼ�ȥ������������ı�ԭ��������ֵ
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
		Date& operator-=(int dayNum)//-=,��ı�ԭ����ֵ��������ԭ����ֵ���������ָ��������
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
		Date& operator--()//ǰ�èC 
		{
			*this -= 1;
			return *this;
		}
		Date operator--(int)//���� �C
		{
			Date tmpDate(*this);//�ȶ�*this���п���
			*this -= 1;
			return *this;
		}
		int operator-( const Date& d) // ��������������� 
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
	
		
		
	
 
private://˽�г�Ա����
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
	cout << "(d1 < d10):�Ƿ�С��(1:��ʾС�� 0��ʾ�����ڵ���):"<<(d1 < d10) << endl;
	
	Date d11(2018,1,1);
	d11.showDate9();
	cout <<"(d1 > d10):�Ƿ����(1:��ʾ���� 0��ʾС�ڵ���)"<< (d1 > d10) << endl;
	Date d12(2018,8,18);
	d12.showDate9();
	cout <<"(d1 >= d10):�Ƿ���ڵ���(0:��ʾС�� 1��ʾ�����ڵ���)"<< (d1 >= d10) << endl;
	Date d13(2018,10,1);
	d13.showDate9();
	cout <<"(d1 <= d10):�Ƿ�С�ڵ���(1:��ʾС�ڵ��� 0��ʾ������)"<< (d1 <= d10) << endl;
	Date d14(2018,1,2);
	d14.showDate();
	cout << "�����������������" <<(d1-d14) << endl;
	system("pause");
	return 0;
}

