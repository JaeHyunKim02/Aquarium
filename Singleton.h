#pragma once
template<typename T>//모르겠음
//싱글톤이란 클래스를 전역변수와 비슷하게 만들어 주는것을 의미한다.
class Singleton
{
private:
	//클래스 내부 변수에 static을 사용하게 되면
	//클래스를 따로 만들지 않아도 변수가 먼저 만들어지게 된다.
	static T* p;//T라는 포인터 p

public:
	Singleton() {};
	virtual ~Singleton() {};

	static T* GetInstance() {//클래스의 정보를 가져옴
		if (!p)
			p = new T;
		return p;
	}
	//함수에 static을 사용하게 되면
	//클래스가 없어도 클래스 이름만으로 함수를 사용할 수 있게 된다

	static void Resetinstance() {//삭제
		if (p)
			delete p;
		p = nullptr;
	}
	
};

template<typename T>
T* Singleton<T>::p = nullptr;//초기화
//스테틱 변수는 내부에선 초기화를 못하고, 클래스 외부에서 한번 초기화 해주어야 한다.
