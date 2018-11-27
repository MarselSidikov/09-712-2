#include <iostream>
#include "ToLowerCaseFunction.h"
#include "AlphaBetOrDigitsExtractFunction.h"
#include "MainTextProcessor.h"
#include "ToUpperCaseFunction.h"

using namespace std;
int main() {
    char text[50];
    cin.getline(text, 50);

//    TextFunction *lowerCaseFunction = new ToLowerCaseFunction();
//    lowerCaseFunction->apply(text);
//    cout << "AFTER LOWERCASING: " <<  text << endl;
//
//    TextFunction *alphaBetOfDigitsExtractFunction = new AlphaBetOrDigitsExtractFunction();
//    alphaBetOfDigitsExtractFunction->apply(text);
//    cout << "AFTER EXTRACT: " << text;

    TextFunction *lowerCaseFunction = new ToLowerCaseFunction();
    TextFunction *alphaBetOfDigitsExtractFunction = new AlphaBetOrDigitsExtractFunction();
    TextFunction *upperCaseFunction = new ToUpperCaseFunction();
    TextFunction* functions[3] = {lowerCaseFunction, alphaBetOfDigitsExtractFunction, upperCaseFunction};

    MainTextProcessor *processor = new MainTextProcessor();
    processor->process(text, functions, 3);
    cout << text << endl;
    return 0;
}