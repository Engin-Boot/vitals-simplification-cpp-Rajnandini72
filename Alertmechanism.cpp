#include <assert.h>
#include <iostream>
using namespace std;


struct vitals {
    float bpm;
    int spo2;
    int respRate;
};

class AlertInterface
{
public:
    virtual void raiseAlert(const char* vitalName, const char* level) = 0;
};

class AlertWithSMS : public AlertInterface
{
public:
    void raiseAlert(const char* vitalName, const char* level) override
    {
        std::cout << "SMS: " << vitalName << " " << level << std::endl;
    }
};

class AlertWithSound : public AlertInterface
{
public:
    void raiseAlert(const char* vitalName, const char* level) override
    {
        std::cout << "Sound: " << vitalName << " " << level << std::endl;  //'what'
    }
};

class AlertIntegrator : public AlertInterface
{
private:
    AlertWithSMS smsAlerter;
    AlertWithSound soundAlerter;
public:
    void raiseAlert(const char* vitalName, const char* level) override
    {
        smsAlerter.raiseAlert(vitalName, level);
        soundAlerter.raiseAlert(vitalName, level);
    }
};

class RangeChecker
{
private:
    int lower;
    int upper;
    const char* vitalName;
    AlertInterface* alerter;
public:
    RangeChecker(const char* name, int low, int up, AlertInterface* alerterPtr)
    {
        vitalName = name;
        lower = low;
        upper = up;
        alerter = alerterPtr;
    }
    void checkAgainstRange(float value)
    {
        if (value < lower) {
            alerter->raiseAlert(vitalName, "too low");  //'when'
        }
        else if (value > upper) {
            alerter->raiseAlert(vitalName, "too high");
        }
    }
};

class VitalsIntegrator
{
private:
    RangeChecker bpmChecker, spo2Checker, respChecker;
public:
    VitalsIntegrator(AlertInterface* alertPtr) :
        bpmChecker("pulse rate", 70, 150, alertPtr),
        spo2Checker("spo2", 90, 101, alertPtr),
        respChecker("resp rate", 30, 95, alertPtr)
    {}
    void checkAllVitals(vitals *pat)
    {
        bpmChecker.checkAgainstRange(pat->bpm);
        spo2Checker.checkAgainstRange(pat->spo2);
        respChecker.checkAgainstRange(pat->respRate);
    }
};

int main() {
    int alertType;
    struct vitals pat1 = {60,95,60};
    struct vitals pat2 = {80,85,60};
    struct vitals pat3 = {80,95,160};

    cout << "Choose the Alert you need:" << endl;
    cout << "1.Sound Alert" << endl;
    cout << "2.SMS Alert" << endl;
    cin >> alertType;
    if (alertType == 1)
    {
        cout << "Sound Alert:" << endl;
        AlertWithSound alerter;
        VitalsIntegrator vitals(&alerter);

        vitals.checkAllVitals(&pat1);
        vitals.checkAllVitals(&pat2);
        vitals.checkAllVitals(&pat3);
    }
    else if(alertType==2)
    {
        cout << "SMS Alert:" << endl;
        AlertWithSMS alerter1;
        VitalsIntegrator vitals12(&alerter1);

        vitals12.checkAllVitals(&pat1);
        vitals12.checkAllVitals(&pat2);
        vitals12.checkAllVitals(&pat3);
    }
    else { cout << "Invalid Choice" << endl; }
    
}
