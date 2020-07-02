#ifndef algorithmPlus_hpp
#define algorithmPlus_hpp
#include <vector>
#include <iostream>
using namespace std;

class algorithmPlus {
    public:
        class arithmeticSequence {
            public:
                vector<int> arithmeticSequenceList; 
                int getNumber(int template1, int template2, int WHERE);
                bool initArithmeticSequence(int template1, int template2, int length);
        }; class randomNumber {
            public:
                vector<int> randomNumberList;
                int randomIntGet(int range1, int range2);
                int randomIntGet();
                double randomFloatGet(double range1, double range2);
                double randomFloatGet(bool Zero2one);
                double randomFloatGet();
        }; class vectorProcessing {
            public:
                int vectorMaxInt(vector<int> maxObj);
                int vectorMaxInt(vector<int> maxObj, int range1, int range2);
        };
};

// class of arithmeticSequence

/* 
 * 这个函数可以帮助你求出等差数列的第 n 个数字，需要几个模板，运用一个公式。
 * This function can help you find the nth number of the arithmetic sequence.
 * It requires several templates and a formula.
 */
int algorithmPlus::arithmeticSequence::getNumber(int template1, int template2, int WHERE) {
    int deleter;
    if(template1 > template2) { deleter = template1 - template2; return template1 + (WHERE - 1) * deleter; } 
    if(template2 > template1) { deleter = template2 - template1; return template2 + (WHERE - 1) * deleter; }
}

/*
 * 这个函数会生成一个等差数列，需要几个模板和一个长度限制。可能资源占用有点多，因为是使用列举的方式。
 * 返回值会在 algorithmPlus::arithmeticSequence 类里的 arithmeticSequenceList 里出现。
 * This function will generate an arithmetic sequence, requiring several templates and a length limit. 
 * Probably the resource occupation is a bit too much, because it is the way of enumeration.
 * The return value will appear in the arithmeticSequenceList in the algorithmPlus::arithmeticSequence class.
 */
bool algorithmPlus::arithmeticSequence::initArithmeticSequence(int template1, int template2, int length) {
    if(length <= 0) {
        int sequence;
        if(template1 > template2) sequence = template1 - template2;
        if(template2 > template1) sequence = template2 - template1;

        int arithmeticSequenceBuffer = 0;
        for(int i = 0; i < length; i++) {
            arithmeticSequenceBuffer += sequence;
            algorithmPlus::arithmeticSequence::arithmeticSequenceList.push_back(arithmeticSequenceBuffer);
        } return true;
    } else return false;
}

// class of randomNumber

int algorithmPlus::randomNumber::randomIntGet(int range1, int range2) {
    int max, min;
    if(range1 > range2) { max = range1; min = range2; }
    if(range2 > range1) { max = range2; min = range1; }
    return max + rand() % min;
}

int algorithmPlus::randomNumber::randomIntGet() {
    unsigned int getedSeed = algorithmPlus::randomNumber::randomIntGet(0, 255); // Summon a seed
    srand(getedSeed); return rand(); // random
}

double algorithmPlus::randomNumber::randomFloatGet(double range1, double range2) {
    int max, min;
    if(range1 > range2) { max = range1; min = range2; }
    if(range2 > range1) { max = range2; min = range1; }

    double returnModule1 = (double)(rand() % 101) / 101; int usingMinRange = min + 1;
    double returnModule2 = (double)((rand() % (max - min + 1)) + min); returnModule2 = returnModule2 - returnModule1;
    return returnModule1 + returnModule2;
}

double algorithmPlus::randomNumber::randomFloatGet(bool Zero2one) {
    int max, min; max = 1; min = 0;
    double returnModule1 = (double)(rand() % 101) / 101; int usingMinRange = min + 1;
    double returnModule2 = (double)((rand() % (max - min + 1)) + min); returnModule2 = returnModule2 - returnModule1;
    return returnModule1 + returnModule2;
}

double algorithmPlus::randomNumber::randomFloatGet() {
    unsigned int getedSeed = algorithmPlus::randomNumber::randomIntGet(0, 255); // Summon a seed
    srand(getedSeed); return rand(); // random

    int max, min; max = 256; min = 0;
    double returnModule1 = (double)(rand() % 101) / 101; int usingMinRange = min + 1;
    double returnModule2 = (double)((rand() % (max - min + 1)) + min); returnModule2 = returnModule2 - returnModule1;
    return returnModule1 + returnModule2;
}
#endif