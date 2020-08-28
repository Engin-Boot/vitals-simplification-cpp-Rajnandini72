#include <iostream>
#include<assert.h>
using namespace std;

struct vitals {
    float bpm;
    int spo2;
    int respRate;
};

bool vitalsAreOk(vitals);
bool cardiacIsOk(float, int);
bool respIsOk(int);

int main() {
    vitals pat1 = { 60,95,40 };
    assert(vitalsAreOk(pat1) == false);
    vitals pat2 = { 80,85,40 };
    assert(vitalsAreOk(pat2) == false);
    vitals pat3 = { 80,95,125 };
    assert(vitalsAreOk(pat3) == false);
    vitals pat4 = { 80,95,40 };
    assert(vitalsAreOk(pat4) == true);
    cout << "ok!!";
    return 0;
}
bool cardiacIsOk(float bpm, int spo2) {
    return(bpm > 70 && bpm < 150 && spo2 > 90 && spo2 < 100);
}

bool respIsOk(int respRate) {
    return(respRate > 30 && respRate < 95);
}

bool vitalsAreOk(vitals pat1)
{
    return(cardiacIsOk(pat1.bpm, pat1.spo2) && respIsOk(pat1.respRate));
}

