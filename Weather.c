#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const NO_OF_REAGIONS = 50;

typedef struct WeatherDataRecord {
    int centerID;
    float tempurature;
    float humidity;
    int rainfall;
    float windSpeed;
}WDR;

typedef struct summeryWeatherReoprt {
    float maxTempurature;
    float minHumidity;
    int totalRainfall;
    float avgWindSpeed;
}SWR;

WDR readData();
void printWeatherReport(WDR Record [] );
void printSummeryReport(SWR Report);
float calMaxTempurature(WDR Record []);
float calMinHumidity(WDR Record []);
int calTotalRainfall(WDR Record []);
float calAvgWindSpeed(WDR Record []);
void displayMenu();

int main() {
    printf("\t\tMain Menu\n");
    printf("===========================\n");
    printf("(1) Add New Record\n");
    printf("(2) Print Daily Weather Report\n");
    printf("(3) Print Summery Report\n");
    return 0;
}
