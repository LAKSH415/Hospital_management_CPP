#include <iostream>
#include<vector>
using namespace std;
int pid;
int did;
class Patient{
    public:
    string name;
    string gender;
    int age;
    int id;
    Patient(string n,int a,string g){
        name=n;
        id=pid++;
        age=a;
        gender=g;
    }
};
class Doctor{
    public:
    string name;
    string gender;
    int age;
    int id;
    Doctor(string n,int a,string g){
        name=n;
        id=did++;
        age=a;
        gender=g;
    }
};
class Appointment{
    public:
    int patientID;
    int doctorID;
    string Date;
   
    Appointment(int p,int d,string date){
        Date=date;
        patientID=p;
        doctorID=d;
    }
};
vector<Patient>allPatients;
vector<Doctor>allDoctors;
vector<Appointment>allAppointments;
void addpatient(){
    string n,g;
    int a;
    cout<<"Give the patient name:"<<endl;
    cin>>n;
    cout<<"Give the patient age:"<<endl;
    cin>>a;
    cout<<"Give the patient gender(M/F):"<<endl;
    cin>>g;
    Patient temp(n,a,g);
    allPatients.push_back(temp);
}
void adddoctor(){
    string n,g;
    int a;
    cout<<"Give the doctor name:"<<endl;
    cin>>n;
    cout<<"Give the doctor age:"<<endl;
    cin>>a;
    cout<<"Give the doctor gender(M/F):"<<endl;
    cin>>g;
    Doctor temp(n,a,g);
    allDoctors.push_back(temp);
}
bool isPatientpresent(int id){
    for(int i=0;i<allPatients.size();i++){
        if(allPatients[i].id==id) return true;
    }
    return false;
}
bool isDoctorpresent(int id){
    for(int i=0;i<allDoctors.size();i++){
        if(allDoctors[i].id==id) return true;
    }
    return false;
}
void scheduleAppointment(){
    int patientID;
    int doctorID;
    string Date;
    cout<<"Give the patient ID:"<<endl;
    cin>>patientID;
    cout<<"Give the doctor ID:"<<endl;
    cin>>doctorID;
    cout<<"Give the date in DD-MM-YYYY:"<<endl;
    cin>>Date;
    if(!isPatientpresent(patientID) || !isDoctorpresent(doctorID)){
        cout<<"ID is invalid"<<endl;
        cout<<"Unsuccesful attempt"<<endl;
        return;
    }
    Appointment temp(patientID,doctorID,Date);
    allAppointments.push_back(temp);
}
void viewpatient(){
    for(int i=0;i<allPatients.size();i++){
        cout<<"Patient Name-"<<allPatients[i].name<<endl;
    }
}
void viewdoctor(){
    for(int i=0;i<allDoctors.size();i++){
        cout<<"Doctor Name-"<<allDoctors[i].name<<endl;
    }
}
void viewappointment(){
    for(int i=0;i<allAppointments.size();i++){
        cout<<allAppointments[i].patientID<<" has appointment with Doctor "<<allAppointments[i].doctorID<<" on "<<allAppointments[i].Date<<endl;
    }
}
int main() {
    int choice;
    do{
        cout<<"1.Add Patient"<<endl;
        cout<<"2.Add Doctor"<<endl;
        cout<<"3.Schedule Appointment"<<endl;
        cout<<"4.View Patients"<<endl;
        cout<<"5.View Doctors"<<endl;
        cout<<"6.View Appointments"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"Give your choice:"<<endl;
        cin>>choice;
        switch(choice){
        case 1:addpatient(); break;
        case 2:adddoctor(); break;
        case 3:scheduleAppointment(); break;
        case 4:viewpatient(); break;
        case 5:viewdoctor(); break;
        case 6:viewappointment(); break;
        default:
            cout<<"Invalid choice."<<endl;
        }
    }while(choice!=0);
}