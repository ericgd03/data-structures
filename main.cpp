// Carlos Eric González Domínguez - A00834447

// Actividad 2.3 Actividad Integral estructura de datos lineales

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

int datePartition(int left, int right, vector<string> &list){
    
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

void dateQuickSort(int left, int right, vector<string> &list){

    if (left < right){
        
        int pivot = datePartition(left, right, list);
        
        dateQuickSort(left, pivot - 1, list);
        
        dateQuickSort(pivot + 1, list.size() - 1, list);
    }
}

int dateBinarySearch(vector<string> &list, long int searchingValue){
    
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
    return end ;
}

int getInitialDateIndex(vector<string> &list, string initialMonth, string initialDay, string initialHour, string initialMinute, string initialSecond){
    
    long double initialDate = stoi(getMonthNumber(initialMonth) + initialDay + initialHour + initialMinute + initialSecond);
    
    int initialDateIndex = dateBinarySearch(list, initialDate);
    
    return initialDateIndex;
}

int getFinalDateIndex(vector<string> &list, string finalMonth, string finalDay, string finalHour, string finalMinute, string finalSecond){
    
    long double finalDate = stoi(getMonthNumber(finalMonth) + finalDay + finalHour + finalMinute + finalSecond);
    
    int finalDateIndex = dateBinarySearch(list, finalDate);
    
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
    
    if (finalDay.size() == 1){
        
        finalDay = "0" + finalDay;
    }
    cout << "Input final hour: "; cin >> finalHour;
    
    if (finalHour.size() == 1){
        
        finalHour = "0" + finalHour;
    }
    cout << "Input final minute: "; cin >> finalMinute;
    
    if (finalMinute.size() == 1){
        
        finalMinute = "0" + finalMinute;
    }
    cout << "Input final second: "; cin >> finalSecond;
    
    if (finalSecond.size() == 1){
        
        finalSecond = "0" + finalSecond;
    }
    int initialDateIndex = getInitialDateIndex(list, initialMonth, initialDay, initialHour, initialMinute, initialSecond);
    
    int finalDateIntex = getFinalDateIndex(list, finalMonth, finalDay, finalHour, finalMinute, finalSecond);
    
    cout << "\nSORTED BY DATE" << endl;
    
    cout << "\n" << initialMonth << " " << initialDay << " - " << finalMonth << " " << finalDay << "\n" << endl;
    
    for (int i = initialDateIndex; i <= finalDateIntex; i++){
        
        cout << list[i] << endl;
    }
}

string getIpValue(string line){
    
    string ip = line.substr(line.find_first_of(':') + 7, 15);
    
    ip = ip.substr(0, ip.find_first_of(':'));
    
    string firstPartIp = ip.substr(0, ip.find_first_of('.'));
    
    if (firstPartIp.size() == 1){
        
        firstPartIp = "00" + firstPartIp;
    }
    else if (firstPartIp.size() == 2){
        
        firstPartIp = "0" + firstPartIp;
    }
    ip = ip.substr(ip.find_first_of('.') + 1, 11);
    
    string secondPartIp = ip.substr(0, ip.find_first_of('.'));
    
    if (secondPartIp.size() == 1){
        
        secondPartIp = "00" + secondPartIp;
    }
    else if (secondPartIp.size() == 2){
        
        secondPartIp = "0" + secondPartIp;
    }
    ip = ip.substr(ip.find_first_of('.') + 1, 7);
    
    string thirdPartIp = ip.substr(0, ip.find_first_of('.'));
    
    if (thirdPartIp.size() == 1){
        
        thirdPartIp = "00" + thirdPartIp;
    }
    else if (thirdPartIp.size() == 2){
        
        thirdPartIp = "0" + thirdPartIp;
    }
    ip = ip.substr(ip.find_first_of('.') + 1, 3);

    string fourthPartIp = ip.substr(0, 3);
    
    if (fourthPartIp.size() == 1){
        
        fourthPartIp = "00" + fourthPartIp;
    }
    else if (fourthPartIp.size() == 2){
        
        fourthPartIp = "0" + fourthPartIp;
    }
    string ipValue = firstPartIp + secondPartIp + thirdPartIp + fourthPartIp;
    
    return ipValue;
}

int firstIpPartition(int left, int right, vector<string> &list){
    
    string aux;
    
    int pivot = right;

    int lastSmallValue = left - 1;
    
    for (int i = left; i < right; i++){
        
        string currentIpValue = getIpValue(list[i]);
        
        string pivotIpValue = getIpValue(list[pivot]);
        
        if (stoi(currentIpValue.substr(3, 9)) <= stoi(pivotIpValue.substr(3, 9))){
            
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

void firstIpQuickSort(int left, int right, vector<string> &list){
    
    if (left < right){
        
        int pivot = firstIpPartition(left, right, list);
        
        firstIpQuickSort(left, pivot - 1, list);
        
        firstIpQuickSort(pivot + 1, list.size() - 1, list);
    }
}

int secondIpPartition(int left, int right, vector<string> &list){
    
    string aux;
    
    int pivot = right;

    int lastSmallValue = left - 1;
    
    for (int i = left; i < right; i++){
        
        string currentIpValue = getIpValue(list[i]);
        
        string pivotIpValue = getIpValue(list[pivot]);
        
        if (stoi(currentIpValue.substr(0, 3)) <= stoi(pivotIpValue.substr(0, 3))){
            
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

void secondIpQuickSort(int left, int right, vector<string> &list){
    
    if (left < right){
        
        int pivot = secondIpPartition(left, right, list);
        
        secondIpQuickSort(left, pivot - 1, list);
        
        secondIpQuickSort(pivot + 1, list.size() - 1, list);
    }
}

void ipSort(vector<string> &list){
    
    firstIpQuickSort(0, list.size() - 1, list);
    
    secondIpQuickSort(0, list.size() - 1, list);
}

int ipBinarySearchInitialIndex(vector<string> &list, string searchingValue){
    
    int beginning = 0;
    
    int end = list.size() - 1;
    
    while (beginning <= end){
        
        int middle = (beginning + end) / 2;
        
        if (stoi(searchingValue.substr(0, 9)) == stoi(getIpValue(list[middle]).substr(0, 9)) && stoi(searchingValue.substr(9, 3)) == stoi(getIpValue(list[middle]).substr(9, 3))){
            
            while (stoi(getIpValue(list[middle]).substr(0, 9)) == stoi(getIpValue(list[middle - 1]).substr(0, 9)) &&        stoi(getIpValue(list[middle]).substr(9, 3)) == stoi(getIpValue(list[middle - 1]).substr(9, 3)))
                
                middle -= 1;
            
            return middle;
        }
        if (stoi(searchingValue.substr(0, 9)) == stoi(getIpValue(list[middle]).substr(0, 9)) && stoi(searchingValue.substr(9, 3)) != stoi(getIpValue(list[middle]).substr(9, 3))){
            
            if (stoi(searchingValue.substr(9, 3)) < stoi(getIpValue(list[middle]).substr(9, 3))){
                
                while (stoi(getIpValue(list[middle]).substr(0, 6)) == stoi(getIpValue(list[middle - 1]).substr(0, 6)) &&    stoi(getIpValue(list[middle]).substr(6, 6)) == stoi(getIpValue(list[middle - 1]).substr(6, 6)))

                    middle -= 1;

                return middle;
            }
            else if (stoi(searchingValue.substr(9, 3)) > stoi(getIpValue(list[middle]).substr(9, 3))){
                
                while ((stoi(getIpValue(list[middle]).substr(0, 6)) == stoi(getIpValue(list[middle + 1]).substr(0, 6))) && (stoi(getIpValue(list[middle]).substr(6, 6)) == stoi(getIpValue(list[middle + 1]).substr(6, 6))))

                    middle += 1;
                
                return middle + 1;
            }
        }
        if (stoi(searchingValue.substr(0, 9)) != stoi(getIpValue(list[middle]).substr(0, 9)) && stoi(searchingValue.substr(0, 9)) < stoi(getIpValue(list[middle + 1]).substr(0, 9)) && stoi(searchingValue.substr(0, 9)) > stoi(getIpValue(list[middle - 1]).substr(0, 9))){
            
            if (stoi(searchingValue.substr(0, 9)) < stoi(getIpValue(list[middle]).substr(0, 9))){
                
                return middle;
            }
            else if (stoi(searchingValue.substr(0, 9)) > stoi(getIpValue(list[middle]).substr(0, 9))){
                
                return middle + 1;
            }
        }
        if (stoi(searchingValue.substr(0, 9)) < stoi(getIpValue(list[middle]).substr(0, 9))){
            
            end = middle - 1;
        }
        else if (stoi(searchingValue.substr(0, 9)) > stoi(getIpValue(list[middle]).substr(0, 9))){
            
            beginning = middle + 1;
        }
        else if (stoi(searchingValue.substr(0, 9)) == stoi(getIpValue(list[middle]).substr(0, 9)) && stoi(searchingValue.substr(9, 3)) > stoi(getIpValue(list[middle]).substr(9, 3))){
            
            beginning = middle + 1;
        }
        else if (stoi(searchingValue.substr(0, 9)) == stoi(getIpValue(list[middle]).substr(0, 9)) && stoi(searchingValue.substr(9, 3)) < stoi(getIpValue(list[middle]).substr(9, 3))){
            
            end = middle - 1;
        }
    }
    return -1;
}

int ipBinarySearchFinalIndex(vector<string> &list, string searchingValue){
    
    int beginning = 0;
    
    int end = list.size() - 1;
    
    while (beginning <= end){
        
        int middle = (beginning + end) / 2;
        
        if (stoi(searchingValue.substr(0, 9)) == stoi(getIpValue(list[middle]).substr(0, 9)) && stoi(searchingValue.substr(9, 3)) == stoi(getIpValue(list[middle]).substr(9, 3))){
            
            while (stoi(getIpValue(list[middle]).substr(0, 9)) == stoi(getIpValue(list[middle - 1]).substr(0, 9)) &&        stoi(getIpValue(list[middle]).substr(9, 3)) == stoi(getIpValue(list[middle - 1]).substr(9, 3)))
                
                middle += 1;
            
            return middle;
        }
        if (stoi(searchingValue.substr(0, 9)) == stoi(getIpValue(list[middle]).substr(0, 9)) && stoi(searchingValue.substr(9, 3)) != stoi(getIpValue(list[middle]).substr(9, 3))){
            
            if (stoi(searchingValue.substr(9, 3)) < stoi(getIpValue(list[middle]).substr(9, 3))){
                
                while (stoi(getIpValue(list[middle]).substr(0, 6)) == stoi(getIpValue(list[middle - 1]).substr(0, 6)) &&    stoi(getIpValue(list[middle]).substr(6, 6)) == stoi(getIpValue(list[middle - 1]).substr(6, 6)))

                    middle -= 1;

                return middle;
            }
            else if (stoi(searchingValue.substr(9, 3)) > stoi(getIpValue(list[middle]).substr(9, 3))){
                
                while ((stoi(getIpValue(list[middle]).substr(0, 6)) == stoi(getIpValue(list[middle + 1]).substr(0, 6))) && (stoi(getIpValue(list[middle]).substr(6, 6)) == stoi(getIpValue(list[middle + 1]).substr(6, 6))))

                    middle += 1;
                
                return middle + 1;
            }
        }
        if (stoi(searchingValue.substr(0, 9)) != stoi(getIpValue(list[middle]).substr(0, 9)) && stoi(searchingValue.substr(0, 9)) < stoi(getIpValue(list[middle + 1]).substr(0, 9)) && stoi(searchingValue.substr(0, 9)) > stoi(getIpValue(list[middle - 1]).substr(0, 9))){
            
            if (stoi(searchingValue.substr(0, 9)) < stoi(getIpValue(list[middle]).substr(0, 9))){
                
                return middle;
            }
            else if (stoi(searchingValue.substr(0, 9)) > stoi(getIpValue(list[middle]).substr(0, 9))){
                
                return middle + 1;
            }
        }
        if (stoi(searchingValue.substr(0, 9)) < stoi(getIpValue(list[middle]).substr(0, 9))){
            
            end = middle - 1;
        }
        else if (stoi(searchingValue.substr(0, 9)) > stoi(getIpValue(list[middle]).substr(0, 9))){
            
            beginning = middle + 1;
        }
        else if (stoi(searchingValue.substr(0, 9)) == stoi(getIpValue(list[middle]).substr(0, 9)) && stoi(searchingValue.substr(9, 3)) > stoi(getIpValue(list[middle]).substr(9, 3))){
            
            beginning = middle + 1;
        }
        else if (stoi(searchingValue.substr(0, 9)) == stoi(getIpValue(list[middle]).substr(0, 9)) && stoi(searchingValue.substr(9, 3)) < stoi(getIpValue(list[middle]).substr(9, 3))){
            
            end = middle - 1;
        }
    }
    return -1;
}

int getInitialIpIndex(vector<string> &list, string firstPartInitialIp, string secondPartInitialIp, string thirdPartInitialIp, string fourthPartInitialIp){

    string initialIp = firstPartInitialIp + secondPartInitialIp + thirdPartInitialIp + fourthPartInitialIp;
    
    int initialIpIndex = ipBinarySearchInitialIndex(list, initialIp);
    
    return initialIpIndex;
}

int getFinalIpIndex(vector<string> &list, string firstPartFinalIp, string secondPartFinalIp, string thirdPartFinalIp, string fourthPartFinalIp){
    
    string finalIp = firstPartFinalIp + secondPartFinalIp + thirdPartFinalIp + fourthPartFinalIp;
    
    int finalIpIndex = ipBinarySearchFinalIndex(list, finalIp);
    
    return finalIpIndex;
}

void getIpRange(vector<string> &list){
    
    string firstPartInitialIp, secondPartInitialIp, thirdPartInitialIp, fourthPartInitialIp;
    
    cout << "\nINITIAL IP\n" << endl;
    
    cout << "Input the first part of the initial IP: "; cin >> firstPartInitialIp;
    
    if (firstPartInitialIp.size() == 1){
        
        firstPartInitialIp = "00" + firstPartInitialIp;
    }
    else if (firstPartInitialIp.size() == 2){
        
        firstPartInitialIp = "0" + firstPartInitialIp;
    }
    else if (firstPartInitialIp.size() > 3){
        
        cout << "\nInvalid value!\n" << endl;
        
        exit(1);
    }
    cout << "Input the second part of the initial IP: "; cin >> secondPartInitialIp;
    
    if (secondPartInitialIp.size() == 1){
        
        secondPartInitialIp = "00" + secondPartInitialIp;
    }
    else if (secondPartInitialIp.size() == 2){
        
        secondPartInitialIp = "0" + secondPartInitialIp;
    }
    else if (secondPartInitialIp.size() > 3){
        
        cout << "\nInvalid value!\n" << endl;
        
        exit(1);
    }
    cout << "Input the third part of the initial IP: "; cin >> thirdPartInitialIp;
    
    if (thirdPartInitialIp.size() == 1){
        
        thirdPartInitialIp = "00" + thirdPartInitialIp;
    }
    else if (thirdPartInitialIp.size() == 2){
        
        thirdPartInitialIp = "0" + thirdPartInitialIp;
    }
    else if (thirdPartInitialIp.size() > 3){
        
        cout << "\nInvalid value!\n" << endl;
        
        exit(1);
    }
    cout << "Input the fourth part of the initial IP: "; cin >> fourthPartInitialIp;
    
    if (fourthPartInitialIp.size() == 1){
        
        fourthPartInitialIp = "00" + fourthPartInitialIp;
    }
    else if (fourthPartInitialIp.size() == 2){
        
        fourthPartInitialIp = "0" + fourthPartInitialIp;
    }
    else if (fourthPartInitialIp.size() > 3){
        
        cout << "\nInvalid value!\n" << endl;
        
        exit(1);
    }
    string firstPartFinalIp, secondPartFinalIp, thirdPartFinalIp, fourthPartFinalIp;
    
    cout << "\nFINAL IP\n" << endl;
    
    cout << "Input the first part of the final IP: "; cin >> firstPartFinalIp;
    
    if (firstPartFinalIp.size() == 1){
        
        firstPartFinalIp = "00" + firstPartFinalIp;
    }
    else if (firstPartFinalIp.size() == 2){
        
        firstPartFinalIp = "0" + firstPartFinalIp;
    }
    else if (firstPartFinalIp.size() > 3){
        
        cout << "\nInvalid value!\n" << endl;
        
        exit(1);
    }
    cout << "Input the second part of the final IP: "; cin >> secondPartFinalIp;
    
    if (secondPartFinalIp.size() == 1){
        
        secondPartFinalIp = "00" + secondPartFinalIp;
    }
    else if (secondPartFinalIp.size() == 2){
        
        secondPartFinalIp = "0" + secondPartFinalIp;
    }
    else if (secondPartFinalIp.size() > 3){
        
        cout << "\nInvalid value!\n" << endl;
        
        exit(1);
    }
    cout << "Input the third part of the final IP: "; cin >> thirdPartFinalIp;
    
    if (thirdPartFinalIp.size() == 1){
        
        thirdPartFinalIp = "00" + thirdPartFinalIp;
    }
    else if (thirdPartFinalIp.size() == 2){
        
        thirdPartFinalIp = "0" + thirdPartFinalIp;
    }
    else if (thirdPartFinalIp.size() > 3){
        
        cout << "\nInvalid value!\n" << endl;
        
        exit(1);
    }
    cout << "Input the fourth part of the final IP: "; cin >> fourthPartFinalIp;
    
    if (fourthPartFinalIp.size() == 1){
        
        fourthPartFinalIp = "00" + fourthPartFinalIp;
    }
    else if (fourthPartFinalIp.size() == 2){
        
        fourthPartFinalIp = "0" + fourthPartFinalIp;
    }
    else if (fourthPartFinalIp.size() > 3){
        
        cout << "\nInvalid value!\n" << endl;
        
        exit(1);
    }
    int initialIpIndex = getInitialIpIndex(list, firstPartInitialIp, secondPartInitialIp, thirdPartInitialIp, fourthPartInitialIp);
    
    int finalIpIndex = getFinalIpIndex(list, firstPartFinalIp, secondPartFinalIp, thirdPartFinalIp, fourthPartFinalIp);
    
    cout << "\nSORTED BY IP" << endl;
    
    cout << "\n" << firstPartInitialIp << "." << secondPartInitialIp << "." << thirdPartInitialIp << "." << fourthPartInitialIp << " - " << firstPartFinalIp << "." << secondPartFinalIp << "." << thirdPartFinalIp << "." << fourthPartFinalIp << "\n" << endl;
    
    for (int i = initialIpIndex; i < finalIpIndex; i++){
        
        cout << list[i] << endl;
    }
}

vector<string> inputFile(){
    
    vector<string> list;
    
    string line;
    
    ifstream input("prueba.txt");
    
    ofstream output("salida.txt");
    
    if (input.is_open() && output.is_open()){
        
        while (getline(input, line)){
            
            list.push_back(line);
        }
    }
    for (int i = 0; i < list.size(); i++){

        output << list[i] << endl;
    }
    input.close();
    
    output.close();
    
    return list;
}

void printFile(vector<string> list){
    
    cout << "\nFILE\n" << endl;
    
    for (int i = 0; i < list.size(); i++){
        
        cout << list[i] << endl;
    }
}

int main(){
    
    vector<string> list = inputFile();
    
    cout << "\nMENU\n" << endl;
    
    cout << "1. Ordenar por fecha." << endl;
    
    cout << "2. Ordenar por IPs." << endl;
    
    cout << "3. Salir." << endl;
    
    int option;
    
    cout << "\nIngresa una opción: "; cin >> option;
        
    while (option != 3){
        
        switch (option){
                
            case 1:
                
                dateQuickSort(0, list.size() - 1, list);
                
                printFile(list);
                
                getDateRange(list);
                
                break;
                
            case 2:
                
                ipSort(list);
                
                printFile(list);
                
                getIpRange(list);
                
                break;
                
            case 3:
                
                break;
                
            default:
                
                cout << "Valor inválido!" << endl;
                
                break;
        }
        cout << "\nIngresa una opción: "; cin >> option;
    }
    return 0;
}
