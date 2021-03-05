/*
 * CDatabase.h
 *
 *  Created on: Mar 4, 2021
 *      Author: reza
 */

#ifndef CDATABASE_H_
#define CDATABASE_H_
#include <map>
#include <iostream>

template <class CONTENT>
class CDatabase {
public:
	typedef std::map<std::string, CONTENT> Point_map;
	CDatabase();
	void add(std::string name, CONTENT const&  element);
	CONTENT* get(std::string name);
	Point_map const & getReferenceToMap() const;
	void print();
	void clearDb();
//	virtual ~CDatabase();
private:
	Point_map m_data;
};

template<class CONTENT>
inline CDatabase<CONTENT>::CDatabase(){
	m_data.clear();
}

template<class CONTENT>
inline void CDatabase<CONTENT>::add(std::string name, CONTENT const&  element){
	m_data.insert(std::pair<std::string, CONTENT> (name, element));
}

template<class CONTENT>
inline CONTENT* CDatabase<CONTENT>::get(std::string name) {
	CONTENT* PtrToPoint = NULL;
	for(auto& point: m_data)
	{
		if(point.first == name)
		{
			PtrToPoint=&point.second;
			break;
		}

	}
	PtrToPoint->print();
	return PtrToPoint;
}

template<class CONTENT>
inline std::map<std::string, CONTENT>const & CDatabase<CONTENT>::getReferenceToMap() const {
	return m_data;
}

template<class CONTENT>
inline void CDatabase<CONTENT>::clearDb(){
	 m_data.clear();
}

template<class CONTENT>
inline void CDatabase<CONTENT>::print(){
	 for(auto point:m_data){
//		 point.second.print();
		 std::cout << point.second;
	 }
}


#endif /* CDATABASE_H_ */
