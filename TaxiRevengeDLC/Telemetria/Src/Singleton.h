#pragma once

template <typename T>
class Singleton
{
public:

	Singleton(){}
	inline static T* getInstance() { return instance; }
	static void deleteInstance();

protected:
	static T* instance;

};


template<typename T>
inline void Singleton<T>::deleteInstance()
{
	delete Singleton<T>::instance;
	Singleton<T>::instance = nullptr;
}
