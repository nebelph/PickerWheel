#include "activity.h"

Activity::Activity(std::string title) : m_title(title) {}

std::string Activity::getTitle() const {
	return m_title;
}