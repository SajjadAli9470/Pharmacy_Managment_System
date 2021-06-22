#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>
#include<windows.h>
#include <ctime>
# define Size 1000
using namespace std;

size_t recno = 0;
// Stacksuse to Store all fetched data;
string *MedicStack = new string[Size];
int *PriceStack = new int[Size];
int *QuantStack = new int[Size];
// For Admin block




struct node{
    int id;
    string CustomerName;
    string date;
    int top;
    string Medic[Size];
    int Quant[Size];
    int Price[Size];
    int totalPrice;
    node*prev;
    node*next;
};
node*head=NULL;
node*tail=NULL;

// For Manager Block to Control All Information About Medicince like buy or Update Medic Stock impelement the Stack method here..

// for Welcome Designing
void Welcome();
// Manager have to required Login First to Move Further
bool Login();
// This Method Fetch All data About Medicines from record File
void FetchData();
// this method use to update every Possible Costimization
void UpdateData(int code,bool check);
// this method is to delete any Medicine
void DeleteData(int code,bool confirm);
// this method is used to Save Data in File
void SaveData();
// this method is used to Add medicine in Stock
void AddData();
// to Search about any Medicine
void SearchData();
// Display All information about Medicine
void DisplayData();
// Summary OF All Medicine
void MedicDisplay(int id);
// Expertize to Delete From Stack Using
void DeleteExpert(int pos);


// For Admin Block
void Create(int num);
void InsertEnd();
void InsertBegin();
bool checkEmpty();
void DeleteBegin();
void DeleteEnd();
void DeletePosition();
void Display();
void TakeOrder();
void UpdateOrder();
void DisplaySort( int size);
void Sort( int low, int high);
int ListDivision ( int low, int high);
void swappingName(int i,int j);
void swappingValue(int MedicStack[],int i,int j);



void SearchOrder();
void Searching();
void AllOrdersDetail();
bool CorrectID(int id);
bool CorrectQuantity(int id,int quant);
void AddMedic(node *temp);
void DisplayNodeArray(struct node *temp);
void FetchCustomerData();
void SaveCustomerData();
void MainMenu();
void AdminMenu();
void ManagerMenu();
void BuyMedic(string custName);
void TakeCustomerPosition();
void CustomersSummary();
void RemovePosition();
string GetTime();

