#include<iostream>
using namespace std;

int objCount = 0;

class Rational
{
private:
	int num, den;//���ӣ���ĸ
public:
	Rational(int num = 0,int den = 1)//��ʼ���ӷ�ĸ Ĭ�Ϲ��캯��
	{
		cout << "newCount" << endl;
		objCount += 1;
	}
	
	Rational(Rational &a)
	:num(a.num),den(a.den)
	{
		cout << "copyCount" << endl;
	}

	~Rational()
	{
		cout << "Discount" << endl;
		objCount -= 1;
	}


	void Set(int x, int y)//�趨���ӷ�ĸ
	{	
		num = x;
		den = y;
	}

	void print()//���x/y
	{
		if (num == 0 || den == 0) {

		}
		else {
			cout << num << "/" << den << endl;
		}
		
	}

	double ToDec()//ת����С��
	{
		double dec = num / den;
		return dec;
	}

	void simple()//����
	{
		int temp;
		int x = num, y = den;
		while (temp = x % y)//շת�����
		{
			x = y;
			y = temp;
		}
		den /= y;
		num /= y;
		if (den < 0) {
			den = -den;
			num = -num;
		}
	}

public:
	Rational plus(const Rational &r1, const Rational &r2)
	{
		Rational r;
		r.num = r1.num*r2.den + r2.num*r1.den;
		r.den = r1.den*r2.den;
		r.simple();
			cout<<"��ǰ��������"<<objCount<<endl;
		return r;
	}

	Rational sub(const Rational &r1, const Rational &r2)
	{
		Rational r;
		r.num = r1.num*r2.den - r2.num*r1.den;
		r.den = r1.den*r2.den;
		r.simple();
			cout<<"��ǰ��������"<<objCount<<endl;
		return r;
	}

	Rational mult(const Rational &r1, const Rational &r2)
	{
		Rational r;
		r.num = r1.num*r2.num;
		r.den = r1.den*r2.den;
		r.simple();
			cout<<"��ǰ��������"<<objCount<<endl;
		return r;
	}

	Rational div(const Rational &r1, const Rational &r2)
	{
		Rational r;
		if (r2.num == 0 || r2.den == 0)
		{
			cout << "��ĸ����Ϊ0" << endl;
		}
		else {
			r.num = r1.num*r2.den;
			r.den = r2.num*r1.den;
		}
		r.simple();
			cout<<"��ǰ��������"<<objCount<<endl;
		return r;
	}
};

int main()
{
	Rational r1;
	
	r1.Set(1,2);
	cout<<"��ǰ��������"<<objCount<<endl;
	
	Rational r2(r1);
	Rational r;
	
	cout<<"��ǰ��������"<<objCount<<endl;
	
	r = r.plus(r1, r2);
	r.print();

	cout<<"��ǰ��������"<<objCount<<endl;

	getchar();
	getchar();
	return 0;
}

