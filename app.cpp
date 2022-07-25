#include<bits/stdc++.h>
using namespace std;

class Restaurant 
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    double total_tax;

    Restaurant(int food_item_codes[12], string food_item_names[12], int food_item_prices[12]){
        for(int i=0;i<12;i++){
            this->food_item_codes[i] = food_item_codes[i];
            this->food_item_prices[i] = food_item_prices[i];
            this->food_item_names[i] = food_item_names[i];
            this->total_tax = 0;
        } 
        
    }

    void show_item(){
         cout<<"                            "<<"Make bill"<<endl;
         cout<<"                       "<<"___________________"<<endl<<endl;
         cout<<"Item code:"<<"      "<<"Item name:"<<"                      "<<"Item Price:"<<endl;
         for(int i=0;i<12;i++){
            cout<<food_item_codes[i]<<"             "<<left<<setw(25)<<food_item_names[i]<<"       "<<food_item_prices[i]<<endl;
         } 
    }


    void food_item(int item_count,int item_code[],int foodItem[]){
        for(int i=0;i<item_count;i++){
            for(int j=0;j<12;j++){
                if(item_code[i] == food_item_codes[j]) {
                    foodItem[i] = j;
                }
            }
        }
    }

    int check_item(int code){
        for(int i=0;i<12;i++){
            if(code == this->food_item_codes[i]) return 1;
        }
        return 0;
    }

};

Restaurant* takeInput(){
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>food_item_codes[i];
        cin.ignore();
        getline(cin, food_item_names[i]);
        cin>>food_item_prices[i];
    } 
    
    
    Restaurant *myRes = new Restaurant(food_item_codes,food_item_names,food_item_prices); 
    return myRes;
}

void takeInput(int j,int item_count, int item_code[], int quantity[], Restaurant* myRes){
     for(int i=j;i<item_count;i++){
        cout<<endl<<"Ente item "<<i+1<<" code: ";
        cin>>item_code[i];
        int chk_error = myRes->check_item(item_code[i]);
        if(!chk_error){
            cout<<endl<<"item not found, please enter a valid code.";
            takeInput(i,item_count, item_code, quantity, myRes);
            break;
        }
        cout<<endl<<"Ente item "<<i+1<<" quantity: ";
        cin>>quantity[i];
    }
}


int main(){
    Restaurant *myRes = takeInput();

Flag:
    myRes->show_item();

    //take input from the customer
    int table_no,item_count;

    cout<<"Enter table no: ";
    cin>>table_no;
    cout<<endl<<"Enter number of items: ";
    cin>>item_count;

    int item_code[item_count] = {0}, quantity[item_count];
    int i = 0;
    takeInput(i,item_count, item_code, quantity, myRes);

    int foodIitem[item_count] = {-1};
    myRes->food_item(item_count,item_code,foodIitem);

    //Bill summary
    cout<<"                                                "<<"Bill summary"<<endl;
    cout<<"                                            "<<"___________________"<<endl<<endl;
    cout<<"table no: "<<table_no<<endl;
    cout<<"Item code:"<<"      "<<"Item name:"<<"                   "<<"Item Price:"<<"       "<<"Item quantity:"<<"      "<<"Total price:"<<endl;

    //count total price
    int total_price = 0;
    for(int i=0;i<item_count;i++){
        int total = myRes->food_item_prices[foodIitem[i]]*quantity[i];
        cout<<myRes->food_item_codes[foodIitem[i]]<<"             "<<left<<setw(25)<<myRes->food_item_names[foodIitem[i]]<<"    "<<myRes->food_item_prices[foodIitem[i]]<<"               "<<left<<setw(4)<<quantity[i]<<"                "<<total<<endl;
        total_price += total;
    } 

    double tax = (5*total_price)/100;
    cout<<"Tax"<<"                                                                                "<<fixed<<setprecision(2)<<tax<<endl;

    cout<<"___________________________________________________________________________________________________"<<endl;

    cout<<"Net total"<<"                                                                          "<<total_price+tax<<endl;

    // add total tax on resturent class
    myRes->total_tax = tax;
    
    goto Flag;
    return 0;
}