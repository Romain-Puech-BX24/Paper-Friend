#include "moodanalysis.h"
//#include "entryclasses.h"

#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <map>



bool MoodAnalysis::alert_depression(){
    /**
    * @param no params
    * @returns whether the mood has been declining over the last few days or not
    */
    int num_days_to_consider = 10;  // These values are just dummy values for now.
    double slope_threshold = -1;

    LinearRegressionCoeffs trend = general_trend(num_days_to_consider, MOOD);
    return trend.slope < slope_threshold;
}

std::multimap<double, Variables> invert(std::map<Variables, double> & mymap){
    /**
    * @param map
    * @returns inversed map (swaps keys with values)
    */
    std::multimap<double, Variables> multiMap;

    std::map<Variables, double> :: iterator it;
    for (it=mymap.begin(); it!=mymap.end(); it++)
    {
        multiMap.insert(std::make_pair(it->second, it->first));
    }

    return multiMap;
}

std::vector<Variables> MoodAnalysis::item_priority(){

    std::vector<double> mood_list = get_vect(log, MOOD);

    std::vector<double> sleep_list = get_vect(log, SLEEP);

    std::vector<double> eating_healthy_list = get_vect(log, EATING_HEALTHY);

    std::vector<double> productivity_list = get_vect(log, PRODUCTIVITY);

    std::vector<double> communications_list = get_vect(log, COMMUNICATIONS);

    std::vector<double> screen_time_list = get_vect(log, SCREEN_TIME);

    //correlations with mood
    double cor_sleep_mood = cor(sleep_list, mood_list);
    double cor_eating_healthy_mood = cor(eating_healthy_list, mood_list);
    double cor_productivity_mood = cor(productivity_list, mood_list);
    double cor_communications_mood = cor(communications_list, mood_list);
    double cor_screen_time_mood = cor(screen_time_list, mood_list);

    int N = log.size();
    //deviation of avg of last week from avg of last month ( 0, when N <= 7)
    double sleep_dev = abs(get_lastn_average(std::min(7, N), SLEEP) - get_lastn_average(std::min(N, 30), SLEEP));
    double eating_healthy_dev = abs(get_lastn_average(std::min(7, N), EATING_HEALTHY) - get_lastn_average(std::min(N, 30), EATING_HEALTHY));
    double productivity_dev = abs(get_lastn_average(std::min(7, N), PRODUCTIVITY) - get_lastn_average(std::min(N, 30), PRODUCTIVITY));
    double communications_dev = abs(get_lastn_average(std::min(7, N), COMMUNICATIONS) - get_lastn_average(std::min(N, 30), COMMUNICATIONS));
    double screen_time_dev = abs(get_lastn_average(std::min(7, N), SCREEN_TIME) - get_lastn_average(std::min(N, 30), SCREEN_TIME));

    std::map<Variables, double> mood_influence;  // correlation with mood * item deviation from avg
    mood_influence[SLEEP] = cor_sleep_mood * sleep_dev;
    mood_influence[EATING_HEALTHY] = cor_eating_healthy_mood * eating_healthy_dev;
    mood_influence[PRODUCTIVITY] = cor_productivity_mood * productivity_dev;
    mood_influence[COMMUNICATIONS] = cor_communications_mood * communications_dev;
    mood_influence[SCREEN_TIME] = cor_screen_time_mood * screen_time_dev;

    //Sort map (done with MULTIMAP)
    std::map<double, Variables> :: iterator iter;

    // invert mymap using the invert function created above
    std::multimap<double, Variables> newmap = invert(mood_influence);
    //pushing sorted item names in the vector
    std::vector<Variables> vec{};
    for (iter=newmap.begin(); iter!=newmap.end(); iter++)
        {
            vec.push_back(iter->second);
        }
    return vec;
}

std::string MoodAnalysis::suggestion(){  // some more exciting gameplay can be implementen later
    /**
    * @param NAN
    *
    * @returns string "general mood review + suggestion"
    */
    std::string str{};
    if (log.end()->get_mood() >= get_lastn_average(7, MOOD)){
        str += "Your mood today is better than averadge! \n";
        str += "Your progress in" + var_to_str(*(item_priority().begin())) + " and " + var_to_str(*(item_priority().begin() + 1)) + "improves your mood the most, keep it up!";  // suggest top two items which affected the mood the most
    }
    else{
        str += "Your mood today is less than averadge:( \n";
        str += "Try to wrok on your " + var_to_str(*(item_priority().begin())) + " and " + var_to_str(*(item_priority().begin() + 1)) + "!";
    }

    return str;
}
