#include <iostream>
#include <fstream>
#include <windows.h> 
//#include <string>    
//#include <thread>     ----- add for online compiler and remove window.h------------ 
//#include <chrono>

#include <sstream>
using namespace std;

class Hostel{
private:
 string Name;
int Rent, Bed;
public:
Hostel(string name, int rent, int bed){
 Name = name;
 Rent = rent;
 Bed = bed;	
}

string getName(){
return Name;
}

int getRent(){
 return Rent;
}

int getBed(){
 return Bed;
}

reserve(){      //void reserve()
ifstream in("D:/Hostel.txt");         //remove D:/ in both lines
ofstream out("D:/Hostel Temp.txt");

string line;
while(getline(in,line)){
int pos = line.find("3star");
if(pos != string::npos){

int bed = Bed-1;
Bed = bed;

stringstream ss;
ss<<bed;
string strBed = ss.str();

int bedPos = line.find_last_of(':');
line.replace(bedPos+1, string::npos, strBed);
}
out<<line<<endl;
}
out.close();
in.close();
remove("D:/Hostel.txt");
rename("D:/Hostel Temp.txt", "D:/Hostel.txt");        //remove  D:/
cout<<"\tBed Reserved Successfuly!"<<endl;
cout << "\tMonthly Rent: Rs. " << h.getRent() << endl;  // for print rent
}
};

class Student{
private:
string Name, RollNo, Address;
public:
Student():Name(""), RollNo(""),Address(""){}

setName(string name){
Name = name;
}

setRollNo(string rollNo){
 RollNo = rollNo;
}

setAddress(string address){
 Address = address;
}


string getName(){
	return Name;
}

string getRollNo(){
	return RollNo;
}

string getAddress(){
	return Address;
}

};

int main(){
Hostel h("3star", 5000, 2);
ofstream out("D:/Hostel.txt");
out<<"\t"<<h.getName()<<" : "<<h.getRent()<<" : "<<h.getBed()<<endl<<endl;
cout<<"Hostel Data Saved"<<endl;
out.close();

Student s;

bool exit = false;
while(!exit){
	system("cls");
 int val;
cout<<"\tWelcome To Hostel Accommodation System"<<endl;
cout<<"\t**************************************"<<endl;
cout<<"\t1.Reserve A Bed."<<endl;
cout<<"\t2.Exit."<<endl;
cout<<"\tEnter Choice: ";
cin>>val;

if(val==1){
system("cls");           //  remove
string name,rollNo, address;
cout<<"\tEnter Name of Student: ";
cin>>name;
s.setName(name);

cout<<"\tEnter RollNo of Student: ";
cin>>rollNo;
s.setRollNo(rollNo);

cout<<"\tEnter Address of Student: ";
cin>>address;
s.setAddress(address);

if(h.getBed() > 0){
h.reserve();
}

else if(h.getBed() ==0){
cout<<"\tSorry, Bed Not Available!"<<endl;
}
ofstream outFile("D:/Student.txt", ios::app);
outFile<<"\t"<<s.getName()<<" : "<<s.getRollNo()<<" : "<<s.getAddress()<<endl<<endl;
Sleep(5000);   // this_thread::sleep_for(chrono::seconds(5));
}

else if(val==2){
system("cls");      ///remove
exit = true;
cout<<"Good Luck!"<<endl;
Sleep(3000);              // this_thread::sleep_for(chrono::seconds(3));
}
}
}












// online compiler-------------------------------------------------------



#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
using namespace std;

class Hostel {
private:
    string Name;
    int Rent, Bed;

public:
    Hostel(string name, int rent, int bed) {
        Name = name;
        Rent = rent;
        Bed = bed;
    }

    string getName() {
        return Name;
    }

    int getRent() {
        return Rent;
    }

    int getBed() {
        return Bed;
    }

    void reserve() {
        ifstream in("Hostel.txt");
        ofstream out("Hostel_Temp.txt");

        string line;
        while (getline(in, line)) {
            int pos = line.find("3star");
            if (pos != string::npos) {
                Bed -= 1;

                stringstream ss;
                ss << Bed;
                string strBed = ss.str();

                int bedPos = line.find_last_of(':');
                line.replace(bedPos + 1, string::npos, strBed);
            }
            out << line << endl;
        }

        out.close();
        in.close();
        remove("Hostel.txt");
        rename("Hostel_Temp.txt", "Hostel.txt");

        cout << "\tBed Reserved Successfully!" << endl;
        cout << "\tMonthly Rent: Rs. " << Rent << endl;
    }
};

class Student {
private:
    string Name, RollNo, Address;

public:
    Student() : Name(""), RollNo(""), Address("") {}

    void setName(string name) {
        Name = name;
    }

    void setRollNo(string rollNo) {
        RollNo = rollNo;
    }

    void setAddress(string address) {
        Address = address;
    }

    string getName() {
        return Name;
    }

    string getRollNo() {
        return RollNo;
    }

    string getAddress() {
        return Address;
    }
};

int main() {
    Hostel h("3star", 5000, 2);
    ofstream out("Hostel.txt");
    out << "\t" << h.getName() << " : " << h.getRent() << " : " << h.getBed() << endl << endl;
    cout << "Hostel Data Saved" << endl;
    out.close();

    Student s;
    bool exit = false;

    while (!exit) {
        cout << "\n\n\tWelcome To Hostel Accommodation System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Reserve A Bed." << endl;
        cout << "\t2. Exit." << endl;
        cout << "\tEnter Choice: ";
        int val;
        cin >> val;

        if (val == 1) {
            string name, rollNo, address;
            cout << "\tEnter Name of Student: ";
            cin >> name;
            s.setName(name);

            cout << "\tEnter RollNo of Student: ";
            cin >> rollNo;
            s.setRollNo(rollNo);

            cout << "\tEnter Address of Student: ";
            cin >> address;
            s.setAddress(address);

            if (h.getBed() > 0) {
                h.reserve();
            } else {
                cout << "\tSorry, Bed Not Available!" << endl;
            }

            ofstream outFile("Student.txt", ios::app);
            outFile << "\t" << s.getName() << " : " << s.getRollNo() << " : " << s.getAddress() << endl << endl;
            outFile.close();

            this_thread::sleep_for(chrono::seconds(5));
        } else if (val == 2) {
            exit = true;
            cout << "Good Luck!" << endl;
            this_thread::sleep_for(chrono::seconds(3));
        }
    }

    return 0;
}
