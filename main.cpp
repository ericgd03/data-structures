// Carlos Eric González Domínguez - A00834447

// Actividad 1.3 Actividad Integral de Conceptos Básicos y Algoritmos Fundamentales

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string getMonthNumber(string month){
    
    if (month == "Jan") {return "1";}
    
    else if (month == "Feb") {return "2";}
    
    else if (month == "Mar") {return "3";}
    
    else if (month == "Apr") {return "4";}
    
    else if (month == "May") {return "5";}
    
    else if (month == "Jun") {return "6";}
    
    else if (month == "Jul") {return "7";}
    
    else if (month == "Aug") {return "8";}
    
    else if (month == "Sep") {return "9";}
    
    else if (month == "Oct") {return "10";}
    
    else if (month == "Nov") {return "11";}
    
    else if (month == "Dec") {return "12";}
    
    return NULL;
}

long int getDateValue(string line){
    
    string month = getMonthNumber(line.substr(0, 3));
    
    string day = line.substr(line.find_first_of(' ') + 1, 2);
    
    if (day.find(' ') == 1){
        
        day = "0" + day.substr(0, 1);
    }
    string hour = line.substr(line.find_first_of(':') - 2, 2);
    
    string minute = line.substr(line.find_first_of(':') + 1, 2);
    
    string second = line.substr(line.find_first_of(':') + 4, 2);
    
    return stoi(month + day + hour + minute + second);
}

int partition(int left, int right, vector<string> &list){
    
    string aux;
    
    int pivot = right;

    int lastSmallValue = left - 1;
    
    for (int i = left; i < right; i++){
        
        if (getDateValue(list[i]) <= getDateValue(list[pivot])){
            
            lastSmallValue++;
            
            aux = list[lastSmallValue];
            
            list[lastSmallValue] = list[i];
            
            list[i] = aux;
        }
    }
    aux = list[lastSmallValue + 1];
    
    list[lastSmallValue + 1] = list[pivot];
    
    list[pivot] = aux;
    
    return lastSmallValue + 1;
}

void quickSort(int left, int right, vector<string> &list){

    if (left < right){
        
        int pivot = partition(left, right, list);
        
        quickSort(left, pivot - 1, list);
        
        quickSort(pivot + 1, list.size() - 1, list);
    }
}

int binarySearch(vector<string> &list, long int searchingValue){
    
    int beginning = 0;
    
    int end = list.size() - 1;
    
    while (beginning < end){
        
        int middle = (beginning + end) / 2;
        
        if (searchingValue == getDateValue(list[middle])){
            
            return middle;
        }
        if (searchingValue != getDateValue(list[middle]) && searchingValue < getDateValue(list[middle + 1]) && searchingValue > getDateValue(list[middle - 1])){
            
            if (searchingValue < getDateValue(list[middle])){
                
                return middle;
            }
            else if (searchingValue > getDateValue(list[middle])){
                
                return middle + 1;
            }
        }
        if (searchingValue < getDateValue(list[middle])){
            
            end = middle - 1;
        }
        else if (searchingValue > getDateValue(list[middle])){
            
            beginning = middle + 1;
        }
    }
    return -1;
}

int getInitialDateIndex(vector<string> &list, string initialMonth, string initialDay, string initialHour, string initialMinute, string initialSecond){
    
    long int initialDate = stoi(getMonthNumber(initialMonth) + initialDay + initialHour + initialMinute + initialSecond);
    
    int initialDateIndex = binarySearch(list, initialDate);
    
    return initialDateIndex;
}

int getFinalDateIndex(vector<string> &list, string finalMonth, string finalDay, string finalHour, string finalMinute, string finalSecond){
    
    long int finalDate = stoi(getMonthNumber(finalMonth) + finalDay + finalHour + finalMinute + finalSecond);
    
    int finalDateIndex = binarySearch(list, finalDate);
    
    return finalDateIndex;
}

void getDateRange(vector<string> &list){
    
    string initialMonth, initialDay, initialHour, initialMinute, initialSecond;
    
    cout << "\nINITIAL DATE\n" << endl;
        
    cout << "Input initial month: "; cin >> initialMonth;
    
    cout << "Input initial day: "; cin >> initialDay;
    
    if (initialDay.size() == 1){
        
        initialDay = "0" + initialDay;
    }
    cout << "Input initial hour: "; cin >> initialHour;
    
    if (initialHour.size() == 1){
        
        initialHour = "0" + initialHour;
    }
    cout << "Input initial minute: "; cin >> initialMinute;
    
    if (initialMinute.size() == 1){
        
        initialMinute = "0" + initialMinute;
    }
    cout << "Input initial second: "; cin >> initialSecond;
    
    if (initialSecond.size() == 1){
        
        initialSecond = "0" + initialSecond;
    }
    string finalMonth, finalDay, finalHour, finalMinute, finalSecond;
    
    cout << "\nFINAL DATE\n" << endl;

    cout << "Input final month: "; cin >> finalMonth;
    
    cout << "Input final day: "; cin >> finalDay;
    
    if (finalDay.size()){
        
        finalDay = "0" + finalDay;
    }
    cout << "Input final hour: "; cin >> finalHour;
    
    if (finalHour.size()){
        
        finalHour = "0" + finalHour;
    }
    cout << "Input final minute: "; cin >> finalMinute;
    
    if (finalMinute.size()){
        
        finalMinute = "0" + finalMinute;
    }
    cout << "Input final second: "; cin >> finalSecond;
    
    if (finalSecond.size()){
        
        finalSecond = "0" + finalSecond;
    }
    int initialDateIndex = getInitialDateIndex(list, initialMonth, initialDay, initialHour, initialMinute, initialSecond);
    
    int finalDateIntex = getFinalDateIndex(list, finalMonth, finalDay, finalHour, finalMinute, finalSecond);
    
    cout << "\n" << initialMonth << " " << initialDay << " - " << finalMonth << " " << finalDay << "\n" << endl;
    
    for (int i = initialDateIndex; i < finalDateIntex; i++){
        
        cout << list[i] << endl;
    }
}

int main(){
    
    vector<string> list;
    
    string line;
    
    ifstream input("prueba.txt");
    
    ofstream output("salida.txt");
    
    if (input.is_open() && output.is_open()){
        
        while (getline(input, line)){
            
            list.push_back(line);
        }
    }
    quickSort(0, list.size() - 1, list);
    
    cout << "\nSORTED FILE\n" << endl;
    
    for (int i = 0; i < list.size(); i++){

        output << list[i] << endl;

        cout << list[i] << endl;
    }
    input.close();
    
    output.close();

    getDateRange(list);
    
    return 0;
}
