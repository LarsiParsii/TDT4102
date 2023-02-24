#include "std_lib_facilities.h"
#include "utilities.h"
#include "cannonball_viz.h"
#include "cannonball.h"

double acclY()
{
    return -9.81;
}

double velY(double initVelocityY, double time)
{
    return initVelocityY + acclY() * time;
}

double posX(double initPosition, double initVelocity, double time)
{
    return initPosition + initVelocity * time + 0.5 * 0 * time * time;
}

double posY(double initPosition, double initVelocity, double time)
{
    return initPosition + initVelocity * time + 0.5 * acclY() * time * time;
}

void printTime(double seconds)
{
    int hours = (int)(seconds / 3600);
    int minutes = (int)((seconds - hours * 3600) / 60);
    seconds = seconds - hours * 3600 - minutes * 60;
    cout << "Time: " << hours << "h " << minutes << "m " << seconds << "s" << endl;
}

double flightTime(double initVelocityY)
{
    return -2 * initVelocityY / acclY();
}

double getUserInputTheta()
{
    double theta;
    cout << "Enter angle: ";
    cin >> theta;
    return degToRad(theta);
}

double getUserInputAbsVelocity()
{
    double absVelocity;
    cout << "Enter absolute velocity: ";
    cin >> absVelocity;
    return absVelocity;
}

double degToRad(double deg)
{
    return deg * M_PI / 180;
}

double getVelocityX(double theta, double absVelocity)
{
    return absVelocity * cos(theta);
}

double getVelocityY(double theta, double absVelocity)
{
    return absVelocity * sin(theta);
}

std::vector<double> getVelocityVector(double theta, double absVelocity)
{
    vector<double> velocityVector;
    velocityVector.push_back(getVelocityX(theta, absVelocity));
    velocityVector.push_back(getVelocityY(theta, absVelocity));
    return velocityVector;
}

double getDistanceTraveled(double velocityX, double velocityY)
{
    return velocityX * flightTime(velocityY);
}   

double targetPractice(double distanceToTarget, double velocityX, double velocityY)
{
    return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

void playTargetPractice(void)
{
    int attempt = 0;
    double distanceToTarget = randomWithLimits(100, 1000);

    for (attempt = 0; attempt < 10; attempt++)
    {
        cout << "----------------------------------------" << endl;
        double theta = getUserInputTheta();
        double absVelocity = getUserInputAbsVelocity();
        
        vector<double> velocityVector = getVelocityVector(theta, absVelocity);
        double velocityX = velocityVector[0];
        double velocityY = velocityVector[1];
        double distanceDifference = targetPractice(distanceToTarget, velocityX, velocityY);
        
        if (abs(distanceDifference) < 5)
        {
            cout << "You hit the target! \nCongratz, love!" << endl;
            cout << "The target was " << distanceToTarget << " meters away." << endl;
            cout << "The ball was airborne for ";
            printTime(flightTime(velocityY));
            cannonBallViz(distanceToTarget, 1000, velocityX, velocityY, 100);
            break;
        }
        else if (distanceDifference < 0)
        {
            cout << "You overshot the target!" << endl;
        }
        else
        {
            cout << "You undershot the target!" << endl;
        }
        cout << "You missed by " << abs(distanceDifference) << " meters." << endl;
        cout << "The ball was airborne for ";
        printTime(flightTime(velocityY));
        cannonBallViz(distanceToTarget, 1000, velocityX, velocityY, 100);
    }

    if (attempt == 10)
    {
        cout << "\nYou failed to hit the target in 10 attempts. \nI'm still proud of you, though!" << endl;
    }
}