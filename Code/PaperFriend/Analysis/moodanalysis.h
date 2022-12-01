#ifndef MOODANALYSIS_H
#define MOODANALYSIS_H

#include "DataAnalysis.h"


#include <vector>
#include <string>
#include <math.h>
#include <vector>

class MoodAnalysis : public DataAnalysis{
public:
    bool alert_depression(int n, int m);
    std::string suggestion();  // text that will be suggested to user daily
private:
    std::vector<Variables> item_priority();

private:
};



#endif // MOODANALYSIS_H
