#include <iostream>
#include <algorithm>
using namespace std;


class rectangle
{
private:
	int x1, y1, x2, y2;//A(x1,y1),B(x2,y1),C(x2,y2),D(x1,y2)

public:
	void set(int x1, int y1, int x2, int y2)
	{
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
	}

	int area()
	{
		int s;
		s = (x1 - x2)*(y1 - y2);
		if (s < 0)
		{
			s = -s;
		}
		return s;
	};

	bool equal(rectangle d)
	{
		if ((d.x1-d.x2)!=(this->x1-this->x2)||
			(d.y1-d.y2)!=(this->y1-this->y2))
			return false;
		return true;
	};

	void setright(int x2,int y2)
	{
		this->x2 = x2;
		this->y2 = y2;
	}

	void move(int vx, int vy)
	{
		x1 += vx;
		x2 += vx;
		y1 += vy;
		y2 += vy;
	}

	void coincide(rectangle c, rectangle d)
	{
		x1 = max(c.x1, d.x1);
		y1 = max(c.y1, d.y1);
		x2 = min(c.x2, d.x2);
		y2 = min(c.y2, d.y2);
		if ((x1 <= x2) && (y1 <= y2))
			cout << "�������ص�" << endl;
		else {
			cout << "�����β��ص�" << endl;
		}
	}

	void print()
	{
		cout << "Ŀǰ���ε�����" << endl;
		cout << "(" << x1 << "," << y1 <<")" << endl;
		cout << "(" << x2 << "," << y2 << ")" << endl;

	}

};



void scanf(int &x1, int &y1, int &x2, int &y2)
{
	cout << "����������Ͻ����½����꣺ ���Ͻ�(x1,y1)" << endl;
	cin >> x1 >> y1;
	cout << "���½ǣ�x2,y2��" << endl;
	cin >> x2 >> y2;

}


int main()
{
	rectangle c;
	rectangle d;
	rectangle e;
	int x1, x2, y1, y2;
	int x3, y3, x4, y4;
	scanf(x1, y1, x2, y2);
	scanf(x3, y3, x4, y4);

	c.set(x1, y1, x2, y2);
	d.set(x3, y3, x4, y4);

	//��������
	cout << "��������ǣ�" << c.area() << endl;

	//�жϾ��δ�С���
	if (c.equal(d)==true)
	{
		cout << "�����������" << endl;
	}
	else {
		cout << "�������β���" << endl;
	}

	//������δ�С
	int x2new, y2new;
	cout << "�������µ����½����꣺" << endl;
	cin >> x2new >> y2new;
	c.setright(x2new,y2new);
	c.print();

	//�ƶ�����
	int vx, vy;
	cout << "������λ��������" << endl;
	cin >> vx >> vy;
	c.move(vx, vy);
	c.print();

	//���������ص�����
	e.coincide(c,d);
	e.print();

	getchar();
	getchar();
	return 0;
}