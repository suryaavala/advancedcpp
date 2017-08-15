#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <list>
#include <map>

int main() {
	std::string s = "one";
	std::string t = "two";
	std::string u = "three";
	std::vector<std::string> sVec;
	sVec.push_back(s);
	sVec.push_back(t);
	sVec.push_back(u);
	
	std::array<int, 3> iArray = {1,2,3};
	
	std::sort(sVec.begin(),sVec.end());
	std::sort(iArray.begin(),iArray.end());
	
	std::list<int> iList;
	std::back_insert_iterator<std::list<int>> iListItr(iList);
	
	for (auto itr = iArray.begin(); itr < iArray.end(); itr++) {
		*iListItr = *itr * -1;
	}
	
	iList.sort();
	
	std::map<std::string,int> stringIntMap;

	int i;
	for (auto j = iList.begin(); j != iList.end(); j++) {
		stringIntMap.insert(std::pair<std::string,int>(sVec[i],(*j)));
		i++;
	}
	
	for (auto p : stringIntMap) {
		std::cout << p.first << " " << p.second << std::endl;
	}
	
	
}