int main()
{
    // FetchData();
    // FetchCustomerData();
    // Create(1);
    // Display();
    // Display();
    // TakeCustomerPosition();

    system("CLS");
    system("Color 70");
    FetchData();
    FetchCustomerData();
    // Create(2);
    // DisplayData();
    char choiceLogin,choiceAdmin,choiceManager;
    
    do{ 
         system("CLS");
         Welcome();
         MainMenu();
    cout<<"\t\t\t\t\tSelect Require Login Option : ";  cin>>choiceLogin;
    choiceLogin=(char)tolower(choiceLogin);
        switch(choiceLogin){

        case 'm' :{
            
           
            if(Login()==true){
                system("CLS");
                ManagerMenu();
                do{
                    cout<<"\t\t\t\t\tSelect Require Option to Manage : ";  cin>>choiceManager;
                    choiceManager=(char)tolower(choiceManager);
                    switch(choiceManager){
                    case 'a':{
                        AddData();
                        break;
                    }
                    case 'u':{
                        UpdateData(0,false);
                        break;
                    }
                    case 'd':{
                        DeleteData(0,false);
                        break;
                    }
                    case 's':{
                        SearchData();
                        break;
                    }
                    case 'm':{
                        cout<<endl;
                        cout<<endl;
                        DisplayData();
                        int c=0;
                        char merzi;
                        bool check=false;
                        do{
                            c++;
                            if(c==1){    
                                cout<<"\t\t\t\tIs you Want to Update Any Record(y/n) : "; cin>>merzi;
                            }
                            else{
                                cout<<"\t\t\t\tPlease Select *valid Options\n ";
                                cout<<"\t\t\t\tIs you Want to Update Any Record(y/n) : "; cin>>merzi;

                            }
                            merzi=(char)tolower(merzi);
                            if(merzi=='y'||merzi=='n'){
                                check=true;
                            }
                            else{
                                check=false;
                            }
                        }while(check!=true);
                        
                        if(merzi=='y'){
                            system("CLS");
                            UpdateData(0,false);
                        }
                        else{
                            system("CLS");
                            ManagerMenu();
                        }
                        break;
                    }
                    case 'e':{
                        cout<<"\t\t\t\t\tManager--Menu  Exited......\n";
                    }
                    default:{
                        cout<<"\n\t\t\t\tPlease Select Valid Option....thanks\n";
                    }
                    
                    }
                }while (choiceManager!='e');

            }

            break;
        }
        case 'a' :{
            system("CLS");
            AdminMenu();
            do{
                cout<<"\t\t\t\tSelect Require Option as Admin : ";  cin>>choiceAdmin;
                choiceAdmin=(char)tolower(choiceAdmin);
                switch(choiceAdmin){
                    case 'a' :{
                        TakeOrder();
                        break;
                    }
                    case 'u' :{
                        TakeCustomerPosition();
                        break;
                    }
                    case 's' :{
                        Searching();
                        break;
                    }
                    case 'd' :{
                        RemovePosition();
                        break;
                    }
                    case 'o' :{
                        system("CLS");
                        Display();
                         int c=0;
                        char merzi;
                        bool check=false;
                        do{
                            c++;
                            if(c==1){    
                                cout<<"\t\t\t\tIs you Want to Update Any Record(y/n) : "; cin>>merzi;
                            }
                            else{
                                cout<<"\t\t\t\tPlease Select *valid Options\n ";
                                cout<<"\t\t\t\tIs you Want to Update Any Record(y/n) : "; cin>>merzi;

                            }
                            merzi=(char)tolower(merzi);
                            if(merzi=='y'||merzi=='n'){
                                check=true;
                            }
                            else{
                                check=false;
                            }
                        }while(check!=true);
                        
                        if(merzi=='y'){
                            system("CLS");
                        TakeCustomerPosition();
                        }
                        else {
                            system("CLS");
                            AdminMenu();
                        }
                        break;
                    }
                    case 'e' :{
                        cout<<"\t\t\t\t\tAdmin--Menu  Exited......\n";
                        break;
                    }
                    default:{
                        cout<<"\n\t\t\t\tPlease Select Valid Option....thanks\n";
                    }
                }

            }while(choiceAdmin!='e');

            break;
        }
        case 'g':{
            system("cmd/c start https://guessanumber-32d75.web.app");
            break;
        }
        case 'e':{
            cout<<"\t\t\t\t\tPharmacy Managment System Exited......\n";
        
            break;
        }
        default:{
            cout<<"\n\t\t\tPlease Select Valid Option....thanks\n";
        }


    }
    
    }while(choiceLogin!='e');

    

    SaveData();
    SaveCustomerData();
    return 0;
}
string GetTime(){
   
                 time_t ct = time(0);
                 char* cc = ctime(&ct);
                string date="";
                for(int i=0;i<24;i++){
                cout<<cc[i]<<" : "<<i<<endl;
                date+=cc[i];
                }
                     
 return date;

}
void MainMenu(){
    cout<<"\n\n\t\t\t\t   -------------MENU FOR LOGIN-------------\n";
        cout<<"\t\t\t\t              MANAGER : PRESS M/m          \n";
        cout<<"\t\t\t\t              ADMIN   : PRESS A/a          \n";
        cout<<"\t\t\t\t              GAME    : PRESS G/g          \n";
        cout<<"\t\t\t\t              EXIT    : PRESS E/e          \n";
        cout<<"\t\t\t\t   ----------------------------------------\n";
}
void AdminMenu(){
    cout<<"\n\n\t\t\t\t--------------------MENU FOR ADMIN---------------------\n";
        cout<<"\t\t\t\t          ADD    CUSTOMER  DATA : PRESS A/a            \n";
        cout<<"\t\t\t\t          UPDATE CUSTOMERS DATA : PRESS U/u            \n";
        cout<<"\t\t\t\t          SEARCH CUSTOMERS DATA : PRESS S/s            \n";
        cout<<"\t\t\t\t          DELETE CUSTOMERS DATA : PRESS D/d            \n";
        cout<<"\t\t\t\t          ORDERS SUMMARY        : PRESS O/o            \n";
        cout<<"\t\t\t\t          GOTO   MAIN MENU      : PRESS E/e            \n";
        cout<<"\t\t\t\t-------------------------------------------------------\n";
}
void ManagerMenu(){
    cout<<"\n\n\t\t\t\t-------------MENU FOR MANAGER--------------\n";
        cout<<"\t\t\t\t       ADD    MEDICINE   : PRESS A/a       \n";
        cout<<"\t\t\t\t       UPDATE MEDICINE   : PRESS U/u       \n";
        cout<<"\t\t\t\t       DELETE MEDICINE   : PRESS D/d       \n";
        cout<<"\t\t\t\t       SEARCH MEDICINE   : PRESS S/s       \n";
        cout<<"\t\t\t\t       MEDICS SUMMARY    : PRESS M/m       \n";
        cout<<"\t\t\t\t       GOTO   MAINMENU   : PRESS E/e       \n";
        cout<<"\t\t\t\t-------------------------------------------\n";
}
void Welcome(){

      cout<<"\t\t\t\t\t ____________________________\n";
      cout<<"\t\t\t\t\t|           _____            |\n";
      cout<<"\t\t\t\t\t|          |     |           |\n";
      cout<<"\t\t\t\t\t|      ____|     |____       |\n";
      cout<<"\t\t\t\t\t|     |               |      |\n";
      cout<<"\t\t\t\t\t|     |    PHARMACY   |      |\n";
      cout<<"\t\t\t\t\t|     |____       ____|      |\n";
      cout<<"\t\t\t\t\t|          |     |           |\n";
      cout<<"\t\t\t\t\t|          |_____|           |\n";
      cout<<"\t\t\t\t\t|____________________________|\n";
      cout<<"\t\t\t\t\t     WELCOME TO PHARMACY      \n";
}
void BuyMedic(string custName){
    
            cout<<"\t\t\t\t\t\t         MEDICS FOR "<<custName<<"\n";
            cout<<"\t\t\t\t\t\t  ---------------------------------------\n";
            cout<<"\t\t\t\t\t\t |       ADD MORE MEDICS : PRESS A/a     |\n";
            cout<<"\t\t\t\t\t\t |       GOTO NEXT       : PRESS E/e     |\n";
            cout<<"\t\t\t\t\t\t  ---------------------------------------\n";
}
// MANAGER BLOCK
void swappingValue(int Values[],int i,int j){
     int temp=Values[i];
			Values[i]=Values[j];
			Values[j]=temp;
}
void swappingName(int i,int j){
     string temp=MedicStack[i];
			MedicStack[i]=MedicStack[j];
			MedicStack[j]=temp;
      swappingValue(QuantStack,i,j);
      swappingValue(PriceStack,i,j);
}
int ListDivision (int low, int high)
{
    string pivot = MedicStack[high]; 
    int i = (low - 1); 
	for (int j = low; j <= high - 1; j++)
    {
        if (MedicStack[j] < pivot)
        {

            i++;
  swappingName(i,j);
        }
    }
    swappingName(i+1,high);

    return (i + 1);
}
void Sort( int low, int high)
{
    if (low < high)
    {
        int pi = ListDivision(low, high);
        Sort(low, pi - 1);
        Sort(pi + 1, high);
    }
}
void MedicDisplay(int id){
        cout<<"\t\t\t\t ------------------"<<MedicStack[id]<<"------------------\n";
        cout<<"\t\t\t\t           Product ID : "<<id<<"                  \n";
        cout<<"\t\t\t\t           Medic Name : "<<MedicStack[id]<<"      \n";
        cout<<"\t\t\t\t           Price      : "<<PriceStack[id]<<"      \n";
        cout<<"\t\t\t\t           Quantity   : "<<QuantStack[id]<<"      \n";
        cout<<"\t\t\t\t -------------------------------------------\n";
}
bool Login(){
    string userName;
    string userpassword;
    bool login=false;
    int count=0;
    while(login!=true){
        count++;
        if(count==5){
            login=false;
            cout<<"\t\t\tYou excced the limit.Please tryagain later.....\n";
            break;
        }
        if(count==1){
        cout<<"\t\t\t\tEnter UserName : "; cin>>userName;
        cout<<"\t\t\t\tEnter UserPassword : "; cin>>userpassword;
        }
        else{
        cout<<"\t\t\t\tEnter *Valid UserName : "; cin>>userName;
        cout<<"\t\t\t\tEnter *Valid UserPassword : "; cin>>userpassword;
        }
        if(userName=="admin" && userpassword=="123"){
            login=true;
        }
        

        }
    // cout<<"it's Okay\n";
    return login;

}
void FetchData(){
    string line;
    int num;
    int countLine=0,medic=1,quant=2,price=3;
	ifstream records_input("records.txt"); // create a file stream  for reading 
	while (getline(records_input, line)) // count all the lines from the file
	{
        countLine++; //count all the lines from the file
       

        if(countLine==medic){
            MedicStack[recno]=line;
            // cout <<"Medicince Name : "<< line << endl;
                medic+=3;
        
        }
        else if(countLine==quant){
            istringstream ( line ) >> num;
            QuantStack[recno]=num;
            // cout <<"Total Quantity : "<< line << endl;
            quant+=3;
        
        }
        else if(countLine==price){
            istringstream ( line ) >> num;
            PriceStack[recno]=num;
            // cout <<"Price per Drug : "<< line << endl;
            price+=3;
            recno++;
        }
 
	}
	records_input.close();
    
    // DisplayData();

    

}
void UpdateData(int code,bool check){
    char choice;
   
            int recno2;
            if(check==true){
                recno2=code;
            }
            else{
                DisplayData();
                cout << "\t\t\t\tEnter Medicince(ID) which you like to Update : ";
                cin >> recno2; // get the user to pick a record
            }
            if (recno2 < 0 || recno2 >= recno) // validate their choice
            {
                cout << "\t\t\t\t\tInvalid choice of ID (id>0 && id<"<<recno<<") "<< endl;
            }
            else
            {
                do
                    {
                        system("CLS");
                        MedicDisplay(recno2);
                        cout << "\n\t\t\t\tYou have chosen to Update record " << recno2 << " : " <<MedicStack[recno2]<<endl;
                        cout<<"\t\t\t\t---------MEDICINE UPDATE MENU----------\n";
                        cout<<"\t\t\t\t     MEDICINE NAME     : PRESS N/n      \n";
                        cout<<"\t\t\t\t     MEDICINE PRICE    : PRESS P/p      \n";
                        cout<<"\t\t\t\t     MEDICINE QUANTITY : PRESS Q/q      \n";
                        cout<<"\t\t\t\t     MEDICINE FULL     : PRESS F/f      \n";
                        cout<<"\t\t\t\t     EXIT TO MANAGER   : PRESS E/e      \n";
                        cout<<"\t\t\t\t---------------------------------------\n";
                        
                        cout<<"\t\t\t\t\tSelect Required Option : "; cin>>choice;
                        choice=(char)tolower(choice);
                        string nam;
                        int pr,quant;
                        switch (choice)
                        {
                        case 'p' :
                            {   
                                cout<<"\t\t\t\t\tEnter Price of Medicince : "; int pr; cin>>pr;
                                
                                PriceStack[recno2]=pr;
                                break;
                            }
                        case 'n' :
                            {               
                                    
                                cout<<"\t\t\t\t\tEnter Name of Medicince : ";  
                                cin.ignore();
                                getline(cin,nam);
                                MedicStack[recno2]=nam;
                                break;
                            }
                        case 'q' :
                            {               
                                    
                                cout<<"\t\t\t\t\tEnter Quantity of Medicince : ";  
                                cin>>quant;
                                // auto q = to_string(quant);
                                QuantStack[recno2]=quant;
                                break;
                            }
                        case 'a' :
                            {   
                                
                                cout<<"\t\t\t\t\tEnter Name of Medicince : "; 
                                cin.ignore(); 
                                getline(cin,nam);
                                MedicStack[recno2]=nam;

                                cout<<"\t\t\t\t\tEnter Price of Medicince : ";  
                                cin>>pr;
                                // auto price = to_string(pr);
                                PriceStack[recno2]=pr;

                                cout<<"\t\t\t\t\tEnter Quantity of Medicince : ";  
                                cin>>quant;
                                // auto q = to_string(quant);
                                QuantStack[recno2]=quant;
                                break;
                            }
                        case 'd' : {
                            DeleteData(recno2,true);
                        }
                        case 'e': {
                            system("CLS");
                            ManagerMenu();
                            break;
                            
                        }
                        
                        default:
                        cout<<"\t\t\t\t\tPlease Select Valid Option from Menu";
                            break;
                        }
                }while(choice!='e');
                
            }
    
    
    SaveData();
    // system("CLS");
    // ManagerMenu();
    
}
void DeleteExpert(int a[],int pos,string b[],bool integer){
     if(integer==true){
            for(int i=pos; i<recno;i++)
                {
                    a[i]=a[i+1];
                }
        }
    else{
        for(int i=pos; i<recno;i++)
                {
                    b[i]=b[i+1];
                }
    }
}
void DeleteData(int code,bool confirm){
    char choice;
    size_t recno1 = 0;
    do{
            if(confirm==true){
              recno1=code;  
            }
            else{
            DisplayData();
            cout << "\t\t\t\tEnter Medicine(ID) you like to delete : ";
            cin >> recno1;
            }; // get the user to pick a record
            
            if (recno1 < 0 || recno1 >= recno) // validate their choice
            {
                cout << "\t\t\t\tInvalid choice" << endl;
            }
            else
            {
                cout << "\t\t\t\tYou have chosen to delete record " << recno1<<" : "<<MedicStack[recno1]<<endl;
                DeleteExpert(QuantStack,recno1,MedicStack,false);
                DeleteExpert(QuantStack,recno1,MedicStack,true);
                DeleteExpert(PriceStack,recno1,MedicStack,true);
                recno--; // blank out users choice 
            }
            cout<<"\t\t\t\tMedicine "<<MedicStack[recno1]<<" Deleted Successfully....\n";
            SaveData();
            
            cout<<"\n\t\t\t\tDo you want to Delete More Data(y/n) : "; cin>>choice;
            choice=(char)tolower(choice);
            confirm=false;
    }while(choice!='n');
    system("CLS");
    ManagerMenu();
}
void SaveData(){
    Sort(0,recno);
    ofstream records_output("records.txt"); // create a file stream and open the file for output
	for (size_t i = 0; i < recno; i++) // write out the new records to screen
	{
		if (!MedicStack[i].empty())
		{
			records_output << MedicStack[i] << endl;// also overwrite the original file 
			records_output << QuantStack[i] << endl;// also overwrite the original file 
			records_output << PriceStack[i] << endl;// also overwrite the original file 
		}
	}
    // DisplayData();
	records_output.close(); // close the file
}
void AddData(){

   
    char choice;
    string nam;
    int pr,quant;
   
    do{
    cout<<"\t\t\t(A/a)Add Medicine(E/e) to Exit MENU...  : "; cin>>choice;
    choice=(char)tolower(choice);
        switch (choice)
            {
            case 'a' :
            {   
                        // cout<<recno<<"Befor Add\n";
                        
                        
                        cout<<"\t\t\t\t\tEnter Name of Medicince : "; 
                        cin.ignore(); 
                        getline(cin,nam);
                        
                        MedicStack[recno]=nam;
                        // cout<<MedicStack[recno]<<"----\n";
                        
                        cout<<"\t\t\t\t\tEnter Price of Medicince : ";  
                        cin>>pr;
                        // auto price = to_string(pr);
                         
                        PriceStack[recno]=pr;
                        // cout<<PriceStack[recno]<<"----\n";
                        
                        cout<<"\t\t\t\t\tEnter Quantity of Medicince : ";  
                        cin>>quant;
                        // auto q = to_string(quant);
                        QuantStack[recno]=quant;

                        // cout<<QuantStack[recno]<<"----\n";

                        // cout<<recno<<"After Add\n";
                        recno++;
                        break;
                        
            }
            case 'e' : {
                        system("CLS");
                        ManagerMenu();
                        break;
            }
            
            default:
                        {

                        cout<<"\t\t\t\tInvalid Choice\n";
                        break;}

            }
    
    }while(choice!='e');
    SaveData();
}
void DisplayData(){
    
    cout<<"\t\t\t\t----------------MEDICINES DATA------------------\n";
      cout<<"\t\t\t\t  ID / MEDIC / PRICE(Rs) / QUANTITY\n";
    	for (size_t i = 0; i < recno; i++) 
            {  
            
            cout<<"\t\t\t\t"<<i<<"\t"<<MedicStack[i]<<"\t"<<PriceStack[i]<<"\t"<<QuantStack[i]<<endl;
        }
    cout<<"\t\t\t\t------------------------------------------------\n";
    
    cout<<endl;
}
void SearchData(){
    string MediName;
    int id=-1;
    cin.ignore();
    cout<<"\t\t\t\t\tEnter Medicine Name to Search : "; 
    getline(cin,MediName);
    cout<<MediName;
    for(int i=0;i<recno;i++)
    {
        if(MediName==MedicStack[i]){
        id=i;
        break;
        }

    }
    if(id>-1){

        MedicDisplay(id);
        cout<<"\t\t\t\tYou Want to Edit this Record(y/n) : "; char merzi; cin>>merzi;
        merzi=(char)tolower(merzi);
        if(merzi=='y'){
            system("CLS");
            UpdateData(id,true);
        }
    }
    else{
        cout<<"\t\t\t\t Sorry "<<MediName<<" is Not Avaliable yet!.....\n";
    }
   
}
// ADMIN BLOCK
void FetchCustomerData(){
    
    
    
    string line;
    int num;
    int countLine=0;
	int countCustomer=1;
    int countMedic=0;
    int initialTop=0;
    ifstream records_input("CustomerRecord.txt"); 
    int medic=0,quant=0,price=0;
    int top=0;
    int lastLine=0;
    struct node*ptr;
    while (getline(records_input, line)) // count all the lines from the file
	{
        
        countLine++;
        // this one count the lines from my file...
        
            if(countLine==1){
                medic=6;
                quant=7;
                price=8;
                ptr=new node();
                // cout<<"probelem"<<line<<endl;
                istringstream ( line ) >> num;
                
                ptr->id=num;
                
                // cout<<ptr->id<<endl;
            
            }
            
            else if(countLine==2){
            // cout<<"countLine : "<<countLine<<endl;
                string name=line;
                // cout<<line<<endl;
                ptr->CustomerName=name;
                // cout<<ptr->CustomerName<<endl;
            }
            else if(countLine==3){
            // cout<<"countLine : "<<countLine<<endl;
                // string name=line;
                // cout<<line<<endl;
                ptr->date=line;
                // cout<<ptr->date<<endl;
            }
            
            else if(countLine==4){
            // cout<<"countLine : "<<countLine<<endl;
            // cout<<"probelem"<<line<<endl;
                // top=stoi(line);
                istringstream ( line ) >> top;
                ptr->top=top;
                // cout<<ptr->top<<endl;
            
            }
            else if(countLine==5){
            // nothing to do with this because its not to save in data so i skipp this one line
            
            }
            // cout<<"\t\t\t TOP of "<<countCustomer<<" = "<<top<<endl;
            else if(initialTop<top){ 
            // initialTop is top mean numbers of Medic
            // at first medics is intialize with 6
            // at first quant is intialize with 7
            // at first price is intialize with 7
                            if(countLine==medic){
                                
                                string medicname=line;
                                ptr->Medic[initialTop]=medicname;
                                medic=medic+3;
                            
                            }
                            else if(countLine==quant){
                                istringstream ( line ) >> num;
                                ptr->Quant[initialTop]=num;
                                quant+=3;
                            
                            }
                            else if(countLine==price){
                                // cout<<"Price : "<<price;

                                istringstream ( line ) >> num;
                                ptr->Price[initialTop]=num;
                                // cout<<"Price :"<<ptr->Price[initialTop]<<endl;
                                price+=3;

                                initialTop++;
                            }
              }
              else  if(line=="Total Price : "){
                //   skipped
                //   cout<<"countLine : "<<countLine<<endl;
                //   cout<<""<<line<<endl;
              }
              else if(line=="--------------------"){
                //   skipped
                //   cout<<line<<endl;
              }
              else{
                      double total=0;
                    
                      istringstream ( line ) >> total;
                        // cout<<"countLine : "<<countLine<<endl;
                    //   cout<<total<<endl;
                      ptr->totalPrice=total;
                    //   cout<<ptr->totalPrice<<endl;
              }
     
        if(countCustomer==1&&line=="--------------------"){
            // cout<<line<<endl;
            countLine=0;
            initialTop=0;
            countCustomer++;
            // cout<<"countLine : "<<countLine<<endl;
            // cout<<"first round Compeleted"<<endl;
            head=ptr;
            ptr->next=NULL;
            ptr->prev=NULL;
            tail=ptr;
            // // cout<<"Header : "<<head<<endl;    
            // cout<<"tail : "<<tail<<endl;    
            }
        else if(countCustomer>1&&line=="--------------------"){
            countLine=0;
            initialTop=0;
            countCustomer++;
            // cout<<"2"<<line<<endl;
            // cout<<"for 2nd Header : "<<head<<endl;    
            // cout<<"for 2nd tail : "<<tail<<endl;
            // cout<<"for 2ndPrevious Result : "<<tail;
            tail->next=ptr;
            ptr->prev=tail;
            ptr->next=NULL;
            tail=ptr;
            // cout<<"for 2nd Header : "<<head<<endl;    
            // cout<<"Now tail : "<<tail<<endl;
            // cout<<"for 2ndPrevious Result : "<<tail;    

        }



        }
       
 records_input.close();
 
	}
