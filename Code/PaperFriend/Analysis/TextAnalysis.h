#ifndef TEXTANALYSIS_H
#define TEXTANALYSIS_H


#include "DataAnalysis.h"


class TextAnalysis{

public:

    TextAnalysis(QString text_to_analize): text_to_analize(text_to_analize.toStdString()){text_mood=0; qDebug()<<QString::fromStdString(this->text_to_analize);};

    void analyze_text();

    double str_to_double(std::string text);

    double get_text_mood();

private:

    double text_mood;  // mood predicted from the text from 0 to 1
    std::string text_to_analize;
};

#endif // TEXTANALYSIS_H