#include <iostream>
#include <utility>
#include <cmath>

#define v0 1 //krok
#define epsilon 0.000001 //błąd

#define n 2 //2 kierunki

using namespace std;

/**
    hooke jeeves dla 2 zmiennych
 */

double f(pair<double,double> x){
    return -pow(x.first, 2) + 2*pow(x.second, 2) -3*x.first*x.second - 3*x.second;
}

int main(int argc, const char * argv[]) {
    pair<double, double> x0 = make_pair(-1, 4); //punkt startowy, losowany
    double f2 = f(x0);
    double f0 = f2;
    double f1;
    double v = 0.0; //dlugosc kroku
    pair<double,double> x = x0; //aktualne przyblizenie rozwiazania, pierwsze jest losowane
    pair<double,double> x1;
    bool roboczy = false; //czy krok roboczy został wykonany
    bool temp = true;
    int k = 1; //kierunek szukania (mamy 2)
    int counter = 0; 
    v = v0; //krok
    
    do{
        counter ++;
        if (temp){
                k = 1; //2
        } temp = true;
        cout << counter << endl << "k = " << k << endl << x.first << " " << x.second << endl << "f(x) = " << f(x) << endl << endl;
    
        if(k == 1) x1 = make_pair(x.first + v, x.second); //3
        if(k == 2) x1 = make_pair(x.first, x.second + v);
    
        f1 = f(x1); //4
    
        if (f1 < f2){
            x = x1;
            f2 = f1;
        }
        
        else{
            if(k == 1) x1 = make_pair(x.first - v, x.second); //6
            if(k == 2) x1 = make_pair(x.first, x.second - v);
        
            f1 = f(x1);
        
            if (f1 < f2){
                x = x1;
                f2 = f1;
            }
        }
    
        if (k < n){ //9
            k++;
            temp = false;
            continue; //przejdz do 3
        }
    
        if (f2 < f1){
            x1 = x0;
            x0 = x;
            f0 = f2;
        
            roboczy = true;
        
            x = make_pair(x0.first + 1.5*(x.first-x1.first), x0.second + 1.5*(x.second-x1.second));
            f2 = f(x);
            v *= 1.25; cout << "wies";
            //przejdz do 12
        }
        else{
            if (roboczy){
                x = x0;
                f2 = f0;
                //przejdz do 12
            }
            else{
                if (v>epsilon) v *= 0.8;
            }
            roboczy = false;
        }
        //12
    } while(v > epsilon);
    
    cout << "f(" << x.first << " " << x.second << ") = " << f(x) << endl;
    
    return 0;
}
