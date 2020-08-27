#include <assert.h>

bool bpm_is_ok(float bpm)
{
    return !(bpm < 70 || bpm > 150);
}
bool spo2_is_ok(float spo2)
{
    return !(spo2 < 90);
}
bool respRate_is_ok(float respRate)
{
    return !(respRate < 30 || respRate > 95);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
    return(bpm_is_ok(bpm) && spo2_is_ok(spo2) && respRate_is_ok(respRate));
}

int main() {
    assert(vitalsAreOk(80, 95, 60) == true);
    assert(vitalsAreOk(60, 90, 40) == false);
}

