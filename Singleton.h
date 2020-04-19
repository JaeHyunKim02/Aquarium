#pragma once
template<typename T>//�𸣰���
//�̱����̶� Ŭ������ ���������� ����ϰ� ����� �ִ°��� �ǹ��Ѵ�.
class Singleton
{
private:
	//Ŭ���� ���� ������ static�� ����ϰ� �Ǹ�
	//Ŭ������ ���� ������ �ʾƵ� ������ ���� ��������� �ȴ�.
	static T* p;//T��� ������ p

public:
	Singleton() {};
	virtual ~Singleton() {};

	static T* GetInstance() {//Ŭ������ ������ ������
		if (!p)
			p = new T;
		return p;
	}
	//�Լ��� static�� ����ϰ� �Ǹ�
	//Ŭ������ ��� Ŭ���� �̸������� �Լ��� ����� �� �ְ� �ȴ�

	static void Resetinstance() {//����
		if (p)
			delete p;
		p = nullptr;
	}
	
};

template<typename T>
T* Singleton<T>::p = nullptr;//�ʱ�ȭ
//����ƽ ������ ���ο��� �ʱ�ȭ�� ���ϰ�, Ŭ���� �ܺο��� �ѹ� �ʱ�ȭ ���־�� �Ѵ�.
