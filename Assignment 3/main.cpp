#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
#include "cannonball_viz.h"

// prototypes
void testDeviation(double compareOperand, double toOperand, double maxError, string name);

/*
bool checkIfDistanceToTargetIsCorrect() {
    double error = targetPractice
    (0,0,0);
    if(error == 0) return true;
}
*/

int main() {
    
    playTargetPractice();

    /*
    // 5b/c
    for (int i = 0; i < 10; i++) {
        cout << randomWithLimits(0, 10) << endl;
    }
    */

    /*
    // Oppgave 4
    vector<double> velocityVector = getVelocityVector(getUserInputTheta(), getUserInputAbsVelocity());
    testDeviation(velocityVector[0], 13.8728, 0.0001, "getVelocityVectorx");
    testDeviation(velocityVector[1], 7.22175, 0.0001, "getVelocityVectory");
    testDeviation(getDistanceTraveled(velocityVector[0], velocityVector[1]), 20.4253, 0.0001, "getDistanceTraveled");


    //for loop for å teste targetPractice
    for (int i = 10; i < 20; i++) {
        cout << targetPractice(i, velocityVector[0], velocityVector[1]) << endl;
    }
    */

    //checkIfDistanceToTargetIsCorrect();
    // Oppgave 4e
    // Kompileringen feiler fordi checkIfDistanceToTargetIsCorrect() ikke returnerer
    // noe dersom if-setningen ikke er sann. Selv etter å ha endret koden endret den seg ikke.

    /*
    // Oppgave 3
    cout << "----------------------------------------" << endl;
    testDeviation(acclY(), -9.81, 0.0001, "acclY");
    testDeviation(velY(0, 0), 0, 0.01, "velY");
    testDeviation(posX(0, 0, 0), 0, 0.01, "posX");
    testDeviation(posY(0, 0, 0), 0, 0.01, "posY");
    cout << "----------------------------------------" << endl;
    testDeviation(velY(25, 2.5), 0.475, 0.01, "velY t=2.5");
    testDeviation(posX(0, 50, 2.5), 125, 0.01, "posX t=2.5");
    testDeviation(posY(0, 25, 2.5), 31.84, 0.01 , "posY t=2.5");
    cout << "----------------------------------------" << endl;
    testDeviation(velY(25, 5), -24.05, 0.01, "velY t=5");
    testDeviation(posX(0, 50, 5), 250, 0.01, "posX t=5");
    testDeviation(posY(0, 25, 5), 2.375, 0.01, "posY t=5");
    cout << "----------------------------------------" << endl;
    testDeviation(flightTime(25), 5.09, 0.01, "flightTime, initVelocityY=25");
    testDeviation(flightTime(50), 10.19, 0.01, "flightTime, initVelocityY=50");
    cout << "----------------------------------------\n" << endl;
    */
    return 0;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    if (abs(compareOperand - toOperand) <= maxError) {
        cout << name << " OK" << endl;
    } else {
        cout << name << " NOT OK, expected " << toOperand << " but got " << compareOperand << endl;
    }
}