#ifndef SINGLETON_H
#define SINGLETON_H
template <class SINGLETON>
class  Singleton
{
public:
	Singleton() {
		m_pInstance = static_cast<SINGLETON *>(this);
	}

	~Singleton() {
		m_pInstance = 0;
	}

	static Singleton * CreateInstance() {
		return IsInstantiated() ? GetInstance() : new Singleton;
	}
	static void			DestroyInstance() { if (IsInstantiated()) delete SINGLETON::GetInstance(); m_pInstance = 0; }
	static SINGLETON*	GetInstance() { return m_pInstance; }
	static bool			IsInstantiated() { return m_pInstance ? true : false; }

protected:
	static SINGLETON*	m_pInstance;
};

template <class SINGLETON> SINGLETON*	Singleton<SINGLETON>::m_pInstance = 0;
#endif
