#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const NO_OF_REAGIONS = 50;

enum mainMenuOptions {ADD_NEW_RECORD =1, PRINT_WEATHER_REPORT, PRINT_SUMMERY, EXIT};

typedef struct WeatherDataRecord {
    int centerID;
    char date[15];
    float temperature;
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
void printWeatherReport(WDR Records [NO_OF_REAGIONS] );
void printSummeryReport(SWR Report);
float calMaxTempurature(WDR Records [NO_OF_REAGIONS]);
float calMinHumidity(WDR Records [NO_OF_REAGIONS]);
int calTotalRainfall(WDR Records [NO_OF_REAGIONS]);
float calAvgWindSpeed(WDR Records [NO_OF_REAGIONS]);
void getSummeryReport(WDR Records [NO_OF_REAGIONS]);

int main() {
    mainMenuHandler();
    return 0;
}

int displayMenu() {
    int choice;
    printf("\t\tMain Menu\n");
    printf("=======================================\n");
    printf("(1) Add New Record\n");
    printf("(2) Print Daily Weather Report\n");
    printf("(3) Print Summery Report\n");
    printf("(4) Exit\n\n");

    printf("Input any number among 1 - 4: ");
    scanf("%d", &choice);
    printf("\n");

    return choice;
}

void mainMenuHandler() {
    int choice;
    WDR newRecord;
    WDR Records [NO_OF_REAGIONS];

    do {
        choice = displayMenu();
        switch (choice) {
            case ADD_NEW_RECORD:
                newRecord = readData();
                Records[newRecord.centerID - 1] =newRecord;
                break;
            case PRINT_WEATHER_REPORT:
                printWeatherReport(Records);
                break;
            case PRINT_SUMMERY:
                getSummeryReport(Records);
                break;
            case EXIT:
                printf("Exit\n");
                break;
        }
    }while (choice!= EXIT);
}

WDR readData(){
    int centerID;
    char date [15];
    float temp;
    float humi;
    int rain;
    float wSpeed;

     printf("Enter center ID\t\t\t:");
    scanf("%d", &centerID);

    printf("Enter date (yyyy/mm/dd)\t\t:");
    scanf(" %[^\n]s", date);

    printf("Enter Temperature(C)\t\t:");
    scanf("%f", &temp);

    printf("Enter Humidity(%%)\t\t:");
    scanf("%f", &humi);

    printf("Enter Rainfall(ml)\t\t:");
    scanf("%d", &rain);

    printf("Enter Wind Speed(km/h)\t\t:");
    scanf("%f", &wSpeed);
    printf("\n");

    WDR newRecord = {centerID, "", temp, humi, rain, wSpeed};
    strcpy(newRecord.date, date);

    return newRecord;
}

void printWeatherReport(WDR Records [NO_OF_REAGIONS] ) {
    printf("\t\t Daily Weather Report \(%s\)\n", Records[0].date);
    printf("CenterID\tTemperature(C)\tHumidity(%%)\tRainfall(ml)\tWind Speed(km/h)\n");
    printf("============================================================================\n\n");
    for (int i=0; i<NO_OF_REAGIONS; i++) {
        printf("%d\t\t%.2f\t\t%.2f\t\t%d\t\t%.2f\n\n", Records[i].centerID, Records[i].temperature, Records[i].humidity, Records[i].rainfall, Records[i].windSpeed);
    }
}

float calMaxTempurature(WDR Records [NO_OF_REAGIONS]){
    float maxTemp = 0;

    for (int i=0; i<NO_OF_REAGIONS; i++) {
        if (Records[i].temperature > maxTemp) {
            maxTemp = Records[i].temperature;
        }
    }
    return maxTemp;
}

float calMinHumidity(WDR Records [NO_OF_REAGIONS]) {
    float minHumi = 1000;

    for (int i=0; i<NO_OF_REAGIONS; i++) {
        if (Records[i].humidity < minHumi) {
            minHumi = Records[i].humidity;
        }
    }
    return minHumi;
}

int calTotalRainfall(WDR Records [NO_OF_REAGIONS]){
    int maxRainfall = 0;

    for (int i=0; i<NO_OF_REAGIONS; i++) {
        maxRainfall += Records[i].rainfall;
    }
    return maxRainfall;
}

float calAvgWindSpeed(WDR Records [NO_OF_REAGIONS]) {
    int AvgWindSpeed = 0;

    for (int i=0; i<NO_OF_REAGIONS; i++) {
        AvgWindSpeed += Records[i].windSpeed;
    }

    AvgWindSpeed = AvgWindSpeed/50.00;

    return AvgWindSpeed;
}

void getSummeryReport(WDR Records [NO_OF_REAGIONS]) {
    float maxTempurature = calMaxTempurature(Records);
    float minHumidity = calMinHumidity(Records);
    int totalRainfall = calTotalRainfall(Records);
    float avgWindSpeed = calAvgWindSpeed(Records);

    SWR Report = {maxTempurature, minHumidity, totalRainfall, avgWindSpeed};
    printSummeryReport(Report);
}

void printSummeryReport(SWR Report){
    printf("\n\t\tSummery Weather Report\n");
    printf("================================================\n");
    printf("Maximum Temperature(c)\t\t:%.2f\n", Report.maxTempurature);
    printf("Minimum Humidity(%%) \t\t:%.2f\n", Report.minHumidity);
    printf("Total Rainfall(ml)\t\t:%d\n", Report.totalRainfall);
    printf("Average Wind Speed(km\h) \t\t:%.2f\n\n", Report.avgWindSpeed);
}
