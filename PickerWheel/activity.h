#pragma once
#include <iostream>

class Activity {
	std::string m_title;
public:
	explicit Activity(std::string);
	std::string getTitle() const;
};

