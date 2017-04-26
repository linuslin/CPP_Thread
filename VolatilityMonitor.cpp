#include "VolatilityMonitor.h"

#include <iostream>
#include <algorithm>


void VolatilityMonitor::print(){
	std::cout<<"[ ";
	for(std::vector<double>::iterator it=this->m_data.begin(); it!=this->m_data.end(); ++it){
		std::cout<<*it<<" ";
	}
	std::cout<<"]"<<std::endl;
}

VolatilityMonitor::VolatilityMonitor(double avg,double avgRatio,double preRatio,unsigned int times)
:m_lastAvg(avg),m_avgRatio(avg),m_preRatio(preRatio),m_meetTimes(times){};

int VolatilityMonitor::avg(double & result, unsigned int rmCount,std::vector<VolatilityData>& resultData){
	if(this->m_data.count()<=0){
		return -1;
	}
	if(this->m_data.cout()<= rmCount*2){
		return -1;
	}

	result=0.0;
	vector<double> tmpData(this->m_data);
	resultData.clear();
	std::sort(tmpData.begin(),tmpData.end());
	int count=0;
	for (std::vector<double>::iterator it=tmpData.begin(); it!=tmpData.end(); ++it,++count){
		if(count<rmCount || count>this->tmpData.size()-rmCount){
			resultData.push_back(VolatilityData(*it,true));
		}else{
			resultData.push_back(VolatilityData(*it,false))
			result+=*it;
		}
	}
	result/=(mpData.size()-rmCount*2);
	
	return 0;
}

bool isMeetCondition(){
	if(this->m_data.size()<=this->m_meetTimes){
		return false;
	}
	int times=0;
	for(std::vector<double>::iterator it=this->m_data.end()-this->m_meetTimes; it!=this->m_data.end(); ++it){
		if((*it)>this->lastAvg *(1+this->m_avgRatio) && (*it)>(*(it-1)*(1+this->m_preRatio))){
			times++;
		}
	}

	
	if (times>=this->m_meetTimes){
		return true;
	}
	return false
}

int VolatilityMonitor::push(double data){
	this->m_data.push_back(data);
	
	return isMeetCondition();
}
