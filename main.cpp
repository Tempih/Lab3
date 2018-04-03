#include<iostream>
#include<sstream>
#include<cassert>

using namespace std;
char Scale[]="CKF";
struct Temperature{
double temp;
char scale;
};
        istream & operator>>(istream& in,Temperature & Temp);
istream & operator>>(istream& in,Temperature & Temp)
{
in >> Temp.temp;
in >> Temp.scale;
}
void test_temperature_input(){
 Temperature Temp;
    string inp="10C";
istringstream iss(inp);
    iss>>Temp;
    assert(Temp.temp==10);
    assert(Temp.scale=='C');
    istringstream issK("0K");
    issK>>Temp;
    assert(Temp.temp==0);
    assert(Temp.scale=='K');
    istringstream issF("-400F");
    issF>>Temp;
    assert(Temp.temp==-400);
    assert(Temp.scale=='F');

}
double convert(const Temperature& Temp,char scale_to){
    double Kelvins;
    if(scale_to==Temp.scale){return Temp.temp;}
    switch (Temp.scale){
    case 'K':
    case 'k':
        Kelvins=Temp.temp;
    break;
    case 'C':
    case 'c':Kelvins+=-273.15;
    break;
    case 'F':
    case 'f':
        Kelvins=(5*(Temp.temp-32))/9+273.15;
break;
    };
scale_to=Temp.scale;
    switch (scale_to){
    case 'K':
    case 'k':
        return Kelvins;
    case 'C':
    case 'c':
        return Kelvins+=-273.15;
    case 'F':
    case 'f':
        return Kelvins=((9.0/5)*(Temp.temp-273)+32);
}}
    bool operator < (const Temperature & lhs,const Temperature& rhs){
    return convert(lhs,'K')< convert(rhs,'K');
    }
Temperature operator - (const Temperature & lhs,const Temperature & rhs )
{
    Temperature ret_temp;
    ret_temp.temp=convert(lhs,'K')-convert(rhs,'K');
ret_temp.scale='K';
    return ret_temp;
}
Temperature operator / ( const Temperature & lhs,const Temperature & rhs)
{
    Temperature ret_temp;
    ret_temp.temp=convert(lhs,'K')/convert(rhs,'K');
    ret_temp.scale='K';
    return ret_temp;
}
int main() {
    test_temperature_input();


    return 0;
}