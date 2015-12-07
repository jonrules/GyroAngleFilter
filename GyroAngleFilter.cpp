#include <GyroAngleFilter.h>
#include <Arduino.h>
#include <math.h>

template <class T>
GyroAngleFilter<T>::GyroAngleFilter(void)
{

};

template <class T>
GyroAngleFilter<T>::~GyroAngleFilter(void)
{
	
};

template <class T>
void GyroAngleFilter<T>::init(T initialValue)
{
	_lastResult = initialValue;
	_lastTime = millis();
};

template <class T>
float GyroAngleFilter<T>::getCorrectionFactor(void)
{
	return _correctionFactor;
};

template <class T>
void GyroAngleFilter<T>::setCorrectionFactor(float correctionFactor)
{
	_correctionFactor = correctionFactor;
	_primaryFactor = 1.0 - correctionFactor;
};

template <class T>
unsigned long GyroAngleFilter<T>::getSampleTime(void)
{
	return _sampleTime;
};

template <class T>
void GyroAngleFilter<T>::setSampleTime(unsigned long sampleTime)
{
	_sampleTime = sampleTime;
};

template <class T>
T GyroAngleFilter<T>::getLastResult(void)
{
	return _lastResult;
};

template <class T>
unsigned long GyroAngleFilter<T>::getLastTime(void)
{
	return _lastTime;
};

template <class T>
T GyroAngleFilter<T>::calculate(T velocity, T correctionValue)
{
	unsigned long time = millis();
	long dt = time - _lastTime;
	if (dt < _sampleTime)
	{
		return _lastResult;
	}
	T primaryResult = _lastResult + velocity*dt;
	_lastResult = primaryResult*_primaryFactor - correctionValue*_correctionFactor;
	_lastTime = time;
	return _lastResult;
};



template class GyroAngleFilter<char>;
template class GyroAngleFilter<int>;
template class GyroAngleFilter<long>;
template class GyroAngleFilter<long long>;
template class GyroAngleFilter<float>;
template class GyroAngleFilter<double>;

