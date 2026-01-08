#include <iostream>

using namespace std;

//I used 21 to be easy to use from 1 to 20
string names[21][5];
int status[21][5];
int len_of_spec[21];

void add_patient(){
    int spec , stat;
    string patient_name;
    cout << "What is specialization (1-20)? \n";
    cin >> spec;

    cout << "Enter patient name: \n";
    cin >> patient_name;

    cout << "Enter the status \n";
    cin>> stat;


    //close if there is no more
    if (len_of_spec[spec]==5)
    {  
        cout << "لا مؤاخذه يا باشا والله مفيش مكان \n";
        return ;
    }
    //regular status
    if (stat == 0) 
    {
        names[spec][len_of_spec[spec]]= patient_name;
        status[spec][len_of_spec[spec]]= stat;
        len_of_spec[spec]++;
    }
    //urgent
    else
    {
     for(int i = 0 ; i< len_of_spec[spec]-1;i++)
    {
        names[spec][i] = names[spec][i+1];
        status[spec][i] = status[spec][i+1];
    }
    len_of_spec[spec]--;
        //put the patient in frist
        names[spec][0] = patient_name;
        status[spec][0] = stat;
        len_of_spec[spec]++;

    }

}

void print_patient(){


    for(int j = 1 ; j < 21; j++)
    {
        if(len_of_spec[j] > 0)
        {
            cout << "Specialization " << j<< ":\n";
            for(int i = 0; i<len_of_spec[j];i++)
            {
                cout << names[j][i]<< ' ';
                if (status[j][i]) cout << "urgant\n";
                else cout  << "regular\n";
            }
        }
    }
}

void get_the_next(){
     int spec;
    cout << "Enter specialization: ";
    cin >> spec;
    if(len_of_spec[spec]==0)
    {
        cout <<"THere is no pateints!" ;
        return;
    }
   cout<< names[spec][0]<<' ';
if(status[spec][0]) cout << "urgant\n";
else cout << "regular\n";

for(int i = 0 ; i< len_of_spec[spec]-1;i++)
{
    names[spec][i] = names[spec][i+1];
    status[spec][i] = status[spec][i+1];
}
len_of_spec[spec]--;
    
}

int main() {
    int choice;


  while (true) {
        cout << "\n1) Add patient\n";
        cout << "2) Print patients\n";
        cout << "3) Doctor pickup\n";
        cout << "4) Exit\n";
        cin >> choice;

        if (choice == 1)
            add_patient();
        else if (choice == 2)
            print_patient();
        else if (choice == 3)
            get_the_next();
        else
            break;
    }
    
   
    return 0;
}


//DONE!
//hospital system project

