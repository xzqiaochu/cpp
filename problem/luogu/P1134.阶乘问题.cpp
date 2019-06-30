#include <iostream>  
#include <string>

using namespace std;

//���ǰ׺0���������ǿ��ַ�������Ϊ0 
inline void clear(string& a){
    while(a.length()>0 && a[0]=='0')
        a.erase(0, 1);
    if(a == "")
        a = "0";
}

//���a>=b�򷵻��棨�������ǰ׺��ᱻ������ 
bool isBigger(string a, string b){
    clear(a);
    clear(b);
    if(a.length() > b.length())
        return true;
    if(a.length()==b.length() && a>=b)
        return true;
    return false; 
}

//�����߾����������ӷ� a+b 
string stringAddString(string a, string b){
    //1����λ��������������ֱ���������ͬ���� 
    while(a.length() < b.length())         
        a = '0' + a;
    while(a.length() > b.length())
        b = '0' + b; 
    //2�����㣬�ڿ�ͷ�ټ�һ��0�Ա��λ
    a = '0' + a;
    b = '0' + b;
    //3���ӵ�λ��ʼ��ӣ�ע���λ
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

//�����߾����������˷� a*b
//�����ӷ� 
string stringMultString(string a, string b){
    string result = "0";
    if(a.length() < b.length()){
        string buf = a;
        a = b;
        b = buf;
    } 
    //��λ����һλ������ֱ��ʹ�üӷ�
    //��λ����������d*10^n��������ת��Ϊ��λ������һλ�� 
    //��λ�����Զ�λ������ת��Ϊ���ɸ���λ������һλ�����
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
