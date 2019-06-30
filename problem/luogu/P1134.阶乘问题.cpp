#include <iostream>  
#include <string>

using namespace std;

//清除前缀0，如果结果是空字符串则设为0 
inline void clear(string& a){
    while(a.length()>0 && a[0]=='0')
        a.erase(0, 1);
    if(a == "")
        a = "0";
}

//如果a>=b则返回真（如果包含前缀零会被消除） 
bool isBigger(string a, string b){
    clear(a);
    clear(b);
    if(a.length() > b.length())
        return true;
    if(a.length()==b.length() && a>=b)
        return true;
    return false; 
}

//两个高精度正整数加法 a+b 
string stringAddString(string a, string b){
    //1、对位，将两个数补零直到其具有相同长度 
    while(a.length() < b.length())         
        a = '0' + a;
    while(a.length() > b.length())
        b = '0' + b; 
    //2、补零，在开头再加一个0以便进位
    a = '0' + a;
    b = '0' + b;
    //3、从低位开始相加，注意进位
    for(int i=a.length()-1; i>=0; i--){
        a[i] = a[i] + b[i] - '0';
        if(a[i] > '9'){
            a[i] = a[i] - 10;
            a[i-1] += 1;
        }
    } 
    clear(a);
    return a;  
}

//两个高精度正整数乘法 a*b
//依赖加法 
string stringMultString(string a, string b){
    string result = "0";
    if(a.length() < b.length()){
        string buf = a;
        a = b;
        b = buf;
    } 
    //多位数乘一位数可以直接使用加法
    //多位数乘以形如d*10^n的数可以转化为多位数乘以一位数 
    //多位数乘以多位数可以转化为若干个多位数乘以一位数相加
    for(int i=b.length()-1; i>=0; i--){
        for(int j=0; j<b[i]-'0'; j++){
            result = stringAddString(result, a);
        }
        a = a + '0';
    }
    clear(result);
    return result; 
}

int main() {
	string n;
    cin >> n;
    string r = "1";
	for (string i = "2"; isBigger(n, i); i = stringAddString(i, "1")) r = stringMultString(r, i);
	for (int j = r.length() - 1; j >= 0; j--) {
		if (r[j] != '0') {
			cout << r[j];
			return 0;
		}
	}
	cout << r;
    return 0;
}
