#pragma once
#include <iostream>
#include <vector>
#include "activity.h"

class ActivityList {
	std::vector<Activity> m_list;
	ActivityList();
	ActivityList(ActivityList const&);
public:
	static ActivityList& instance();
	bool contains(std::string const&) const;
	int find(std::string const&) const;
	size_t size() const;
	Activity at(size_t const&) const;
	void add(std::string const&);
	void clear();
	void remove(std::string const&);
};

