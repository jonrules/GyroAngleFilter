#ifndef GyroAngleFilter_h
#define GyroAngleFilter_h

template <class T> 
class GyroAngleFilter
{
	public:
		GyroAngleFilter(void);
		~GyroAngleFilter(void);

		void init(T initialValue);

		float getCorrectionFactor(void);
		void setCorrectionFactor(float correctionFactor);

		unsigned long getSampleTime(void);
		void setSampleTime(unsigned long sampleTime);

		T getLastResult(void);
		unsigned long getLastTime(void);

		T calculate(T velocity, T correctionValue);

	private:
		float _correctionFactor = 0.1;
		float _primaryFactor = 0.9;
		T _lastResult;
		unsigned long _lastTime;
		unsigned long _sampleTime = 100;

};

#endif
