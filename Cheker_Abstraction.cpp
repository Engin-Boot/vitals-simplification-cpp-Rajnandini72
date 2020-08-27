#include <assert.h>
#include<iostream>

bool vitalsIsInLimit(float value, int lowerLimit, int upperLimit)
{
    return(value >= lowerLimit && value <= upperLimit);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
    return(vitalsIsInLimit(bpm,70,150)&& vitalsIsInLimit(spo2,90,100)&& vitalsIsInLimit(respRate, 30,95));
}

int main() {
    assert(vitalsAreOk(80, 95, 60) == true);
    assert(vitalsAreOk(60, 90, 40) == false);
    assert(vitalsAreOk(85, 85, 60) == false);
    assert(vitalsAreOk(85, 95, 130) == false);
}
