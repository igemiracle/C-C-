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
		cout << "Count" << endl;
		objCount += 1;
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
		return r;
	}

	Rational sub(const Rational &r1, const Rational &r2)
	{
		Rational r;
		r.num = r1.num*r2.den - r2.num*r1.den;
		r.den = r1.den*r2.den;
		r.simple();
		return r;
	}

	Rational mult(const Rational &r1, const Rational &r2)
	{
		Rational r;
		r.num = r1.num*r2.num;
		r.den = r1.den*r2.den;
		r.simple();
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
		return r;
	}
};

int main()
{
	Rational r1, r2;
	Rational r;
	int num1, den1, num2, den2;

	cout << "���趨���ӷ�ĸ" << endl;
	cin >> num1 >> den1;
	r1.Set(num1, den1);
	r1.print();

	cout << "���趨���ӷ�ĸ" << endl;
	cin >> num2 >> den2;
	r2.Set(num2, den2);
	r2.print();


	r = r.plus(r1, r2);
	r.print();

	r = r.sub(r1, r2);
	r.print();

	r = r.mult(r1, r2);
	r.print();

	r = r.div(r1, r2);
	r.print();


	getchar();
	getchar();
	return 0;
}
