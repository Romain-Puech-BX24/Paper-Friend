#ifndef FILE_SAVE_AND_LOAD_H
#define FILE_SAVE_AND_LOAD_H
#include "activityclasses.h"
#include "entryclasses.h"
#include "entryrecap.h"
#include "friendclasses.h"
#include "json-develop/single_include/nlohmann/json.hpp"
#include <QJsonDocument>
#include <fstream>
#include <iostream>
#include <string>

bool save_entry(Entry entry);

Entry load_entry(std::string filename);

std::string activity_to_string(Activity act);

Activity string_to_activity(std::string act);

std::string activities_vec_to_str(std::vector<Activity *> acts);

std::vector<Activity *>
str_to_vec_activities(std::vector<Activity *> possible_activities,
                      std::string act);

std::string friend_to_string(Friend act);

Friend string_to_frend(std::string act);

std::string friend_vec_to_str(std::vector<Friend *> acts);

std::vector<Friend *> str_to_vec_friends(std::string act);

bool save_entryperso(EntryPerso entry);

EntryPerso *load_entryperso(std::string filename,
                            std::vector<Activity> possible_activities);

bool save_activities(std::vector<Activity> act);

bool save_friends(std::vector<Friend> fr);

bool save_entryrecap(EntryRecap entry);


EntryRecap* load_entryrecap (std::string filename, std::vector<Activity> possible_activities);


std::vector<Activity> load_activities();

std::vector<Friend> load_friends();

std::vector<QStringList> load_habits();

std::vector<QString> load_last_recaps_dates();

void save_last_recaps_dates(std::vector<QString> last_recaps_dates);

void save_habits_to_file(std::vector<QStringList> new_habits);

void resave_habits_in_new_file(std::vector<QStringList> new_habits);

int save_incrementation_of_habits(QString to_increment);

void save_reset_of_habits(QString to_reset);

void save_delete_of_habits(QString to_delete);

std::vector<QStringList> get_daily_habits();

#endif
