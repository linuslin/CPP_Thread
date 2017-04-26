
#ifndef __VOLATILITY_MONITOR_H__
#define __VOLATILITY_MONITOR_H__

#include <vecctor>


struct VolatilityData{
	double m_data;
	bool m_isOutlier;
	VolatilityData(double data,bool isOutlier):m_data(data),m_isOutlier(isOutlier){}
};

class VolatilityMonitor{
	std::vector<double> m_data;
	double m_avgRatio;
	double m_preRatio;
	unsigned m_meetTimes;
	double m_lastAvg;
	unsigned int removeCount;


	bool isMeetCondition();

    public:

	void print();
	VolatilityMonitor(double avg,double avgRatio,double preRatio,unsigned int times);
	int avg(double & reslt, unsigned int rmCount=0,std::vector<VolatilityData>& resultData=null);
	int push(double data);
	
};


#endif //__VOLATILITY_MONITOR_H__
