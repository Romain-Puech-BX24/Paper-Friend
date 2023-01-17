#include "mascot.h"
#include <QLayout>

Mascot::Mascot(){
    QString peaceout = "<img src=:/pictures/rsc/peaceout-resized.png align=middle height=\"85\">";
    QString  excited = "<img src=:/pictures/rsc/excited-resized.png align=middle height=\"85\">";
    QString pleading = "<img src=:/pictures/rsc/pleading-resized.png align=middle height=\"85\">";
    imagepath_strings_vect = {excited,pleading,peaceout};}
Mascot::~Mascot(){

}
QString Mascot::get_emotion(int num){
    /* Takes a number from 0 to 100 and returns a string with image path written in a way such that it
     * can be displayed in the chat_layout in mascot chat [each image corresponds to a certain range
     * according to the emotion it displays */
    if(num >=0 and num < 50){
        return imagepath_strings_vect[1];
    }
    else if (num >=50 and num <70) {
        return imagepath_strings_vect[2];
    }
    else{
        return imagepath_strings_vect[0];
    }
}