void SaveCustomerData(){
    ofstream records_output("CustomerRecord.txt"); // create a file stream and open the file for output
	
    struct node*ptr;
    ptr=head;
    
    if(ptr==NULL){
        cout<<"\n\t\t\t\tNo Data to Store..........\n\n";
    }
    else{

        while(ptr!=NULL){
            records_output<<ptr->id<<endl;
            records_output<<ptr->CustomerName<<endl;
            // cout<<ptr->date;
            records_output<<ptr->date<<endl;

            // cout<<ptr->top<<"**\n";
            records_output<<(ptr->top)<<endl;
            records_output<<"Medicince Detail : "<<endl;
            for(int i=0;i<ptr->top;i++){
                records_output<<ptr->Medic[i]<<endl;
                records_output<<ptr->Quant[i]<<endl;
                records_output<<ptr->Price[i]<<endl;
            }
            records_output<<"Total Price : "<<endl;
            records_output<<ptr->totalPrice<<endl;
            records_output<<"--------------------"<<endl;

            ptr=ptr->next;

        }


    }

    // cout<<"\t\t\t\t\tData Stored Sucessfully....\n";    
	records_output.close(); // close the file
}     
void DisplayNodeArray(struct node *temp){
  
    for(int i=0;i<temp->top;i++){
        cout<<"\t\t\t\t"<<i<<")   Medic : "<<temp->Medic[i]<<"   Price : "<<temp->Price[i]<<"   Quantity : "<<temp->Quant[i]<<endl;
    }
    
}
void AddMedic(node*temp){
    
   char choice;
    do{
        int id;
        int quant;
        
               
                    bool check=false;
                    while(check!=true)
                    {   
                        cout<<"\t\t\t\tSelect Medic(ID) From TABLE to buy : ";  cin>>id; 
                        check=CorrectID(id);
                    }
                temp->Medic[temp->top]=MedicStack[id];

                    check=false;
                    while(check!=true)
                    {   
                        cout<<"\t\t\t\tEnter Quantity of Order "<<MedicStack[id]<<" (x<"<<QuantStack[id]<<") : ";  cin>>quant; 
                        check=CorrectQuantity(id,quant);
                    }
                QuantStack[id]=QuantStack[id]-quant;
                temp->Quant[temp->top]=quant;
                temp->Price[temp->top]=PriceStack[id]*quant;
                temp->top++;
                
                cout<<"\t\t\t\tIs You Want To Buy More Medics (y/n) : ";  cin>>choice;
                choice=(char)tolower(choice);

    }while(choice!='n');
                

}
bool CorrectQuantity(int id,int quant){
    bool check=false;
    if(quant>0&&quant<=QuantStack[id]){
        check=true;
    }
    else{
        check=false;
        cout<<"\nQuantity must less than "<<QuantStack[id]<<endl;
    }

    return check;

}
bool CorrectID(int id){
                    
                    
      bool check=false;                  
        if(id>=0&&id<recno){
           check=true;
         }
        else{
           check=false;
           cout<<"\nValidate ID must be less than"<<recno<<endl;
         }
                    
    return check;

}
void Create(int num){
    
    node* temp,*start;
    // start=head;
    for(int i=1;i<=num;i++){
       cout<<"\t\t\t\t\tCUSTOMER # "<<i<<endl;
       
        if(head==NULL){
            // cin.ignore();
            cout<<"\t\t\t\tName of Customer : "; string name; getline(cin,name);
            temp=new node();
            head=temp;
            temp->id=1;
            temp->CustomerName=name;

            
                    //   BuyMedic(name);         
                      DisplayData();
                      AddMedic(temp);
                    int TotalPrice=0;
                    for(int i=0;i<temp->top;i++){
                     
                        TotalPrice+=temp->Price[i];
                    }
             
            temp->date=GetTime();
            temp->totalPrice=TotalPrice;
            temp->next=NULL;
            temp->prev=NULL;
              cout<<"\n-----------------\n";             
            
        }
        else{
            
            InsertEnd();
        }
 


    }
    SaveCustomerData();
    SaveData();
    system("CLS");
    AdminMenu();
    // DisplayData();
}
void InsertEnd(){
     
    if(head==NULL){
        Create(1);
    }
    else{
          
    node *temp,*ptr;
    ptr=head;
    
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    
    temp=new node();
        cin.ignore();
     cout<<"\t\t\t\tName of Customer : "; string name; getline(cin,name);
            
            temp->id=ptr->id+1;
            temp->CustomerName=name;
                    DisplayData();          
                    AddMedic(temp);
                    int TotalPrice=0;
                    for(int i=0;i<temp->top;i++){
                        TotalPrice+=temp->Price[i];
                    }
                    
            
            temp->date=GetTime();     
            temp->totalPrice=TotalPrice;
            temp->next=NULL;
            temp->prev=ptr;
            ptr->next=temp;
            tail=temp;
    }
}
void DeleteEnd(){
    if(head==NULL){
        cout<<"\tAlready Empty...\n";
    }
    else{
        node* ptr;
        ptr=head;
        // This if/Else Additional for Additional bug
        if(ptr->next==NULL){
            cout<<"\t\t\t\tSucessfully Deleted :"<<ptr->CustomerName<<" \n";
            delete ptr;
            head=NULL;
            
        }
        else
        {
        // Main to learn :
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                cout<<"\t\t\t\tSucessfully Deleted :"<<ptr->CustomerName<<" \n";
                ptr->prev->next=NULL;
                ptr->prev=NULL;
                delete ptr;
        }
       
    }
}
void DeleteBegin(){
    node* ptr=head;
    if(head==NULL){
        cout<<"\tAlready Empty...\n";
    }
    else{
        // For Additional Bug
        if(ptr->next==NULL){
            cout<<"\tA Sucessfully Deleted :"<<ptr->CustomerName<<" \n";
            delete ptr;
            head=NULL;
        }
        else{
            // Main to learn
             cout<<"\t Sucessfully Deleted :"<<ptr->CustomerName<<" \n";
            head=ptr->next;
            delete ptr;
            head->prev=NULL;
             
        }
        
    }
}
void DeletePosition(int pos){
    node*PrevNode,*PosNode;
    PosNode=head;
    // if its a First Value
   if(PosNode!=NULL){
            if(pos==1){
                DeleteBegin();
            }
            else{
                for(int i=1;i<pos;i++){

                    PrevNode=PosNode;
                    PosNode=PosNode->next;    
                
                }
                // if its a last Value
                if(PosNode->next==NULL){
                    DeleteEnd();
                }
                else{
                    // Main to learn
                    cout<<"\t\t\tSucessfully Deleted :"<<PosNode->CustomerName<<" \n";
                    PrevNode->next=PosNode->next;
                    PosNode->next->prev=PrevNode;
                    delete PosNode;
                }
            }
   }
   else{
       cout<<"\tList already is Empty\n";
   }
   SaveCustomerData();
}
void UpdateOrder(int pos){
    struct node *PrevNode;
    struct node *PosNode;
    PosNode=head;
    char choice;
    string name;
    if(PosNode!=NULL){
         for(int i=1;i<pos;i++){

              PrevNode=PosNode;
              PosNode=PosNode->next;    
                            
                            } 
                          
         cout<<"\t\t\t\t ---------------EDITING MENU---------------\n";
         cout<<"\t\t\t\t|     CUSTOMER NAME     : PRESS N/n        | \n";
         cout<<"\t\t\t\t|     CUSTOMER MEDICINE : PRESS M/m        |\n";
         cout<<"\t\t\t\t|     GOTO ADMIN MENU   : PRESS E/e        |\n";
         cout<<"\t\t\t\t ------------------------------------------\n";
    
       do{  
             cout<<"\t\t\t\tEnter require option to Edit : "; cin>>choice;
             choice=(char)tolower(choice);

         switch(choice){

             case 'n':
             {  
                 cout<<PosNode->CustomerName<<endl;
                 cin.ignore();
                 cout<<"\t\t\t\t\tEnter Name of Custumer : "; getline(cin,name);
                 PosNode->CustomerName=name;
                 cout<<PosNode->CustomerName<<endl;
                 
                 break;
             }
             case 'm' : 
             {
                //  for(int i=0;i<PosNode->top;i++){
                //      cout<<i<<"   "<<PosNode->Medic[i]<<"   "<<PosNode->Quant[i]<<"   "<<PosNode->Price[i]<<endl;
                //  }
                //  cout<<"\t\t\t\t\t\t\tNow Your Total Price : "<<PosNode->totalPrice<<endl;
                 cout<<"\t\t\t\t ---------------EDITING MENU---------------\n";
                 cout<<"\t\t\t\t|     UPDATE MEDICINE     : PRESS M/m        |\n";
                 cout<<"\t\t\t\t|     UPDATE QUANTITY     : PRESS Q/q        |\n";
                 cout<<"\t\t\t\t|     GOTO ADMIN MENU     : PRESS E/e        |\n";
                 cout<<"\t\t\t\t ------------------------------------------\n";
                
                 char mchoice;
                 do{
                    
                    cout<<"\n\t\t\t\tEnter Required Option : "; cin>>mchoice;
                    mchoice=(char)tolower(mchoice);
                    switch (mchoice)
                    {
                    case 'm':
                            {   
                                DisplayNodeArray(PosNode);
                                int id;  
                                char merzi;
                                do{   
                                    // DisplayNode(**PosNode);
                                    cout<<"\t\t\t(a)Add or (r)Remove Medicince (e)EXIT : "; cin>>merzi;
                                    if(merzi=='r')                            
                                    { 
                                        cout<<PosNode->top<<"<-POSITION TOP\n";
                                        bool correct=false;
                                        DisplayNodeArray(PosNode);
                                        do{
                                            cout<<"\t\t\t\tEnter id to remove Medicince : ";  cin>>id; 
                                            if(id<=PosNode->top) correct=true;
                                            else id=false;
                                        }while(correct!=true);
                                        
                                        string Medicine=PosNode->Medic[id];
                                        int realID=-1;
                                            for(int i=0;i<recno;i++){
                                                if(Medicine==MedicStack[i]){
                                                    realID=i;
                                                    break;
                                                }
                                            }
                                        if(realID!=-1){
                                                // cout<<"\t\t\t\t\t\tNow Quantity Stack : "<<QuantStack[realID]<<endl;
                                            QuantStack[realID]+=PosNode->Quant[id];
                                                // cout<<"\t\t\t\t\t\tAfter remove Quantity Stack : "<<QuantStack[realID]<<endl;
                                                
                                            PosNode->totalPrice=PosNode->totalPrice-PosNode->Price[id];
                                        
                                        
                                        for(int i=id; i<PosNode->top;i++)
                                        {
                                            PosNode->Medic[i]=PosNode->Medic[i+1];
                                            PosNode->Quant[i]=PosNode->Quant[i+1];
                                            PosNode->Price[i]=PosNode->Price[i+1];
                                        }
                                        PosNode->top--;
                                            
                                        cout<<"\t\t\t\tNOTE :\n\t\t\t\t Medicince Removed Sucessfully\n\t\t\t\tMoney Transfer to your Account..\n";
                                        cout<<endl;
                                        // for(int i=0;i<PosNode->top;i++){
                                        //  cout<<i<<"   "<<PosNode->Medic[i]<<"   "<<PosNode->Quant[i]<<"   "<<PosNode->Price[i]<<endl;
                                        //      }
                                        // cout<<"Now Your Total Price : "<<PosNode->totalPrice<<endl;


                                                // cout<<"\nMain Data is this : \n";
                                                // DisplayData();
                                            }
                                            else{
                                                cout<<"\n\t\t\t\tNot Validate to return or Update this Medicince ......\n";
                                            }
                                            
                                        // DisplayNode(PosNode);    
                                    }
                                    else if(merzi=='a'){
                                            int code;
                                            bool check=false;
                                            int countAttempt=0;
                                            while(check!=true){
                                                countAttempt++;
                                                if(countAttempt==1){
                                                
                                                cout<<"\t\t\t\tEnter Medicine code : "; cin>>code;
                                                
                                                }else{
                                                    cout<<"\t\t\t\tEnter *Validate Medicine code : "; cin>>code;
                                                }
                                                check=CorrectID(code);
                                            } 
                                            PosNode->Medic[PosNode->top]=MedicStack[code];
                                            check=false;
                                            int q;
                                            while(check!=true){
                                                 cout<<"\t\t\t\tEnter Quantity of "<<MedicStack[code]<<" : "; cin>>q;
                                                 check=CorrectQuantity(code,q);
                                            }
                                                    PosNode->Quant[PosNode->top]=q;
                                                    QuantStack[code]=QuantStack[code]-q;
                                                    PosNode->Price[PosNode->top]=q*PriceStack[code];
                                                    PosNode->totalPrice+=PosNode->Price[PosNode->top];
                                                    PosNode->top++;
                                        // DisplayNode(PosNode);
                                         cout<<"\t\t\t\tAdded Successfully......\n";
                                        //  for(int i=0;i<PosNode->top;i++){
                                        //  cout<<i<<"   "<<PosNode->Medic[i]<<"   "<<PosNode->Quant[i]<<"   "<<PosNode->Price[i]<<endl;
                                        //      }
                                        // cout<<"Now Your Total Price : "<<PosNode->totalPrice<<endl;
                                    }
                                    else{
                                        cout<<"\t\t\tPlease press (a) for add, (r) for remove and (e) EXIT only.....\n";
                                    }
                                    
                            }while(merzi!='e');

                          break;
                        }
                        case 'q' :
                        {
                         char merzi;
                         do{
                            //  for(int i=0;i<PosNode->top;i++){
                            //              cout<<i<<"   "<<PosNode->Medic[i]<<"   "<<PosNode->Quant[i]<<"   "<<PosNode->Price[i]<<endl;
                            //                  }
                                        // cout<<"Now Your Total Price : "<<PosNode->totalPrice<<endl;
                                    
                            cout<<"\n\t\t\t(a)Add or (r)Remove Medicine Quantity (e)EXIT : "; cin>>merzi;
                            if(merzi=='r'){
                                int id;
                                bool correct=false;
                                DisplayNodeArray(PosNode);
                                do{
                                    cout<<"\t\t\t\t\t\t\tEnter id of Medicince to remove Quantity : ";  cin>>id; 
                                    if(id<PosNode->top) correct=true;
                                    else id=false;

                                }while(correct!=true);
                                int items;
                                bool check=false;
                                do{
                                    cout<<"\t\t\t\tEnter Quantity of Medicine remove : "; cin>>items;
                                    if(items<=PosNode->Quant[id]){
                                        check=true;
                                    }
                                }while(check!=true);
                                int Remaining=PosNode->Quant[id]-items;
                                if(Remaining==0)
                                {

                                     string Medicine=PosNode->Medic[id];
                                        int realID=-1;
                                            for(int i=0;i<recno;i++){
                                                if(Medicine==MedicStack[i]){
                                                    realID=i;
                                                    break;
                                                }
                                            }
                                    if(realID!=-1){
                                            QuantStack[realID]+=PosNode->Quant[id];
                                            PosNode->totalPrice=PosNode->totalPrice-PosNode->Price[id];
                                        
                                        for(int i=id; i<PosNode->top;i++)
                                        {
                                            PosNode->Medic[i]=PosNode->Medic[i+1];
                                            PosNode->Quant[i]=PosNode->Quant[i+1];
                                            PosNode->Price[i]=PosNode->Price[i+1];
                                        }
                                        }else
                                        {
                                             cout<<"\n\t\t\t\ttNot Validate for return or Update ......\n";
                                        }
                                }else{
                                PosNode->totalPrice=PosNode->totalPrice-(items*(PosNode->Price[id]/PosNode->Quant[id]));
                                PosNode->Price[id]=PosNode->Price[id]-(items*(PosNode->Price[id]/PosNode->Quant[id]));
                                PosNode->Quant[id]=Remaining;
                                }
                                DisplayNodeArray(PosNode);
                                // for(int i=0;i<PosNode->top;i++){
                                //          cout<<i<<"   "<<PosNode->Medic[i]<<"   "<<PosNode->Quant[i]<<"   "<<PosNode->Price[i]<<endl;
                                //              }
                                //         cout<<"Now Your Total Price : "<<PosNode->totalPrice<<endl;
                            // DisplayNode(PosNode);
                            }else if(merzi=='a'){

                                // for(int i=0;i<PosNode->top;i++){
                                //          cout<<i<<"   "<<PosNode->Medic[i]<<"   "<<PosNode->Quant[i]<<"   "<<PosNode->Price[i]<<endl;
                                //              }
                                //         cout<<"Now Your Total Price : "<<PosNode->totalPrice<<endl;
                                int id;
                                bool correct=false;
                                // DisplayNode(PosNode);
                                do{
                                    cout<<"\t\t\tEnter id of Medicince to Add Quantity : ";  cin>>id; 
                                    if(id<PosNode->top) correct=true;
                                    else id=false;

                                }while(correct!=true);
                                int items;
                                bool check=false;
                                do{
                                    cout<<"\t\t\t\tEnter Quantity of Medicine to add : "; cin>>items;
                                    check=CorrectQuantity(id,items);
                                }while(check!=true);
                                string Medicine=PosNode->Medic[id];
                                        int realID=-1;
                                            for(int i=0;i<recno;i++){
                                                if(Medicine==MedicStack[i]){
                                                    realID=i;
                                                    break;
                                                }
                                            }
                                
                                if(realID!=-1){
                                PosNode->totalPrice=PosNode->totalPrice-(items*PriceStack[realID]);
                                PosNode->Price[id]=PosNode->Price[id]-(items*PriceStack[realID]);
                                PosNode->Quant[id]+=items;
                            }
                            else{
                                
                               cout<<"\n\t\t\t\tNot Validate for return or Update ......\n";
                                             
                            }
                        }
                            // for(int i=0;i<PosNode->top;i++){
                            //              cout<<i<<"   "<<PosNode->Medic[i]<<"   "<<PosNode->Quant[i]<<"   "<<PosNode->Price[i]<<endl;
                            //                  }
                            //             cout<<"\t\t\t\t\t\tNow Your Total Price : "<<PosNode->totalPrice<<endl;
                            // // DisplayNode(PosNode);
                            // } 

                         }while (merzi!='e');
                         
                          break;
                        }
                    case 'e' : {

                    }

                    default:
                        {cout<<"\t\t\t\tPlease select *valid OPtion Only......\n";
                        break;}
                    }
                 }while(mchoice!='e');
             }

         }

        }while(choice!='e');
     }
    else{
        cout<<"\t\t\t\tList already is Empty\n";
}
  
 SaveData();  
 SaveCustomerData();           
  system("CLS");
  AdminMenu(); 
}
void CustomersSummary(){
    node*ptr=head;
    if(ptr!=NULL){
        system("CLS");
        cout<<"\t\t\t\t------------CUSTOMERS SUMMARY-------------\n";
        cout<<"\t\t\t\t ID          NAME          TIMMING\n";
            while(ptr!=NULL){
        cout<<"\t\t\t\t  "<<ptr->id<<" -> "<<ptr->CustomerName<<" -> "<<ptr->date<<endl;
        ptr=ptr->next;
            }
        cout<<"\t\t\t\t------------------------------------------\n";
    
    }
}
void Display(){
    node* ptr=head;
    if(ptr!=NULL){
    cout<<"\t\t\t\t\t_____________CUSTOMER DATA_______________ \n";
    while (ptr!=NULL)
    {
        cout<<"\t\t\t\t\tID:"<<ptr->id<<") \n";
        cout<<"\t\t\t\t\t   NAME       : "<<ptr->CustomerName<<" \n";
        cout<<"\t\t\t\t\t   Date       : "<<ptr->date<<" \n";
        cout<<"\t\t\t\t\t   MEDIC/QUANTITY/PRICE->\n";
        for(int i=0;i<ptr->top;i++){
            cout<<"\t\t\t\t\t   "<<i<<")"<<ptr->Medic[i]<<"    "<<ptr->Quant[i]<<"    "<<ptr->Price[i]<<endl;
        }
        cout<<"\t\t\t\t\t  Total Price : "<<ptr->totalPrice<<" \n";
        cout<<"\t\t\t\t\t    -------------------------------\n";
        ptr=ptr->next;
    }
        
    // cout<<ptr->id<<") ";
    // cout<<"\t\t\t\t\t\t"<<ptr->CustomerName<<endl;
    

    }
    else{
        cout<<"\t\t\t\t\t\tNo Customer Record Found....Sorry\n";
    }
}
bool CheckEmpty(){
    bool check=false;
    if(head==NULL){
    check=true;
        // cout<<"\tList is Empty\n";
    }
    else

        check=false;
        // cout<<"\tList is not Empty\n";

    return check;
}
void Searching(){
 bool check=false;
 int count=0;
 do{   
     count++;
     string name;
     if(count==1){
    cin.ignore();
    cout<<"\t\t\t\t\tEnter Customer Name : ";   getline(cin,name);
    }
    else{
        cout<<"\t\t\t\t\tEnter *Valid Customer Name : ";  getline(cin,name);
    }
   int check=-1;
//    int i=0;
    node*ptr;
    ptr=head;
    int count=0;
    while (ptr!=NULL)
    {
        count++;
        if(ptr->CustomerName==name){
            check=count;
            break;
        }
        ptr=ptr->next;
    }
    if(check!=-1){
                cout<<"\t\t\t\t\t--------------"<<ptr->CustomerName<<"--------------\n";
                cout<<"\t\t\t\t\t           Costumer ID     : "<<ptr->id<<"                  \n";
                cout<<"\t\t\t\t\t-----------------------------------------\n";
                cout<<"\t\t\t\t\t   MEDICINE / QUANTITY  / PRICE     \n";
                cout<<"\t\t\t\t\t-----------------------------------------\n";
                for(int i=0;i<ptr->top;i++){
                cout<<"\t\t\t\t\t"<<i+1<<")  "<<ptr->Medic[i]<<"    "<<ptr->Quant[i]<<"    "<<ptr->Price[i]<<endl;
                }
                cout<<"\t\t\t\t\t           Total  Price      : "<<ptr->totalPrice<<"      \n";
                cout<<"\t\t\t\t\t-----------------------------------------\n";
                
                cout<<"\t\t\t\tYou Want to Edit this Record(y/n) : "; char merzi; cin>>merzi;
                merzi=(char)tolower(merzi);
                if(merzi=='y'){
                    UpdateOrder(check);
                }
                else{
                    system("CLS");
                    ManagerMenu();
                    break;
                }
        check=true;
        }
    
    else{
        cout<<"\t\t\tCustomer is not found...\n";
        check=false;
        }
    }while(check!=true);
}
void TakeOrder(){
    int number;
    int count=0;
    do{
        count++;
         if(count==1){   cout<<"\t\t\t\t\t\tEnter Numbers of Customers : "; cin>>number;}
         else{           cout<<"\t\t\t\t\t\tEnter Numbers of Customers(N>0) : "; cin>>number;}
    }while(number<=0);
    Create(number);
}
void TakeCustomerPosition(){
    
    int realID=0;
    node*ptr;
    ptr=head;
    bool checked=false;
    int CountAttempt=0;
    system("CLS");
    CustomersSummary();
    do{
        CountAttempt++;
        // cout<<CountAttempt<<"COUNT\n";
        int id; 
        if(CountAttempt==1){
        cout<<"\t\t\t\tEnter Customer ID to UPDATE DATA :  "; cin>>id;
        }
        else{
        cout<<"\t\t\t\tEnter *Valid Customer ID to UPDATE DATA :  "; cin>>id;
        }
        int count=0;
        
        while(ptr!=NULL){
            count++;
            // cout<<"countAnother : "<<count<<"\n";
            if(ptr->id==id){
                cout<<ptr->id;
                realID=count;
                // break;
            }
        
        // cout<<"count : "<<count<<endl;
        // cout<<"Real ID : "<<realID<<endl;
        // cout<<"ID : "<<id<<endl;
        if(id<=count&&id>0){
            checked=true;
        }
        else{
            checked==false;
        }
        ptr=ptr->next;
        }
    }while(checked!=true);    
    
    if(checked==true){
        UpdateOrder(realID);
    }
    else{
        cout<<"\t\t\tYou put Invalid ID....\n";
    }
    

}
void RemovePosition(){
   int realID=0;
    node*ptr;
    ptr=head;
    bool checked=false;
    int CountAttempt=0;
    system("CLS");
    CustomersSummary();
    do{
        CountAttempt++;
        // cout<<CountAttempt<<"COUNT\n";
        int id; 
        if(CountAttempt==1){
        cout<<"\t\t\t\tEnter Customer ID to DELETE DATA(-1/Exit) :  "; cin>>id;
        }
        else{
        cout<<"\t\t\t\tEnter *Valid Customer ID to UPDATE DATA(-1/Exit) :  "; cin>>id;
        }
        if(id!=-1){
            int count=0;
    
                 while(ptr!=NULL){
                    count++;
                    // cout<<"countAnother : "<<count<<"\n";
                    if(ptr->id==id){
                        cout<<ptr->id;
                        realID=count;
                        // break;
                    }
            
                if(id<=count&&id>0){
                    checked=true;
                }
                else{
                    checked==false;
                }
                ptr=ptr->next;
                }
        }else{
            break;
        }

    }while(checked!=true);    
            
            if(checked==true){
                DeletePosition(realID);
            }
           
    
    system("CLS");
    AdminMenu();
}

// // iso::in	File opened in reading mode
// // iso::out	File opened in write mode
// // iso::app	File opened in append mode
// // iso::ate	File opened in append mode but read and write performed at the end of the file.
// // iso::binary	File opened in binary mode
// // iso::trunc	File opened in truncate mode
// // iso::nocreate	The file opens only if it exists
// // iso::noreplace	The file opens only if it doesn’t exist
//          COLOUR
// system("Color 0A"); GREEN
// system("Color 0C"); RED
// system("Color 70"); White background black Colourtext