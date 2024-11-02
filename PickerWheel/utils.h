#pragma once
#include <iostream>
#include "activitylist.h"

void print(ActivityList const&);
void spin(ActivityList const&);
void removeSpaces(std::string&);
void readCommand(ActivityList&, std::string&, bool&);
void read(ActivityList&, std::string&, char&, bool&);
int exec();