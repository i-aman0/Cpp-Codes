#include<iostream>
using namespace std;
class Employee
{
   protected:
   //Data_Members
   

         string employeename;
         int employeeid;
         string employeedepartment;
         int employeesalary;
    //Member_Functions
        void input()
        {
            cout<<"Enter Employee Name:";
            cin>>employeename;
            cout<<"\n Enter Employee id";
            cin>>employeeid;
            cout<<"\n Enter Employee Department";
            cin>>employeedepartment;
            cout<<"\n Enter Employee Salary";
            cin>>employeesalary;
        }
         
};
class Bonus : public Employee{
    public:
    //Data_Member
        int Bonus1;
        int TotalSalary; 
        Bonus(){
            Employee::input();
        }
        void calc()
        {
            if(employeesalary<10000)
           Bonus1=0.5*employeesalary;
        else if (employeesalary>=10001 && employeesalary<20000)
           Bonus1=0.1*employeesalary;
        else if (employeesalary>=20001 && employeesalary<40000)
           Bonus1=0.15*employeesalary;
        else if(employeesalary>=40001 && employeesalary<50000)
           Bonus1=0.2*employeesalary;
        else if(employeesalary>=50001)
          Bonus1=0.25*employeesalary;
          cout<<"The total salary is : "<<employeesalary+Bonus1<<endl;
        }
         
        
};
int main()
{
    //Object for class Employee
    Employee E;
    //Object for class Bonus
    Bonus B; 
    
    B.calc();
    return 0;
}