#include "entryclasses.h"

#include <iostream>
#include <string>

std::string current_date() {
    const int maxlen = 80;
    char s[maxlen];
    time_t t = time(nullptr);
    strftime(s, maxlen, "%m/%d/%Y", localtime(&t));
    return s;
}

std::string find_weekday(){
    const int maxlen = 80;
    char s[maxlen];
    time_t t = time(nullptr);
    strftime(s, maxlen, "%A", localtime(&t));
    return s;
}

int find_absolute_day(){ // ! we assume time() returns the number of seconds since epoch UTC. further, we assume days are always exactly 24h
    return (time(NULL)+3600)/(60*60*24);
}

Entry::Entry() {
    this->text = "";
    this->title = "";
    this->time_log = time(nullptr);
    this->date = current_date();
    this->weekday = find_weekday();
    this->absolute_day = find_absolute_day();
}

Entry::Entry(std::string text, std::string title){
    this->text = text;
    this->title = title;
    this->time_log = time(nullptr);
    this->date = current_date();
    this->weekday = find_weekday();
    this->absolute_day = find_absolute_day();
}

Entry::~Entry() {}

std::string Entry::get_text() const {
    return text;
}

void Entry::set_text(std::string text) {
    this->text=text;
}

std::string Entry::get_title() const {
    return title;
}

void Entry::set_title(std::string title) {
    this->title=title;
}

std::string Entry::get_date() const {
    return date;
}

void Entry::set_date(std::string date) {
    this->date=date;

std::string Entry::get_weekday() const{
    return weekday;
}

int Entry::get_absolute_day() const{
    return absolute_day;

}


EntryPerso::EntryPerso() : Entry(), activities(NULL), friends(NULL), mood(0) {}

EntryPerso::EntryPerso(std::string text, std::string title, Activity* activities, Friend* friends, double mood,
                                                                                                   double sleep,
                                                                                                   double eating_healthy,
                                                                                                   double productivity,
                                                                                                   double communications,
                                                                                                   double screen_time) :
    Entry(text, title), activities(activities), friends(friends), mood(mood),
                                                                  sleep(sleep),
                                                                  eating_healthy(eating_healthy),
                                                                  productivity(productivity),
                                                                  communications(communications),
                                                                  screen_time(screen_time) {}

EntryPerso::~EntryPerso() {
    delete activities;
    delete friends;
}

Activity* EntryPerso::get_activities() const {
    return activities;
}

void EntryPerso::set_activities(Activity* activities) {
    this->activities = activities;
}

Friend* EntryPerso::get_friends() const {
    return friends;
}

void EntryPerso::set_friends(Friend* friends) {
    this->friends = friends;
}

double EntryPerso::get_mood() const {
    return mood;
}

void EntryPerso::set_mood(double mood) {
    this->mood = mood;
}

double EntryPerso::get_sleep() const {
    return sleep;
}

void EntryPerso::set_sleep(double sleep) {
    this->sleep = sleep;
}

double EntryPerso::get_eating_healthy() const {
    return eating_healthy;
}

void EntryPerso::set_eating_healthy(double eating_healthy) {
    this->eating_healthy = eating_healthy;
}

double EntryPerso::get_productivity() const {
    return productivity;
}

void EntryPerso::set_productivity(double productivity) {
    this->productivity = productivity;
}

double EntryPerso::get_communications() const {
    return communications;
}

void EntryPerso::set_communications(double communications) {
    this->communications = communications;
}

double EntryPerso::get_screen_time() const {
    return screen_time;
}

void EntryPerso::set_screen_time(double screen_time) {
    this->screen_time = screen_time;
}
