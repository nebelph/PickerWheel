#include "activitylist.h"

ActivityList::ActivityList() {

}

ActivityList::ActivityList(ActivityList const&) {

}

ActivityList& ActivityList::instance() {
	static ActivityList al;
	return al;
}

bool ActivityList::contains(std::string const& title) const {
	for (auto const& i : m_list)
		if (i.getTitle() == title)
			return true;
	return false;
}

int ActivityList::find(std::string const& title) const {
	for (int i = 0; i < m_list.size(); i++)
		if (m_list.at(i).getTitle() == title) return i;
	return -1; // not found
}

size_t ActivityList::size() const {
	return m_list.size();
}

Activity ActivityList::at(size_t const& i) const {
	return m_list.at(i);
}

void ActivityList::add(std::string const& title) {
	if (!contains(title))
		m_list.push_back(Activity(title));
}

void ActivityList::clear() {
	m_list.clear();
}

void ActivityList::remove(std::string const& title) {
	int index = find(title);
	if (index != -1)
		m_list.erase(m_list.begin() + index);
}